var n,m,k,l,j,i,ans:longint;
a,b,c,d:array[1..100000] of longint;
begin
	assign(input,'lky.in');reset(input);
	assign(output,'lky.out');rewrite(output);
	readln(n);
	for i:=1 to n do 
	read(a[i]);
	readln;
	readln(m);
	for i:=1 to m do 
	readln(b[i],c[i]);
	ans:=0;
	for i:=1 to m do 
	begin
		k:=a[b[i]];
		a[b[i]]:=a[c[i]];
		a[c[i]]:=k;
		for j:=1 to n do 
		begin
			for l:=1 to n do 
			begin
				if (l<j) and (a[l]>a[j]) then ans:=ans+1;
			end;
		end;
		writeln(ans mod 2);
		ans:=0;
	end;
	close(input);
	close(output);
end.