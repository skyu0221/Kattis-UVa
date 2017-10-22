#include <iostream>

using namespace std;

int main() {

	char names[100];
	int  counter = 0;

	cin >> names;

	while ( names[counter++] )

		if ( names[counter - 1] >= 'A' && names[counter - 1] <= 'Z' )
			cout << names[counter - 1];

	return 0;
}
