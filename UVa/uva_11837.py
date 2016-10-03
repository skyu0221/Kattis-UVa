'''
 * UVa problem: 11873
 *
 * Topic: String
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Check if string 2 is a substring of string 1's family.
 *
 * Solution Summary:
 *
 *   The start height might different, but the difference between two
 *   semiton won't. So find the difference then check.
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

semitone = { 'A': 1, 'A#': 2, 'Bb': 2, 'B': 3, 'Cb': 3, 'C': 4, 'B#': 4,
             'C#': 5, 'Db':5, 'D': 6, 'D#': 7, 'Eb': 7, 'E': 8, 'Fb': 8,
             'F': 9, 'E#': 9, 'F#': 10, 'Gb': 10, 'G': 11, 'G#': 0, 'Ab': 0}

def convert( semi ):
	return semitone[semi]

def main():

	case = input()

	while case != "0 0":

		original = list( map( convert, input().split(' ') ) )
		suspect  = list( map( convert, input().split(' ') ) )

		distance = list()
		position = 0

		result   = 'N'

		for i in range( 1, len( suspect ) ):

			distance.append( ( suspect[i] - suspect[i - 1] ) % 12 )

		if len( suspect ) != 1:

			for i in range( 1, len( original ) ):

				diff = ( original[i] - original[i - 1] ) % 12

				if diff == distance[position]:
					position += 1
				elif diff == distance[0]:
					position = 1
				else:
					position = 0

				if position == len( distance ):
					break

		if position == len( distance ):
			print( 'S' )
		else:
			print( 'N' )

		case = input()

if __name__ == "__main__":
	main()
