#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<vector>
using namespace std;

int all[1002][4];
int n,ct;
int sum;
int pt1,pt2,t3,t4,t5,t6,tc,rt1,rt2;

int get(int x,int y){
	int t0=0;
	for (int i=1;i<=n;i++){
		if (all[i][1]*x+all[i][2]*y+all[i][3]==0) t0++;		
	}
	return t0;
}

bool flag1,flag2;
vector<int>a[1002];
vector<int>b[1002];

void find(int t1,int t2,int step){
	while (step>0){
		flag1=1;
		while (flag1==1){
			tc=get(t1,t2);
			if (tc>sum){
				a[tc].push_back(t1);
				b[tc].push_back(t2);
				sum=tc;
				ct=1;
			}
			else if (tc==sum){
				flag2=0;
				for (int i=0;i<a[tc].size();i++){
					if (a[tc][i]==t1&&b[tc][i]==t2){
						flag2=1;
						break;
					}
				}
				if (flag2==0){
					a[tc].push_back(t1);
					b[tc].push_back(t2);
					ct++;
				}
			}
			flag1=0;
			rt1=t1;
			rt2=t2;
			for (int i=1;i<=4;i++){
				if (i==1){
					pt1=t1;
					pt2=t2-step;
				}
				if (i==2){
					pt1=t1+step;
					pt2=t2;
				}
				if (i==3){
					pt1=t1;
					pt2=t2+step;
				}
				if (i==4){
					pt1=t1-step;
					pt2=t2;
				}
				
				if (get(pt1,pt2)>get(rt1,rt2)){
					flag1=1;
					rt1=pt1;
					rt2=pt2;
				}
			}
			t1=rt1;
			t2=rt2;
		}
		step*=0.65;
	}
}

int r1,r2;
clock_t a1,b1;

int main(){
	freopen ("star.in","r",stdin);
	freopen ("star.out","w",stdout);
	scanf ("%d",&n);
	srand(time(NULL));
	for (int i=1;i<=n;i++) scanf ("%d%d%d",&all[i][1],&all[i][2],&all[i][3]);
	for (int i=1;i<=13000;i++){
		r1=rand()%2000+1;
		r1-=1000;
		r2=rand()%2000+1;
		r2-=1000;
		find(r1,r2,1000);
		find(r2,r1,1000);
	}
	printf ("%d %d",sum,ct);
	
	return 0;
}