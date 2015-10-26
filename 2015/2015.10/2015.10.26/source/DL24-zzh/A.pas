var n:longint;
a,b:array[1..2000000]of longint;
i:longint;
temp:longint;
flag:boolean;
p:longint;

function max(a,b:longint):longint;
begin
if a<b then exit(b) else exit(a);
end;

begin
assign(input,'A.in');
assign(output,'A.out');
reset(input);
rewrite(output);

read(n);
temp:=0;
flag:=false;

for i:=1 to n-1 do begin
	read(a[i]);
	if (a[i]>temp+2) or (flag and (a[i]>temp+1)) then begin
		writeln(0);
		halt;
		close(input);
		close(output);
		end
	else if a[i]>temp+1 then begin
		flag:=true;
		p:=i;
		end;
	temp:=max(temp,a[i]);
	end;


b[1]:=1;
temp:=1;
for i:=2 to n do begin
	b[i]:=max(b[i-1],a[i-1]+1);
	temp:=temp+b[i];
	end;
if flag then begin
	temp:=0;
	for i:=1 to p do if b[i]>=a[p]-1 then inc(temp);
	writeln(temp);
	end
else begin
	for i:=1 to n-1 do if (a[i]<=b[i]) and (a[i]<=b[i+1]) then dec(temp);
	writeln(temp);
	end;

close(input);
close(output);
end.
