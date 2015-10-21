var fish:array[1..100000] of integer;
	a,n,num,b:integer;
	finish:boolean;
	f1,f2:text;
begin
	assign(f1,'eat.in');
	assign(f2,'eat.out');
	reset(f1);
	readln(f1,n);
	for a:=1 to n do readln(f1,fish[a]);
	close(f1);
	num:=0;
	repeat
		finish:=true;
		a:=n;
		while a>1 do
		begin
			while (fish[a]=0) and (a>2) do dec(a);
			if fish[a]>0 then b:=a-1
				else break;
			while fish[b]=0 do dec(b);
			if fish[a]<fish[b] then 
				begin
					fish[a]:=0;
					finish:=false;
				end;
			dec(a);
		end;
		if finish=false then inc(num);
	until finish;
	rewrite(f2);
	write(f2,num);
	close(f2);
end.