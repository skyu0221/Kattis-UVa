#include <iostream>
#include <cstring>
#include <cstdio>

#define MAX 1000000
#define swap( x, y ) { int tmp; tmp = x, x = y, y = tmp; }

using namespace std;

int table[MAX + 1];

void build() {

	long long counter, current;

	table[1] = 1;

	for ( int i = 2; i <= MAX; i++ ) {

		counter = 1;
		current = i;

		while ( current != 1 ) {

			if ( current % 2 )
				current = ( current << 1 ) + current + 1;
			else
				current >>= 1;

			if ( current <= MAX && table[current] != -1 ) {

				counter += table[current];
				break;
			}

			counter++;
		}

		table[i] = counter;

		//cout << i << ": " << table[i] << endl;
	}
}

int single( int number ) {

	long long counter = 1, current = number;

	if ( table[number] != -1 )
		return table[number];

	while ( current != 1 ) {

		if ( current % 2 )
			current = ( current << 1 ) + current + 1;
		else
			current >>= 1;

		if ( current <= MAX && table[current] != -1 ) {

			counter += table[current];
			break;
		}

		counter++;
	}

	table[number] = counter;

	return table[number];
}

int main() {

	int i, j, output;

	memset( table, -1, sizeof( table ) );

	while( scanf( "%d %d", &i, &j ) == 2 ) {

		output = 0;

		cout << i << ' ' << j << ' ';

		if( i > j )
			swap( i, j );

		for ( ; i <= j; i++ )
			if ( single(i) > output )
				output = table[i];

		cout << output << endl;
	}

	return 0;
}
