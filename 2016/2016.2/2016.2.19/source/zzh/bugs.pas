type matrix = record
	n,m:longint;
	d:array[1..4,1..4]of int64;
	end;

var n,m,p:longint;
b:array[0..22]of ansistring;
len,s:array[0..22]of longint;
t:ansistring;
i,t1,ans:longint;
rl,lf,rf:ansistring;
rlrf,rllf:longint;
start,base:matrix;



operator * (const a,b:matrix)c:matrix;
var i,j,k:longint;
begin
fillchar(c.d,sizeof(c.d),0);
c.n:=a.n;c.m:=b.m;
for i:=1 to a.n do for j:=1 to b.m do for k:=1 to a.m do begin
	c.d[i,j]:=(c.d[i,j]+a.d[i,k]*b.d[k,j] mod p) mod p;
	end;
end;

function get(var a:ansistring):longint;
var i,t1:longint;
begin
t1:=length(t);
get:=0;
for i:=1 to length(a)-t1+1 do if t=copy(a,i,t1) then inc(get);
end;

function power(a:matrix;p:longint):matrix;
begin
if p=1 then exit(a)
else begin
	power:=power(a,p>>1);
	power:=power*power;
	if p and 1 = 1 then power:=power*a;
	end;
end;

procedure hehe;
begin
close(input);
close(output);
halt;
end;

begin
assign(input,'bugs.in');
assign(output,'bugs.out');
reset(input);
rewrite(output);
readln(n,m,p);
readln(t);
if n<=20 then begin
	b[0]:='1';b[1]:='01';
	for i:=2 to n-1 do b[i]:=b[i-2]+b[i-1];
	//for i:=0 to n-1 do writeln(b[i]);
	t1:=length(t);
	ans:=0;
	for i:=1 to length(b[n-1])-t1+1 do if t=copy(b[n-1],i,t1) then inc(ans);
	writeln(ans);
	hehe;
	end
else begin
	len[0]:=1;len[1]:=2;
	b[0]:='1';b[1]:='01';
	for i:=2 to 22 do begin
		len[i]:=len[i-2]+len[i-1];
		b[i]:=b[i-2]+b[i-1];
		end;
	rf:=copy(b[22],1,m-1);
	lf:=copy(b[21],1,m-1);
	rl:=copy(b[22],len[22]-(m-1)+1,m-1);
	rf:=rl+rf;
	lf:=rl+lf;
	rlrf:=get(rf);
	rllf:=get(lf);
	with base do begin
		n:=4;m:=4;
		d[1,1]:=2;d[1,2]:=1;d[1,3]:=0;d[1,4]:=rllf+rlrf;
		d[2,1]:=1;d[2,2]:=1;d[2,3]:=0;d[2,4]:=rlrf;
		d[3,1]:=1;d[3,2]:=0;d[3,3]:=0;d[3,4]:=0;
		d[4,1]:=0;d[4,2]:=0;d[4,3]:=0;d[4,4]:=1;
		end;
	with start do begin
		n:=4;m:=1;
		d[1,1]:=get(b[22]);
		d[2,1]:=get(b[21]);
		d[3,1]:=get(b[20]);
		d[4,1]:=1;
		end;
	start:=start*power(base,(n-21)>>1);
	if n and 1 = 1 then writeln(start.d[3,1] mod p) else writeln(start.d[2,1] mod p);
	hehe;
	end;
hehe;
end.
