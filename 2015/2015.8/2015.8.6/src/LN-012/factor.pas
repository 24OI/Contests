var l,r,i:int64;
j,t:longint;
prime,minprime:array[1..2100000]of longint;
tot:longint;
isprime:array[1..2100000]of boolean;
temp:longint;

procedure euler(n:longint);
var i,j:longint;
begin
tot:=0;
fillchar(isprime,sizeof(isprime),true);
for i:=2 to n do begin
	if isprime[i] then begin
		inc(tot);
		prime[tot]:=i;
		end;
	for j:=1 to tot do begin
		if prime[j]*i>n then break;
		isprime[i*prime[j]]:=false;
		if i mod prime[j] = 0 then break;
		end;
	end;
end;

function min(a,b:longint):longint;
begin
if a<b then exit(a) else exit(b);
end;

procedure solve1;
var i,j:longint;
now:longint;
begin
fillchar(isprime,sizeof(isprime),true);
fillchar(minprime,sizeof(minprime),$1f);
for i:=2 to r do begin
	if isprime[i] then begin
		minprime[i]:=i;
		now:=i;
		repeat
			now:=now+i;
			minprime[now]:=min(i,minprime[now]);
			isprime[now]:=false;
		until now>r;
		end;
	end;
for i:=2 to r do writeln(minprime[i]);
end;

begin
assign(input,'factor.in');
assign(output,'factor.out');
reset(input);
rewrite(output);
read(l,r);
if l=2 then solve1
else begin
	euler(1100000);
	for t:=0 to r-l do begin
		i:=t+l;
		temp:=trunc(sqrt(i));
		for j:=1 to tot do begin
			if i mod prime[j] = 0 then begin
				writeln(prime[j]);
				break;
				end;
			if prime[j]>temp then begin
				writeln(i);
				break;
				end;
			end;
		end;
	end;
close(input);
close(output);

end.
