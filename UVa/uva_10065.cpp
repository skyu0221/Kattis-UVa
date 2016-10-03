/* UVa problem: 10065
 *
 * Topic: Geometry
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find the percentage between original and hull convex.
 *
 * Solution Summary:
 *
 *   Sort those point by x, then y, then direction.
 *
 * Used Resources:
 *
 * http://bbs.dartmouth.edu/~fangq/MATH/download/source/Determining%20if%20a%20point%20lies%20on%20the%20interior%20of%20a%20polygon.htm
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {

	double x, y;
};

int points, i, j, counter = 1, top;
double out, in;
Point point[100], convex[100];

double cross( Point p, Point a, Point b ) {

	return ( b.y - p.y ) * ( a.x - p.x ) - ( b.x - p.x ) * ( a.y - p.y );
}

double length( Point a, Point b ) {

	return sqrt( pow( a.x - b.x, 2 ) + pow( a.y - b.y, 2 ) );
}

// Sort by x, then y
bool sorter( Point a, Point b ) {

	return ( a.x == b.x ) ? ( a.y < b.y ) : ( a.x < b.x );
}

bool cmp( Point a, Point b ) {

	double d = cross( point[0], a, b );

	return ( !d ) ? ( length( point[0], a ) 
	                < length( point[0], b ) ) : ( d > 0 );
}

int main() {

	while ( cin >> points && points != 0 ) {

		j = 0; in = 0; out = 0; top = 1;

		for ( i = 0; i < points; i++ ) cin >> point[i].x >> point[i].y;

		for ( i = 2; i < points; i++ )
			in += cross( point[0], point[i - 1], point[i] ) / 2;

		sort( point + 0, point + points, sorter );
		sort( point + 1, point + points, cmp );

		convex[0] = point[0];
		convex[1] = point[1];

		for ( i = 2; i < points; i++ ) {
			while ( cross( convex[top - 1], convex[top], point[i] ) <= 0 
				  && top > 0 ) top--;
			convex[++top] = point[i];
		}

		for ( i = 2; i <= top; i++ )
			out += cross( convex[0], convex[i - 1], convex[i] ) / 2;

		out = fabs( out );
		in  = fabs( in );

		cout << "Tile #" << counter++ << endl;
		cout << "Wasted Space = " << fixed << setprecision(2);
		cout << ( out - in ) * 100 / out << " %" << endl << endl;
	}

	return 0;
}
