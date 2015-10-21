var n,i:longint;
ans,t1,t2,now:longint;
none:boolean;
s1,s2:array[1..100000]of longint;




begin
assign(input,'eat.in');
assign(output,'eat.out');
reset(input);
rewrite(output);
read(n);
if n=1 then begin
	write(0);
	close(input);
	close(output);
	halt;
	end;

for i:=1 to n do read(s2[i]);
t1:=0;
t2:=n;
ans:=0;
while t1<>t2 do begin
	for i:=1 to t2 do s1[i]:=s2[i];
	t1:=t2;
	t2:=0;
	inc(t2);
	s2[t2]:=s1[1];
	for i:=2 to t1 do begin
		if s1[i]>s1[i-1] then begin
			inc(t2);
			s2[t2]:=s1[i];
			end;
		end;
	inc(ans);
	end;
write(ans-1);
close(input);
close(output);
end.
