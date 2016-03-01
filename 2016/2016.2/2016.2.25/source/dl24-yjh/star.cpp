#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	
	scanf("%d",&n);
	if (n==3) printf("2 3");
		else printf("%d %d",n-1,n);
	
	return 0;
	}