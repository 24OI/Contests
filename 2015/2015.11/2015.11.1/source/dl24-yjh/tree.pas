program dy3;
var n:longint;

begin
assign(input,'tree.in');
assign(output,'tree.out');
reset(input);
rewrite(output);

	readln(n);
	write(random(n*n));

close(input);
close(output);
end.