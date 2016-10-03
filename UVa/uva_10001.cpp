/*
 * UVa problem: 10001
 *
 * Topic: Backtracking
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Given identifier, automaton, length, transfer the number to new state
 *   recover the number then if it is new, print reachable
 *
 * Solution Summary:
 *
 *   DFS, list all number before thansfer
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
#include <cstdio>
#define check_loop for(int i=0;i<8;i++)
#define machine(j) automaton[i][j]

using namespace std;

int automaton[8][3] = { { 0, 0, 0 },
                        { 0, 0, 1 },
                        { 0, 1, 0 },
                        { 0, 1, 1 },
                        { 1, 0, 0 },
                        { 1, 0, 1 },
                        { 1, 1, 0 },
                        { 1, 1, 1 } };

int identifier, length, number[33], convert[33], i;
char binary[32], code[10];
bool eden;

bool dfs( int pos ) {

	if ( length - 1 == pos || length == pos ) {

		check_loop

			if ( code[i] == number[pos] && convert[pos-1] == machine(0) &&
			     convert[pos] == machine(1) && convert[pos+1] == machine(2) ) {
				if ( pos == length - 1 && !dfs( pos + 1 ) ) return false;
				else return true;
			}

	} else {

		check_loop

			if ( code[i] == number[pos] && convert[pos-1] == machine(0) &&
			     convert[pos] == machine(1) ) {
				convert[pos + 1] = machine(2);
				if ( dfs( pos + 1 ) ) return true;
			}
	}

	return false;
}

int main() {

	while ( scanf("%d%d%s", &identifier, &length, binary ) != EOF ) {

		eden = true;

		for ( i = 0; i < length; i++ ) number[i + 1] = binary[i] - '0';

		check_loop {

			code[i] = identifier % 2;
			identifier /= 2;
		}

		check_loop

			if ( number[1] == code[i] ) {

				convert[0]          = machine(0);
				convert[1]          = machine(1);
				convert[2]          = machine(2);
				convert[length]     = machine(0);
				convert[length + 1] = machine(1);

				if ( dfs( 2 ) ) {
					eden = false;
					break;
				}
			}

		if ( !eden ) printf( "REACHABLE\n" );
		else printf( "GARDEN OF EDEN\n" );
	}

	return 0;
}
