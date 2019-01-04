#include <iostream>

using namespace std;

int main() {

	int n, m, minimum, maximum;

	cin >> n >> m;

	minimum = n > m ? m : n;
	maximum = n > m ? n : m;

	for (int i = 0; i <= maximum - minimum; ++i)
		cout << minimum + 1 + i << endl;

	return 0;
}
