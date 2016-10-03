/* UVa problem: 10034
 *
 * Topic: Graphs
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Find the smallest length of line link all nodes
 *
 * Solution Summary:
 *
 *   MST, use prim algorithm 
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
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

struct Freckle {

	double x;
	double y;
};

int cases, node;
double graph[100][100], sum = 0;
Freckle freckles[100];

void prim() {

	double key[node];
	bool visit[node];

	memset( visit, false, sizeof( visit ) );

	visit[0] = true;

	for ( int i = 0; i < node; i++ ) key[i] = graph[0][i];

	for ( int i = 0; i < node; i++ ) {

		int next = -1;
		double min = INT_MAX;
		for ( int j = 0; j < node; j++ ) {

			if ( key[j] < min && !visit[j] ) {

				next = j;
				min = key[j];
			}
		}

		if ( next == -1 ) break;

		sum += min;
		visit[next] = true;

		for ( int j = 0; j < node; j++ )
			if( graph[next][j] < key[j] ) key[j] = graph[next][j];
	}
}

int main() {

	cin >> cases;

	while ( cases-- ) {

		cin >> node;

		memset( freckles, 0, sizeof( freckles ) );
		memset( graph, 0, sizeof( graph ) );
		sum = 0;

		for ( int i = 0; i < node; i++ ) cin >> freckles[i].x >> freckles[i].y;

		for ( int i = 0; i < node; i++ ) {
			for ( int j = i + 1; j < node; j++ ) {
				graph[i][j] = sqrt( pow( freckles[i].x - freckles[j].x, 2 ) + 
				                    pow( freckles[i].y - freckles[j].y, 2 ) );
				graph[j][i] = graph[i][j];
			}
		}

		prim();
		cout << fixed << setprecision(2) << sum << endl;
		if ( cases ) cout << endl;

	}
	return 0;
}
