'''
 * Kattis ID: catalansquare
 *
 * Topic: Arithmetic
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Math problem. Please see webpage
 *
 * Solution Summary:
 *
 *   Normaliy run the algorithm will cost 1 min for solution.
 *   But if we reduce the function then the O can reduce to constant time
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
def C( n ):
    top = 1
    bot = 1
    for i in range( n ):
        top *= ( n + i + 1 )
        bot *= ( i + 1 )
    return ( top // bot ) // ( n + 1 )

def main():
    n = int( input() )
    print(C(n+1))

if __name__ == "__main__":
    main()
