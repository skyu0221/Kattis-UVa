#include <iostream>
#include <cstring>

using namespace std;

long long table[2010][2010];

int main() {

    int cases, j;

    cin >> cases;

    while ( cases-- ) {

        string name;

        memset( table, 0, sizeof( table ) );

        cin >> name;

        for ( int i = 0; i < name.length(); i++ ) {

            table[i][i] = 1;
            table[i][i+1] = 2 + ( name[i] == name[i+1] );
        }

        for ( int k = 2; k < name.length(); k++ ) {

            for ( int i = 0; i < name.length() - k; i++ ) {

                j = k + i;

                table[i][j] = ( table[i+1][j] + table[i][j-1] - table[i+1][j-1]
                                + ( name[i] == name[j] ) * ( table[i+1][j-1] +
                                1 ) ) % 1000000007;
            }
        }

        cout << table[0][name.length() - 1] << endl;
    }

    return 0;
}
