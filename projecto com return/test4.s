letglobal
	integer z
	integer k
	integer n
end

procedure proc1
let 
	double 	x
	char 	z
in
	z='v'
	x=1.1
	k=4
	write	n
	write	k
end

let
	integer z
in
	z=10
	write z
	call proc1
end 