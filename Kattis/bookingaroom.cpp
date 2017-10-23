#include <iostream>
#include <cstring>

using namespace std;

int main() {

	int r, n, room[101], booked, i = 0;

	memset( room, 0, sizeof( room ) );

	cin >> r >> n;

	while ( n-- ) {

		cin >> booked;

		room[booked - 1] = 1;
	}

	while ( room[i++] );

	if ( i - 1 >= r )
		cout << "too late" << endl;
	else
		cout << i << endl;

	return 0;
}
