const gzq=593119681;
var f:array[0..5000,1..5000] of longint;
	n,i,j,k,qaq,t:longint;
	a,b,zz:array[0..5000] of longint;
function pw(x,y:longint):longint;
   var t:longint;
    begin
    if y=0 then exit(1);
        t:=pw(x,y>>1);
        if y and 1=1 then exit(t*t*x)
                    else exit(t*t)
    end;
function panduan(x:longint):boolean;
	var i:longint;
	begin
	if x=1 then exit(true);
	for i:= 1 to 10 do
		if pw(2,i)=x then exit(true);
	exit(false); 
	end;
begin
assign(input,'monster.in');
assign(output,'monster.out');
reset(input);rewrite(output);
	readln(n,t);
	n:=pw(2,n);
for i:= 0 to n-1 do 
	read(a[i]);
for i:= 0 to n-2 do 
	for j:= i+1 to n-1 do 
		begin
		qaq:=i xor j;
		if panduan(qaq) then 
			begin
			inc(zz[i]);
			f[i,zz[i]]:=j;
			inc(zz[j]);
			f[j,zz[j]]:=i;
			end;
		end;

for i:= 1 to t do 
	begin
	b:=a;
	for j:= 0 to n-1 do
		for k:= 1 to zz[j] do
			begin 
			inc(b[f[j,k]],a[j]);
			b[f[j,k]]:=b[f[j,k]] mod gzq;
			end;
	a:=b;
	end;
for i:= 0 to n-1 do 
	write(a[i],' ');
close(input);close(output);
end.