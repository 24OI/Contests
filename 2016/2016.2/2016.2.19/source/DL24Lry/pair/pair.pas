var ans,i,n,p,m,sb,qaq,j:longint;
a:array[1..1000,1..10000] of longint;
b,l,r,zz:array[1..20000] of longint;
c,tt:array[1..20000] of boolean;
function hh(x:longint):boolean; 
var i:longint;
begin
	c[x]:=true;
	//for i:= 1 to 9 do write(b[i],' ');
	//writeln(b[10]);
for i:= 1 to zz[l[x]] do 
	if  (c[a[l[x],i]]=false) and (a[l[x],i]<>x) and (a[l[x],i]<>b[x])and (a[l[x],i]<>qaq) then 
		begin
		c[a[l[x],i]]:=true;
		if (b[a[l[x],i]]=0) or (hh(b[a[l[x],i]])) then 
			begin
			b[a[l[x],i]]:=x;
			b[x]:=a[l[x],i];
			tt[x]:=true;
			tt[a[l[x],i]]:=true;
			exit(true);
			end;
		end;
for i:= 1 to zz[r[x]] do 
	if (c[a[r[x],i]]=false) and (a[r[x],i]<>x)and (a[r[x],i]<>b[x])and (a[r[x],i]<>qaq)then 
		begin
		c[a[r[x],i]]:=true;
		if (b[a[r[x],i]]=0) or (hh(b[a[r[x],i]])) then 
			begin
			b[a[r[x],i]]:=x;
			b[x]:=a[r[x],i];
			tt[x]:=true;
			tt[a[r[x],i]]:=true;
			exit(true);
			end;
		end;
exit(false);


end;
begin
	assign(input,'pair.in');
	assign(output,'pair.out');
	reset(input);rewrite(output);
readln(m,n);
for i:= 1 to n do 
	begin
	readln(l[i],r[i]);
	inc(zz[l[i]]);
	a[l[i],zz[l[i]]]:=i;
	inc(zz[r[i]]);
	a[r[i],zz[r[i]]]:=i;
	end;
fillchar(tt,sizeof(tt),false);
fillchar(b,sizeof(b),0);
{for j:= 1 to 7 do 
	begin
for i:= 1 to zz[j] do 
	write(a[j,i],' ');
	writeln;
	end;
	halt;}
for i:= 1 to n do 
	if tt[i]= false then 
	begin
	fillchar(c,sizeof(c),false);
	qaq:=i;
	if hh(i) then inc(ans);
	end;
writeln(ans);
fillchar(tt,sizeof(tt),false);
for i:= 1 to n do 
	if tt[i]= false then 
	begin
	writeln(i,' ',b[i]);
	tt[i]:=true;
	tt[b[i]]:=true;
	end;

//for i:= 1 to 10 do write(b[i],' ');
close(input);close(output);
end.
