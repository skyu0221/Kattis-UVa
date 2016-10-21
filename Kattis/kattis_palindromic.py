def main():

	cases = int( input() )

	for i in range( cases ):

		name   = input()
		length = len( name )
		table  = list()

		for i in range( length ):

			table.append( [0] * length )
			table[i][i] = 1

			if i != length - 1:

				table[i][i+1] = 2

				if name[i] == name[i+1]:

					table[i][i+1] += 1

		for k in range( 2, length ):
			for i in range( length - k ):

				j = k + i

				table[i][j] = ( table[i+1][j] + table[i][j-1] - \
								table[i+1][j-1] ) % ( 10e9 + 7 )

				if name[i] == name[j]:

					table[i][j] += ( table[i+1][j-1] + 1 ) % ( 10e9 + 7 )

		print( int( table[0][-1] % ( 10e9 + 7 ) ) )

if __name__ == "__main__":

	main()
