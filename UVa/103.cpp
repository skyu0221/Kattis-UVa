#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int compare_array ( const void *a, const void *b ) {

	long long const *lhs = static_cast<long long const*>( a );
	long long const *rhs = static_cast<long long const*>( b );

	return ( lhs[10] < rhs[10] ) ?
	                               -1 :
                                   ( ( lhs[10] > rhs[10] ) ?
                                                             1 :
                                                             0 );
}

bool stack( long long box[30][12], int dimension, int a, int b ) {

	for ( int i = 0; i < dimension; i++ )
		if ( box[a][i] >= box[b][i] )
			return false;
	return true;
}

int main() {

	int       dimension, line, tracker[30][2], max, chain[30], current;
	bool      new_node;
	long long box[30][12];

	while ( cin >> line >> dimension ) {

		memset( tracker, 0, sizeof( tracker ) );

		for ( int i = 0; i < line; i++ ) {

			box[i][10] = 0;
			box[i][11] = i + 1;

			for ( int j = 0; j < dimension; j++ ) {

				cin >> box[i][j];
				box[i][10] += box[i][j];
			}

			sort( box[i], box[i] + dimension );
		}

		qsort( box, line, sizeof( *box ), compare_array );

		for ( int i = 1; i < line; i++ ) {

			for ( int j = 0; j < i; j++ ) {

				if ( stack( box, dimension, j, i ) &&
                     tracker[i][1] < tracker[j][1] + 1 ) {

					tracker[i][1] = tracker[j][1] + 1;
					tracker[i][0] = j;
				}
			}
		}

		//cout << "===" << endl;
		//for ( int i = 0; i < line; i++ ) {
		//	cout << box[i][11] << ":\t" << box[i][10] << "\t|";
		//	for ( int j = 0; j < dimension; j++)
		//		cout << box[i][j] << '\t';
		//	cout << endl;
		//}
		//cout << "---" << endl;
		//for ( int i = 0; i < line; i++ ) {
		//	cout << tracker[i][0] << "\tcounter:\t" << tracker[i][1] << endl;
		//}

		max = 0;

		for ( int i = 1; i < line; i++ )
			if ( tracker[i][1] > tracker[max][1] )
				max = i;

		current = max;
		//cout << current << " " << box[current][11] << endl;

		for ( int i = tracker[max][1]; i >= 0; i-- ) {

			chain[i] = box[current][11];
			current  = tracker[current][0];
		}

		cout << tracker[max][1] + 1 << endl;

		for ( int i = 0; i < tracker[max][1]; i++ )
			cout << chain[i] << ' ';
		cout << chain[tracker[max][1]] << endl;

		//cout << "===" << endl;
	}
	return 0;
}
