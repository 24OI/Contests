#include <iostream>
#include <cstdio>

using namespace std;

int n,game=0,tail,l,t;
struct node
{
	int size,left;
}fish[10001];

int main()
{
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	scanf("%d",&n);
	tail=n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&fish[i].size);
		fish[i].left=i-1;
	}
	fish[1].left=-1;
	while (233)
	{
		l=tail;
		while (fish[l].size<fish[fish[l].left].size) l=fish[l].left;
		if (tail==l)
		{
			cout << game;
			return 0;
		}
		tail=l;
		l=fish[l].left;
		l++;
		while (l>1)
		{
			l--;t=l;
			while (fish[l].size<fish[fish[l].left].size) l=fish[l].left;
			fish[t+1].left=l;
		}
		game++;
	}
	return 0;
}
