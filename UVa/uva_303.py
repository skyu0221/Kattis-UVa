'''
 * UVa problem: 303
 *
 * Topic: Geometry
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Find the farest distance that light can reach through pipe.
 *
 * Solution Summary:
 *
 *   First I tried to combine two pipes to one pipe and finally combine
 *   to one pipe that light can through. If it hit the pipe, return the
 *   distance. Otherwise, through all pipes. But somehow it failed. So
 *   now I'm tring to list all possible farest light. That kind of light
 *   is definitely a kind of combination that light through a upper point
 *   and a lower point. So I calculated every possible solution and skip
 *   the solution that cannot reach the start point then take the maximum.
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

def intersect( a, b, m, n ):

    d1 = ( b[0] - a[0] ) * ( m[1] - a[1] ) - ( b[1] - a[1] ) * ( m[0] - a[0] )
    d2 = ( b[0] - a[0] ) * ( n[1] - a[1] ) - ( b[1] - a[1] ) * ( n[0] - a[0] )

    if d1 * d2 > 0:
        return [ False, 0 ]

    return [ True, ( m[0] * d2 - n[0] * d1 ) / ( d2 - d1 ) ]
    

def iteration( a, b, bent, points ):

    for i in range( points ):

        result = intersect( a, b, bent[i][0], bent[i][1] )

        if not result[0]:
            if i == 0:
                return bent[0][0][0]
            result = intersect( a, b, bent[i][0], bent[i-1][0] )
            x1 = result[1]
            result = intersect( a, b, bent[i][1], bent[i-1][1] )
            x2 = result[1]
            if x1 == 0 and x2 != 0:
                return x2
            elif x1 != 0 and x2 == 0:
                return x1
            elif x1 == 0 and x2 == 0: 
                return -1e9
            return max( x1, x2 )


    return bent[points - 1][0][0]

def main():

    points = int( input() )

    while points != 0:

        bent    = list()

        for point in range( points ):

            up = list( map( float, input().split(' ') ) )
            bent.append( [ up, [ up[0], up[1] - 1 ] ] )

        maximum = bent[0][0][0]

        for i in range( points ):

            for j in range( points ):

                if i == j:
                    continue

                maximum = max( maximum, iteration( bent[i][0], bent[j][1], \
                                                   bent, points) )

        if maximum - bent[points - 1][0][0] < 0:
            print( "%.2f" %maximum )
        else:
            print( "Through all the pipe." )

        points = int( input() )

if __name__ == "__main__":
    main()
