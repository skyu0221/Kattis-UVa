/* UVa problem: 11330
 *
 * Topic: Combinatorics
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   ...
 *
 * Solution Summary:
 *
 *   Assume one shoe is ordered, just sort another shoe.
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
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {

	int test_case;
	cin >> test_case;

	for ( int case_num = 0; case_num < test_case; case_num++ ) {

		int pairs, result = 0;
		int rack[10001];
		cin >> pairs;

		memset( rack, 0, sizeof(rack) );

		for ( int i = 0; i < pairs; i++ ) {
			int left, right;
			cin >> left >> right;
			if ( left != right ) {
				rack[left] = right;
			}
		}

		for ( int i = 1; i <= 10000; i++ ) {
			if ( rack[i] != 0 ) {
				int temp = rack[i], count = 0;
				rack[i] = 0;
				while ( rack[temp] != 0 ) {
					int next = rack[temp];
					count++;
					rack[temp] = 0;
					temp = next;
				}
				result += count;
			}
		}
		cout << result << endl;
	}

	return 0;

}
