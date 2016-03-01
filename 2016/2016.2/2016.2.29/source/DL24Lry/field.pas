var n,i,t,wz:longint;
prime:array[1..250000] of longint;
isprime:array[1..250000] of boolean;
tot,ans,x,y,p,j,z:longint;
bobo:boolean;
dcd:array[1..250000] of longint;
function min(x,y:longint):longint;
	begin
	if x>y then exit(y)
			else exit(x);
	end;
function gcd(x,y:longint):longint;
	var t:longint;
	begin
	//if (isprime[x]=true) and (isprime[y]=true) then exit(min(x,y)); 
	if x mod y=0  then exit(y)
			else exit(gcd(y,x mod y));
	end;
procedure oula(x:longint);
    var i,j:longint;
    begin
    for i:= 2 to n do 
        begin
        if isprime[i] then begin inc(tot);prime[tot]:=i;end;
        for j:= 1 to tot do 
            begin
            if i*prime[j]>n then break;
            isprime[i*prime[j]]:=false;
            if i mod prime[j] = 0 then break;
            end;

        end;
    end;
begin
		assign(input,'field.in');
	assign(output,'field.out');
	reset(input);rewrite(output);
fillchar(isprime,sizeof(isprime),true);
n:=2500;
oula(2500);
for i:= 2 to 2500 do 
	begin
	t:=i;
	wz:=1;
	ans:=0;
	bobo:=true;
	while t <> 1 do 
		begin
		if t mod prime[wz]=0 then begin 
									t:=t div prime[wz];
								//	if dcd[t]<>0 then begin dcd[i]:=dcd[t]+ans;bobo:=false;break;end;
									inc(ans);
									end
							else inc(wz);
		end; 	
	if bobo then dcd[i]:=ans;
	end;
//	for i:= 1 to 100 do 
//	writeln(i,' ',dcd[i]);halt;
//	writeln(gcd(2,2));
//	writeln(gcd(3,3));halt;

{ for i:= 1 to 10 do 
 	for j:= i+1 to 10 do 
 		begin
 		if gcd(i,j)=1 then inc(ans);
 		end;
 	writeln(ans+1);
 	halt; }
readln(t);
for z:= 1 to t do 
	begin
	readln(x,y,p);
	if x>y then 
		begin
		t:=x;
		x:=y;
		y:=t;
		end;
		ans:=0;
	for i:= 1 to x do 
		for j:= i+1 to y do 
			if dcd[gcd(i,j)]<=p then inc(ans);
	ans:=ans*2;
	for i:= 1 to x do 
		if dcd[i]<=p then inc(ans);	
		writeln(ans);
	end;
	close(input);
	close(output);
end.