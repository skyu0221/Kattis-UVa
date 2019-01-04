#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int maximum = 0;
	int card, mapper[256];

	for (int i = 0; i < 14; ++i){

		card = getchar();
		
		if (i % 3 == 0 && ++mapper[card] > maximum)
			maximum = mapper[card];
	}

	cout << maximum << endl;
}
