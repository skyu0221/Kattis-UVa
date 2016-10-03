/* UVa problem: 11331
 *
 * Topic: Bipartite Graphs
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   ...
 *
 * Solution Summary:
 *
 *   2 Color problem. Try to draw graph in 2 colors.
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
#include <list>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

bool seen[2001];
int color[2001];
int current_color, color1, color2;
bool result = true;

void explore( list<int> *graph, int v ) {

	if ( current_color == 2 ) {
		current_color = 1;
		color1++;
	}
	else {
		current_color = 2;
		color2++;
	}
	color[v] = current_color;
	seen[v] = 1;
	for ( auto nbr: graph[v] ) {
		current_color = color[v];
		if ( !seen[nbr] )
			explore( graph, nbr );
		else if ( color[nbr] == color[v] ) {
			result = false;
			return;
		}
	}
}

int main() {

	int test_case;
	cin >> test_case;

	for ( int case_num = 0; case_num < test_case; case_num++ ) {

		int bull, cow, edge;
		cin >> bull >> cow >> edge;

		list<int> graph[2001];

		for ( int i = 0; i < edge; i++ ) {

			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);

		}
		// dfs
		int w1[bull+cow], w2[bull+cow], n = 0;
		memset( seen, false, sizeof( seen ) );
		current_color = 2;
		result = true;

		for ( int i = 1; i <= bull + cow; i++ ) {
			if ( !seen[i] && result ) {
				memset( color, 0, sizeof( color ) );
				color1 = 0;
				color2 = 0;
				explore( graph, i );
				w1[n] = color1;
				w2[n] = color2;
				n++;
			}
		}
		// end

		if ( !result ) {
			cout << "no" << endl;
			continue;
		}

		int dp[2][bull+cow+1], roll = 0, small;

		dp[0][0] = 1;

		small = min( bull, cow );

		for ( int i = 0; i < n; i++ ) {

		    memset( dp[!roll], 0, sizeof( dp[!roll] ) );

		    int ww1 = w1[i], ww2 = w2[i];
		    int min_of_two = min(ww1, ww2);

		    for ( int j = small; j >= min_of_two; j-- ) {

		        if(j-ww1 >= 0)    dp[!roll][j] |= dp[roll][j-ww1];
		        if(j-ww2 >= 0)    dp[!roll][j] |= dp[roll][j-ww2];
		    }

		    roll = !roll;
		}

		puts( dp[roll][small] ? "yes" : "no");
	}

	return 0;

}
