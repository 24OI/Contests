#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int mo=1000000001;
const int maxn=100010;
struct node{
	int l,r,sum;
	vector<int>tag;
}t[maxn*3];
int a[maxn],f[maxn],s[maxn],n,m,x,y,op;

char BUF[200000],*buf,*end;
#define getch() (end==buf?fread(BUF,1,200000,stdin),buf=BUF,end=buf+200000,*(buf++):*(buf++))
template<class T>
void read(T &x){
	char c=getch();
	for(;c<'0'||c>'9';c=getch());
	for(x=0;'0'<=c&&c<='9';c=getch())x=x*10+c-'0';
}

int built(int l,int r,int k){
	t[k].l=l; t[k].r=r;
	if(l==r)return t[k].sum=a[l]%mo,0;
	int mid=l+r>>1;
	built(l,mid,k*2);
	built(mid+1,r,k*2+1);
	return t[k].sum=(t[k*2].sum+t[k*2+1].sum)%mo,0;
}

void updata(int k){
	if(t[k].l==t[k].r)t[k].tag.clear();
	if(t[k].tag.empty())return;
	int size=t[k].tag.size(),tmp,mid;
	for(int i=0;i<size;i++){
		mid=t[k].l+t[k].r>>1;
		tmp=(mid-t[k].l+t[k].tag[i]);
		t[k*2].sum=(t[k*2].sum+(s[tmp]-s[t[k].tag[i]-1]+mo)%mo)%mo;
		t[k*2].tag.push_back(t[k].tag[i]);
		t[k*2+1].sum=(t[k*2+1].sum+(s[t[k].r-t[k].l+t[k].tag[i]]-s[tmp]+mo)%mo)%mo;
		t[k*2+1].tag.push_back(tmp+1);
	}
	t[k].tag.clear();
}

void change(int l,int r,int k,int x){
	updata(k);
	if(l==t[k].l&&r==t[k].r){
		t[k].sum=(t[k].sum+(s[r-l+x]-s[x-1]+mo)%mo)%mo;
		t[k].tag.push_back(x);
		return;
	}
	int mid=t[k].l+t[k].r>>1,tmp=(mid-l+x+1);
	if(r<=mid)change(l,r,k*2,x);
	else if(l>mid)change(l,r,k*2+1,x);
	else change(l,mid,k*2,x),change(mid+1,r,k*2+1,tmp);
	t[k].sum=(t[k*2].sum+t[k*2+1].sum)%mo;
}

int ask(int l,int r,int k){
	if(l==t[k].l&&r==t[k].r)return t[k].sum;
	updata(k);
	int mid=t[k].l+t[k].r>>1;
	if(r<=mid)return ask(l,r,k*2);
	else if(l>mid)return ask(l,r,k*2+1);
	else return (ask(l,mid,k*2)+ask(mid+1,r,k*2+1))%mo;
}

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	read(n); read(m);
	f[1]=1;
	for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mo;
	for(int i=1;i<=n;i++)s[i]=(s[i-1]+f[i])%mo;
	for(int i=1;i<=n;i++)read(a[i]);
	built(1,n,1);
	for(int i=1;i<=m;i++){
		read(op);  read(x); read(y);
		if(op==1)change(x,y,1,1);
		else printf("%d\n",ask(x,y,1));
	}
	return 0;
}
