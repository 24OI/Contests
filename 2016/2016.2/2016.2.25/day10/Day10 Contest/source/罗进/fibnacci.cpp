#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn=1e5+10,MOD=1e9+1;
LL f[maxn],S[maxn],k[maxn],sum[maxn];
int fa[maxn],ch[maxn][2],l_right[maxn],l_left[maxn],root,size[maxn][2];
void push_up(int x){
	sum[x]=0,size[x][0]=size[x][1]=0;;
	if(ch[x][1]) sum[x]+=sum[ch[x][1]],size[x][1]=size[ch[x][1]][0]+size[ch[x][1]][1]+1;
	if(ch[x][0]) sum[x]+=sum[ch[x][0]],size[x][0]=size[ch[x][0]][0]+size[ch[x][0]][1]+1;
	sum[x]+=k[x];
	sum[x]%=MOD;
}
void push_down(int x){
	if(!l_right[x]&&!l_left[x]) return;
	else if(l_right[x]==l_left[x]){
		k[x]+=f[l_right[x]];
		l_right[x]=l_left[x]=0;
	}
	if(ch[x][0]){
		int son=ch[x][0],s=size[x][0];
		//sum[son]=(sum[son]+S[s+l]-S[l-1])%MOD;
		l_left[son]=l_left[x],l_right[son]=l_left[x]+s-1;
		sum[son]=(sum[son]+S[l_right[son]]-S[l_left[son]-1])%MOD;
	}
	if(ch[x][1]){
		int son=ch[x][1],s=size[x][1];
		l_left[son]=l_right[x]-s+1,l_right[son]=l_right[x];
		sum[son]=(sum[son]+S[l_right[son]]-S[l_left[son]-1])%MOD;
	}
	k[x]+=f[l_left[x]+size[x][0]-1];
	l_left[x]=l_right[x]=0;
}
void rotate(int x){
	int y=fa[x],g=fa[y],c=ch[y][1]==x;
	push_down(y);
	push_down(x);
	ch[y][c]=ch[x][c^1],fa[ch[y][c]]=y;
	fa[y]=x,ch[x][c^1]=y;
	fa[x]=g;
	if(g){
		c=ch[g][1]==y;
		ch[g][c]=x;
	}
	push_up(y);
	push_up(x);
}
void splay(int x,int goal){
	for(int y;(y=fa[x])!=goal;rotate(x))
		if(fa[y]!=goal) rotate(y);
	if(!goal) root=x;
}
void update(int l,int r){
	splay(l-1,root);
	splay(r+1,l-1);
	int x=ch[r+1][0];
	l_left[x]=1,l_right[x]=r-l+1;
	sum[x]=(sum[x]+S[r-l+1])%MOD;
	push_up(r+1),push_up(l-1);
}
void query(int l,int r){
	splay(l-1,root);
	splay(r+1,l-1);
	push_down(l-1);
	push_down(r+1);
	int x=ch[r+1][0];
	printf("%lld\n",sum[x]%MOD);
}
int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	f[1]=1,f[2]=1;
	S[1]=1,S[2]=2;
	for(int i=3;i<=n;i++) f[i]=(f[i-1]+f[i-2])%MOD,S[i]=(S[i-1]+f[i])%MOD;
	if(n<=1000&&m<=1000){
		long long a[maxn];
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) scanf("%lld",a+i);
		while(m--){
			int type,l,r;
			scanf("%d%d%d",&type,&l,&r);
			if(type==1){
				for(int i=l;i<=r;i++) a[i]=(a[i]+f[i-l+1])%MOD;
			}
			else{
				long long sum=0;
				for(int i=l;i<=r;i++) sum=(sum+a[i])%MOD;
				printf("%lld\n",sum%MOD);
			}
		}
	}
	else{
		for(int i=2;i<=n+1;i++){
			fa[i]=i-1,ch[i-1][1]=i;
			scanf("%d",k+i);
		}
		fa[n+2]=n+1,ch[n+1][1]=n+2;
		for(int i=n+2;i>=1;i--) push_up(i);
		while(m--){
			int type,l,r;
			scanf("%d%d%d",&type,&l,&r);
			++l,++r;
			if(type==1) update(l,r);
			else query(l,r);
		} 
	}
	return 0;
}
