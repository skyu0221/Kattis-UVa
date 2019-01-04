#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	unsigned int n, total = 0;
	int b, card, suit, mapper[256];

	mapper['A'] = 11;
	mapper['K'] = 4; 
	mapper['Q'] = 3;
	mapper['J'] = 2;
	mapper['T'] = 10;
	mapper['9'] = 0;
	mapper['8'] = 0;
	mapper['7'] = 0;

	cin >> n;

	getchar();
	b = getchar();

	n *= 4;

	while (n--) {

		getchar();
		card = getchar();
		suit = getchar();

		total += mapper[card];

		if (suit == b) {
		
			if (card == '9')
				total += 14;
			else if (card == 'J')
				total += 18;
		}
	}

	cout << total << endl;

	return 0;
}
