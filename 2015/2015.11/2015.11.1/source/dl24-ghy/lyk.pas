var
	n,m,i,j,p,ans: Longint;
	a,b:array[1..1000005] of Longint;
procedure m2(w,x,y,z:Longint);
	var
		l,r,t,k: Longint;
	begin
		l:=w;
		r:=y;
		t:=1;
		repeat
			if a[l]<=a[r] then 
				begin
					b[t]:=a[l];
					inc(l);
				end
			else 
				begin
					b[t]:=a[r];
					inc(r);
					inc(ans);
				end;
			inc(t);
		until (l>x) or (r>z);
		if l>x then 
			begin
				for k:=r to z do 
					begin
						b[t]:=a[k];
						inc(T); 	
					end; 
			end;
		if r>z then 
			begin
				for k:=l to x do
					begin
						b[t]:=a[k];
						inc(t);
					end;
			end;
		t:=1;
		for k:=w to z Do 
			begin
				a[k]:=b[t];
				inc(t);
			end; 
	end;
procedure m1(x,y:Longint);
	begin
		if x=y then exit;
		m1(x,(x+y) div 2);
		m1((x+y) div 2+1,y);
		m2(x,(x+y) div 2,(x+y)div 2+1,y);
	end;
begin
	assign(input,'lyk.in');
	assign(output,'lyk.out');
	reset(input);
	rewrite(output);
	read(n);
	for i:=1 to n do read(a[i]);
	read(m);
	for i:=1 to m do 
		begin
			read(j,p);
			a[j]:=a[j] xor a[p];
			a[p]:=a[j] xor a[p];
			a[j]:=a[p] xor a[j];
			ans:=0;
			m1(1,n);
			write(ans mod 2);
		end;
	ans:=0;
	m1(1,n);
	write(ans mod 2);
	close(input);
	close(output);
end.