/* UVa problem: 10278
 *
 * Topic: Graphs
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Add a fire station reduce the maximum distance.
 *
 * Solution Summary:
 *
 *   SPFA or floyd_warchall can solve the problem
 *
 * Used Resources:
 *
 *   https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

int cases, stations, station[101], node, graph[501][501], length[501];
int a, b, road, i, j, k, maximum, intersection;
string line;
istringstream iss;

void floyd_warshall() {

	for ( k = 1; k <= node; k++ )

		for ( i = 1; i <= node; i++ )

			for ( j = 1; j <= node; j++ )

				if ( graph[i][k] + graph[k][j] < graph[i][j] )

					graph[i][j] = 
					    graph[i][k] + graph[k][j];
}

int main() {

	cin >> cases;

	while ( cases-- ) {

		memset( graph, 0x1f, sizeof( graph ) );
		memset( length, 0x1f, sizeof( length ) );

		maximum = 0;

		cin >> stations >> node;

		for ( i = 0; i < stations; i++ ) cin >> station[i];

		for ( i = 1; i <= node; i++ ) graph[i][i] = 0;

		cin.ignore();

		while ( getline( cin, line ), line.length() ) {

			iss.clear();
			iss.str( line );
			iss >> a >> b >> road;
			graph[a][b] = road;
			graph[b][a] = road;
		}

		floyd_warshall();

		for ( i = 1; i <= node; i++ ) {

			for ( j = 0; j < stations; j++ )
				if ( graph[i][station[j]] < length[i] )
					length[i] = graph[i][station[j]];

			if ( length[i] > maximum ) maximum = length[i];
		}

		intersection = 1;

		for ( i = 1; i <= node; i++ ) {

			int shorter = 0;

			for( j = 1; j <= node; j++ )
				shorter = max( shorter, 
				          min( graph[i][j], length[j] ) );

			if ( shorter < maximum ) {

				maximum = shorter;
				intersection = i;
			}
		}

		cout << intersection << endl;

		if ( cases ) cout << endl;
	}
	return 0;
}
