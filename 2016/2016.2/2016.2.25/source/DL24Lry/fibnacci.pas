const gzq=1000000001;
var f,a:array[0..100001] of longint;
i,j,ans,n,x,l,r,m:longint;

begin
assign(input,'fibnacci.in');
assign(output,'fibnacci.out');
reset(input);rewrite(output);
	f[0]:=0;
	f[1]:=1;
for i:= 2 to 10000 do
	begin 
	f[i]:=f[i-1]+f[i-2];
	f[i]:=f[i] mod gzq;
	end;
readln(n,m);
for i:= 1 to n do 
	read(a[i]);

for i:= 1 to m do 
	begin
	readln(x,l,r);
	ans:=0;
	if x=1 then 
	for j:= l to r do 
		a[j]:=(a[j] + f[j-l+1]) mod gzq;
	if x=2 then 
		begin
		for j:= l to r do 
			begin
			ans:=ans + a[j];
			ans:=ans mod gzq;
			end;
		writeln( ans );
		end;
	end;
close(input);close(output);
end.