var n,d,i,j,k,ans,tt:longint;
var s:array[1..50001]of string;

begin
assign(input,'idioms.in');
assign(output,'idioms.out');
reset(input);
rewrite(output);

	read(n);
	readln(d);
	for i:=1 to n do
		readln(s[i]);

	tt:=0;
	for i:=1 to n do
		begin
		for j:=i+1 to n do
			begin
			ans:=0;
			for k:=1 to 4 do
				if s[i][k]<>s[j][k] then inc(ans);
			if ans=d then inc(tt); 
			end; 
		end;
	write(tt);
		
close(input);
close(output);
end.
