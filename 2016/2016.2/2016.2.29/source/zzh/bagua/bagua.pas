var head,next,toward,ind,oud:array[1..600]of longint;
startpoint,pipei:array[1..600]of longint;
vis:array[1..600]of boolean;
sumedge:longint;
k:longint;
ans:longint;
n,m,p:longint;


procedure add(s,t:longint);
begin
inc(sumedge);
next[sumedge]:=head[s];
head[s]:=sumedge;
toward[sumedge]:=t;
inc(ind[t]);
inc(oud[s]);
end;

procedure init;
var i,t1,t2:longint;
begin
for i:=1 to m do begin
	read(t1,t2);
	add(t1,t2);
	end;
end;


procedure gaoyixia;
var i:longint;
begin
for i:=1 to n do if ind[i]=0 then begin
	inc(k);
	startpoint[k]:=i;
	end;
end;

procedure gao;
var i,j,temp:longint;
begin
temp:=0;
for i:=1 to k do for j:=i+1 to k do if pipei[i]>pipei[j] then inc(temp);
if temp and 1 = 1 then dec(ans) else inc(ans);
end;

procedure dfs(nowpoint,u:longint);
var now,v:longint;
begin
vis[u]:=true;
if oud[u]=0 then begin
	pipei[nowpoint]:=u;
	if nowpoint=k then gao else begin
		dfs(nowpoint+1,startpoint[nowpoint+1]);
		vis[startpoint[nowpoint+1]]:=false;
		end;
	exit;
	end;
now:=head[u];
while now<>0 do begin
	v:=toward[now];
	if not vis[v] then begin
		dfs(nowpoint,v);
		vis[v]:=false;
		end;
	now:=next[now];
	end;
end;

begin
assign(input,'bagua.in');
assign(output,'bagua.out');
reset(input);
rewrite(output);
read(n,m,p);
init;
gaoyixia;
dfs(1,startpoint[1]);
if ans<0 then writeln(ans mod p + p) else writeln(ans mod p);
close(input);
close(output);
end.
