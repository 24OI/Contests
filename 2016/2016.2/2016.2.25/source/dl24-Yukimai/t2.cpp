#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define RD rand()/(double)RAND_MAX
using namespace std;
struct line{int a, b, c;bool operator==(const line &rhs)const{return a == rhs.a && b == rhs.b && c == rhs.c;}} night[1100];
int gcd(int a, int b){return b?gcd(b, a%b):a;}
void yuefen(line &l)
{
	int g = gcd(l.a, l.b);
	g = gcd(g, l.c);
	l.a/=g;
	l.b/=g;
	l.c/=g;
}
int rando(int b, int e)
{
	int r = RD*(e-b);
	return r+b;
}
int main(int argc, char **argv)
{
#ifndef snowoi
	srand(time(0)+atoi(argv[1]));
#endif
#ifdef snowoi
	freopen("star.in", "w", stdout);
	srand(time(0));
#endif
	puts("300");
	for(int i = 1; i <= 300; ++i)
	{
		bool ok = true;
		line nw;
		nw.a = rando(-1000, 1000);
		nw.b = rando(-1000, 1000);
		nw.c = rando(-100000000, 100000000); 
		yuefen(nw);
		for(int j = 1; j < i; ++j)
			if(night[j] == nw){--i;break;ok = false;}
		if(!ok) continue;
		printf("%d %d %d\n", nw.a, nw.b, nw.c);
		night[i] = nw;
	}
	return 0;
}

