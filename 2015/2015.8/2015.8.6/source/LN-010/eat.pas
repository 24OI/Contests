
var a:array[1..10000] of longint;
	c:array[1..10000] of boolean;
	bobo,panduan:boolean;
	i,n,ans,x,q:longint;

begin
assign(input,'eat.in');
reset(input);
assign(output,'eat.out');
rewrite(output);
panduan:=true;
readln(n);
q:=n;
for i := 1 to n do 
	begin
	readln(a[i]);

	if (i<>1) and (a[i]<a[i-1]) then panduan:=false;
	end;
if panduan=true then begin write(0);halt; end;


repeat
bobo:=true;
for i:= n downto 2 do 
	begin
	x:=i-1;
	while (c[x]) and (c[i]=false) and (x<>1) do dec(x);
	if (c[i]=false) and (a[i]<a[x]) then begin c[i]:=true;dec(q);end; 
	end;
inc(ans);
if q=1 then begin write(ans); halt; end;
for i:= 1 to n-1 do 
	begin
	x:=i+1;
	while (c[x]) and (x<>n) do inc(x);
	if (c[i]=false) and (a[i]>a[x]) then bobo:=false;
	end;
until bobo	;
write(ans);
close(input);close(output);
end.