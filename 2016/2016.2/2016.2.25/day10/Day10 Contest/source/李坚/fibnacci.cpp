#include<iostream>
#include<cstdio>
using namespace std;
struct Mark
{
  int l,r;
  bool Flag;
};
struct tree
{
  int Data;
  Mark AddMark;
  int l,r;
  int left,right;
};
int mod=1000000001;
int fib[377777];
int fibsum[377777];
int AskFib(int x)
{
  if (x==0) return 0;
  if (x==1) return 1;
  return (fib[x-1]+fib[x-2])%mod;
}
int n,m;
int ID=0;
tree t[377777];
void UpDataPoint(int x)
{
  t[x].Data=t[t[x].left].Data+t[t[x].right].Data;
  if (t[x].Data>=mod)
    t[x].Data=t[x].Data%mod;
}
inline int read()
{
  int x=0;
  int f=1;
  char ch=getchar();
  while (ch>'9' || ch<'0')
  {
    if (ch=='-')
      f=-1;
    ch=getchar();
  }
  while (ch>='0' && ch<='9')
  {
    x=x*10+ch-'0';
    ch=getchar();
  }
  return x*f;
}
void UpData(int x)
{
  if (t[x].AddMark.Flag==true)
  {
      int first=t[x].l-t[x].AddMark.l;
      int last=t[x].r-t[x].AddMark.l+1;
      t[x].Data+=(fibsum[last]-fibsum[first])%mod;
      if (t[x].left!=0) t[t[x].left].AddMark=t[x].AddMark;
      if (t[x].right!=0) t[t[x].right].AddMark=t[x].AddMark;
      t[x].AddMark.l=0;
      t[x].AddMark.r=0;
      t[x].AddMark.Flag=false;
  }
}
int build(int l,int r,int F,bool B)
{
  if (l==r)
  {
    ID++;
    t[ID].Data=read();
    t[ID].l=l;
    t[ID].r=r;
    if (B==true) 
      t[F].left=ID;
    else 
      t[F].right=ID;
    return t[ID].Data;
  }
  ID++;
  int Fnum=ID;
  int mid=(l+r)>>1;
  t[ID].l=l;
  t[ID].r=r;
  if (B==true) 
      t[F].left=ID;
    else 
      t[F].right=ID;
  t[ID].Data=build(l,mid,Fnum,true)+build(mid+1,r,Fnum,false);
  return t[Fnum].Data;
}
void Add(int a,int b,int l,int r,int Tree)
{
  UpData(Tree);
  if (t[Tree].l>=l && t[Tree].r<=r)
  {
      t[Tree].AddMark.l=a;
      t[Tree].AddMark.r=b;
      t[Tree].AddMark.Flag=true;
      return ;
  }  
  int x=Tree;
  int mid=(t[Tree].l+t[Tree].r)>>1;
  if (r<=mid)
  {
    Add(a,b,l,r,t[Tree].left);
  }
  if (l>mid)
  {
    Add(a,b,l,r,t[Tree].right);
  }
  if (l<=mid && r>mid)
  {
    Add(a,b,l,mid,t[Tree].left);
    Add(a,b,mid+1,r,t[Tree].right);
  }
  UpData(t[Tree].left);
  UpData(t[Tree].right);
  UpDataPoint(Tree);
}
int Ask(int l,int r,int Tree)
{
  UpData(Tree);
  if (t[Tree].l>=l && t[Tree].r<=r)
  {
    //cout<<l<<" "<<r<<endl;
    //cout<<t[Tree].Data<<endl;
    return t[Tree].Data;
  }

  int ans=0;
  int mid=(t[Tree].l+t[Tree].r)/2;
  if (l>mid)
  {
    ans+=Ask(l,r,t[Tree].right);
    if (ans>=mod) ans=ans%mod;
  }
  if (r<=mid)
  {
    ans+=Ask(l,r,t[Tree].left);
    if (ans>=mod) ans=ans%mod;
  }
  if (l<=mid && r>mid)
  {
    ans+=Ask(l,mid,t[Tree].left);
    //cout<<ans<<" ";
       if (ans>=mod) ans=ans%mod;
    ans+=Ask(mid+1,r,t[Tree].right);
       if (ans>=mod) ans=ans%mod;
    //cout<<ans<<endl;
  }
 // cout<<l<<" "<<r<<endl;
  //cout<<0<<" "<<t[Tree].l<<" "<<t[Tree].r<<endl;
  UpData(t[Tree].left);
  UpData(t[Tree].right);
  UpDataPoint(Tree);
  return ans%mod;
}
void init()
{
  n=read();
  m=read();
  for (int i=1;i<=n;i++)
  {
    fib[i]=AskFib(i);
    fibsum[i]=fibsum[i-1]+fib[i];
    if (fibsum[i]>=mod) fibsum[i]=fibsum[i]%mod;
  }
  build(1,n,0,true);
}
int main()
{
   freopen("fibnacci.in","r",stdin);
   freopen("fibnacci.out","w",stdout);
   init();
   for (int i=1;i<=m;i++)
   {
    int l,r,kind;
    kind=read();
    l=read();
    r=read();
    if (kind==1)
    {
     Add(l,r,l,r,1);
    }
    else
    {
     cout<<Ask(l,r,1)%mod<<endl;
    }
   }
   //for (int i=1;i<=10;i++)
   //if (t[i].l==t[i].r)
   //cout<<t[i].Data<<endl; 
}
  