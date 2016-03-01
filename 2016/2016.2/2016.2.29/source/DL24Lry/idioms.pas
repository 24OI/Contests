var i,ans:longint;
s:array[1..3000] of string[4];
n,m,j,zz,k,temp:longint;
t,q:string[4];
begin
	assign(input,'idioms.in');
	assign(output,'idioms.out');
	reset(input);rewrite(output);
readln(n,m);
for i:= 1 to n do 
	readln(s[i]);


	for i:= 1 to n-1 do 
	for j:= i+1 to n do 
		begin
		q:=s[i];t:=s[j];
		temp:=0;
		for k:= 1 to 4 do 
			begin
			if q[k]<>t[k] then inc(temp);
			end;
		if temp = m then inc(ans);
		end;
writeln(ans);
close(input);close(output);
end.