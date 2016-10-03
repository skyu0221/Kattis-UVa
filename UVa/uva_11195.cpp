/* UVa problem: 11195
 *
 * Topic: Backtracking
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   find the number of possible placement in board.
 *
 * Solution Summary:
 *
 *   the diagonal line's number have same x+y and x-y. col have same x
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
#include <cstring>

using namespace std;

int result = 0, size = 0;
bool checker[3][29];
string table, tmp;

void set_queen( int row, int col, bool state ) {

    checker[0][col]       = state;
    checker[1][row - col] = state;
    checker[2][row + col] = state;
}

void tracking( int row ) {

	if ( row == size ) result++;
	else {

		for ( int i = 0; i < size; i++ ) {

			if ( table[row * size + i] != '*' &&
			     checker[0][i] &&
			     checker[1][row - i] &&
			     checker[2][row + i] ) {

				set_queen( row, i, false );
				tracking( row + 1 );
				set_queen( row, i, true );
			}
		}
	}
}

int main() {

	cin >> size;
	int cases = 1;

	while ( size != 0 ) {

		table.clear();
		result = 0;
		memset( checker, true, sizeof( checker ) );

		for ( int i = 0; i < size; i++ ) {
			cin >> tmp;
			table += tmp;
		}

		tracking( 0 );

		cout << "Case " << cases++ << ": " << result << endl;

		cin >> size;
	}

	return 0;
}
