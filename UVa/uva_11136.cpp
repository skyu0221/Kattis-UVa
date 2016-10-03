/* UVa problem: 11136
 *
 * Topic: Data Structure
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find the sum of the difference between largest and smallest.
 *
 * Solution Summary:
 *
 *   Tried vector and Python before. But received TE. After several
 *   try, multiset works the best. Number mighb be big so use long long.
 *   In multiset it will sort automatically so just find the difference
 *   between first and last element. Then erase it.
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
#include <set>

using namespace std;

int main() {

	long long days;
	cin >> days;

	while ( days != 0 ) {

		long long num_of_bill, promotion = 0, bill;
		multiset<long long> bills;
		bills.clear();

		for ( int i = 0; i < days; i++ ) {

			cin >> num_of_bill;

			for ( int j = 0; j < num_of_bill; j++ ) {

				cin >> bill;
				bills.insert( bill );

			}

			multiset<long long>::iterator it;

			it         = bills.begin();
			promotion -= *it;
			it         = bills.end();
			promotion += *(--it);

			bills.erase( it );
			bills.erase( bills.begin() );

		}

		cout << promotion << endl;
		cin >> days;

	}

	return 0;

}
