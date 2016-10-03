/* UVa problem: 11512
 *
 * Topic: String
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find the longest substring appears more than once.
 *
 * Solution Summary:
 *
 *   Build tree, BFS. first in python, receive TLE. Convert to C++, AC(1.35s)
 *
 * Used Resources:
 *
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct LinkedNode {
	char value;
	int count;
	bool visit;
	LinkedNode *parent = nullptr;
	LinkedNode *children[4] = { nullptr, nullptr, nullptr, nullptr };
};

LinkedNode *head, *current;
string line, result;
int cases, i, j, height, convert;
bool deep;

int main() {

	cin >> cases;

	while ( cases-- ) {

		height      = -1;
		head        = new LinkedNode;
		head->value = '0';
		head->count = 0;
		head->visit = false;
		result.clear();
		cin >> line;

		for ( i = 0; i < line.length(); i++ ) {

			current = head;

			for ( j = i; j < line.length(); j++ ) {

				if ( line[j] == 'A' ) convert = 0;
				else if ( line[j] == 'C' ) convert = 1;
				else if ( line[j] == 'G' ) convert = 2;
				else convert = 3;

				if ( current->children[convert] == nullptr ) {

					LinkedNode *tmp;
					tmp = new LinkedNode;

					tmp->value = line[j];
					tmp->count = 0;
					tmp->visit = false;
					tmp->parent = current;
					current->children[convert] = tmp;
					current = current->children[convert];

				} else current = current->children[convert];

				current->count++;

				if ( j - i > height && current->count > 1 )
					height = j - i;
			}
		}

		current = head;

		if ( height == -1 ) cout << "No repetitions found!" << endl;
		else {
			while ( height != -1 ) {

				deep = false;
				for ( i = 0; i < 4; i++ )
					if ( current->children[i] != nullptr ) {
						if ( current->children[i]->count != 1 &&
						     !current->children[i]->visit ) {
							current        = current->children[i];
							current->visit = true;
							deep           = true;
							height--;
							break;
						}
					}

				if ( !deep ) {
					current = current->parent;
					height++;
				}

			}

			height = current->count;

			while ( current->value != '0' ) {

				result += current->value;
				current = current->parent;

			}

			reverse( result.begin(), result.end() );
			cout << result << " " << height << endl;
		}
	}
	return 0;
}
