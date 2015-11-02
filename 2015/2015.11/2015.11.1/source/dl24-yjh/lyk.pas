program dy1;
Type arr=array[1..100001]of longint;
var i,j,n,m,x1,y1:longint;
var k:int64;
var a,b,c:arr;
	
	Procedure merge(var a:arr;l,x,r:longint);
		var i,j,p:longint;//p:position
		begin
		i:=l;
		j:=x+1;
		p:=l;
		while (p<=r) do begin
		if (i<=x) and ((j>r) or (a[i]<=a[j])) then begin
			b[p]:=a[i];
			inc(i);
			end
	   else begin
			b[p]:=a[j];
			inc(j);
			inc(k,x-i+1);
			end;
			inc(p);
			end;
		for i:=l to r do a[i]:=b[i];
		end;
	 
	Procedure msort(var a:arr;l,r:longint);
		var x:longint;
		begin
		if (l<>r) then begin
		x:=(l+r) div 2;
		msort(a,l,x);
		msort(a,x+1,r);
		merge(a,l,x,r);
		end;
	 end;

begin
assign(input,'lyk.in');
assign(output,'lyk.out');
reset(input);
rewrite(output);

	readln(n);
	for i:=1 to n do
		read(c[i]);
	readln;
	readln(m);
	for i:=1 to m do
		begin
		k:=0;
		readln(x1,y1);
		c[x1]:=c[x1] xor c[y1];
		c[y1]:=c[x1] xor c[y1];
		c[x1]:=c[x1] xor c[y1];
		for j:=1 to n do
			a[j]:=c[j];
		msort(a,1,n);
		writeln(k mod 2);
		end;

close(input);
close(output);
end.