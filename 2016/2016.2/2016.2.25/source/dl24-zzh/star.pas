type point = record
	x1,y1,x2,y2:int64;
	end;
	xian=record
	a,b,c:int64;
	end;
var n:longint;
x:array[1..2000]of xian;
p:array[1..2000000]of point;
i,j,tot,now:longint;
max,count:longint;

procedure init;
var i:longint;
begin
read(n);
for i:=1 to n do read(x[i].a,x[i].b,x[i].c);
end;

function gcd(a,b:longint):longint;
begin
if b=0 then exit(a) else exit(gcd(b,a mod b));
end;


procedure yue(var a:point);
var t:longint;
begin
with a do begin
	if x2<0 then begin
		x1:=-x1;x2:=-x2;
		end;
	if y2<0 then begin
		y1:=-y1;y2:=-y2;
		end;

	if x1>0 then begin
		t:=gcd(x1,x2);
		x1:=x1 div t;x2:=x2 div t;
		end
	else if x1=0 then x2:=0
	else begin
		t:=gcd(-x1,x2);
		x1:=x1 div t;x2:=x2 div t;
		end;
	if y1>0 then begin
		t:=gcd(y1,y2);
		y1:=y1 div t;y2:=y2 div t;
		end
	else if y1=0 then y2:=0
	else begin
		t:=gcd(-y1,y2);
		y1:=y1 div t;y2:=y2 div t;
		end;
	end;
end;




procedure calc(mm,nn:xian);
begin
if mm.a*nn.b=mm.b*nn.a then exit;
inc(tot);
p[tot].x1:=mm.b*nn.c-nn.b*mm.c;
p[tot].x2:=mm.a*nn.b-nn.a*mm.b;
p[tot].y1:=nn.a*mm.c-mm.a*nn.c;
p[tot].y2:=p[tot].x2;
yue(p[tot]);
end;

operator <(const a,b:point)c:boolean;
begin
if a.x1<b.x1 then exit(true);
if a.x1>b.x1 then exit(false);
if a.x2<b.x2 then exit(true);
if a.x2>b.x2 then exit(false);
if a.y1<b.y1 then exit(true);
if a.y1>b.y1 then exit(false);
if a.y2<b.y2 then exit(true);
if a.y2>b.y2 then exit(false);
exit(false);
end;

operator =(const a,b:point)c:boolean;
begin
exit((a.x1=b.x1) and (a.x2=b.x2) and (a.y1=b.y1) and (a.y2=b.y2));
end;

procedure sort(l,r: longint);
var
	i,j: longint;x,y:point;
begin
	i:=l;
	j:=r;
	x:=p[(l+r) div 2];
	repeat
	while p[i]<x do
		inc(i);
	while x<p[j] do
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
assign(input,'star.in');
assign(output,'star.out');
reset(input);
rewrite(output);
init;
for i:=1 to n do for j:=i+1 to n do calc(x[i],x[j]);
sort(1,tot);
now:=1;
max:=1;
count:=0;
for i:=2 to tot do begin
	if p[i]=p[i-1] then inc(now)
	else begin
		if now>max then begin
			max:=now;
			count:=1;
			end
		else if now=max then inc(count);
		now:=1;
		end;
	end;
if now>max then begin
	max:=now;
	count:=1;
	end
else if now=max then inc(count);
writeln(round((sqrt(max*8+1)+1)/2),' ',count);
close(input);
close(output);
end.
