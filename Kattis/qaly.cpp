#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int line;
	double sum = 0, q, y;

	cin >> line;

	while (line--) {

		cin >> q >> y;
		sum += q * y;
	}

	cout << fixed << setprecision(3) << sum << endl;
	return 0;
}
