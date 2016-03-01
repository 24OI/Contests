#include <cstdio>
#include <cstring>

unsigned int monster[2][1 << 11];

int main(void)
{
	unsigned int n,t;
	unsigned int i,j,k;

	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%u %u",&n,&t);
	n = 1 << n;
	for(i = 0;i < n;++i)
		scanf("%u",&monster[0][i]);

	for(k = 1;k <= t;++k)
	{
		memcpy(monster[k & 1],monster[(k - 1) & 1],sizeof(monster[k & 1]));
		for(i = 0;i < n;++i)
		{
//			monster[k & 1][i] = monster[(k - 1) & 1][i];
			for(j = 1;j < n;j <<= 1)
			{
				(monster[k & 1][i] += monster[(k - 1) & 1][i ^ j]) %= 593119681;
			}
		}
	}

	for(i = 0;i < n - 1;++i)
		printf("%u ",monster[t & 1][i]);
	printf("%u\n",monster[t & 1][n - 1]);
	
//	printf("%d\n",sizeof(monster) / 1024 / 1024);
	return 0;
}
