procedure proc1
	let 
		integer x
		integer n
	in 		
		x=99
		write x
	end

procedure proc2
	let 
		char s 
	in 
		s='a' 
		write s
	end

letglobal
	integer s
end

let 
	integer p
	double 	x
	char 	z
in
	s = 2
	x = 1.1
	z='c'
	call proc2
	write	s
	write	x
	write   z
	call proc1
end
