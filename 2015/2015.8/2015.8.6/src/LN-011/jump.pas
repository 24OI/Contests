var
n,k,a,b:longint;
function pw(a,b:longint;const c:longint):longint;
var ans,t,base:longint;
begin
if b=1 then exit(a);
base:=1;
t:=b;
repeat
	if(t and 1)=1 then base:=base*a;
		t:=t shr 1;
	ans:=a*base*a ;
	until t=1;
exit(ans);
	end;
	begin
	assign(input,'jump.in');reset(input);
	assign (output,'jump.out');rewrite(output);
	read(n,a,b,k);
	if(abs(a-b)=2)and (abs(n-a)<abs(a-b))then begin write(2);halt;end; 
	if(abs(a-b)=1)then begin write(0);halt;end;
	if(a+b<=n)then begin 
	b:=n shr 1;
	write(pw(b,k,1000000007));
halt;end;	
close(input);close(output);
end.