var n,i,ans:longint;
a,b:array[0..100101] of longint;
m,x,y,t:longint;

procedure merge(left,mid,right:longint);
var le,mi,k,i:longint;
begin
le:=left;mi:=mid+1;k:=left;
while (le<=mid) and (mi<=right) do
begin
if a[le]<=a[mi] then
begin
b[k]:=a[le];
inc(le);
inc(k);
end else
begin
b[k]:=a[mi];
inc(mi);
inc(k);
ans:=(ans mod 2+mid mod 2-le mod 2+1)mod 2; 
end;
end;
while le<=mid do begin b[k]:=a[le];inc(le);inc(k); end;
while mi<=right do begin b[k]:=a[mi];inc(mi);inc(k); end;
for i:=left to right do a[i]:=b[i];
end;


procedure msort(left,right:longint);
var mid:longint;
begin
if left=right then exit;
mid:=(left+right) div 2;
msort(left,mid);
msort(mid+1,right);
merge(left,mid,right);
end;


begin
assign(input,'lyk.in');reset(input);
assign(output,'lyk.out');rewrite(output);
readln(n);
for i:=1 to n do read(a[i]);
readln(m);
for i:=1 to m do begin 
readln(x,y);
t:=a[x];a[x]:=a[y];a[y]:=t;
msort(1,n);
writeln(ans and 1);
end;
close(input);close(output);
end.  