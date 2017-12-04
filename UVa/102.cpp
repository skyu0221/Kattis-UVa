#include <iostream>
#include <string>

using namespace std;

int main() {

	long long b[3], g[3], c[3], result[6], min_label;
	char name[6][4] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

	while ( cin >> b[0] >> g[0] >> c[0] ) {

		cin >> b[1] >> g[1] >> c[1];
		cin >> b[2] >> g[2] >> c[2];

		min_label = 0;

		result[0] = b[1] + b[2] + c[0] + c[2] + g[0] + g[1];
		result[1] = b[1] + b[2] + g[0] + g[2] + c[0] + c[1];
		result[2] = c[1] + c[2] + b[0] + b[2] + g[0] + g[1];
		result[3] = c[1] + c[2] + g[0] + g[2] + b[0] + b[1];
		result[4] = g[1] + g[2] + b[0] + b[2] + c[0] + c[1];
		result[5] = g[1] + g[2] + c[0] + c[2] + b[0] + b[1];

		for ( int i = 1; i < 6; i++ )
			if ( result[min_label] > result[i] )
				min_label = i;

		cout << name[min_label] << ' ' << result[min_label] << endl;
	}

	return 0;
}
