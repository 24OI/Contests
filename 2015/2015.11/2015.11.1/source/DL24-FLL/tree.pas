var n,m,x,y,z,i,j,a,b,c,d,k,max:longint;
q:array [1..10000,1..10000] of longint;
ans:array [1..10000] of longint;
begin
assign(input,'tree.in');
reset(input);
assign(output,'tree.out');
rewrite(output);
readln(n);
for i:=1 to n do 
	for j:=1 to n do q[i][j]:=20000;
for i:=1 to n-1 do begin
	read(x,y,z);
	q[x][y]:=z;
	q[y][x]:=z;
	end;
for k:=1 to n do
	for i:=1 to n do 
		for j:=1 to n do 
		if (k<>i)and(k<>j)and(i<>j)then 
			if (q[i][j]>(q[i][k]+q[k][j]))then
				q[i][j]:=q[i][k]+q[k][j];
	for i:=1 to n do q[i][i]:=0;
	
read(m);
for i:=1 to m do begin
	read(a,b,c,d);
	max:=0;
	for j:=a to b do 
		for k:=c to d do 
	if max<q[j][k] then max:=q[j][k];
	ans[i]:=max;
		end;

for i:=1 to m do writeln(ans[i]);
close(input);close(output);	

end.