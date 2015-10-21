type prime=record
	x:array[1..10000] of longint;
	top:longint;
end;
var 
	p:prime;
	i,j,l,r:longint;

procedure fill(m:longint);
var i,k:longint;
begin
i:=0;k:=0;
while(i<p.top)do begin
	inc(i);
	if(m mod p.x[i])=0 then k:=1;
		end;
		if k=0 then 
		begin
		inc(p.top);
	p.x[p.top]:=m;
	end;
 end;
procedure init;
	var i:integer;
		begin 
	p.top:=2;p.x[1]:=2;p.x[2]:=3;
	for i:=4 to 100 do fill(i);
		end;
procedure p1(i:integer);
begin  
case i of
		2,3,5,7:writeln(i);
	4,6,8,10:writeln(2);
	9:writeln(3);
	end;
end;

begin 
assign(input,'factor.in');reset(input);
assign(output,'factor.out');rewrite(output);

readln(l,r);
init;

	for i:=l to r do
		begin
	if(r<=10)then begin p1(i);continue;end;
	if (i and 1)=0 then writeln(2) else begin
		for j:=1 to p.top do
			if ((i mod p.x[j])=0)then 
			begin
			if  (p.x[j]<i)then 
			writeln(p.x[j])
				else
				if (p.x[j]=i) then writeln(i);
				end;
			end;
		end;
close(input);close(output);	
end.			