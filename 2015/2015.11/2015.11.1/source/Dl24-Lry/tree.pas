type wxz=record
	t:longint;
	lucheng:longint;
	end;
type lry=record
	vv:longint;
	tt:longint;
	next:longint;
	end;
var e:array[1..3000,1..3000] of longint;
list:array[1..4000,1..4000] of wxz;
edge:array[1..6000] of lry;
head:array[1..3000] of longint;
cc:array[1..3000] of boolean;
sumedge,n,x,y,z,m,tou,tail,i,a,b,c,d,j,max,now,k:longint;
{function jiancha:boolean;
	var k:longint;
	begin
	for k:= 1 to tail do 
		if 	list[i,k].t=edge[now].tt then exit(false);
		exit(true);
	end;}
procedure rd(x,y,z:longint);
	begin
	inc(sumedge);
	edge[sumedge].vv:=z;
	edge[sumedge].tt:=y;
    edge[sumedge].next:=head[x];
    head[x]:=sumedge;
	end;
begin
		assign(input,'tree.in');
	assign(output,'tree.out');
	reset(input);rewrite(output);
readln(n);
for i:= 1 to n-1 do
	begin
	readln(x,y,z);
	e[x,y]:=z;
	e[y,x]:=z;
	rd(x,y,z);
	rd(y,x,z);
	end;
read(m);
for i:= 1 to n do 
	begin
	tou:=0;
	tail:=1;
	list[i,1].t:=i;
	cc[i]:=true;
	fillchar(cc,sizeof(cc),false);
	repeat
	inc(tou);
	if tou>tail then break;
	now:=head[list[i,tou].t];
		repeat
		if cc[edge[now].tt]=false then 
			begin 
			inc(tail);
			list[i,tail].t:=edge[now].tt;
			list[i,tail].lucheng:=list[i,tou].lucheng+edge[now].vv;
			e[i,edge[now].tt]:=list[i,tail].lucheng;
			e[edge[now].tt,i]:=list[i,tail].lucheng;
			cc[edge[now].tt]:=true;
			end;
		now:=edge[now].next;
		until now=0;
	until tou>tail;
	end;


for i:= 1 to m do 
	begin
	max:=0;
	readln(a,b,c,d);
	for j:= a to b do 
		for k:=c to d do 
		if e[j,k]>max then max:=e[j,k];
	writeln(max);
	end;
close(input);close(output);

end.