#include <iostream>
#include <string>

using namespace std;

int main() {

	string month;
	int date;

	cin >> month >> date;

	if ((date == 31 && month == "OCT") || (date == 25 && month == "DEC"))
		cout << "yup" << endl;
	else
		cout << "nope" << endl;

	return 0;
}
