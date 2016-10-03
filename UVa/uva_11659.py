'''
 * UVa problem: 11659
 *
 * Topic: Backtracking
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Find the largest possible people speak the truth.
 *
 * Solution Summary:
 *
 *   If someone say a guy is lying, then mark that guy to unreliable.
 *   Otherwise, keep going.
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
def main():

    line = input()

    while line != '0 0':

        init      = list( map( int, line.split(' ') ) )
        result    = [ True ] * init[0]
        count     = 0

        for i in range( init[1] ):
            speaker, target = input().split(' ')
            if int( target ) < 0:
                if result[-int(target) - 1]:
                    init[0] -= 1
                    result[-int(target) - 1] = False

        print( init[0] )

        line = input()
        if len( line ) == 0:
            line = input()

if __name__ == "__main__":
    main()
