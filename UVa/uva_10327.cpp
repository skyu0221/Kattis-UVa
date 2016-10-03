/* UVa problem: 10327
 *
 * Topic: Sorting
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Count the number of switch in bubble sort.
 *
 * Solution Summary:
 *
 *   Do bubble sort, then count.
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
#include <cstring>

using namespace std;

int number, numbers[1000], count, tmp;
int i, j;

int main() {

	while( scanf( "%d", &number ) != EOF ) {

		count = 0;
		memset( numbers, 0 , sizeof( numbers ) );

		for ( i = 0; i < number; i++ ) cin >> numbers[i];

		for ( i = 0; i < number; i++ ) {

			for ( j = number - 1; j > i; j-- ) {

				if ( numbers[j] < numbers[j - 1] ) {

					tmp = numbers[j];
					numbers[j] = numbers[j - 1];
					numbers[j - 1] = tmp;
					count++;
				}
			}
		}

		cout << "Minimum exchange operations : " << count << endl;
		cin.ignore();
	}

	return 0;
}
