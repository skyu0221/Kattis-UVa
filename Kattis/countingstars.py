import resource, sys
sys.setrecursionlimit( 10**6 )

def floodfill( y, x, number ):

	if table[y][x] != '-':
		return
	table[y][x] = number

	if y + 1 < m:
		floodfill( y + 1, x, number )
	if y > 0:
		floodfill( y - 1, x, number )
	if x + 1 < n:
		floodfill( y, x + 1, number )
	if x > 0:
		floodfill( y, x - 1, number )
	return

counter = 0

while True:

	counter += 1

	try:
		m, n  = input().split()
		m = int( m )
		n = int( n )
	except EOFError:
		break

	table = []

	found = 0

	for _ in range( m ):

		table.append( list( input() ) )

	for y in range( m ):
		for x in range( n ):

			if table[y][x] == '-':
				floodfill( y, x, found )
				found += 1

	print( "Case %d: %d" %( counter, found ) )
