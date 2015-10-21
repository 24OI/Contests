var l,r,a,b,x:longint;
	i,t:text;
begin
	assign(i,'factor.in');
	assign(t,'factor.out');
	reset(i);
	read(i,l,r);
	close(i);
	rewrite(t);
	repeat
		if (l mod 2)=0 then a:=2
			else begin
					b:=trunc(sqrt(l));
					x:=3;
					while ((l mod x)>0) and  (x<b) do inc(x);
					if (l mod x)=0 then a:=x
						else a:=l;	
				 end;
		writelnt,a);
		inc(l);
	until l>r;
	close(t);
end.