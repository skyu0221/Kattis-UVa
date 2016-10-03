'''
 * UVa problem: 10706
 *
 * Topic: Binary Search
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Find the kth number in 112123123412345...
 *
 * Solution Summary:
 *
 *   First I tried to find the relation between position and number of
 *   repeat loop. But the calculation is hugh, and neet to find some
 *   complex square root. So I decide to just try out the position of
 *   all loop and compare with given position. Then find the exact location.
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

def build_table():

    table  = list()
    line   = 1
    length = 1
    
    while length < 2147483648:
        table.append( length )
        line += 1
        temp  = line
        for i in range( len( str( line ) ) ):
            length += temp
            temp    = line - int( '9' * ( i + 1 ) )

    table.append(2147483648)
    return table

def main():

    table = build_table()

    cases = int( input() )

    for case in range( cases ):

        i   = 0
        pos = int( input() )
        s = pos

        while table[i] < pos:
            i += 1

        if i != 0:
            pos -= table[i - 1]

        digit = 1
        posit = 9
        while pos - posit > 0:
            digit += 1
            posit += digit * 9 * pow( 10, digit - 1 )

        posit -= digit * 9 * pow( 10, digit - 1 )
        pos -= posit
        if digit == 1:
            print( pos )
        else:
            pos -= 1
            num = pos // digit
            num += pow( 10, digit - 1 )
            print( str( num )[pos%digit] )

if __name__ == "__main__":
    main()
