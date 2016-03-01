#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#define mod 593119681

using namespace std;

int f[ ( 1 << 18 ) + 10 ];
int g[ ( 1 << 18 ) + 10 ];
int n , t;

int main()
{
	freopen( "monster.in" , "r" , stdin );
	freopen( "monster.out" , "w" , stdout );
	scanf( "%d %d" , &n , &t );
	for( register int i = 0 ; i < ( 1 << n ) ; i++ )
		scanf( "%d" , &f[i] );
	while( t-- )
	{
		memset( g , 0 , sizeof( g ) );
		for( register int i = 0 ; i < ( 1 << n ) ; i++ )
			for( register int j = 0 ; j < n ; j++ )
			{
				g[ i ^ ( 1 << j ) ] += f[i];
				if( g[ i ^ ( 1 << j ) ] >= mod ) g[ i ^ ( 1 << j ) ] -= mod;
			}
		for( register int i = 0 ; i < ( 1 << n ) ; i++ )
		{
			f[i] += g[i];
			if( f[i] >= mod ) f[i] -= mod;
		}
	}
	for( register int i = 0 ; i < ( 1 << n ) ; i++ )
		printf( "%d " , f[i] );
	return 0;
}
