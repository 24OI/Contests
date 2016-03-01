const saffah=1000000001;
var n,m,i,j,op,l,r,ans:longint;
f,s:array[1..110000]of longint;
begin
assign(input,'fibnacci.in');
assign(output,'fibnacci.out');
reset(input);
rewrite(output);
read(n,m);
f[1]:=1;f[2]:=1;
for i:=3 to n do f[i]:=(f[i-1]+f[i-2]) mod saffah;
//s[1]:=1;
//for i:=2 to n do s[i]:=(s[i-1]+f[i]) mod saffah;
for i:=1 to n do read(s[i]);
for j:=1 to m do begin
	read(op,l,r);
	if op=1 then begin
		for i:=l to r do s[i]:=(s[i]+f[i-l+1]) mod saffah;
		end
	else begin
		ans:=0;
		for i:=l to r do ans:=(ans+s[i]) mod saffah;
		writeln(ans);
		end;
//	for i:=1 to n do write(s[i],' ');writeln;
	end;
close(input);
close(output);
end.
