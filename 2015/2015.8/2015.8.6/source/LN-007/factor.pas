var l,r,i,j,k,m,n:longint;
	a:array[1..9999999] of longint;

begin
	assign(input,'factor.in');reset(input);
	assign(output,'factor.out');rewrite(output);
	readln(l);
	readln(r);
	for i:=l to r do 
	begin
			for j:=2 to i do 
			begin
				if i mod j = 0 then 
				begin
					if j=2 then 
					begin
					a[i]:=j;
					break;
					end
				else 
					begin
						k:=2;
						for n:=2 to j-1 do
						begin
							if j mod n=0 then break
							else k:=k+1;
						end;
						if k=j then a[i]:=j;
					end;
				end;
	end;
	end;
	for i:=l to r do 
	writeln(a[i]);
	close(input);
	close(output);
end.