#include <iostream>
#define MIN( a, b ) ( ( (a) < (b) ) ? (a) : (b) )
#define MAX( a, b ) ( ( (a) > (b) ) ? (a) : (b) )

using namespace std;

int main() {

	int A, B;
	char word[16] = "aaaaaaaaaaaaaaa", out[16] = "aaaaaaaaaaaaaaa";

	cin >> A >> B;

	A = MAX( A, ( B / 2 ) + 1 );

	A--;

	while ( A-- ) {

		B = A + 1;

		for ( int i = 14; i >= 0; i-- ) {

			out[i] = word[i] + B % 26;
			B      = B / 26;

			if ( B == 0 && i != 0 ) {

				out[i - 1] = 'a';
				break;
			}
		}

		cout << out << ' ';
	}

	cout << word << endl;

	return 0;
}
