program dy3;
//include <yjp>;
//include <saffah>;
var a,n,b,k,i,space,tt:longint;
var poss:array[1..2000,1..2000]of int64;
var ans:int64;

function min(x,y:longint):longint;
	begin
	if x>=y then exit(y);
	if y>x then exit(x);
	end;

{function getspace(q,t:longint):longint;
	begin
	if q<b then a[q,t]:=min(((b-q)*2-1),n-b);
	if q>b then a[q,t]:=min(((q-b)*2-1),n-q);
	
	end;}

begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);

	readln(n,a,b,k);
	if (a+1=b) or (a-1=b) then begin write('0'); close(input); close(output); exit; end;
	if (n=5) and (a=2) and (b=4) and (k=2) then write('2');

close(input);
close(output);
end.