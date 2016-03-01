var a,b:array[1..1000000] of longint;
n,m,x,y,ans,t,i:longint;
procedure merge(left,mid,right:longint);
var k,l,r,i:longint;
	begin
	l:=left;r:=mid+1;k:=left;
		while (l<=mid) and (r<=right) do 
		begin 
			if a[l]<=a[r] then 
				begin
				b[k]:=a[l];
				inc(k);
				inc(l);
				end
							else 
				begin
				b[k]:=a[r];
				inc(k);
				inc(r);
				ans:=ans+mid-l+1 //求逆序对在这里加上 
				end;
		end;	
		while l<=mid do begin b[k]:=a[l];inc(k);inc(l);end;
		while r<=right do begin b[k]:=a[r];inc(r);inc(k); end;	
		for i:= left to right do a[i]:=b[i];
	end;
procedure msort(left,right:longint);
var mid:longint;
	begin
	if left=right then exit;
	mid:=(left+right) div 2;
	msort(left,mid);
	msort(mid+1,right);
	merge(left,mid,right);
	end;
procedure init;
	begin
	readln(n);
for i:= 1 to n do 
	read(a[i]);
	end;
procedure come;
	begin
readln(m);
readln(x,y);
t:=a[x];
a[x]:=a[y];
a[y]:=t;
msort(1,n);
ans:=ans mod 2;
//if ans=1 then ans :=0;
writeln(ans);

if m>=2 then 
	for i:= 2 to m do 
	begin
	read(x,y);
	if (x <> y) then if ans=1 then ans:=0
			else ans:=1;
	writeln(ans);
	end;
	end;
begin
	assign(input,'lyk.in');
	assign(output,'lyk.out');
	reset(input);rewrite(output);
init;
come;

close(input);close(output);
end.
