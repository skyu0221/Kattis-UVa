/* UVa problem: 11955
 *
 * Topic: Arithmetic
 *
 * Level: 1 point
 * 
 * Brief problem description: 
 *
 *   ...
 *
 * Solution Summary:
 *
 *   Mainly math problem
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
#include <string>
#include <sstream>

using namespace std;

long long C( int i, int k ) {

	long long result = 1;

	if ( i > k / 2 ) i = k - i;

	for ( int j = 0; j < i; j++ ) {
		result = result * ( k - j ) / ( j + 1 );
	}

	return result;

}

int main() {

	int test_case;
	cin >> test_case;

	for ( int i = 0; i < test_case; i++ ) {

		string line, a, b, c;
		stringstream ss;
		int power;

		cin >> line;

		a = line.substr( 1, line.find('+') - 1 );
		b = line.substr( line.find('+') + 1, 
			line.find(')') - line.find('+') - 1 );
		ss << line.substr( line.find('^') + 1 );
		ss >> power;

		cout << "Case " << i + 1 << ": ";

		for ( int j = 0; j < power + 1; j++ ) {


			if ( C(j,power) != 1 ) {
				cout << C(j,power) << "*";
			}

			if ( j != power ) {
				cout << a;
				if ( power - j != 1 ) {
					cout << "^" << power - j;
				}
			}

			if ( j != 0 && j != power ) cout << "*";

			if ( j != 0 ) {
				cout << b;
				if ( j != 1 ) {
					cout << "^" << j;
				}
			}

			if ( j != power ) cout << "+";

		}

		cout << endl;

	}

	return 0;

}
