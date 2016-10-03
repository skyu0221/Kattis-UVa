'''
 * UVa problem: 105
 *
 * Topic: Geometry
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Given set of rectangles, find the skyline.
 *
 * Solution Summary:
 *
 *   Because only have integer, then find the highest point of each x.
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

	top    = [0] * 10000
	stop   = 0
	result = list()

	while True:
		try:

			left, height, right = input().split(' ')
			left   = int( left )
			right  = int( right )
			height = int( height )

			for i in range( left, right ):

				if top[i] < height:
					top[i] = height
				if right > stop:
					stop = right				

		except EOFError:

			result.append( top[0] )

			for i in range( stop + 1 ):

				if top[i] == result[-1]:
					pass
				else:
					result.append( i )
					result.append( top[i] )

			result.pop(0)

			print( " ".join( list( map( str, result ) ) ) )
				
			return

if __name__ == "__main__":
	main()
