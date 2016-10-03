/* UVa problem: 202
 *
 * Topic: Arithmetic
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   ...
 *
 * Solution Summary:
 *
 *   Compare the numerator, if repeat, then a circle occurs.
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
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string line;

	while ( getline( cin, line ) ) {

		int a, b, i;
		vector<int> target;
		bool infinity = false;
		char number;
		string result = "";
		stringstream ss1, ss;

		ss1 << line;
		ss1 >> a >> b;

		cout << a << "/" << b << " = ";
		cout << floor( a/b ) << ".";

		a = a % b;
		target.push_back( a );

		while ( a != 0 ) {
			a *= 10;
			ss << floor( a/b );
			ss >> number;
			result += number;
			a = a % b;

			i = find( target.begin(), target.end(), a ) - target.begin();

			if ( i < target.size() ) {
				infinity = true;
				a = 0;
			} else target.push_back( a );

		}

		if ( infinity ) {
			if ( result.length() < 50 + i ) {
				cout << result.substr(0,i);
				cout << "(" << result.substr(i) << ")" << endl;
			} else {
				cout << result.substr(0,i);
				cout << "(" << result.substr(i,50-i) << "...)" << endl;
			}
			cout << "   " << result.length() - i;
			cout << " = number of digits in repeating cycle";
		} else {
			cout << result << "(0)" << endl;
			cout << "   1 = number of digits in repeating cycle";
		}

		cout << endl << endl;

	}
	return 0;
}
