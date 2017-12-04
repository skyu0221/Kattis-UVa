#include <iostream>

using namespace std;

void floodfill( char table[100][100], int x, int y, int m, int n, int c ) {

	table[x][y] = '#';

	if ( x > 0 && table[x - 1][y] == '-' )
		floodfill( table, x - 1, y, m, n, c );
	if ( y > 0 && table[x][y - 1] == '-' )
		floodfill( table, x, y - 1, m, n, c );
	if ( x < m - 1 && table[x + 1][y] == '-' )
		floodfill( table, x + 1, y, m, n, c );
	if ( y < n - 1 && table[x][y + 1] == '-' )
		floodfill( table, x, y + 1, m, n, c );
}

int main() {

	int  m, n, counter, loop = 1;
	char table[100][100];

	while ( cin >> m >> n ) {

		counter = 0;

		for ( int i = 0; i < m; i++ )
			cin >> table[i];

		for ( int i = 0; i < m; i++ )
			for ( int j = 0; j < n; j++ )
				if ( table[i][j] == '-' )
					floodfill( table, i, j, m, n, counter++ );

		cout << "Case " << loop++ << ": " << counter << endl;;
	}

	return 0;
}
