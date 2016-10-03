/* UVa problem: 12492
 *
 * Topic: Combinatorics
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find the steps neede to recovery the rubik.
 *
 * Solution Summary:
 *
 *   Simply simulate the given transforamtion and keep doing until rubik
 *   back to the original position.
 *
 *     4
 *   2 0 3
 *     5
 *     1
 *
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 */
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int info[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0,
               1, 1, 1, 1, 1, 1, 1, 1, 1,
               2, 2, 2, 2, 2, 2, 2, 2, 2,
               3, 3, 3, 3, 3, 3, 3, 3, 3,
               4, 4, 4, 4, 4, 4, 4, 4, 4,
               5, 5, 5, 5, 5, 5, 5, 5, 5 };

int affect[][12] = { { 42, 43, 44, 27, 30, 33, 47, 46, 45, 26, 23, 20 },
                     { 51, 52, 53, 35, 32, 29, 38, 37, 36, 18, 21, 24 },
                     { 36, 39, 42,  0,  3,  6, 45, 48, 51,  9, 12, 15 },
                     { 44, 41, 38, 17, 14, 11, 53, 50, 47,  8,  5,  2 },
                     { 15, 16, 17, 29, 28, 27,  2,  1,  0, 20, 19, 18 },
                     {  6,  7,  8, 33, 34, 35, 11, 10,  9, 24, 25, 26 } };

void rotate( int face ) {
    
    int temp;

    if ( face <= 5 ) {
        
        temp = info[face * 9 + 0];
        info[face * 9 + 0] = info[face * 9 + 6];
        info[face * 9 + 6] = info[face * 9 + 8];
        info[face * 9 + 8] = info[face * 9 + 2];
        info[face * 9 + 2] = temp;
        temp = info[face * 9 + 1];
        info[face * 9 + 1] = info[face * 9 + 3];
        info[face * 9 + 3] = info[face * 9 + 7];
        info[face * 9 + 7] = info[face * 9 + 5];
        info[face * 9 + 5] = temp;

        temp = info[affect[face][0]];
        info[affect[face][0]]  = info[affect[face][9]];
        info[affect[face][9]]  = info[affect[face][6]];
        info[affect[face][6]]  = info[affect[face][3]];
        info[affect[face][3]]  = temp;
        temp = info[affect[face][1]];
        info[affect[face][1]]  = info[affect[face][10]];
        info[affect[face][10]] = info[affect[face][7]];
        info[affect[face][7]]  = info[affect[face][4]];
        info[affect[face][4]]  = temp;
        temp = info[affect[face][2]];
        info[affect[face][2]]  = info[affect[face][11]];
        info[affect[face][11]] = info[affect[face][8]];
        info[affect[face][8]]  = info[affect[face][5]];
        info[affect[face][5]]  = temp;
    
    } else {

        face -= 6;
        temp = info[face * 9 + 0];
        info[face * 9 + 0] = info[face * 9 + 2];
        info[face * 9 + 2] = info[face * 9 + 8];
        info[face * 9 + 8] = info[face * 9 + 6];
        info[face * 9 + 6] = temp;
        temp = info[face * 9 + 1];
        info[face * 9 + 1] = info[face * 9 + 5];
        info[face * 9 + 5] = info[face * 9 + 7];
        info[face * 9 + 7] = info[face * 9 + 3];
        info[face * 9 + 3] = temp;

        temp = info[affect[face][0]];
        info[affect[face][0]]  = info[affect[face][3]];
        info[affect[face][3]]  = info[affect[face][6]];
        info[affect[face][6]]  = info[affect[face][9]];
        info[affect[face][9]]  = temp;
        temp = info[affect[face][1]];
        info[affect[face][1]]  = info[affect[face][4]];
        info[affect[face][4]]  = info[affect[face][7]];
        info[affect[face][7]]  = info[affect[face][10]];
        info[affect[face][10]] = temp;
        temp = info[affect[face][2]];
        info[affect[face][2]]  = info[affect[face][5]];
        info[affect[face][5]]  = info[affect[face][8]];
        info[affect[face][8]]  = info[affect[face][11]];
        info[affect[face][11]] = temp;
    
    }
}

bool finish() {
    
    for ( int i = 0; i < 54; i++ )
        if ( info[i] != floor( i / 9 ) ) return false;
    return true;
}

int main() {

    string line;

    while ( cin >> line ) {
        int result = 0;

        do {
    
            for ( int i = 0; i < line.size(); i++ ) {

                switch ( line[i]) {

                    case 'U': rotate( 0); break;
                    case 'D': rotate( 1); break;
                    case 'L': rotate( 2); break;
                    case 'R': rotate( 3); break;
                    case 'B': rotate( 4); break;
                    case 'F': rotate( 5); break;
                    case 'u': rotate( 6); break;
                    case 'd': rotate( 7); break;
                    case 'l': rotate( 8); break;
                    case 'r': rotate( 9); break;
                    case 'b': rotate(10); break;
                    case 'f': rotate(11); break;

                }
            }
            result++;
        } while ( !finish() );
        cout << result << endl;
    }
	return 0;
}
