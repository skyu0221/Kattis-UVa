#include <iostream>
#include <cstring>

using namespace std;

char command[5], rewrite[5];
int  grids[25][25], block_pos[25][2], grid_size[25];

void print_test( int init ) {

	cout << "=====" << endl;
	cout << "GRIDS: " << endl;
	for ( int i = init - 1; i >= 0; i-- ) {
		cout << "Pos " << i << '\t';
		for ( int j = 0; j < init; j++ )
			if ( grids[j][i] != -1 )
				cout << grids[j][i] << '\t';
			else
				cout << '\t';
		cout << endl;
	}
	cout << '\t';
	for ( int i = 0; i < init; i++ )
		cout << "#" << i << '\t';
	cout << endl << endl << "BLOCK POSITION TRACKER" << endl << "Col\t";
	for ( int i = 0; i < init; i++ )
		cout << block_pos[i][0] << '\t';
	cout << endl << "Pos\t";
	for ( int i = 0; i < init; i++ )
		cout << block_pos[i][1] << '\t';
	cout << endl << "\t";
	for ( int i = 0; i < init; i++ )
		cout << "#" << i << '\t';
	cout << endl << endl << "GRID SIZE" << endl << '\t';
	for ( int i = 0; i < init; i++ )
		cout << grid_size[i] << '\t';
	cout << endl << '\t';
	for ( int i = 0; i < init; i++ )
		cout << "#" << i << '\t';
	cout << endl;
	cout << "=====" << endl;
}

void move( int select, int column ) {
 
	grids[column][grid_size[column]]                  = select;
	grids[block_pos[select][0]][block_pos[select][1]] = -1;
	grid_size[block_pos[select][0]]--;
	block_pos[select][0]                              = column;
	block_pos[select][1]                              = grid_size[column];
	grid_size[column]++;
}

void put_back_behind( int select ) {

	for ( int i = grid_size[block_pos[select][0]] - 1;
	          i > block_pos[select][1];
	          i-- )
		move( grids[block_pos[select][0]][i], grids[block_pos[select][0]][i] );
}

void pile( int select, int column ) {

	int selected_row, height;

	selected_row = block_pos[select][0];
	height       = block_pos[select][1];

	for ( int i = block_pos[select][1];
			  i < grid_size[selected_row];
			  i++ ) {

		grids[column][grid_size[column]]     = grids[selected_row][i];
		block_pos[grids[selected_row][i]][0] = column;
		block_pos[grids[selected_row][i]][1] = grid_size[column];
		grids[selected_row][i]               = -1;
		grid_size[column]++;
	}

	grid_size[selected_row] = height;
}

int main() {

	int select, target, init;

	cin >> init;
	cin >> command;

	memset( grids,     -1, sizeof( grids ) );
	memset( block_pos,  0, sizeof( block_pos ) );

	for ( int i = 0; i < init; i++ ) {

		grids[i][0]     = i;
		block_pos[i][0] = i;
		grid_size[i]    = 1;
	}

	//print_test( init );

	while ( command[0] != 'q' ) {

		cin >> select >> rewrite >> target;

		//cout << command << ' ' << select << ' ' << rewrite << ' ' << target << endl;

		if ( select != target &&
		     block_pos[select][0] != block_pos[target][0] ) {

			if ( command[0] == 'm' ) {

				put_back_behind( select );

				if ( rewrite[1] == 'n' )
					put_back_behind( target );

				move( select, block_pos[target][0] );

			} else {

				if ( rewrite[1] == 'n' )
					put_back_behind( target );

				pile( select, block_pos[target][0] );
			}
		}

		//print_test( init );

		cin >> command;
	}

	for ( int i = 0; i < init; i++ ) {

		cout << i << ":";

		for ( int j = 0; j < grid_size[i]; j++ )
			cout << " " << grids[i][j];

		cout << endl;
	}

	return 0;
}
