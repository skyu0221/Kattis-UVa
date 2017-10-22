#include <iostream>

using namespace std;

double A, N, pi = 3.1415926;

int main() {


	cin >> A >> N;

	if ( A <= N * N / ( 4 * pi ) )
		cout << "Diablo is happy!" << endl;
	else
		cout << "Need more materials!" << endl;

	return 0;
}
