'''
 * UVa problem: 10136
 *
 * Topic: Geometry
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Given some point find the circle that contains the most points.
 *
 * Solution Summary:
 *
 *   If only one point, result is one. Otherwise set two points on the
 *   circle and find how many points in this circle.
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
 *
'''
import math

def dist( a, b ):
    return round( math.sqrt( ( a[0] - b[0] ) * ( a[0] - b[0] ) + \
                      ( a[1] - b[1] ) * ( a[1] - b[1] ) ), 5 )

def center( a, b ):
    if a[0] == b[0]:
        y = ( a[1] + b[1] ) / 2.0
        x = math.sqrt( 6.25 - ( ( a[1] - b[1] ) / 2.0 ) * \
                       ( ( a[1] - b[1] ) / 2.0 ) )
        return [ [ round( a[0] + x, 5 ), round( y, 5 ) ], \
                 [ round( a[0] - x, 5 ), round( y, 5 ) ] ]
    elif a[1] == b[1]:
        x = ( a[0] + b[0] ) / 2.0
        y = math.sqrt( 6.25 - ( ( a[0] - b[0] ) / 2.0 ) * \
                       ( ( a[0] - b[0] ) / 2.0 ) )
        return [ [ round( x, 5 ), round( a[1] + y, 5 ) ], \
                 [ round( x, 5 ), round( a[1] - y, 5 ) ] ]
    else:
        k = -( a[0] - b[0] ) / ( a[1] - b[1] )
        x = ( a[0] + b[0] ) / 2.0
        y = ( a[1] + b[1] ) / 2.0
        s = math.sqrt( 6.25 - ( ( a[0] - b[0] ) * ( a[0] - b[0] ) + \
                                ( a[1] - b[1] ) * ( a[1] - b[1] ) ) / 4.0 )
        d = math.atan(k)
        return [ [ round( x + s * math.cos(d), 5 ), \
                   round( y + s * math.sin(d), 5 ) ], \
                 [ round( x - s * math.cos(d), 5 ), \
                   round( y - s * math.sin(d), 5 ) ] ]

def main():

    cases = int( input() )
    line = input()

    for case in range( cases ):

        line  = input().strip(' ')
        point = list()
        count = 1

        while len( line ) > 1:

            point.append( list( map( float, line.split(' ') ) ) )
            try:
                line = input().strip(' ')
            except:
                break
        for i in range( len( point ) ):
            for j in range( i + 1, len( point ) ):
                if dist( point[i], point[j] ) <= 5:

                    check = center( point[i], point[j] )

                    inside = 0
                    for k in point:
                        if dist( check[0], k ) <= 2.5:
                            inside += 1
                    if inside > count:
                        count = inside
                    inside = 0
                    if check[1] != check[0]:
                        for k in point:
                            if dist( check[1], k ) <= 2.5:
                                inside += 1
                        if inside > count:
                            count = inside
        print( count )
        if case != cases - 1:
            print()

if __name__ == "__main__":
    main()
