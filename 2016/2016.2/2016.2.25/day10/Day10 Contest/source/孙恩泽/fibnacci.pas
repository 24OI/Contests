const modmod=1000000001;
type tree=^node;
      node=record
       data,a0,a1,l,r,x:longint;
       lc,rc:tree;
      end;
var head:tree;
    ksm:array[0..2,0..2,0..20]of int64;
    i,j,k,l,n,m,x,a0,a1,r,op:longint;
    a:array[1..200000] of longint;
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
function build(l,r,x:longint):tree;
var p:tree;
begin
 new(p);
 p^.l:=l;
 p^.r:=r;
 p^.x:=x;
 p^.a0:=0;
 p^.a1:=0;
 if l=r then
  begin
   p^.lc:=nil;
   p^.rc:=nil;
   p^.data:=a[l];
   exit(p);
  end;
 p^.lc:=build(l,(l+r) div 2,x-1);
 p^.rc:=build((l+r) div 2+1,r,x-1);
 p^.data:=(p^.lc^.data+p^.rc^.data) mod modmod;
 exit(p);
end;
procedure gx(p:tree);
var xx:longint;
begin
 p^.lc^.data:=(ksm[0,2,p^.lc^.x]*p^.a0+ksm[1,2,p^.lc^.x]*p^.a1+p^.lc^.data)mod modmod;
 p^.lc^.a0:=p^.lc^.a0+p^.a0;
 p^.lc^.a1:=p^.lc^.a1+p^.a1;
 xx:=(ksm[0,0,p^.lc^.x]*p^.a0+ksm[1,0,p^.lc^.x]*p^.a1) mod modmod;
 p^.a1:=(ksm[0,1,p^.lc^.x]*p^.a0+ksm[1,1,p^.lc^.x]*p^.a1) mod modmod;
 p^.a0:=xx;
 p^.rc^.data:=(ksm[0,2,p^.rc^.x]*p^.a0+ksm[1,2,p^.rc^.x]*p^.a1+p^.rc^.data)mod modmod;
 p^.rc^.a0:=(p^.rc^.a0+p^.a0) mod modmod;
 p^.rc^.a1:=(p^.rc^.a1+p^.a1) mod modmod;
 p^.a0:=0;
 p^.a1:=0;
end;
procedure tian(p:tree);
var xx:longint;
begin
 if p^.r<l then exit;
 if p^.l>r then exit;
 if (l=p^.l)and(p^.r<=r) then
  begin
   p^.data:=(ksm[0,2,p^.x]*a0+ksm[1,2,p^.x]*a1+p^.data)mod modmod;
   p^.a0:=(p^.a0+a0) mod modmod;
   p^.a1:=(p^.a1+a1) mod modmod;
   xx:=(ksm[0,0,p^.x]*a0+ksm[1,0,p^.x]*a1) mod modmod;
   a1:=(ksm[0,1,p^.x]*a0+ksm[1,1,p^.x]*a1) mod modmod;
   a0:=xx;
   l:=p^.r+1;
   exit;
  end;
 gx(p);
 tian(p^.lc);
 tian(p^.rc);
 p^.data:=(p^.lc^.data+p^.rc^.data) mod modmod;
end;
function cha(p:tree):longint;
var xx:longint;
begin
 if p^.r<l then exit(0);
 if p^.l>r then exit(0);
 if (l=p^.l)and(p^.r<=r) then
  begin
   l:=p^.r+1;
   exit(p^.data);
  end;
 gx(p);
 exit((cha(p^.lc)+cha(p^.rc))mod modmod);
end;
begin
 init('fibnacci');
 read(n,m);
 for i:=1 to n do
  read(a[i]);
 x:=trunc(ln(n)/ln(2)-0.00000001)+1;
 n:=1 shl x;
 ksm[0,0,0]:=0;
 ksm[0,1,0]:=1;
 ksm[1,0,0]:=1;
 ksm[1,1,0]:=1;
 ksm[0,2,0]:=0;
 ksm[1,2,0]:=1;
 ksm[2,2,0]:=1;
 ksm[2,0,0]:=0;
 ksm[2,1,0]:=0;
 for i:=1 to x do
  for j:=0 to 2 do
   for k:=0 to 2 do
    for l:=0 to 2 do
     ksm[j,l,i]:=(ksm[j,l,i]+ksm[j,k,i-1]*ksm[k,l,i-1]) mod modmod;
 head:=build(1,n,x);
 for i:=1 to m do
  begin
   read(op,l,r);
   if op=1 then
    begin
     a0:=0;
     a1:=1;
     tian(head);
    end else
   writeln(cha(head));
  end;
 clo;
end.
