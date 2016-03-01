#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mod 20000013

using namespace std;

long long gcd( long long a , long long b )
{
	if( !b ) return a;
	return gcd( b , a % b );
}

struct Node
{
	long long p[4] , value;
	Node * next;
	Node( long long a[] )
	{
		p[0] = a[0] , p[1] = a[1] , p[2] = a[2] , p[3] = a[3];
		value = 1;
		next = 0;
	}
	Node() {}
};

Node * h[20000000 + 20];
long long a[1000 + 2] , b[1000 + 2] , c[1000 + 2];
long long p[4] , n , ans , num , pos;

inline void deal()
{
	long long temp = 0;
	for( register int i = 0 ; i < 4 ; i++ )
	{
		temp = ( temp * 13331 + p[i] + 1000 );
		while( temp < 0 ) temp += 1000000ll * mod;
		temp %= mod;
	}
	bool flag = 0;
	for( register Node * cur = h[ temp ] ; cur ; cur = cur -> next )
		if( cur -> p[0] == p[0] && cur -> p[1] == p[1] && cur -> p[2] == p[2] && cur -> p[3] == p[3] )
		{
			flag = 1;
			cur -> value++;
			ans = max( ans , cur -> value );
			break;
		}
	if( !flag )
	{
		ans = max( ans , 1ll );
		register Node * cur;
		if( !h[ temp ] )
		{
			h[ temp ] = new Node( p );
			return;
		}
		for( cur = h[ temp ] ; cur -> next ; cur = cur -> next );
		cur -> next = new Node( p ); 
	}
	return;
}
			

int main()
{
	freopen( "star.in" , "r" , stdin );
	freopen( "star.out" , "w" , stdout );
	scanf( "%d" , &n );
	for( register int i = 1 ; i <= n ; i++ )
		scanf( "%lld %lld %lld" , &a[i] , &b[i] , &c[i] );
	for( register int i = 1 ; i <= n ; i++ )
		for( register int j = i + 1 ; j <= n ; j++ )
		{
			p[0] = a[i] * b[j] - a[j] * b[i];
			p[1] = a[j] * c[i] - a[i] * c[j];
			p[2] = a[j] * b[i] - a[i] * b[j];
			p[3] = b[j] * c[i] - b[i] * c[j];
			if( !p[0] || !p[2] ) continue;
			long long a = gcd( p[0] , p[1] ) , b = gcd( p[2] , p[3] );
			p[0] /= a , p[1] /= a , p[2] /= b , p[3] /= b;
			deal();
		}
	for( register int i = 0 ; i < mod ; i++ )
		for( register Node * cur = h[i] ; cur ; cur = cur -> next )
			if( cur -> value == ans )
				num++;
	if( !ans )
	{
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	for( register int i = 1 ;  ; i++ )
		if( i * ( i - 1 ) / 2 == ans )
		{
			cout << i << " " << num << endl;
			break;
		}
	return 0;
}
