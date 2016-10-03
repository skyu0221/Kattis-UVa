/*
 * UVa problem: 701
 *
 * Topic: Arithmetic
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Given N, find E such that N * 10^y <= 2^E < ( N + 1 ) * 10^y, E is integer
 *
 * Solution Summary:
 *
 *   Use math to convert the inequation to
 *   log2(N) + y * log2(10) ≤ E < log2( N + 1 ) + y * log2(10)
 *
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 *
 */
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long number, a, b;
char num[10];
int i;

int main() {

	while ( scanf( "%lld", &number ) != EOF ) {

		sprintf( num, "%lld", number );

		i = strlen( num );

		while ( i++ ) {

			a = ceil( log2( number ) + i * log2(10) );
			b = floor( log2( number + 1 ) + i * log2(10) );

			if ( a <= b ) {
				printf( "%lld\n", a );
				break;
			} else if ( i == 99999999) {
				printf( "no power of 2\n" );
				break;
			}	
		}
	}

	return 0;
}
