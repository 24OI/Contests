type node = record
	l,r,u,d,max:longint;
	end;
var tree:array[1..15000000]of node;
a:array[1..3000,1..3000]of longint;
dist:array[1..3000]of longint;

head,next,dat,toward:array[1..10000]of longint;
sumedge:longint;

n,m:longint;
t1,t2,t3,t4:longint;
i,j:longint;

function max(a,b:longint):longint;
begin
if a<b then exit(b) else exit(a);
end;
function max(a,b,c,d:longint):longint;
begin
max:=max(a,b);
max:=max(max,c);
max:=max(max,d);
end;

procedure add(s,t,w:longint);
begin
inc(sumedge);
next[sumedge]:=head[s];
head[s]:=sumedge;
toward[sumedge]:=t;
dat[sumedge]:=w;
end;

procedure add0(s,t,w:longint);
begin
add(s,t,w);
add(t,s,w);
end;


procedure maketree(l,r,u,d,now:longint);

begin

tree[now].l:=l;
tree[now].r:=r;
tree[now].u:=u;
tree[now].d:=d;
if (l=r) and (u=d) then begin
	tree[now].max:=a[l,u];
	exit;
	end
else if (l>r) or (u>d) then begin
	tree[now].max:=0;
	exit;
	end
else begin
	maketree(l,(l+r)>>1,u,(u+d)>>1,now<<2-2);
	maketree((l+r)>>1+1,r,u,(u+d)>>1,now<<2-1);
	maketree(l,(l+r)>>1,(u+d)>>1+1,d,now<<2);
	maketree((l+r)>>1+1,r,(u+d)>>1+1,d,now<<2+1);
	tree[now].max:=max(tree[now<<2-2].max,tree[now<<2-1].max,tree[now<<2].max,tree[now<<2+1].max);
	end;
end;

function ask(l,r,u,d,now:longint):longint;
var t1,t2,t3,t4:longint;
begin
if (tree[now].l=l) and (tree[now].r=r) and (tree[now].u=u) and (tree[now].d=d) then exit(tree[now].max)
else if r<=tree[now<<2-2].r then begin
	if d<=tree[now<<2-2].d then exit(ask(l,r,u,d,now<<2-2))
	else if u>=tree[now<<2].u then exit(ask(l,r,u,d,now<<2))
	else begin
		t1:=ask(l,r,u,tree[now<<2-2].d,now<<2-2);
		t2:=ask(l,r,tree[now<<2].u,d,now<<2);
		exit(max(t1,t2));
		end;
	end
else if l>=tree[now<<2-1].l then begin
	if d<=tree[now<<2-1].d then exit(ask(l,r,u,d,now<<2-1))
	else if u>=tree[now<<2+1].u then exit(ask(l,r,u,d,now<<2+1))
	else begin
		t1:=ask(l,r,u,tree[now<<2-1].d,now<<2-1);
		t2:=ask(l,r,tree[now<<2+1].u,d,now<<2+1);
		exit(max(t1,t2));
		end;
	end
else begin
	if d<=tree[now<<2-2].d then begin
		t1:=ask(l,tree[now<<2-2].r,u,d,now<<2-2);
		t2:=ask(tree[now<<2-1].l,r,u,d,now<<2-1);
		exit(max(t1,t2));
		end

	else if u>=tree[now<<2].u then begin
		t1:=ask(l,tree[now<<2].r,u,d,now<<2);
		t2:=ask(tree[now<<2+1].l,r,u,d,now<<2+1);
		exit(max(t1,t2));
		end

	else begin
		t1:=ask(l,tree[now<<2-2].r,u,tree[now<<2-2].d,now<<2-2);
		t2:=ask(tree[now<<2-1].l,r,u,tree[now<<2-1].d,now<<2-1);
		t3:=ask(l,tree[now<<2].r,tree[now<<2].u,d,now<<2);
		t4:=ask(tree[now<<2+1].l,r,tree[now<<2+1].u,d,now<<2+1);
		exit(max(t1,t2,t3,t4));
		end;
	end;
end;


procedure xia(var a:longint);
begin
inc(a);
if a>10000 then a:=a mod 10000;
end;

function plus(a:longint):longint;
begin
plus:=a+1;
if plus>10000 then plus:=plus mod 10000;
end;

procedure spfa(s:longint);
var now,t,p,top,tail:longint;
q:array[1..10000]of longint;
v:array[1..10000]of boolean;
begin
filldword(dist,sizeof(dist)>>2,1000000000);
fillchar(v,sizeof(v),false);
dist[s]:=0;
top:=1;tail:=1;
q[top]:=s;v[s]:=true;
while top<>plus(tail) do begin
	p:=q[top];
	xia(top);
	now:=head[p];
	while now<>0 do begin
		t:=toward[now];
		if dist[p]+dat[now]<dist[t] then begin
			dist[t]:=dist[p]+dat[now];
			if not v[t] then begin
				xia(tail);
				q[tail]:=t;
				v[t]:=true;
				end;
			end;
		now:=next[now];
		end;
	v[p]:=false;
	end;
end;

begin
assign(input,'tree.in');
assign(output,'tree.out');
reset(input);
rewrite(output);
read(n);
for i:=1 to n-1 do begin
	read(t1,t2,t3);
	add0(t1,t2,t3);
	end;
for i:=1 to n do begin
	spfa(i);
	for j:=1 to n do a[i,j]:=dist[j];
	end;
maketree(1,n,1,n,1);

read(m);
for i:=1 to m do begin
	read(t1,t2,t3,t4);
	writeln(ask(t1,t2,t3,t4,1));
	end;
close(input);
close(output);
end.
