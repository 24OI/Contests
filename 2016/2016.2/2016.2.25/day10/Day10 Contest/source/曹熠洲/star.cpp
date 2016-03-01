#include<cstdio>
#include<climits>
#include<algorithm>
//#define DEBUG
using namespace std ;

typedef long long uns ;
const double INF = ( double ) LONG_LONG_MAX * LONG_LONG_MAX * LONG_LONG_MAX * LONG_LONG_MAX * LONG_LONG_MAX ;

struct LINE {
	uns A , B , C ;
	void LINE_SCANF () {
		scanf ( "%lld%lld%lld" , & A , & B , & C ) ;
	}
} ;

bool DO_SHARE_POINT ( const LINE & o1 , const LINE & o2 , const LINE & o3 ) {
	#define A(a) o##a.A
	#define B(a) o##a.B
	#define C(a) o##a.C
	return A(2)*C(1)*B(3) + A(1)*C(3)*B(2) + A(3)*C(2)*B(1) == A(2)*C(3)*B(1)+A(1)*C(2)*B(3)+A(3)*C(1)*B(2);
}
#undef A
#undef B
#undef C

double GET_X ( const LINE & a , const LINE & b ) {
	return ( a . A * b . B != b . A * a . B ) ? - ( double ) ( a . B * b . C - b . B * a . C ) / ( b . A *a. B - a . A * b . B) : INF ;
}

const int MAXN = 1000 + 20 ;
int N ;
LINE l [ MAXN ] ;

int _SORT [ MAXN ] ;
double _X [ MAXN ] ;

struct cmp {
	bool operator () ( const int a , const int b ) {
		return _X [ a ] < _X [ b ] ;
	}
} ;

int pa [ MAXN * MAXN ] ;
int size [ MAXN * MAXN ] ;
int MAX_SIZE ;
int CNT ;
int findpa ( const int a ) {
	#ifdef DEBUG
	//printf ( "pa [ %d ] == %d\n" , a , pa [ a ] ) ;
	#endif
	return pa [ a ] == a ? a : pa [ a ] = findpa ( pa [ a ] ) ;
}

void Union ( int a , int b ) {
	#ifdef DEBUG
	printf ( "Union (%d,%d) (%d,%d)\n" , a / N , a % N , b / N , b % N ) ;
	#endif
	a = findpa ( a ) ; b = findpa ( b ) ;
	if ( a == b ) return ;
	if ( size [ b ] > size [ a ] ) swap ( a , b ) ;
	#ifdef DEBUG
	printf ( "%d %d\n" , size [ a ] , size [ b ] ) ;
	#endif
	pa [ b ] = a ; size [ a ] += size [ b ] ;
	if ( size [ a ] > MAX_SIZE ) {
		MAX_SIZE = size [ a ] ;
		CNT = 1 ;
	} else if ( size [ a ] == MAX_SIZE ) CNT ++ ;
}

int GET_BACK ( ) {
	#ifdef DEBUG
	printf ( "MAX_SIZE = %d\n" , MAX_SIZE ) ;
	#endif
	int ans = 1 ;
	while ( ans * ( ans - 1 ) / 2 < MAX_SIZE ) ans ++ ;
	return ans ;
}

int main () {
	freopen ( "star.in" , "r" , stdin ) ;
	freopen ( "star.out" , "w" , stdout ) ;
	scanf ( "%d" , & N ) ;
	for ( int i = 0 ; i < N ; ++ i ) l [ i ] . LINE_SCANF () ;
	
	for ( int i = 0 ; i < N ; ++ i ) 
	
		for ( int j = i + 1 ; j < N ; ++ j ) {
			pa [ i * N + j ] = i * N + j ;
			size [ i * N + j ] = 1 ;
		}
	for ( int i = 0 ; i < N ; ++ i ) {
		for ( int j = i + 1 ; j < N ; ++ j ) {
			const LINE & a = l [ i ] ;
			const LINE & b = l [ j ] ;
			CNT += ( a . A * b . B != b . A * a . B ) ;
		}
	}
	MAX_SIZE = 1 ;	
		
	for ( int i = 0 ; i < N ; ++ i ) {
		for ( int j = i + 1 ; j < N ; ++ j ) {
			_SORT [ j - i - 1 ] = j ;
			_X [ j ] = GET_X ( l [ i ] , l [ j ] ) ;
		}
		
		sort ( _SORT , _SORT + N - i - 1 , cmp () ) ; 
		
		for ( int j = 1 ; j < N - i - 1 ; ++ j ) {
			const int a = _SORT [ j ] ;
			const int b = _SORT [ j - 1 ] ;
			#ifdef DEBUG
			//printf ( "haah %d\n" , a ) ;
			#endif
			if ( _X [ a ] == INF ) break ;
			if ( DO_SHARE_POINT ( l [ i ] , l [ a ] , l [ b ] ) ) {
				Union ( i * N + a , i * N + b ) ;
				Union ( min ( a , b ) * N + max ( a , b ) , i * N + a ) ;
			}
		}
	}
	
	const int MAX_LIGHT = GET_BACK ( ) ;
	printf ( "%d %d\n" , MAX_LIGHT , CNT ) ;
}

