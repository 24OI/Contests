var a:array[1..10000] of int64;
n,i,minwz,maxwz:longint;
max,min:int64;
begin
	assign(input,'array.in');
	assign(output,'array.out');
	reset(input);rewrite(output);
readln(n);
min:=10000000;
for i:= 1 to n do 
	begin
	read(a[i]);
	if a[i]>=max then begin max:=a[i];maxwz:=i;end;
	if a[i]<min then begin min:=a[i];minwz:=i;end;
	end;
writeln(maxwz-minwz+1);
close(input);close(output);
end.