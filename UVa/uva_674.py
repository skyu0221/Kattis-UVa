'''
 * UVa problem: 674
 *
 * Topic: Dynamic Programming
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   How many ways to give an accurate change
 *
 * Solution Summary:
 *
 *   Build a table, which can use position indicate change, the value
 *   is exactly the number of ways. Idea is start from basic situation,
 *   then use idea such as a_n+1 = f( a_n )
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

coins  = [ 1, 5, 10, 25, 50 ]
result = [0] * 7490

def get_result():

    target = int( input() )

    print( result[target] )

def main():

    result[0] = 1

    for coin in coins:

        i = 0
        
        while i + coin <= 7489:

            result[ i + coin ] += result[i]
            i += 1

if __name__ == "__main__":
    main()
    try:
        while True:
            get_result()
    except:
        pass
