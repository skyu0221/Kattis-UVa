/* UVa problem: 11327
 *
 * Topic: Number Theory
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find the nth enumerating rational number
 *
 * Solution Summary:
 *
 *   Get the eular table first, then find the start point do sequence search
 *
 * Used Resources:
 *
 *   http://www.xuebuyuan.com/2063340.html
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 */
#include <iostream>

using namespace std;

int i, j, eular_table[200001];
long long position, partition;

void eular() {

	for ( i = 2; i < 200001; i++ )

		if ( !eular_table[i] )
			for ( j = i; j < 200001; j += i ) {

				if ( !eular_table[j] ) eular_table[j] = j;
				eular_table[j] -= eular_table[j] / i;
			}
}

long long gcd( long long a, long long b ) {

	return b == 0 ? a : gcd( b, a % b );
}

int main() {

	eular();

	while ( cin >> position && position != 0 ) {

		if ( position <= 2 ) cout << position - 1 << "/1" << endl;
		else {

			position -= 2;
			partition = 2;
			i         = 1;

			while ( position > 0 ) position -= eular_table[partition++];
			position += eular_table[--partition];

			while ( position != 0 )
				if ( gcd( i++, partition ) == 1 )
					position--;

			cout << --i << "/" << partition << endl;
		}
	}
	return 0;
}
