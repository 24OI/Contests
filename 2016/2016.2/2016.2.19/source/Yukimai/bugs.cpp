#include <cstdio>
#include <cstring>
#include <algorithm>
#define snowclr(x) memset(x, 0, sizeof(x))
using namespace std;
char t0[50000], t1[50000], src[20100];
const int F[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025};
int n, m, p, d0, d1, nxt[20100];
template <int SZ>
struct matrix
{
	int m[SZ][SZ];
	matrix<SZ> operator*(const matrix<SZ> &rhs) const
	{
		matrix<SZ> ans;
		for(int i = 0; i < SZ; ++i)
			for(int j = 0; j < SZ; ++j)
				for(int k = 0; k < SZ; ++k)
					ans.m[i][j] = (ans.m[i][j]+ ((long long)m[k][j]*rhs.m[i][k])%p)%p;
		return ans;
	}
	matrix<SZ>& operator*=(const matrix<SZ> &rhs)
	{
		return *this = *this * rhs;
	}
	matrix(){memset(m, 0, sizeof(m));}
};
matrix<2> mF;
matrix<3> mK;
void getnext()
{
	int l2 = strlen(src), t = 0, i = 1;
	while(i <= l2)
	{
		while(t && src[i-1] != src[t-1]) t = nxt[t];
		++i, ++t;
		if(src[i-1] == src[t-1]) nxt[i] = nxt[t];
		else nxt[i] = t;
	}
	while(t && src[i-1] != src[t-1]) t = nxt[t];
	++i, ++t;
	nxt[i] = nxt[t];
}
void init()
{
	getnext();
	mF.m[0][1] = mF.m[1][0] = mF.m[1][1] = 1;
	mK.m[0][0] = mK.m[0][1] = mK.m[1][0] = mK.m[1][2] = mK.m[2][2] = 1;
	mK.m[1][1] = 2;
}
int kmp(char *tg, char *sr)
{
	int l1 = strlen(tg), l2 = strlen(sr), ans = 0;
	for(int i = 1, j = 0; l2+1-i<=l1-j;)
		if(sr[i-1] == tg[j])
		{
			++i, ++j;
			if(i > l2) ans = (ans+1)%p, i = nxt[i];
			if(!i) ++i, ++j;
		}else
		{
			i = nxt[i];
			if(!i) ++i, ++j;
		}
	return ans;
}
int getd(char *s, int x)
{
	return F[x] >= m ? kmp(s, src) : 0;
}
int fgetd(char *tg, int pos)
{
	int l1 = strlen(tg), l2 = strlen(src), ans = 0;
	for(int i = 1, j = 0; l2+1-i<=l1-j;)
		if(src[i-1] == tg[j])
		{
			++i, ++j;
			if(i > l2)
			{
				if(j > pos)
				{
					if(j-l2 < pos)
						ans = (ans+1)%p;
					else return ans;
				}
				i = nxt[i];
			}
			if(!i) ++i, ++j;
		}else
		{
			i = nxt[i];
			if(!i) ++i, ++j;
		}
	return ans;
}
void pushs(int x)
{
	char buf[50000];
	strcpy(buf, t0);
	strcat(buf, t1);
	snowclr(t0);
	strcpy(t0, t1);
	strcpy(t1, buf);
	d0 = d1;
	d1 = getd(t1, x);
}
matrix<2> ksmF(int x)
{
	if(x == 1) return mF;
	matrix<2> t = ksmF(x>>1);
	t *= t;
	if(x&1) t *= mF;
	return t;
}
matrix<3> ksmK(int x)
{
	if(x==1) return mK;
	matrix<3> t = ksmK(x>>1);
	t *= t;
	if(x&1) t *= mK;
	return t;
}
int getf(int x)
{
	if(!x||x==1) return 1;
	matrix<2> t = ksmF(x-1);
	return (t.m[1][0]+t.m[1][1])%p;
}
int getk(int x)
{
	if(!x||x==1) return x;
	if(x&1)
	{
		matrix<3> t = ksmK((x-1)>>1);
		return (t.m[1][1]+t.m[1][2])%p;
	}else
	{
		matrix<3> t = ksmK(x>>1);
		return (t.m[0][1]+t.m[0][2])%p;
	}
}
int solve(int cur)
{
	char buf[100100];
	strcpy(buf, t0);
	strcat(buf, t1);
	int da = ((fgetd(buf, strlen(t0))+d0)%p+d1)%p;
	if(n == ++cur) return da;
	snowclr(buf);
	strcpy(buf, t1);
	strcat(buf, t0);
	int db = fgetd(buf, strlen(t1));
	snowclr(buf);
	strcpy(buf, t1);
	strcat(buf, t1);
	int dc = fgetd(buf, strlen(t1));
	d0 = d1;
	d1 = da;
	return (((long long)d1*getf(n-cur)%p + (long long)d0*getf(n-cur-1)%p)%p + ((long long)db*getk(n-cur)%p+(long long)dc*getk(n-cur-1)%p)%p)%p;
}
int main()
{
#ifndef O233
	freopen("bugs.in", "r", stdin);
	freopen("bugs.out", "w", stdout);
#endif
	scanf("%d%d%d%s", &n, &m, &p, src);
	int i = 2;
	init();
	t0[0] = '0';
	t1[0] = '1';
	d0 = getd(t0, 0);
	d1 = getd(t1, 1);
	if(!n) {printf("%d\n", d0); return 0;}
	for(;i <= n && ((i&1) || F[i] < m);++i)
		pushs(i);
	if(i > n) {printf("%d\n", d1);return 0;}
	pushs(i);
	if(i == n){printf("%d\n", d1); return 0;}
	pushs(++i);
	if(i == n){printf("%d\n", d1); return 0;}
	printf("%d\n", solve(i));
	return 0;
}
