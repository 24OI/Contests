#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX_N 1010
using namespace std;
typedef long long ll;
inline ll read(){
	ll sum=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return sum*t;
}
struct data{ll a,b,c;}line[MAX_N];
struct date{
	ll xup,xdown,yup,ydown;
}q[MAX_N*MAX_N];
int n,num[MAX_N*MAX_N],top,back,mx,cnt,ans;
ll c[MAX_N*MAX_N][2];
ll ABS(ll x){return x>0?x:-x;}
ll gcd(ll x,ll y){
	ll y1;
	if(!x||!y)return 1;
	while(y){
		y1=y;
		y=x%y;
		x=y1;
	}
	return x;
}
bool cmp(date a,date b){
	if(a.xdown*b.xdown>0){
		ll l=a.xup*b.xdown,r=b.xup*a.xdown;
		if(l==r){
			if(a.ydown*b.ydown>0)return a.yup*b.ydown<b.yup*a.ydown;
			else return a.yup*b.ydown>b.yup*a.ydown;
		}
		else return a.xup*b.xdown<b.xup*a.xdown;
	}
	else {
		ll l=a.xup*b.xdown,r=b.xup*a.xdown;
		if(l==r){
			if(a.ydown*b.ydown>0)return a.yup*b.ydown<b.yup*a.ydown;
			else return a.yup*b.ydown>b.yup*a.ydown;
		}
		else return a.xup*b.xdown>b.xup*a.xdown;
	}
}
bool check(int i,int j){
	return q[i].xup*q[j].xdown==q[j].xup*q[i].xdown&&q[i].yup*q[j].ydown==q[j].yup*q[i].ydown;
}

int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	n=read();
	c[1][0]=1;c[1][1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=2;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	for(int i=1;i<=n;i++)
		line[i].a=read(),line[i].b=read(),line[i].c=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			ll up=line[i].c*line[j].b-line[j].c*line[i].b;
			ll down=line[j].a*line[i].b-line[i].a*line[j].b;
			if(!down)continue;
			ll G=gcd(ABS(up),ABS(down));
			q[top].xup=up/G;q[top].xdown=down/G;
			up=line[i].a*line[j].c-line[j].a*line[i].c;
			down=line[j].a*line[i].b-line[i].a*line[j].b;
			G=gcd(ABS(up),ABS(down));
			q[top].yup=up/G;q[top].ydown=down/G;
			top++;
		}
	sort(q,q+top,cmp);
	for(int i=0;i<top;i++){
		num[back]=1;
		while(check(i,i+1)&&i<top-1)num[back]++,i++;
		back++;
	}
	for(int i=0;i<back;i++)mx=max(mx,num[i]);
	for(int i=0;i<back;i++)if(num[i]==mx)cnt++;
	for(int i=2;i<=n;i++)if(mx==c[i][2]){ans=i;break;}
	printf("%d %d\n",ans,cnt);
	return 0;
}
