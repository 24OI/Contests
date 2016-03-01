const
	maxn=1001000;
//maxn=100;
  eps=1e-6;
type
	arr=array[1..2] of int64;
var
	x,y,ll:array[0..maxn,1..2] of int64;
	t1,t2:array[1..3] of int64;
	a:array[0..1010,1..3] of int64;
  mark:array[0..1010] of Longint;
	cnt,n,i,j:Longint;
procedure swap(var a,b:arr);
var
	t:arr;
begin
	t:=a; a:=b; b:=t;
end;

function cmp(i,j:Longint):boolean;
var
	t1,t2:extended;
  k:Longint;
begin
	t1:=x[i,1]/x[i,2]; t2:=x[j,1]/x[j,2];
	if abs(t1-t2)<eps then
    begin
		  t1:=y[i,1]/y[i,2]; t2:=y[j,1]*y[j,2];
      if abs(t1-t2)<eps then exit(false)
        else if t1<t2 then exit(true)
          else exit(false);
    end;
  if t1<t2 then exit(true) else exit(false);
end;


procedure qsort(l,r:Longint);
var
	i,j,mid:Longint;
begin
	if l>=r then exit;
	i:=l; j:=r;
	mid:=(l+r) shr 1;
	repeat
			while (i<=cnt) and (cmp(i,mid)) do inc(i);
			while (j>=1) and (cmp(mid,j)) do dec(j);
			if i<=j then
				begin
					swap(x[i],x[j]); swap(y[i],y[j]); swap(ll[i],ll[j]);
					inc(i); dec(j);
				end;
		until i>j;
	qsort(i,r); qsort(l,j);
end;


procedure add(i,j:Longint);
var
	y1,y2,c:int64;
	k:Longint;
begin
	if (a[i,1]=0) and (a[j,1]=0) then exit;
	if a[i,1]*a[j,2]=a[j,1]*a[i,2] then exit;				//ping xing
	if a[j,1]=0 then begin k:=i; i:=j; j:=k; end;
	inc(cnt); ll[cnt,1]:=i; ll[cnt,2]:=j;
	if a[i,1]=0 then
		begin
			for k:=2 to 3 do t1[k]:=a[i,k]*a[j,2];
			for k:=1 to 3 do t2[k]:=a[j,k]*a[i,2];
			x[cnt,1]:=t1[3]-t2[3]; x[cnt,2]:=t2[1];
			y[cnt,1]:=-a[i,3]; y[cnt,2]:=a[i,2];
      exit;
		end;
	for k:=1 to 3 do t1[k]:=a[i,k]*a[j,1];
	for k:=1 to 3 do t2[k]:=a[j,k]*a[i,1];
	y1:=t1[3]-t2[3]; y2:=t2[2]-t1[2];
	x[cnt,1]:=-a[i,3]*y2-a[i,2]*y1;
	x[cnt,2]:=a[i,1]*y2;
	y[cnt,1]:=y1; y[cnt,2]:=y2;
end;

procedure solve;
var
	i,j,k,l1,l2,bri,res,sum,time:Longint;
begin
	i:=1; bri:=1; res:=1; time:=0;
	while i<=cnt do
		begin
			j:=i+1; inc(time); sum:=0;
			while (j<=cnt) and (x[i,1]*x[j,2]=x[j,1]*x[i,2])
                     and (y[i,1]*y[j,2]=y[j,1]*y[i,2]) do inc(j);
      for k:=i to j-1 do
        begin
          l1:=ll[k,1]; l2:=ll[k,2];
          if mark[l1]<>time then begin mark[l1]:=time; inc(sum); end;
          if mark[l2]<>time then begin mark[l2]:=time; inc(sum); end;
        end;
      if sum>bri then begin bri:=sum; res:=1; end
        else if sum=bri then inc(res);
			i:=j;
		end;
	writeln(bri,' ',res);
end;

begin
  assign(input,'star.in'); reset(input);
  assign(output,'star.out'); rewrite(output);
	readln(n);
	for i:=1 to n do
		readln(a[i,1],a[i,2],a[i,3]);
	for i:=1 to n-1 do
		for j:=i+1 to n do
			add(i,j);
	qsort(1,cnt);
 // for i:=1 to cnt do
  //  writeln('(',x[i,1],'/',x[i,2],',',y[i,1],'/',y[i,2],')');
	solve;
  close(input); close(output);
end.
