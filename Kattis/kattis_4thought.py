'''
 * Kattis ID: 4thought
 *
 * Topic: Arithmetic
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Given an integer I, find a equation 4 ? 4 ? 4 ? 4 = I
 *
 * Solution Summary:
 *
 *   Just list all possible solution and take case of the sequence
 *
 * Used Resources:
 *
 *   https://docs.python.org/3/
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
'''
def calculate( string ):

    num = [ 4, 4, 4, 4 ]

    for symbol in [ '/', '*' ]:
        while symbol in string:
            pos = string.index(symbol)
            if symbol == '*':
                num[pos] *= num.pop(pos+1)
            else:
                num[pos] //= num.pop(pos+1)
            string.pop(pos)

    while string:
        if string[0] == '+':
            num[0] += num.pop(1)
        else:
            num[0] -= num.pop(1)
        string.pop(0)

    return num[0]

def main():

    sym = [ '+', '-', '*', '/' ]
    test_case = int( input() )

    for case in range( test_case ):
        
        target = int( input() )
        find = False

        for all_case in range( 64 ):
            i = all_case // 16
            j = ( all_case - i * 16 ) // 4
            k = all_case - i * 16 - j * 4
            if calculate( [ sym[i], sym[j], sym[k] ] ) == target:
                print( "4 %s 4 %s 4 %s 4 = %i" \
                    %( sym[i], sym[j], sym[k], target ) )
                find = True
                break;

        if not find:
            print( "no solution" )

if __name__ == "__main__":
    main()
