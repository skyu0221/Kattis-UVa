/* UVa problem: 10090
 *
 * Topic: Number Theory
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   2 box cost c1, c2 and can contain n1, n2 ball. What is the smallest
 *   cost when require to contain total n.
 *
 * Solution Summary:
 *
 *   Extent gcd, gcd(a,b) = g = ax+by, get (x, y) where n1*x + n2*y = n
 *   x'=x*n/gcd(n1,n2)+n2/gcd(n1,n2)*t
 *   y'=y*n/gcd(n1,n2)-n1/gcd(n1,n2)*t
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
#include <cmath>

using namespace std;

long long marble, cost_1, cost_2, size_1, size_2, x, y;
long long gcd, k_1, k_2;

long long extend_gcd( long long a, long long b, long long &x, long long &y ) {

	if ( a < b ) return extend_gcd( b, a, y, x );

	if ( b == 0 ) {
		x = 1;
		y = 0;
		return a;
	} else {
		long long temp_gcd = extend_gcd( b, a % b, y, x );
		y -= a / b * x;
		return temp_gcd;
	}
}

int main() {

	while (  cin >> marble && marble ) {

		cin >> cost_1 >> size_1 >> cost_2 >> size_2;

		gcd = extend_gcd( size_1, size_2, x, y );
		k_1 = floor( 1.0 * marble * y / size_1 );
		k_2 = ceil( -1.0 * marble * x / size_2 );

		if ( k_1 < k_2 || marble % gcd ) cout << "failed" << endl;
		else {

			if ( cost_1 * size_2 < cost_2 * size_1 ) {
				x = ( marble * x + size_2 * k_1 ) / gcd;
				y = ( marble * y - size_1 * k_1 ) / gcd;
			} else {
				x = ( marble * x + size_2 * k_2 ) / gcd;
				y = ( marble * y - size_1 * k_2 ) / gcd;
			}

			cout << x << " " << y << endl;
		}

	}

	return 0;
}
