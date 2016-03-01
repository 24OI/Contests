const
        fuck=1000000001;
var
        a,f:array[1..100000]of longint;
        s,l,r:array[1..432109]of longint;
        n,i,j,p,q,t,m:longint;
function fbnq(x:longint):longint;
begin
        if f[x]>0 then exit(f[x]);
        f[x]:=(f[x-1]+f[x-2])mod fuck;
        exit(f[x]);
end;
procedure build(x,zuo,you:longint);
var m:longint;
begin
        l[x]:=zuo;
        r[x]:=you;
        if zuo=you then begin
                s[x]:=a[zuo];
                exit;
        end;
        m:=(zuo+you)>>1;
        build(x<<1,zuo,m);
        build(x<<1+1,m+1,you);
        s[x]:=s[x<<1]+s[x<<1+1];
end;
procedure add(x,i,n:longint);
var m:longint;
begin
        s[x]:=(s[x]+fbnq(n))mod fuck;
        if(l[x]<i)or(r[x]>i)then begin
                m:=r[x<<1];
                if i<=m then add(x<<1,i,n)
                else add(x<<1+1,i,n);
        end;
end;
function ask(x,z,y:longint):longint;
var m,q:longint;
begin
        if (l[x]>=z)and(r[x]<=y)then exit(s[x]);
        m:=r[x<<1];
        q:=0;
        if z<=m then q:=q+ask(x<<1,z,y);
        if y>m then q:=q+ask(x<<1+1,z,y);
        exit(q mod fuck);
end;
begin
        assign(input,'fibnacci.in');
        reset(input);
        assign(output,'fibnacci.out');
        rewrite(output);
        readln(n,m);
        f[1]:=1;
        f[2]:=1;
        for i:=1 to n do read(a[i]);
        build(1,1,n);
        for i:=1 to m do begin
                readln(p,q,t);
                if p=1 then for j:=q to t do add(1,j,j-q+1)
                else writeln(ask(1,q,t))
        end;
        close(input);
        close(output);
end.