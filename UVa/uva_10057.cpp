/* UVa problem: 10057
 *
 * Topic: Arithmetic
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Find A makes the sum of distance between points to A smallest
 *
 * Solution Summary:
 *
 *   Find the median, count how many numbers within median region
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
 */
#include <cstdio>
#include <algorithm>

using namespace std;

long long numbers, number[1000000], i, result, a, b, counter;

int main() {

	while ( scanf( "%lld", &numbers ) != EOF ) {

		counter = 0;

		for ( i = 0; i < numbers; i++ ) scanf( "%lld", &number[i] );

		sort( number, number + numbers );

		b = number[numbers / 2];

		if ( numbers % 2 == 1 ) a = number[numbers / 2];
		else a = number[numbers / 2 - 1];

		result = b - a + 1;

		for ( i = numbers / 2; i < numbers; i++ )
			if ( number[i] == b ) counter++;
			else break;
		for ( i = numbers / 2 - 1; i >= 0; i-- )
			if ( number[i] >= a ) counter++;
			else break;

		printf( "%lld %lld %lld\n", a, counter, result );

	}
	
	return 0;
} 
