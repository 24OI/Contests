uses math;
var
ans,aa,b,c,d,m,p:longint;
a:array[1..1000,1..1000] of longint;
 n,i,j,k:integer;
procedure init;
var i,j,x,y:integer;
begin
readln(n);
 for i:=2 to n do
   begin
   readln(x,y,j);
   a[x,y]:=j;
  end;
end;

begin
assign(input,'tree.in');reset(input);
assign(input,'tree.out');reset(output);
fillchar(a,sizeof(a),0);
init;
 for k:=1 to n do
  for i:=1 to n do
   for j:=1 to n do
    if(a[i,j]*a[i,k]*a[k,j]<>0)and( a[i,k]+a[k,j]<a[i,j]) then a[i,j]:=a[i,k]+a[k,j];
	
	readln(m);ans:=0;
	for p:=1 to m do begin readln(aa,b,c,d);
	for i:=aa to b do for j:=c to d do  
	if(a[i,j]<>0)then ans:=max(ans,a[i,j]);
	writeln(ans);
	end;
	close(input);close(output);
end.

