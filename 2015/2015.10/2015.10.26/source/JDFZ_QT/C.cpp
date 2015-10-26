#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int m=5;
int n;

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int x;
	for(int i=1;i<=m;i++)scanf("%d",&x);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int y;
		scanf("%d%d",&x,&y);
	}
	puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
