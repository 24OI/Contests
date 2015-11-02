program dy2;
var i,j,k,n,tt:longint;
var a:array[1..101,1..101]of longint;

begin
assign(input,'tower.in');
assign(output,'tower.out');
reset(input);
rewrite(output);

	readln(n);
	for i:=1 to n do
		for j:=1 to n do
			a[i,j]:=10001;
	
	for i:=1 to n-1 do
	begin
		for j:=i+1 to n do
			read(a[i,j]);
		readln;
	end;
	
	for i:=1 to n do
		for j:=1 to n do
			for k:=1 to n do
				if a[j,k]>a[j,i]+a[i,k] then a[j,k]:=a[j,i]+a[i,k];
	
	writeln(a[1,n]);

close(input);
close(output);
end.