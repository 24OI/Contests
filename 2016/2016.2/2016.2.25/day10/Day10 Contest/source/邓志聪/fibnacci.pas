const
	mo=1000000001;
var
	a,f:array[0..100000] of Longint;
	k,i,l,r,opt,n,m:Longint;
function add(a,b:Longint):Longint;
begin
	a:=a+b;
	if a>mo then dec(a,mo);
	exit(a);
end;

begin
  assign(input,'fibnacci.in'); reset(input);
  assign(output,'fibnacci.out'); rewrite(output);
	f[0]:=0; f[1]:=1;
	readln(n,m);
  	for i:=2 to n+1 do
		f[i]:=add(f[i-1],f[i-2]);
	for i:=1 to n do
		read(a[i]);
	while m<>0 do
		begin
			readln(opt,l,r);
			case opt of
				1:begin
						k:=1;
						for i:=l to r do
							begin a[i]:=add(a[i],f[k]); inc(k); end;
					end;
				2:begin
						k:=0;
						for i:=l to r do
							k:=add(k,a[i]);
						writeln(k);
					end;
			end;
			dec(m);
		end;
  close(input); close(output);
end.
