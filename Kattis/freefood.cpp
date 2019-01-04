#include <iostream>

using namespace std;

int main() {

	int n, total = 0, counter[366] = {0}, s, t;

	cin >> n;

	while (n--) {

		cin >> s >> t;

		for (int i = s; i <= t; ++i) {
			if (!counter[i]++)
				total++;
		}
	}

	cout << total << endl;

	return 0;
}
