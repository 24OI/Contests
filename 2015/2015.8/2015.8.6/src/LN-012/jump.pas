const zhi=1000000007;
var n,a,b,k:longint;
dp:array[1..2000,0..2000]of longint;
h,i,j:longint;
dao:array[1..2000,0..2000]of longint;
ans:int64;
function min(a,b:longint):longint;
begin
if a<b then exit(a) else exit(b);
end;

function max(a,b:longint):longint;
begin
if b<a then exit(a) else exit(b);
end;


begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);
read(n,a,b,k);
fillchar(dao,sizeof(dao),0);
fillchar(dp,sizeof(dp),0);
for i:=1 to n do begin
	for j:=max(1,i-abs(b-i)+1) to min(n,i+abs(b-i)-1) do begin
		if i<>j then begin
			inc(dao[j,0]);
			dao[j,dao[j,0]]:=i;
			end;
		end;
	end;
dp[a,0]:=1;
for j:=1 to k do begin
	for i:=1 to n do begin
		for h:=1 to dao[i,0] do begin
			inc(dp[i,j],dp[dao[i,h],j-1]);
			dp[i,j]:=dp[i,j] mod zhi;
			end;
		end;
	end;
ans:=0;

for i:=1 to n do begin
	ans:=ans+dp[i,k];
	ans:=ans mod zhi;
	end;
write(ans);
close(input);
close(output);
end.
