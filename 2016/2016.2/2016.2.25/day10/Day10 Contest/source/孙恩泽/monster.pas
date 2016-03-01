const modmod=593119681;
var a,z:array[0..20,0..20]of longint;
    f,zz:array[0..20]of longint;
    ans,b:array[0..1000000]of longint;
    n,t,i,j:longint;
procedure init(a:string);
begin
 assign(input,a+'.in');
 assign(output,a+'.out');
 reset(input);
 rewrite(output);
end;
procedure clo;
begin
 close(input);
 close(output);
end;
procedure ksm(t:longint);
var i,j,k:longint;
begin
 if t=0 then exit;
 if t mod 2=1 then
  begin
   for i:=0 to n do
    zz[i]:=0;
   for i:=0 to n do
    for j:=0 to n do
     zz[j]:=(zz[j]+int64(f[i])*a[i,j])mod modmod;
   for i:=0 to n do
    f[i]:=zz[i];
  end;
 for i:=0 to n do
  for j:=0 to n do
   z[i,j]:=0;
 for i:=0 to n do
  for j:=0 to n do
   for k:=0 to n do
    z[i,k]:=(a[j,k]*int64(a[i,j])+z[i,k]) mod modmod;
 for i:=0 to n do
  for j:=0 to n do
   a[i,j]:=z[i,j];
 ksm(t div 2)
end;
function dis(x:longint):longint;
var s,i:longint;
begin
 s:=0;
 for i:=0 to n-1 do
  if (1 shl i)and x<>0 then
   inc(s);
 exit(s);
end;
begin
 init('monster');
 read(n,t);
 for i:=0 to n do
  for j:=0 to n do
   a[i,j]:=0;
 for i:=0 to n do
  a[i,i]:=1;
 for i:=0 to n-1 do
  begin
   a[i,i+1]:=i+1;
   a[i+1,i]:=n-i;
  end;
 for i:=1 to n do
  f[i]:=0;
 f[0]:=1;
 ksm(t);
 for i:=0 to 1 shl n-1 do
  read(b[i]);
 for i:=0 to 1 shl n-1 do
  ans[i]:=0;
 for i:=0 to 1 shl n-1 do
  if b[i]<>0 then
   for j:=0 to 1 shl n-1 do
    ans[j]:=(ans[j]+f[dis(i xor j)]*int64(b[i])) mod modmod;
 for i:=0 to 1 shl n-1 do
  write(ans[i],' ');
 clo;
end.
