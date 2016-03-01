var 
s:array[1..13]of ansistring=('0','1',
'01',
'101',
'01101',
'10101101',
'0110110101101',
'101011010110110101101',
'0110110101101101011010110110101101',
'1010110101101101011010110110101101101011010110110101101',
'01101101011011010110101101101011011010110101101101011010110110101101101011010110110101101',
'101011010110110101101011011010110110101101011011010110101101101011011010110101101101011011010110101101101011010110110101101101011010110110101101',
'01101101011011010110101101101011011010110101101101011010110110101101101011010110110101101101011010110110101101011011010110110101101011011010110101101101011011010110101101101011011010110101101101011010110110101101101011010110110101101');
s1:array[1..21]of ansistring;
dp:array[1..21]of longint;
n,m,i,j,k,p,ans:longint;
t,a,b:ansistring;
next:array[1..10001]of longint;

begin
assign(input,'bugs.in');
assign(output,'bugs.out');
reset(input);
rewrite(output);

	readln(n,m,p);
	read(t);
//看毛片
	
	b:=t;
	for i:=1 to 13 do
		s1[i]:=s[i];
	for i:=14 to n do
		s1[i]:=s[i-2]+s1[i-1];
		
	begin
		a:=s1[n];
		n:=length(a);
		m:=length(b);
//		if m>n then continue;
		ans:=0;
		j:=0;
		for i:=2 to n do
			begin
			while (a[j+1]<>a[i]) and (j<>0) do j:=next[i];
			if a[j+1]=a[i] then inc(j);
			next[j]:=i;
			end;
		
		j:=0;
		for i:=1 to n do
		begin
		   while (j>0) and (B[j+1]<>A[i]) do j:=next[j];
		   if B[j+1]=A[i] then j:=j+1;
		   if j=m then
		   begin
			  inc(ans);
			  j:=next[j];
		   end;
		end;
	end;
//	dp[n]:=dp[n] mod p;
	write(ans mod p);
//

close(input);
close(output);
end.