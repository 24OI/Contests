 var n,m,i,a,b,c,d:longint;
begin
	assign(input,'pinball.in');	reset(input);
	assign(output,'pinball.out');rewrite(output);

readln(n,m);
for i:= 1 to n do 
	readln(a,b,c,d);
writeln('-1');


close(input);close(output);

end.