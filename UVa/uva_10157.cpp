/* UVa problem: 10157
 *
 * Topic: Combinatorics
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Given n brakets, find the legal deep < d combinations
 *
 * Solution Summary:
 *
 *   Catalan, set constraint on depth.
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

using namespace std;

int length, depth, result, i, j, k, a, b;
int catalan[151][151][51], solution[51];

void build_catalan() {

	for ( i = 0; i < 151; i++ ) catalan[0][i][0] = 1;

	for ( i = 1; i < 151; i++ )
		for ( j = 1; j < 151; j++ )
			for ( k = 0; k < j; k++ ) {

				for ( a = 0; a < 25; a++ )
					for ( b = 0; b < 25; b++ )

						catalan[j][i][a + b] += 
						    catalan[k][i - 1][a] * catalan[j - k - 1][i][b];

				for ( a = 1; a <= 50; a++ ) {

					catalan[j][i][a] += catalan[j][i][a - 1] / 10000;
					catalan[j][i][a - 1] %= 10000;
				}
			}
}

int main() {

	build_catalan();

	while ( scanf( "%d%d", &length, &depth ) != EOF ) {

		for ( i = 0; i < 50; i++ )
			solution[i] = catalan[length / 2][depth][i] - 
			              catalan[length / 2][depth - 1][i];

		for ( i = 0; i < 50; i++ )

			while ( solution[i] < 0 ) {

				solution[i] += 10000;
				solution[i + 1] -= 1;
		}

		for ( i = 49; i > 0 && !solution[i]; i-- );

		printf( "%d", solution[i--] );
		while ( i >= 0 ) printf( "%04d", solution[i--] );

		printf( "\n" );
	}

	return 0;
}
