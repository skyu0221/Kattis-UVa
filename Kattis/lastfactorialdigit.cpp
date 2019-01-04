#include <iostream>

using namespace std;

int main() {

	int line, result[] = {0, 1, 2, 6, 4, 0, 0, 0, 0, 0, 0}, q;

	cin >> line;

	while (line--) {

		cin >> q;
		cout << result[q] << endl;
	}

	return 0;
}
