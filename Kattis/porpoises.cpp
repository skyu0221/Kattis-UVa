#include <iostream>
#include <cmath>

using namespace std;

void matmul( long long a[2][2], long long b[2][2] ) {

	long long c[2][2];

	c[0][0] = ( a[0][0] * b[0][0] + a[0][1] * b[1][0] ) % 1000000000;
	c[0][1] = ( a[0][0] * b[0][1] + a[0][1] * b[1][1] ) % 1000000000;
	c[1][0] = ( a[1][0] * b[0][0] + a[1][1] * b[1][0] ) % 1000000000;
	c[1][1] = ( a[1][0] * b[0][1] + a[1][1] * b[1][1] ) % 1000000000;

	a[0][0] = c[0][0];
	a[0][1] = c[0][1];
	a[1][0] = c[1][0];
	a[1][1] = c[1][1];
}

int main() {

	int       cases;

	cin >> cases;

	while ( cases-- ) {

		long long K, Y, mat[2][2]    = { {1, 1},
			                             {1, 0} },
			            result[2][2] = { {1, 0},
			                             {0, 1} };

		cin >> K >> Y;

		Y--;

		while ( Y > 0 ) {

			if ( Y % 2 == 1 )
				matmul( result, mat );

			matmul( mat, mat );
			Y /= 2ll;
		}

		cout << K << ' ' << result[0][0] << endl;
	}

	return 0;
}
