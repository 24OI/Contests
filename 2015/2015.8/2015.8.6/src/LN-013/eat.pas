program dy2;
//include <yjp>;
//include <saffah>;
var n,i,j,tt,d,e,sum:longint;
var a:array[1..100020]of longint;

	procedure eat;
		begin
			for i:=n downto 2 do
				if (a[i]<a[i-1])  then 
				begin 
					d:=i;
					e:=a[i];
					while a[d]=e do
						begin
						a[d]:=a[i-1];
						inc(d);
						end;
					inc(sum); 
				end;
			//writeln('sum=',sum);
			if sum<>0 then inc(tt);
		end;

begin
assign(input,'eat.in');
assign(output,'eat.out');
reset(input);
rewrite(output);

	readln(n);
	for i:=1 to n do
		readln(a[i]);
	
	sum:=1;
	tt:=0;
	while sum<>0 do
		begin
			sum:=0;
			eat;
		end;
	
	write(tt);
//write('saffah qrz');
 
close(input);
close(output);
end.