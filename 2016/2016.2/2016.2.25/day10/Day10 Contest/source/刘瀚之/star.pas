var
  l:array[1..1000,1..3] of int64;
  a,siz,la:array[1..1000000] of longint;
  x,y:array[1..1000000] of double;
  ans:array[1..1000] of longint;
  n,m,i,j,sa:longint;

  ll:array[1..2,1..3] of int64;

procedure make(z1,z2:longint);

function hus(x,y:double):longint;
begin exit(abs(trunc(x*27183+y*31.415)mod 999997));end;

function find(i:longint;xx,yy:double):boolean;
begin
  if i=0 then exit(false);
  if (abs(x[i]-xx)<1e-7)and(abs(y[i]-yy)<1e-7) then begin
    inc(siz[i]);exit(true);end else exit(find(a[i],xx,yy));
end;

var xx,yy:double;
  h,i:longint;
begin
  if l[z1,1]*l[z2,2]=l[z1,2]*l[z2,1] then exit;
  if l[z1,1]<>0 then begin
    ll[1]:=l[z1];ll[2]:=l[z2];end else begin
    ll[2]:=l[z1];ll[1]:=l[z2];end;
  if ll[2,1]<>0 then
    for i:=3 downto 1 do ll[2,i]:=ll[2,i]*ll[1,1]-ll[1,i]*ll[2,1];
  if ll[1,2]<>0 then
    for i:=3 downto 2 do ll[1,i]:=ll[2,2]*ll[1,i]-ll[1,2]*ll[2,i];
  xx:=ll[1,3]/ll[1,1];yy:=ll[2,3]/ll[2,2];
  h:=hus(xx,yy)+1;
  if find(la[h],xx,yy) then exit;
  inc(sa);a[sa]:=la[h];la[h]:=sa;
  siz[sa]:=1;x[sa]:=xx;y[sa]:=yy;
end;

begin
  assign(input,'star.in');reset(input);
  assign(output,'star.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(l[i,1],l[i,2],l[i,3]);
  for i:=1 to n do for j:=i+1 to n do make(i,j);
  for i:=1 to 999997 do inc(ans[trunc(sqrt(siz[i]*2))+1]);
  for i:=1000 downto 1 do if ans[i]>0 then begin
    writeln(i,' ',ans[i]);break;end;
  close(input);close(output);
end.

