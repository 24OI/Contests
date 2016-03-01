const saffah=593119681;
var n,t,tot:longint;
a,s,new:array[0..1023]of longint;
i,j,tat:longint;
b:array[0..31]of boolean;

procedure init;
var i:longint;
begin
read(n,t);
tot:=1<<n-1;
for i:=0 to tot do read(a[i]);
fillchar(s,sizeof(s),0);
s[0]:=1;
end;

procedure plus;
var i,j:longint;
begin
move(s,new,sizeof(s));
for i:=0 to tot do begin
	for j:=0 to n-1 do begin
		new[i xor (1<<j)]:=(new[i xor (1<<j)]+s[i]) mod saffah;
		end;
	end;
move(new,s,sizeof(s));
end;

procedure gao;
var i,j:longint;
begin
fillchar(new,sizeof(new),0);
for i:=0 to tot do begin
	for j:=0 to tot do begin
		new[i xor j]:=(new[i xor j]+int64(s[i])*int64(s[j]) mod saffah) mod saffah;
		end;
	end;
move(new,s,sizeof(s));
end;

procedure print(a:array of longint);
var i:longint;
begin
for i:=0 to tot do write(a[i],' ');
writeln;
end;

begin
assign(input,'monster.in');
assign(output,'monster.out');
reset(input);
rewrite(output);
init;
if t<=1023 then tat:=10 else tat:=31;
//fillchar(b,sizeof(b),false);
for i:=tat downto 0 do begin
	gao;
	if t and (1<<i) <> 0 then plus;
	end;
//print(s);
fillchar(new,sizeof(new),0);
for i:=0 to tot do for j:=0 to tot do new[i xor j]:=(new[i xor j]+int64(a[i])*int64(s[j]) mod saffah) mod saffah;
print(new);
close(input);
close(output);
end.
