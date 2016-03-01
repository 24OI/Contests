#include <cstdio>
#include <cmath>
#include <map>
#include <utility>

std::map<std::pair<long long,long long>,unsigned int> data;
int A[1000];
int B[1000];
int C[1000];
unsigned int ans1;
unsigned int ans2;

void check(unsigned int i,unsigned int j)
{
	std::pair<long long,long long> p;
	long long x,y;
	long long a1 = A[i],b1 = B[i],c1 = C[i];
	long long a2 = A[j],b2 = B[j],c2 = C[j];
	unsigned int c;
	if(a1 * b2 == a2 * b1)
		return;
	y = (c2 * a1 - c1 * a2) * 1000 / (a2 * b1 - a1 * b2);
	x = (c2 * b1 - c1 * b2) * 1000 / (b2 * a1 - b1 * a2);
	p = std::make_pair(x,y);
	c = ++data[p];
	if(c == ans1)
		++ans2;
	else if(c > ans1)
		ans1 = c,ans2 = 1;
}

int main(void)
{
	unsigned int n;
	unsigned int i,j;

	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%u",&n);
	for(i = 0;i < n;++i)
		scanf("%d %d %d",&A[i],&B[i],&C[i]);

	for(i = 0;i < n;++i)
		for(j = i + 1;j < n;++j)
			check(i,j);
	ans1 = ((1.0 + sqrt(1.0 + 8.0 * ans1)) / 2.0) + 0.5;
	printf("%u %u\n",ans1,ans2);
	return 0;
}
