#include<cstdio>
using namespace std ;

const int MAXN = 100000 + 200 ;
const int MAXM = 100000 + 200 ;
int N , M ;
typedef unsigned long long uns ;
uns fi [ MAXN ] ;
const uns MOD = 1e9 + 1 ;
const uns MOD_L = MOD * 20 ;;
uns a [ MAXN ] ;

int main () {
	freopen ( "finbnacci.in" , "r" , stdin ) ;
	freopen ( "finbnacci.out" , "w" , stdout ) ;
	scanf ( "%d%d" , & N , & M ) ;
	fi [ 0 ] = 0 ;
	fi [ 1 ] = 1 ;
	for ( int i = 2 ; i <= N ; ++ i ) fi [ i ] = ( fi [ i - 1 ] + fi [ i - 2 ] ) % MOD ;
	for ( int i = 0 ; i < N ; ++ i ) scanf ( "%llu" , a + i ) ;
	while ( M -- ) {
		int opt , l , r ;
		scanf ( "%d%d%d" , & opt , & l , & r ) ;
		if ( opt == 1 ) {
			for ( int i = l ; i <= r ; ++ i ) {
				a [ i ] += fi [ i - l + 1 ] ;
				if ( a [ i ] > MOD_L ) a [ i ] %= MOD ;
			}
		} else {
			uns ans = 0 ;
			for ( int i = l ; i <= r ; ++ i ) ans += a [ i ] ;
			printf ( "%llu\n" , ans % MOD ) ;
		}
	}
	return 0 ;
}
