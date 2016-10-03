/* UVa problem: 11419
 *
 * Topic: Bipartite Graphs
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find the smallest number of shot to kill all enemy on 2D board.
 *
 * Solution Summary:
 *
 *   Consider row and column to two group and link them. Each line can
 *   consider as a point. Find the less point that can cover all lines.
 *   Use DFS find max pair and do DFS again to pair missed points.
 *
 * Used Resources:
 *
 *   https://en.wikipedia.org/wiki/K%C5%91nig%27s_theorem_(graph_theory)
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int         x[1001],      y[1001],      count;
bool        visitx[1001], visity[1001];
vector<int> points[1001];

bool dfs( int node ) {

	visitx[node] = true;

	for ( int i = 0; i < points[node].size(); i++ ) {

		int neighbour = points[node][i];

		if ( !visity[neighbour] ) {

			visity[neighbour] = true;

			if ( x[neighbour] == -1 || dfs( x[neighbour] ) ) {

				x[neighbour] = node;
				y[node]      = neighbour;

				return true;
			}
		}
	}

	return false;
}

int main() {

	int row, col, a, b;
	long long point;
	cin >> row >> col >> point;

	while ( row && col && point ) {

		count = 0;
		memset( x,      -1,    sizeof(x) );
		memset( y,      -1,    sizeof(y) );
		memset( visitx, false, sizeof(visitx) );

		for ( int i = 1; i <= row; i++ ) points[i].clear();

		while ( point-- ) {
			cin >> a >> b;
			points[a].push_back( b );
		}

		for ( int i = 1; i <= row; i++ ) {
			memset( visity, false, sizeof(visity) );
			if ( dfs( i ) ) count++;
		}

		cout << count;

		memset( visitx, false, sizeof(visitx) );
		memset( visity, false, sizeof(visity) );

		for ( int i = 1; i <= row; i++ )
			if ( y[i] == -1 ) dfs( i );

		for ( int i = 1; i <= row; i++ )
			if ( !visitx[i] ) cout << " r" << i;

		for ( int i = 1; i <= col; i++ )
			if ( visity[i] ) cout << " c" << i;

		cout << endl;

		cin >> row >> col >> point;
	}

}
