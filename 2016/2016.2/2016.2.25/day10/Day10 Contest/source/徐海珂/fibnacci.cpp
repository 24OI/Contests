#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct tree
{int s;
 vector<int> tag;
};
struct tree t[400010];
 
int n,m,opt,x,y,ans;
int a[100010],fib[100010],sf[100010];
const int mod=1000000001; 
 
void build(int p,int l,int r)
{if(l==r)
 {	t[p].s=a[l];
 	return;
 }
 build(p*2,l,(l+r)/2);
 build(p*2+1,(l+r)/2+1,r);
 t[p].s=(t[p*2].s+t[p*2+1].s)%mod;
}

void push_down(int p,int l,int r)
{int i,mid;
 mid=(l+r)/2;
 for(i=0;i<t[p].tag.size();i++)
 {	t[p*2].tag.push_back(t[p].tag[i]);
 	t[p*2].s=(((long long)t[p*2].s+sf[t[p].tag[i]+mid-l]-sf[t[p].tag[i]-1])%mod+mod)%mod;
	t[p*2+1].tag.push_back(t[p].tag[i]+mid-l+1);
	t[p*2+1].s=(((long long)t[p*2+1].s+sf[t[p].tag[i]+r-l]-sf[t[p].tag[i]+mid-l])%mod+mod)%mod;
 }
 t[p].tag.clear();
}

void change(int p,int l,int r)
{if(l>r) return;
 if(l>y || r<x) return;
 if(l>=x && r<=y)
 {	t[p].tag.push_back(l-x+1);
 	t[p].s=(((long long)t[p].s+sf[r-x+1]-sf[l-x])%mod+mod)%mod;
 	//cout<<p<<" "<<l<<" "<<r<<" "<<t[p].s<<endl;
 	return;
 }
 push_down(p,l,r);
 change(p*2,l,(l+r)/2);
 change(p*2+1,(l+r)/2+1,r);
 t[p].s=(t[p*2].s+t[p*2+1].s)%mod;
}

int query(int p,int l,int r)
{if(l>r) return 0;
 if(l>y || r<x) return 0;
 //cout<<p<<" "<<l<<" "<<r<<" "<<t[p].s<<endl;
 if(l>=x && r<=y) return t[p].s;
 push_down(p,l,r);
 return (query(p*2,l,(l+r)/2)+query(p*2+1,(l+r)/2+1,r))%mod;
}
 
int main()
{freopen("fibnacci.in","r",stdin);
 freopen("fibnacci.out","w",stdout);

 int i,j;
 
 fib[0]=0;
 fib[1]=1;
 sf[1]=1;
 for(i=2;i<=100000;i++)
 {	fib[i]=(fib[i-2]+fib[i-1])%mod;
 	sf[i]=(sf[i-1]+fib[i])%mod;
 } 
 
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
 	scanf("%d",&a[i]);
 build(1,1,n);
 for(i=1;i<=m;i++)
 {	scanf("%d%d%d",&opt,&x,&y);
 	if(opt==1)
		change(1,1,n);
	else
	{	ans=query(1,1,n);
		ans=(ans%mod+mod)%mod;
		printf("%d\n",ans);
	}
 }
 return 0;
}
