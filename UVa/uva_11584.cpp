/* UVa problem: 11584
 *
 * Topic: Dynamic Programming
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find small number of palidorme of whole string.
 *
 * Solution Summary:
 *
 *   i ending string = min( j ending, i ending ) if [j:i] is palindorme
 *
 * Used Resources:
 *
 *   http://www.xuebuyuan.com/2063340.html
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, length, i, j, dp[1001];
char line[1000];

bool palindorme( int start, int end ) {

    while ( line[start++] == line[end--]) if ( end <= start ) return true;

    return false;
}

int main() {

    cin >> cases;

    while ( cases-- ) {

        memset( dp, 0x1f, sizeof( dp ) );

        scanf( "%s", line );

        length = strlen( line );

        dp[0] = 0;

        for ( i = 0; i < length; i++ )
            for ( j = 0; j <= i; j++ )
                if ( palindorme( j, i ) )
                    dp[i + 1] = min( dp[i + 1], dp[j] + 1 );

        cout << dp[length] << endl;
    }

    return 0;
}
