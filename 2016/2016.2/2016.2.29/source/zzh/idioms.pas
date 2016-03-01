var n,d,i,j,k,t,ans:longint;
ci:array[1..5000]of string[4];
begin
assign(input,'idioms.in');
assign(output,'idioms.out');
reset(input);
rewrite(output);
readln(n,d);
for i:=1 to n do readln(ci[i]);
ans:=0;
for i:=1 to n do for j:=i+1 to n do begin
	t:=0;
	for k:=1 to 4 do if ci[i][k]=ci[j][k] then inc(t);
	if t=d then inc(ans);
	end;
writeln(ans);
close(input);
close(output);
end.