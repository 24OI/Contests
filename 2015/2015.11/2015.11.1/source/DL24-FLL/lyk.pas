var n,m,i,t:longint;sum:int64;
a:array [1..100000] of longint;
b:array [1..100000,1..2] of longint;

procedure mer(l,r:longint);
var i,j,mid:longint;
begin
mid:=(l+r) div 2;
if l<>r then begin
	mer(l,mid);
	mer(mid+1,r);
	end;
i:=l;
j:=mid+1;
repeat 
	while (i<=mid)and(a[i]<a[j]) do inc(i);
	while (j<=r)and(a[j]<a[i]) do begin
		inc(j);sum:=sum+mid-i+1;sum:=sum mod 2;end;
until (i>mid)or(j>r);

end;


begin
assign(input,'lyk.in');
reset(input);
assign(output,'lyk.out');
rewrite(output);
read(n);
for i:=1 to n do read(a[i]);
read(m);
for i:=1 to m do read(b[i][1],b[i][2]);

for i:=1 to m do begin
	t:=a[b[i][1]];
	a[b[i][1]]:=a[b[i][2]];
	a[b[i][2]]:=t;
	mer(1,n);
	writeln(sum mod 2);
	sum:=0;
	end;
close(input);close(output);	
end.