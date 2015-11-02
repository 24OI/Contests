var a :array[1..120000] of longint;
n,m,i,j,x,y,t,tot :longint;
begin
	assign(input,'lyk.in');
	assign(output,'lyk.out');
	reset(input);
	rewrite(output);
	read(n);
	for i := 1 to n do read(a[i]);
	read(m);
	for i := 1 to m do begin
		read(x,y);
		t := a[x];
		a[x] := a[y];
		a[y] := t;
	end;
	tot := 0;
	for i := 1 to n-1 do
	for j := i+1 to n do
		if a[j] < a[i] then inc(tot);
	writeln(tot mod 2);
	close(input);
	close(output);
end.
