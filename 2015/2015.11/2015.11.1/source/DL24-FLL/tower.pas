var n,i,j,c1,c2,c3,sum,k,l:longint;
a:array [1..100,1..100] of longint;
begin
assign(input,'tower.in');
reset(input);
assign(output,'tower.out');
rewrite(output);

readln(n);
for i:=1 to n-1 do 
	for j:=1 to n-i do read(a[i][i+j]);
c1:=1;
c2:=1;
c3:=1;
for i:=2 to n do begin
	if (a[c1][i]<=a[c2][i])and(a[c1][i]<=a[c3][i])
	then begin sum:=sum+a[c1][i];c1:=i;end else
	if (a[c2][i]<=a[c1][i])and(a[c2][i]<=a[c3][i])
	then begin sum:=sum+a[c2][i];c2:=i;end else
	if (a[c3][i]<=a[c1][i])and(a[c3][i]<=a[c2][i])
	then begin sum:=sum+a[c3][i];c3:=i;end;
	end;
	
writeln(sum);
close(input);close(output);	
end.