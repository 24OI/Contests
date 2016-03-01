const mo=1000000001;
var
  a,F,FF:array[-1..100000] of int64;
  sum,a1,a2:array[0..333333] of int64;
  n,m,i,x,y,z:longint;

function min(x,y:longint):longint;
begin if x<y then exit(x) else exit(y);end;
function max(x,y:longint):longint;
begin if x>y then exit(x) else exit(y);end;
procedure incc(var x:int64;y:int64);
begin x:=(x+y) mod mo;end;

function gsum(x,y,z:int64):int64;
begin exit((x*ff[z]+y*(ff[z+1]+mo-1))mod mo);end;
function ga(x,y,z:int64):int64;
begin exit((x*f[z-1]+y*f[z])mod mo);end;

procedure make(t,l,r:longint);
begin
  if r-l=1 then begin
    sum[t]:=a[l];exit;end;
  make(t+t,l,(l+r)shr 1);
  make(t+t+1,(l+r)shr 1,r);
  sum[t]:=(sum[t+t]+sum[t+t+1])mod mo;
end;

procedure down(t,l,r:longint);
var mid:longint;
begin
  if (a1[t]=0)and(a2[t]=0) then exit;
  if r-l>1 then begin
    mid:=(l+r)shr 1;
    incc(a1[t+t],a1[t]);incc(a2[t+t],a2[t]);
    incc(a1[t+t+1],ga(a1[t],a2[t],mid-l));
    incc(a2[t+t+1],ga(a1[t],a2[t],mid-l+1));
    incc(sum[t+t],gsum(a1[t],a2[t],mid-l));
    incc(sum[t+t+1],gsum(ga(a1[t],a2[t],mid-l),
      ga(a1[t],a2[t],mid-l+1),r-mid));
  end;
  a1[t]:=0;a2[t]:=0;
end;

procedure int(t,l,r,x,y,z1,z2:longint);
var mid:longint;
begin
  down(t,l,r);
  if (l=x)and(r=y) then begin
    incc(a1[t],z1);incc(a2[t],z2);
    incc(sum[t],gsum(z1,z2,r-l));
    exit;end;
  mid:=(l+r)shr 1;
  if x<mid then int(t+t,l,mid,x,min(mid,y),z1,z2);
  if y>mid then int(t+t+1,mid,r,max(x,mid),y,
    ga(z1,z2,max(x,mid)-x),ga(z1,z2,max(x,mid)-x+1));
  sum[t]:=(sum[t+t]+sum[t+t+1])mod mo;
end;

function find(t,l,r,x,y:longint):int64;
var mid:longint;
begin
  down(t,l,r);
  if (l=x)and(r=y) then exit(sum[t]);
  mid:=(l+r)shr 1;find:=0;
  if x<mid then inc(find,find(t+t,l,mid,x,min(mid,y)));
  if y>mid then inc(find,find(t+t+1,mid,r,max(x,mid),y));
  find:=find mod mo;
end;

begin
  assign(input,'fibnacci.in');reset(input);
  assign(output,'fibnacci.out');rewrite(output);
  readln(n,m);f[-1]:=1;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do f[i]:=(f[i-1]+f[i-2])mod mo;
  for i:=1 to n do ff[i]:=(ff[i-1]+f[i])mod mo;

  make(1,1,n+1);
  for i:=1 to m do begin
    readln(x,y,z);
    if x=1 then int(1,1,n+1,y,z+1,1,0);
    if x=2 then writeln(find(1,1,n+1,y,z+1));
  end;
  close(input);close(output);
end.
