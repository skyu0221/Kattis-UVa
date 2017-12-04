#include <cstring>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define CLR(x,a) memset(x,a,sizeof(x))
#define BEND(v) (v).begin(),(v).end()
#define MP make_pair
#define PB push_back
#define A first
#define B second
#define dump(x) cerr << #x << " = " << (x) << endl
typedef long long ll; typedef long double ld;

const int inf = 0x20202020;

int dr[] = { 0, 1, 0, -1 },
    dc[] = { 1, 0, -1, 0 };

int R,C;
char grid[1000][1000];
int fd[1000][1000];
int jd[1000][1000];
void bfs(deque<pair<int,int> > &q, int (*d)[1000]) {
  while (q.size()) {
    int r = q.front().A, c = q.front().B;
    q.pop_front();

    FOR(k,4) {
      int r2 = r+dr[k], c2 = c+dc[k];
      if (r2<0 || r2>=R || c2<0 || c2>=C) continue;
      if (grid[r2][c2] == '#') continue;

      if (1+d[r][c] < d[r2][c2]) {
	d[r2][c2] = 1+d[r][c];
	q.PB(MP(r2,c2));
      }
    }
  }
}

int main() {
  scanf("%d%d",&R,&C);
  assert(1 <= R && R <= 1000);
  assert(1 <= C && C <= 1000);

  deque<pair<int,int> > fq,jq;
  CLR(fd,0x20);
  CLR(jd,0x20);
  FOR(r,R) {
    FOR(c,C) {
      char ch;
      scanf(" %c",&ch);

      grid[r][c] = ch;
      if (ch=='J') {
	jq.PB(MP(r,c));
	jd[r][c] = 0;
      } else if (ch=='F') {
	fq.PB(MP(r,c));
	fd[r][c] = 0;
      }
    }
  }
  assert(jq.size() == 1);

  bfs(fq,fd);
  bfs(jq,jd);

  int best = inf;
  #define TRYIT(r,c) if (grid[r][c] != '#' && jd[r][c] < fd[r][c]) if(best>jd[r][c]+1) best = jd[r][c]+1
  FOR(r,R) {
    TRYIT(r,0);
    TRYIT(r,C-1);
  }
  FOR(c,C) {
    TRYIT(0,c);
    TRYIT(R-1,c);
  }

  if (best < inf) {
    printf("%d\n",best);
  } else {
    printf("IMPOSSIBLE\n");
  }
}
/*
#include <iostream>
#include <cstring>
#include <cstdbool>
#include <iterator>

#define MAX 4294967295

using namespace std;

int one_move( int solver[2][1000][1000], int m, int n ) {

	bool alive = false;

	for ( int x = 0; x < m; x++ )
		for ( int y = 0; y < n; y++ ) {

			if ( solver[0][x][y] > 0 ) {

				if ( solver[1][x][y] == 0 )
					solver[1][x][y] = solver[0][x][y];

				if ( x > 0 &&
				     ( solver[0][x - 1][y] > solver[0][x][y] + 1 ||
				       solver[0][x - 1][y] == 0 ) &&
				     solver[0][x - 1][y] > -1 ) {
					solver[1][x - 1][y] = solver[0][x][y] + 1;
					alive = true;
				}
				if ( y > 0 &&
				     ( solver[0][x][y - 1] > solver[0][x][y] + 1 ||
				       solver[0][x][y - 1] == 0 ) &&
				     solver[0][x][y - 1] > -1 ) {
					solver[1][x][y - 1] = solver[0][x][y] + 1;
					alive = true;
				}
				if ( x < m - 1 &&
				     ( solver[0][x + 1][y] > solver[0][x][y] + 1 ||
				       solver[0][x + 1][y] == 0 ) &&
				     solver[0][x + 1][y] > -1 ) {
					solver[1][x + 1][y] = solver[0][x][y] + 1;
					alive = true;
				}
				if ( y < n - 1 &&
				     ( solver[0][x][y + 1] > solver[0][x][y] + 1 ||
				       solver[0][x][y + 1] == 0 ) &&
				     solver[0][x][y + 1] > -1 ) {
					solver[1][x][y + 1] = solver[0][x][y] + 1;
					alive = true;
				}
			} else if ( solver[0][x][y] == -2 ) {

				solver[1][x][y] = -2;

				if ( x > 0 &&
				     solver[0][x - 1][y] != -1 &&
				     solver[0][x - 1][y] != -2 )
					solver[1][x - 1][y] = -2;
				if ( y > 0 &&
				     solver[0][x][y - 1] != -1 &&
				     solver[0][x][y - 1] != -2 )
					solver[1][x][y - 1] = -2;
				if ( x < m - 1 &&
				     solver[0][x + 1][y] != -1 &&
				     solver[0][x + 1][y] != -2 )
					solver[1][x + 1][y] = -2;
				if ( y < n - 1 &&
				     solver[0][x][y + 1] != -1 &&
				     solver[0][x][y + 1] != -2 )
					solver[1][x][y + 1] = -2;

			} else if ( solver[0][x][y] == -1 )
				solver[1][x][y] = -1;
		}

	if ( !alive )
		return 0;

	memcpy( solver[0], solver[1], sizeof( solver[1] ) );

	for ( int i = 0; i < m; i++ )

		if ( solver[0][i][0] > 0 || solver[0][i][n - 1] > 0 ) {
			return 1;
		}

	for ( int i = 1; i < n - 1; i++ )

		if ( solver[0][0][i] > 0 || solver[0][m - 1][i] > 0 ) {
			return 1;
		}

	return -1;
}

int main() {

	int  m, n, solver[2][1000][1000], alive = -1, counter = 1;
	char table;
	bool possible = true;

	memset( solver, 0, sizeof( solver ) );

	cin >> m >> n;

	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < n; j++ ) {

			cin >> table;

			if ( table == '#' )
				solver[0][i][j] = -1;
			else if ( table == 'F' )
				solver[0][i][j] = -2;
			else if ( table == 'J' ) {
				solver[0][i][j] =  3;
				if ( i == 0 || j == 0 || i == m - 1 || j == n - 1 ) {
					possible = false;
					alive = 3;
				}
			}
		}

	*
	for ( int i = 0; i < m; i++ ) {
		for ( int j = 0; j < n; j++ )
			cout << solver[0][i][j] << '\t';
		cout << endl;
	}
	cout << "-------------------------" << endl;
	*

	while ( possible ) {

		alive = one_move( solver, m, n );

		*
		for ( int i = 0; i < m; i++ ) {
			for ( int j = 0; j < n; j++ )
				cout << solver[0][i][j] << '\t';
			cout << endl;
		}
		cout << "-------------------------" << endl;
		*

		counter++;

		if ( alive >= 0 )
			break;

		possible = false;

		for ( int i = 0; i < m; i++ )

			if ( solver[0][i][0] == 0 || solver[0][i][n - 1] == 0 ) {
				possible = true;
				continue;
			}

		for ( int i = 1; i < n - 1; i++ )

			if ( solver[0][0][i] == 0 || solver[0][m - 1][i] == 0 ) {
				possible = true;
				continue;
			}
	}

	if ( alive <= 0 )
		cout << "IMPOSSIBLE" << endl;
	else
		cout << counter << endl;

	return 0;
}
*/
