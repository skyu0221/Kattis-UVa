'''
 * Kattis ID: digitsum
 *
 * Topic: Number Theorem
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Get the digit sum of all numbers between a and b (include a and b).
 *   Input: a b
 *   Output: digit sum
 *
 * Solution Summary:
 *
 *   Find the 'un-normal' numbers and sum them up. Others can solve by
 *   recursive loop.
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
def digitsum( num ):
	result = 0
	for i in range( len( num ) - 1, -1, -1 ):
		result += ( int( num[i] ) * ( int( num[i] ) - 1 ) // 2 ) * \
			pow( 10, len( num[i:] ) - 1 )
		if( i == len( num ) - 1 ):
			result += int( num[i] )
		else:
			result += int( num[i] ) * ( int( num[i+1:] ) + 1 )
		if( i != 0 ):
			result += 45 * int( num[:i] ) * \
				pow( 10, len( num[i:] ) - 1 )
	return result

def main():

	test_case = int( input() )

	for case in range( test_case ):

		a, b = input().split(' ')
		if a != '0':
			a = str( int( a ) - 1 )

		print( digitsum(b) - digitsum(a) )
if __name__ == "__main__":
	main()
