var n,m,p,i,j,ans,k:longint;
	s,s1,s2,s3:ansistring;
begin
	assign(input,'bugs.in');
	assign(output,'bugs.out');
	reset(input);rewrite(output);
readln(n,m,p);
s1:='0';
s2:='1';
for i:= 1 to n-1 do 
	begin
	s3:=s1;
	s1:=s2;
	s2:=s3+s2;
	end;
readln(s);
for i:= 1 to length(s2) do 
	for j:= 1 to m do 
		begin
		k:=i-1+j;
		if s2[k]<>s[j] then break
				else if j=m then begin  inc(ans) ;ans:=ans mod p;end;
		end;
writeln(ans);
close(input);close(output);
end.