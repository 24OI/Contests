var n,m,k,l,j,i:longint;
	a:array [1..9999999] of longint;
procedure	chinm(x:longint);
begin
	l:=0;
	for i:=x downto 1 do 
	begin
		if a[i]<a[i-1] then a[i]:=0
	end;
	k:=1;
	for i:=1 to n do 
	begin
		if a[i]<>0 then 
		begin
			a[k]:=a[i];
			k:=k+1;
		end;
	end;
	l:=l+1;
		for i:=1 to k do 
		begin
		if a[k]>a[k+1] 
		then begin 
				chinm(k);
				l:=l+1;
				break;
			end;
	end;
end;
begin
assign(input,'eat.in');reset(input);
	assign(output,'eat.out');rewrite(output);
	read(n);
	for i:=1 to n do 
	readln(a[i]);
	chinm(n);
	writeln(l);
	close(input);
	close(output);
end.