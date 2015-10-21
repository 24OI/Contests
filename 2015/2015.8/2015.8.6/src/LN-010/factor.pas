const a:array[1..95] of longint =(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499);
var bobo:boolean;
	i,j,l,r:longint;
function prime(x:longint):boolean;
var i:longint;
	begin
	for i := 2 to trunc(sqrt(x)) do
		if x mod i = 0 then exit(false);
        exit(true);
	end;
begin
assign(input,'factor.in');
reset(input);
assign(output,'factor.out');
rewrite(output);
readln(l);
readln(r);
for i:= l to r do 
	begin
	bobo:=true;
	for j:= 1 to i do
		begin
		if i mod a[j] =0 then begin writeln(a[j]);break;end;
		if (j>3) and bobo then if prime(i) then begin write(i);break;end
									else bobo:=false;
		end;
	
	end;
close(input);close(output);

end.