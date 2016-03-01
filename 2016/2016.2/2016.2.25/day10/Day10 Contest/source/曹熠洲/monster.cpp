#include<cstdio>
using namespace std ;

typedef unsigned long long uns ;
const uns MOD = 593119681 ;
const uns MOD_L = MOD * 1024 ;
const uns MAXN = 20;
const uns MAXM = 1 << MAXN ;
int N , M ;
int T ;
uns v [ 2 ] [ MAXN ] ;
int cur = 0 ;

int main () {
	freopen ( "monster.in" , "r" , stdin ) ;
	freopen ( "monster.out" , "w" ,stdout ) ;
	scanf ( "%d%d" , & N , & T ) ;
	M = 1 << N ;
	for ( int i = 0 ; i < M ; ++ i ) scanf ( "%llu" , & v [ cur ] [ i ] ) ;
	while ( T -- ) {
		cur ^= 1 ;
		for ( int i = 0 ; i < M ; ++ i ) {
			uns * nxt = v [ cur ^ 1 ] ;
			register uns now = nxt /*v [ cur ^ 1 ]*/ [ i ] ;
			for ( register int j = 1 ; j < M ; j <<= 1 ) now += nxt /*v [ cur ^ 1 ]*/ [ i ^ j ] ;
			if ( now > MOD_L ) now %= MOD ;
			v [ cur ] [ i ] = now ;
		}
	}
	for ( int i = 0 ; i < M ; ++ i ) printf ( "%llu\n" , v [ cur ] [ i ] % MOD ) ;
	return 0 ;
}

