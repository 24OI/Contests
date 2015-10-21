
var list:array[1..100000] of string;
	ok:array[1..100000] of string;
	temp,tpg,xz:string;
	head,foot,b,n,x,k,i:longint;
	ans:int64;
	papapa:boolean;
function bobo(x:longint):boolean;
	var orz:longint;
	s:string;
	begin
	s:=list[head];
	val(s[length(s)],orz);
	if x=orz then exit(false);
	if abs(x-orz)>=abs(b-orz) then exit(false)
										else if (b-x=1) and (length(list[head])<>k)then exit(false);
	exit(true);
	end;
function disappear(x:string):boolean;
	 var j:longint;
	begin
	for j:= 1 to ans do 
		if x=ok[j] then exit(false);
	exit(true);
	end;
begin
assign(input,'jump.in');
reset(input);
assign(output,'jump.out');
rewrite(output);
read(n,x,b,k);
if b-x=1 then begin write(0); halt;end;
ans:=1;
 str(x,temp);
list[1]:=list[1]+temp;
head:=0;
foot:=1;
repeat
papapa:=false;
	inc(head);
	if length(list[head])=k+1 then papapa:=true;
	for i:= 1 to n do 
		begin
		if bobo(i) then begin 
							str(i,tpg);
							xz:=list[head]+tpg;
							inc(foot);
							list[foot]:=xz;
							if (length(list[foot])=k+1) and (disappear(list[foot])) then
									begin
									ok[ans]:=list[foot];
									inc(ans);
									end;
							end;
		end;
until papapa;
dec(ans);
write(ans mod 1000000007);
close(input);close(output);
end.