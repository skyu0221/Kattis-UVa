#include <iostream>
#define MIN( a, b ) ( ( (a) < (b) ) ? (a) : (b) )
#define MAX( a, b ) ( ( (a) > (b) ) ? (a) : (b) )

using namespace std;

int main() {

	int cases, x1, y1, x2, y2;
	char c1, c2;

	cin >> cases;

	while ( cases-- ) {

		cin >> c1 >> y1 >> c2 >> y2;

		x1 = c1 - 'A';
		x2 = c2 - 'A';

		if ( ( x1 + y1 ) % 2 != ( x2 + y2 ) % 2 )
			cout << "Impossible" << endl;
		else if ( x1 == x2 && y1 == y2 )
			cout << 0 << ' ' << c1 << ' ' << y1 << endl;
		else if ( abs( x1 - x2 ) == abs( y1 - y2 )  )
			cout << 1 << ' ' << c1 << ' ' << y1 << ' '
			                 << c2 << ' ' << y2 << endl;
		else if ( y1 - y2 + x1 + x2 <= 14 && x1 - x2 + y1 + y2 <= 16 &&
		          y1 - y2 + x1 + x2 >= 0  && x1 - x2 + y1 + y2 > 0 )
			cout << 2 << ' ' << (char)( x1 + 'A' ) << ' ' << y1 << ' '
			                 << (char)( ( y1 - y2 + x1 + x2 ) / 2 + 'A' )
                             << ' '
			                 << ( x1 - x2 + y1 + y2 ) / 2 << ' '
			                 << (char)( x2 + 'A' ) << ' ' << y2 << endl;
		else
			cout << 2 << ' ' << (char)( x1 + 'A' ) << ' ' << y1 << ' '
			                 << (char)( ( y2 - y1 + x1 + x2 ) / 2 + 'A' )
                             << ' '
			                 << ( x2 - x1 + y1 + y2 ) / 2 << ' '
			                 << (char)( x2 + 'A' ) << ' ' << y2 << endl;
	}

	return 0;
}
