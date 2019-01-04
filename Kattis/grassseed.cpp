#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int l;
	double c, w_i, l_i, result = 0;

	cin >> c >> l;

	while (l--) {

		cin >> w_i >> l_i;
		result += w_i * l_i * c;
	}

	cout << setprecision(7) << fixed << result << endl;

	return 0;
}
