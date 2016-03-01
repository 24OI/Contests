type point=record
      x,y:double;
     end;
var a,b,c:array[1..1000]of longint;
    p:array[1..1000000]of point;
    i,j,maxs,n,num,s,pp:longint;
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
function cha(i,j:longint):point;
var x:point;
begin
 x.y:=(c[j]*a[i]-c[i]*a[j])/(b[i]*a[j]-b[j]*a[i]);
 x.x:=(c[j]*b[i]-c[i]*b[j])/(a[i]*b[j]-a[j]*b[i]);
 exit(x);
end;
function xiao(a,b:point):boolean;
begin
 if a.x>b.x+0.00000001 then exit(false);
 if a.x<b.x-0.00000001 then exit(true);
 if a.y>b.y+0.00000001 then exit(false);
 if a.y<b.y-0.00000001 then exit(true);
 exit(false);
end;
function deng(a,b:point):boolean;
begin
 if a.x>b.x+0.00000001 then exit(false);
 if a.x<b.x-0.00000001 then exit(false);
 if a.y>b.y+0.00000001 then exit(false);
 if a.y<b.y-0.00000001 then exit(false);
 exit(true);
end;
    procedure sort(l,r: longint);
      var
         i,j: longint;
         x,y:point;
      begin
         i:=l;
         j:=r;
         x:=p[(l+r) div 2];
         repeat
           while xiao(p[i],x) do
            inc(i);
           while xiao(x,p[j]) do
            dec(j);
           if not(i>j) then
             begin
                y:=p[i];
                p[i]:=p[j];
                p[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
 init('star');
 read(n);
 for i:=1 to n do
  read(a[i],b[i],c[i]);
 pp:=0;
 for i:=1 to n do
  for j:=1 to n do
   if a[i]*b[j]<>a[j]*b[i] then
    begin
     inc(pp);
     p[pp]:=cha(i,j);
    end;
 sort(1,pp);
 p[pp+1].x:=-1E100;
 p[pp+1].y:=-1E100;
 s:=1;
 maxs:=0;
 for i:=1 to pp do
  if deng(p[i],p[i+1]) then inc(s)
   else
    begin
     if s>maxs then
      begin
       maxs:=s;
       num:=1;
      end else
      if s=maxs then inc(num);
     s:=1;
    end;
 maxs:=trunc(sqrt(maxs))+1;
 writeln(maxs,' ',num);
 clo;
end.
