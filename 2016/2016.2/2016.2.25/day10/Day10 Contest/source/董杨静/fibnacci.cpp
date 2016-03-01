#include<stdio.h>
#include<string.h>
//#include<vector>
using namespace std;
typedef long long LL;
const int maxn=1E5+7;
const int mod=1E9+1;
LL F[maxn],transm[maxn],trans[maxn],transp[maxn];

char _mem[50000000];
int _cnt;
void *alloc(size_t size){
	void *ret=_mem+_cnt;
	_cnt+=size;
	return ret;
}

int N,M;
LL V[maxn];

/*
struct FIB{
	int s,t;
};
typedef vector<FIB> VF;
typedef vector<FIB>::iterator VFIT;
*/

struct QUERY{
	int idx,op,l,r;
	void read(int x){
		idx=x;
		scanf("%d%d%d",&op,&l,&r);
	}
}Q[maxn];

struct SEG{
	SEG *ch[2];
	LL sum;
	LL l,r,m,s,p;
	/*
	SEG(){
		memset(this,sizeof(SEG),0);
	}
	*/
	void *operator new(size_t size){return alloc(size);}
	void pass(){
		for(int i=0;i<2;++i){
			ch[i]->m+=m;
			ch[i]->m%=mod;
			ch[i]->s+=s;
			ch[i]->s%=mod;
			ch[i]->p+=p;
			ch[i]->s%=mod;
			int cl=ch[i]->l,cr=ch[i]->r;
			ch[i]->sum+=(F[cr-1]-F[cl-2]+mod)*m;
			ch[i]->sum%=mod;
			ch[i]->sum+=(F[cr]-F[cl-1]+mod)*s;
			ch[i]->sum%=mod;
			ch[i]->sum+=(F[cr+1]-F[cl]+mod)*p;
			ch[i]->sum%=mod;
		}
	}
	void maintain(){
		sum=ch[0]->sum+ch[1]->sum;
	}
}*tr;
void segInit(SEG *&tr,int L,int R){
	tr=new SEG;
	tr->l=L;
	tr->r=R;
	if(L==R){
		return;
	}
	int M=L+((R-L)>>1);
	segInit(tr->ch[0],L,M);
	segInit(tr->ch[1],M+1,R);
}
void segAdd(SEG *tr,int L,int R,int qL,int qR,int v){
	int M=L+((R-L)>>1);
	if(L==qL && R==qR){
		tr->m+=transm[v];
		tr->m%=mod;
		tr->s+=trans[v];
		tr->s%=mod;
		tr->p+=transp[v];
		tr->p%=mod;
		int l=L-v,r=R-v;
		tr->sum+=F[r]-F[l-1]+mod;
		tr->sum%=mod;
		return;
	}
	tr->pass();
	if(qR<=M) segAdd(tr->ch[0],L,M,qL,qR,v);
	else if(qL>M) segAdd(tr->ch[1],M+1,R,qL,qR,v);
	else segAdd(tr->ch[0],L,M,qL,M,v),segAdd(tr->ch[1],M+1,R,M+1,qR,v);
	tr->maintain();
}
LL segQuery(SEG *tr,int L,int R,int qL,int qR){
	int M=L+((R-L)>>1);
	if(L==qL && R==qR){
		return tr->sum;
	}
	tr->pass();
	if(qR<=M) return segQuery(tr->ch[0],L,M,qL,qR);
	else if(qL>M) return segQuery(tr->ch[1],M+1,R,qL,qR);
	else return (segQuery(tr->ch[0],L,M,qL,M)+segQuery(tr->ch[1],M+1,R,M+1,qR))%mod;
}

/*
void solve(int L,int R){
	if(L==R){
		return;
	}
	int M=L+((R-L)>>1);
	solve(L,M);
	solve(M+1,R);
	for(int i=L;i<=M;++i) if(Q[i].op==1){
		segAdd(tr,1,N,Q[i].l,Q[i].r,1);
	}
	for(int i=M+1;i<=R;++i) if(Q[i].op==2){
	}
}
*/

int main(){
	freopen("fibnacci.in","r",stdin);
	freopen("fibnacci.out","w",stdout);
	F[0]=0;F[1]=1;
	for(int i=2;i<maxn;++i) F[i]=(F[i-1]+F[i-2])%mod;
	for(int i=1;i<maxn;++i) F[i]=(F[i]+F[i-1])%mod;

	trans[0]=1;
	transm[1]=1;
	for(int i=2;i<maxn;++i){
		transm[i]=(transm[i-2]-transm[i-1]+mod)%mod;
		trans[i]=(trans[i-2]-trans[i-1]+mod)%mod;
		transp[i]=(transp[i-2]-transp[i-1]+mod)%mod;
	}

	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i) scanf("%I64d",V+i);
	for(int i=1;i<=N;++i) V[i]=(V[i]+V[i-1])%mod;;
	for(int i=1;i<=M;++i) Q[i].read(i);
	segInit(tr,1,N);
	//solve(1,M);
	for(int i=1;i<=M;++i){
		if(Q[i].op==1){
			segAdd(tr,1,N,Q[i].l,Q[i].r,Q[i].l-1);
		}else{
			LL ans1=segQuery(tr,1,N,Q[i].l,Q[i].r);
			LL ans2=(V[Q[i].r]-V[Q[i].l-1]+mod)%mod;
			printf("%I64d\n",(ans1+ans2)%mod);
		}
	}
}
