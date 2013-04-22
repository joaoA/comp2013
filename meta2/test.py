#!/usr/bin/env python
# -*- coding: utf-8 -*-

# qcc-tester.py readme:
# Este script deve funcionar em Python 2.6, 2.7, 3.2 e 3.3, em Linux e Windows (c/ ou s/ cygwin)
# Infelizmente não sei como funciona em OSX, mas não há razões nenhumas para não funcionar bem.
# Para correr, basta simplesmente fazer "./qcc-tester.py" ou "python qcc-tester.py"
# Após executar, verifica por ficheiros de teste novos, portanto é preciso internet.
# As únicas configurações que há são as que estão mesmo abaixo dos imports,
# mas em principio não é preciso alterar nada. Agradeço mais ficheiros de teste
# (principalmente feitos à mão) e assim adicionava tudo no repositório :D
# Já agora, este código pica nos olhos. Use at your own risk :)

from __future__ import print_function, division
try:
    import urllib.request as ulib
except ImportError:
    import urllib2 as ulib
from subprocess import Popen, PIPE, STDOUT
from itertools import islice
import os
import tarfile
import difflib
from cgi import escape

# ------------------------ Config ------------------------
remotedir   = "http://student.dei.uc.pt/~hjalves/qctests/"  # De onde saca os testes
testdir     = "testdata"                                    # Diretorio local
executable  = "./qcparser"                                  # Nome do executável
reportname  = "report.html"                                 # Relatório final
update      = True                                          # False para nunca sacar testes
# --------------------------------------------------------

class Report(object):
    maxresults = 10     # Máximo de resultados por dataset
    def __init__(self, execname):
        self.resultslist = []
        self.execname = execname
    
    def is_empty(self):
        return len(self.resultslist) == 0
    
    def add_results(self, results):
        self.resultslist.append(results)
    
    def summary(self):
        return "\n".join([r.summary() for r in self.resultslist])
    
    def write_html(self, filename):
        results = self.resultslist
        template = """
        <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
                  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
        <html>
        <head>
            <meta http-equiv="Content-Type"
                  content="text/html; charset=ISO-8859-1" />
            <title></title>
            <style type="text/css">%(styles)s
            </style>
        </head>
        <body>
            %(body)s
        </body>
        </html>"""
        
        styles = """
            h1,h2 {font-family:sans-serif}
            h1 {font-size:1.5em}
            h2 {font-size:1em}
            code {font-size:12px}
            table.diff {font-family:monospace; border:medium; font-size:12px}
            .diff_header {background-color:#e0e0e0}
            td.diff_header {text-align:right}
            .diff_next {background-color:#c0c0c0}
            .diff_add {background-color:#aaffaa}
            .diff_chg {background-color:#ffff77}
            .diff_sub {background-color:#ffaaaa}"""
        
        htmldiff = difflib.HtmlDiff()
        body = []
        body.append("<h1> Report Summary </h1>")
        body.append( "<br/>".join(self.summary().splitlines()) )
        for r in results:
            body.append("<h1> %s </h1>" % r.setname)
            if not r.failed:
                body.append("All tests passed. Well done!")
            for f in islice(r.failed, Report.maxresults):
                name = f["name"]
                input = f["input"].decode("ascii").splitlines()
                got = f["got"].decode("ascii").splitlines()
                expected = f["expected"].decode("ascii").splitlines()
                body.append("<h2> %s </h2>" % name)
                body.append( "<code>" + ""
                    .join(["%3d|%s <br/>" % (n, escape(line)) for (n, line) in enumerate(input, 1)])
                    .replace(' ','&nbsp;').replace('\t', '&nbsp'*4) + "</code>" )
                body.append("<br/>")
                body.append( htmldiff.make_table(got, expected, "got output (%s)" % self.execname,
                    "expected (%s.out)" % name ) )
        htmlfile = template % {"styles": styles, "body": "\n".join(body)}
        with open(filename, "w") as reportfile:
            reportfile.write( htmlfile )
        

class Results(object):
    def __init__(self, setname):
        self.setname = setname
        self.total = 0
        self.failed = []
    
    def new_fail(self, name, input, got, expected):
        self.failed.append({"name": name, "input": input, "got": got, "expected": expected})
    
    def summary(self):
        return "{0}: {1} tests, {2} failed. Success rate: {3}%".format(self.setname,
            self.total, len(self.failed), 100*(self.total-len(self.failed))/self.total)


class Dataset(object):
    @staticmethod
    def from_tar(filepath):
        indict, outdict = {}, {}
        tar = tarfile.open(filepath, "r")
        for f in tar:
            s = tar.extractfile(f).read()
            if f.name.endswith(".in"):
                indict[f.name[:-3]] = s
            elif f.name.endswith(".out"):
                outdict[f.name[:-4]] = s
        tar.close()
        return Dataset(os.path.basename(filepath), indict, outdict)
    
    def __init__(self, setname, indict, outdict):
        self.setname = setname
        self.indict, self.outdict = indict, outdict
    
    def run_tests(self, compilerexec):
        results = Results(self.setname)
        for n, name in enumerate(sorted(self.indict)):
            p = Popen(compilerexec, stdout=PIPE, stdin=PIPE, stderr=PIPE)
            pipeout = p.communicate(input=self.indict[name])
            if pipeout[0] != self.outdict[name]:
                results.new_fail(name, self.indict[name], pipeout[0], self.outdict[name])
            results.total += 1
        return results

def localversion():
    try:
        with open(os.path.join(testdir, "ver.txt")) as verfile:
            local_version = int(verfile.read())
            return local_version
    except IOError:
        return 0

def remoteversion():
    response = ulib.urlopen(remotedir + "ver.txt")
    remote_version = int(response.read())
    return remote_version

def get_dataset_files():
    if not os.path.exists(testdir):
        os.makedirs(testdir)
    response = ulib.urlopen(remotedir + "files.txt")
    remote_files = response.read().decode("ascii").split()
    for filename in remote_files + ["ver.txt"]:
        print("Downloading", filename)
        response = ulib.urlopen(remotedir + filename)
        with open(os.path.join(testdir, filename), "wb") as localfile:
            localfile.write(response.read())

def main():
    if update:
        try:
            print("Checking dataset updates...")
            if (localversion() < remoteversion()):
                get_dataset_files()
        except ulib.URLError:
            print("Error while downloading datasets... (There is an option to disable updates) ")
    
    report = Report(executable)
    try:
        testfiles = sorted(os.listdir(testdir))
    except:
        testfiles = []
    
    for testfile in testfiles:
        if testfile.endswith(".tar.gz"):
            print("Loading dataset", testfile)
            tarpath = os.path.join(testdir, testfile)
            dataset = Dataset.from_tar(tarpath)
            print("Testing compiler...", dataset.setname)
            try:
                results = dataset.run_tests(executable)
            except OSError:
                print("Cannot run %s. (You can change the option \"executable\")" % executable)
                exit(0)
            report.add_results(results)
            print(results.summary())
    
    if not report.is_empty():
        print("Saving report to", reportname)
        report.write_html(reportname)
    else:
        print("No test results.")
    print("Will exit.")
    
if __name__ == "__main__":
    main()