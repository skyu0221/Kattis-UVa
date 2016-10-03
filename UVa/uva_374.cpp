/* UVa problem: 374
 *
 * Topic: Big Mod
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find the number = B^P mod M
 *
 * Solution Summary:
 *
 *   In math, B^P mod M = ( B^(P-1) mod M * B ) mod M.
 *   So, convert P to binary.
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

#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

long long B, P, M, result;
int i;
string bin;

int main() {

	while ( scanf( "%lld%lld%lld", &B, &P, &M ) != EOF ) {

		result = 1, i = 0;

		bin = bitset<32>(P).to_string();

		while ( bin[i] != '1' ) i++;

		for ( ; i < 32; i++ ) {

			result = ( result * result ) % M;

			if ( bin[i] == '1' ) result = ( result * B ) % M;
		}

		cout << result << endl;

	}

	return 0;
}
