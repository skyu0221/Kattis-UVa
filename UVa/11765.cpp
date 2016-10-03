/* UVa problem: 11765
 *
 * Topic: Graph
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find the minimum cost of placing component
 *
 * Solution Summary:
 *
 *   Python got TLE, same code in python.
 *   Maxflow, min-cut
 *
 * Used Resources:
 *
 *   https://github.com/UAPSPC/Code-Archive/blob/master/graph/maxflow.cc
 *   @Morris
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 */
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Edge {

	long long source;
	long long target;
	long long cap;
	long long next;
};

Edge edge[100001];
long long head[100001], direction[100001], stack[100001], cur[100001];
long long position, top, i, solution, flow, minimum, cases;
long long component, interconnection, a[100001], b[100001], c[100001];

void addEdge( long long u, long long v, long long cap ) {

	Edge tmp = { u, v, cap, head[u] };
	edge[position] = tmp;
	head[u]        = position;
	position      += 1;

	Edge tmp2 = { v, u, 0, head[v] };
	edge[position] = tmp2;
	head[v]        = position;
	position      += 1;
}

bool BFS( long long source, long long target ) {

	memset( direction, -1, sizeof( direction ) );
	direction[source] = 0;

	queue<long long> mark;
	long long u, v;
	mark.push( source );

	while ( !mark.empty() ) {

		u = mark.front();
		mark.pop();

		i = head[u];
		while ( i != -1 ) {

			v = edge[i].target;

			if ( direction[v] == -1 && edge[i].cap ) {

				direction[v] = direction[u] + 1;
				mark.push( v );

				if ( direction[target] != -1 )
					return true;
			}

			i = edge[i].next;
		}
	}
	return false;
}

long long maxflowDinic( long long source, long long target ) {

	solution = 0;
	long long u;

	while ( BFS( source, target ) ) {

		memcpy( cur, head, sizeof( head ) );
		u   = source;
		top = 0;

		while ( true ) {

			if ( u == target ) {

				flow = 0x3f3f3f3f;

				for ( i = 0; i < top; i++ ) {

					if ( flow > edge[stack[i]].cap ) {

						flow    = edge[stack[i]].cap;
						minimum = i;
					}
				}

				for ( i = 0; i < top; i++ ) {

					edge[stack[i]].cap     -= flow;
					edge[stack[i] ^ 1].cap += flow;
				}

				solution += flow;
				top       = minimum;
				u         = edge[stack[top]].source;
			}

			i = cur[u];
			while ( i != -1 ) {

				if ( edge[i].cap && \
				    direction[u] + 1 == direction[edge[i].target] )
					break;

				i      = edge[i].next;
				cur[u] = i;
			}

			if ( cur[u] != -1 ) {

				stack[top] = cur[u];
				u          = edge[cur[u]].target;
				top       += 1;

			} else {

				if ( top == 0 )
					break;

				direction[u] = -1;
				top         -= 1;
				u            = edge[stack[top]].source;
			}
		}
	}
	return solution;
}

int main() {

	cin >> cases;

	while ( cases-- ) {

		cin >> component >> interconnection;

		long long source, target, p, q, cost;

		position = 0;
		memset( edge, 0, sizeof( edge ) );
		memset( head, -1, sizeof( head ) );
		memset( stack, -1, sizeof( stack ) );
		source   = 0;
		target   = component + 10;

		for ( i = 0; i < component; i++ ) cin >> a[i];
		for ( i = 0; i < component; i++ ) cin >> b[i];
		for ( i = 0; i < component; i++ ) cin >> c[i];

		for ( i = 0; i < component; i++ ) {

			if ( c[i] == 1 ) {
				addEdge( source, i + 1, a[i] );
				addEdge( i + 1, target, 0x3f3f3f3f );
			} else if ( c[i] == -1 ) {
				addEdge( source, i + 1, 0x3f3f3f3f );
				addEdge( i + 1, target, b[i] );
			} else {
				addEdge( source, i + 1, a[i] );
				addEdge( i + 1, target, b[i] );
			}
		}

		for ( i = 0; i < interconnection; i++ ) {

			cin >> p >> q >> cost;
			addEdge( p, q, cost );
			addEdge( q, p, cost );
		}

		cout << maxflowDinic( source, target ) << endl;
	}
	return 0;
}
