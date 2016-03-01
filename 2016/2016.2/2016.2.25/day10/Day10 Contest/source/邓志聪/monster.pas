const
	mo=593119681;
var
	i,n,m,j,k,p:Longint;
	bin:array[0..20] of Longint;
	a,c:array[0..1024] of int64;
	f,t:array[0..1024,0..1024] of int64;
procedure pow(k:Longint);
var
	i,j,p:Longint;
begin
	while k<>0 do
		begin
			if k and 1<>0 then
				begin
					fillchar(c,sizeof(c),0);
					for i:=0 to n do if a[i]<>0 then
						for j:=0 to n do if f[i,j]<>0 then
							c[j]:=(c[j]+a[i]*f[i,j]) mod mo;
					a:=c;
				end;
			fillchar(t,sizeof(t),0);
			for i:=0 to n do
				for p:=0 to n do if f[i,p]<>0 then
					for j:=0 to n do if f[p,j]<>0 then
						t[i,j]:=(t[i,j]+f[i,p]*f[p,j]) mod mo;
			f:=t;
			k:=k shr 1;
		end;
end;

begin
  assign(input,'monster.in'); reset(input);
  assign(output,'monster.out'); rewrite(output);
	bin[0]:=1; for i:=1 to 20 do bin[i]:=bin[i-1] shl 1;
	readln(n,m);
	n:=bin[n]-1;
	for i:=0 to n-1 do
		for j:=i+1 to n do
			begin
				p:=i xor j;
				for k:=0 to 10 do
			 		if bin[k]=p then
						begin f[i,j]:=1; f[j,i]:=1; break; end;
			end;
  for i:=0 to n do f[i,i]:=1;
	for i:=0 to n do
		read(a[i]);
	pow(m);
	for i:=0 to n do
		write(a[i],' ');
	writeln;
  close(input); close(output);
end.
