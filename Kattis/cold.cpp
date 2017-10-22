#include <iostream>

using namespace std;

int main() {

	int n, t, counter = 0;

	cin >> n;

	while ( n-- ) {

		cin >> t;

		if ( t < 0 )
			counter++;
	}

	cout << counter;

	return 0;
}
