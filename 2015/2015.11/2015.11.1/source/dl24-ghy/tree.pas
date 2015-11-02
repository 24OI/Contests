type lian=record
	too: longint;
	next:longint;
end;
var
	n,i,j,t,m,x,y,z,p,v:Longint;
	a:array[0..1005] of lian;
	b:array[0..505] of longint;
	c:array[0..505,0..505] of longint;
	d:array[0..505] of longint;
	e:array[0..505] of longint;
	f:array[0..505] of boolean;
procedure spfa(w:longint);
	var
		k,l,r,h:longint;
	begin
		d[1]:=w;
		l:=1;
		r:=2;
		repeat
		h:=b[d[l]];
		writeln;
		writeln(d[l]);
		writeln;
		write(a[h].too,' ');
			while (h>0) and (a[h].too<>e[d[l]]) do 
			begin
				d[r]:=a[h].too;
				inc(r);
				e[a[h].too]:=d[l];
				k:=c[w,d[l]]+c[d[l],a[h].too];
				if k>c[w,a[h].too] then c[w,a[h].too]:=k;
				h:=a[h].next;
				write(a[h].too,' ');
			end;
		inc(l);	
		until l=r;
		for l:=1 to n do c[l,w]:=c[w,l];
		f[w]:=true;
	end;
begin
	read(n);
	t:=1;
	fillchar(b,sizeof(b),0);
	fillchar(c,sizeof(c),0);
	fillchar(f,sizeof(f),false);
	fillchar(e,sizeof(e),0);
	for i:=1 to n-1 do 
		begin
			read(x,y,z);
			a[t].too:=y;
			a[t].next:=b[x];
			b[x]:=t;
			inc(T);
			a[t].too:=x;
			a[t].next:=b[y];
			b[y]:=t;
			inc(t);
			c[x,y]:=z;
			c[y,x]:=z;
			c[i,i]:=0;
		end; 
	c[n,n]:=0;
	read(m);
	t:=0;
	for i:=1 to m do
		begin
			read(x,y,z,v);
			for j:=x to y do 
				begin
					if not f[j] then spfa(j);
					for p:=z to v do
							if c[j,p]>t then t:=c[j,p];					 	
				end;
		end; 
	for i:=1 to n Do
		begin
		for j:=1 to n do write(c[i,j],' '); 
		writeln;
		end;
	write(t);
end.