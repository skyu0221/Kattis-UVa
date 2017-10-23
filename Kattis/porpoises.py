import math

def matmul( a, b ):

	return [ [ ( a[0][0] * b[0][0] + a[0][1] * b[1][0] ) % 1000000000, \
	           ( a[0][0] * b[0][1] + a[0][1] * b[1][1] ) % 1000000000 ],
	         [ ( a[1][0] * b[0][0] + a[1][1] * b[1][0] ) % 1000000000, \
	           ( a[1][0] * b[0][1] + a[1][1] * b[1][1] ) % 1000000000 ] ]

cases = int( input() )

for case in range( cases ):

	K, Y   = input().split()
	Y      = int( Y ) - 1
	result = [ [1, 0], [0, 1] ]
	helper = [ [1, 1], [1, 0] ]

	while Y > 0:

		if Y % 2 == 1:
			result = matmul( result, helper )

		helper = matmul( helper, helper )
		Y      = math.floor( Y / 2 )

	print( K, result[0][0] )
