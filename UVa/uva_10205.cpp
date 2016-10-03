/*
 * UVa problem: 10205
 *
 * Topic: Data Structure
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Given poker's order and the the shuffle way, print the final cards order
 *
 * Solution Summary:
 *
 *   Simulate the shuffle
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
 *
 */
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char value[13][6] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", 
                      "Jack", "Queen", "King", "Ace" };
char suit[4][9]  = { "Clubs", "Diamonds", "Hearts", "Spades" };
char line[20];
int cases, shuffles, shuffle[101][53], order[53], tmp[53];
int i, j, k;

int main() {

	cin >> cases;

	while ( cases-- ) {

		memset( shuffle, 0, sizeof( shuffle ) );
		for ( i = 1; i <= 52; i++ ) order[i] = i;

		cin >> shuffles;

		for ( i = 1; i <= shuffles; i++ )
			for ( j = 1; j <= 52; j++ )
				cin >> shuffle[i][j];

		getchar();

		while ( gets(line) && strlen( line ) ) {

			sscanf( line, "%d", &shuffles );
			for ( i = 1; i <= 52; i++ ) tmp[i] = order[i];
			for ( i = 1; i <= 52; i++ ) order[i] = tmp[shuffle[shuffles][i]];
		}

		for ( i = 1; i <= 52; i++ )
			cout << value[( order[i] - 1 ) % 13] << " of " <<
			suit[( order[i] - 1 ) / 13 ] << endl;

		if ( cases ) cout << endl;
	}
	return 0;
}
