const mo=593119681;
var
  a,b:array[0..64,0..64] of int64;
  c,d,num:array[0..64] of int64;

  f:array[0..1,0..262144] of longint;
  nex:array[0..262144,0..18] of longint;
  n,nn,t,i,j,k,l:longint;
  ans:int64;

function ff(x:longint):longint;
begin
  ff:=0;
  while x>0 do begin
    x:=x-(-x and x);inc(ff);end;
end;

procedure incc(var x,y:longint);
begin x:=x+y;if x>=mo then dec(x,mo);end;

function exp(x,y:int64):int64;
begin
  if y=0 then exit(1);if y=1 then exit(x);
  exit(exp(x*x mod mo,y shr 1)*exp(x,y and 1)mod mo);
end;

begin
  assign(input,'monster.in');reset(input);
  assign(output,'monster.out');rewrite(output);
  readln(n,t);nn:=1 shl n-1;

if n<=6 then begin

  for i:=0 to nn do read(c[i]);
  for i:=0 to nn do num[i]:=ff(i);

  for i:=0 to nn do for j:=0 to nn do begin
    if abs(num[i]-num[j])=1 then a[i,j]:=1;
    if i=j then a[i,j]:=1;end;
  for l:=0 to 30 do begin
    if t shr l and 1=1 then begin
      fillchar(d,sizeof(d),0);
      for i:=0 to nn do for j:=0 to nn do
        d[j]:=(d[j]+c[i]*a[i,j])mod mo;
      c:=d;
    end;
    if 2 shl l>t then break;
    for i:=0 to nn do for j:=0 to nn do begin
      b[i,j]:=a[i,j];a[i,j]:=0;end;
    for i:=0 to nn do for j:=0 to nn do for k:=0 to nn do
      a[i,j]:=(a[i,j]+b[i,k]*b[k,j])mod mo;
  end;
  for i:=0 to nn do write(c[i],' ');

end else begin

  for i:=0 to nn do read(f[1,i]);
  for i:=0 to nn do for j:=0 to n-1 do
    nex[i,j]:=i xor(1 shl j);

  for l:=1 to t do begin
    j:=-1;
    for i:=0 to nn do begin
      if (i>0)and(f[1,i]<>f[1,i-1]) then j:=0;
      f[0,i]:=f[1,i];end;
    if j=-1 then break;
    for i:=0 to nn do for j:=0 to n-1 do
      incc(f[1,nex[i,j]],f[0,i]);
  end;
  ans:=f[1,0];
  if j=-1 then ans:=ans*exp(n+1,t-l+1) mod mo;
  if j=-1 then for i:=0 to nn do write(ans,' ') else
  for i:=0 to nn do write(f[1,i],' ');

end;
  close(input);close(output);
end.


