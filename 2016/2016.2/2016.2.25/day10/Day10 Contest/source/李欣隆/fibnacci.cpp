#include <iostream>
#include <stdio.h>
#define mod 1000000001

using namespace std;

int f[100000 + 2];
int a[100000 + 2];
int n , m;
int k , l , r;

int main()
{
	freopen( "fibnacci.in" , "r" , stdin );
	freopen( "fibnacci.out" , "w" , stdout );
	scanf( "%d %d" , &n , &m );
	f[1] = 1;
	for( register int i = 2 ; i <= n ; i++ )
		f[i] = ( f[i - 1] + f[i - 2] ) % mod;
	for( register int i = 1 ; i <= n ; i++ )
		scanf( "%d" , &a[i] );
	while( m-- )
	{
		scanf( "%d %d %d" , &k , &l , &r );
		if( k == 1 )
			for( register int i = l ; i <= r ; i++ )
			{
				a[i] += f[i - l + 1];
				if( a[i] >= mod ) a[i] -= mod;
			}
		else
		{
			register int ans = 0;
			for( register int i = l ; i <= r ; i++ )
			{
				ans += a[i];
				if( ans >= mod ) ans -= mod;
			}
			printf( "%d\n" , ans );
		}
	}
	return 0;
}
