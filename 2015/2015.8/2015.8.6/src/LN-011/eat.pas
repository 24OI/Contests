var
t:array[1..10000] of longint;
i,ans,n:longint;
begin
assign(input,'eat.in');reset(input);
assign(output,'eat.out');rewrite(output);
	ans:=0;
	fillchar(t,sizeof(t),0);
	readln(n);
	for i:=1 to n do readln(t[i]);                                
	for i:=2 to n-1 do 
	if (t[i]<t[i-1])and (t[i]<t[i+1])then inc(ans);
		writeln(ans);
close(input);close(output);
	end.
	