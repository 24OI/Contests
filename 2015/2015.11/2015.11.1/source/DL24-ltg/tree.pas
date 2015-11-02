var dist :array[1..3000, 1..3000] of longint;
n,m,i,j,k,x,y,a,b,c,d,max :longint;
begin
	assign(input,'tree.in');
	assign(output,'tree.out');
	reset(input);
	rewrite(output);
	for i := 1 to 3000 do
	for j := 1 to 3000 do
		dist[i,j] := 10000000;
	for i := 1 to 3000 do
		dist[i,i] := 0;
	read(n);
	for i := 1 to n-1 do
	begin	
		read(x,y,dist[x,y]);
		dist[y,x] := dist[x,y];
	end;
	for k := 1 to n do
		for i := 1 to n do
			for j := 1 to n do
				if dist[i,k] + dist[k,j] < dist[i,j] then begin
					dist[i,j] := dist[i,k] + dist[k,j];
					dist[j,i] := dist[i,j];
				end;
	read(m);
	for i := 1 to m do
	begin
		read(a,b,c,d);
		max := -maxlongint;
		for j := a to b do
		for k := c to d do
			if dist[j,k] > max then max := dist[j,k];
		writeln(max);
	end;
	close(input);
	close(output);
end.