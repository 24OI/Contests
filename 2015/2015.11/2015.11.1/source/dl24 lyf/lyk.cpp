#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mid (nowl+nowr>>1)
#define maxn 100001

int N,M;
int a[maxn];
int x,y;
int tree[500001];
int k;

int query(int ql,int qr,int nowl,int nowr,int num){
    if (ql>nowr||nowl>qr) return 0;
    if (ql<=nowl&&nowr<=qr) return tree[num];
    return query(ql,qr,nowl,mid,num<<1)+query(ql,qr,mid+1,nowr,num<<1|1);
}

int search(){
    int rtn=0;
    int tmp;
    for (int i=1;i<=N;++i){
        rtn+=query(a[i]+1,N,1,k,1);
        tmp = k-1+a[i];
        tree[tmp]++;
        tmp>>=1;
        while (tmp!=0){
            tree[tmp]=tree[tmp<<1]+tree[tmp<<1|1];
            tmp>>=1;
        }
    }
    return rtn;
}

int main(){
    freopen("lyk.in","r",stdin);
    freopen("lyk.out","w",stdout);
    scanf("%d",&N);k=int(pow(2,ceil(log2(N))));
    for (int i=1;i<=N;++i) scanf("%d",&a[i]);
    scanf("%d",&M);
    memset(tree,0,sizeof(tree));
    int ans = search()%2;
    while (M--){
        ans = (ans == 0 ? 1 : 0);
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
