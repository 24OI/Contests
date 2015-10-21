var tot,a,b,k,n,i :longint;
	d :array[1..2000] of longint;

procedure dfs(x,y :longint);
var h,i :longint;
begin
	if y=k then begin
		tot := tot + 1;
		exit;
	end;
	h := abs(b-x);
	for i := x-(h-1) to x+(h-1) do
	begin
		if (i>=1) and (i<=n) and (i<>x) then
			if (y+1=k) then begin
				d[y+1] := i;
				dfs(i,y+1);
				d[y+1] := 0;
			end
			else if (abs(b-i)<>1) then begin
				d[y+1] := i;
				dfs(i,y+1);
				d[y+1] := 0;
			end;
	end;
end;

begin
	assign(input,'jump.in');
	assign(output,'jump.out');
	reset(input);
	rewrite(output);
	read(n,a,b,k);
	dfs(a,0);
	writeln(tot);
	close(input);
	close(output);
end.
