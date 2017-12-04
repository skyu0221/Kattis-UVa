import resource, sys
sys.setrecursionlimit( 10**6 )

def floodfill( table, y, x, dist ):

	if table[y][x] > dist or table[y][x] == 0:

		table[y][x] = dist

		if y + 1 < m and table[y + 1][x] != -1:
			floodfill( table, y + 1, x, dist + 1 )
		if y > 0 and table[y - 1][x] != -1:
			floodfill( table, y - 1, x, dist + 1 )
		if x + 1 < n and table[y][x + 1] != -1:
			floodfill( table, y, x + 1, dist + 1 )
		if x > 0 and table[y][x - 1] != -1:
			floodfill( table, y, x - 1, dist + 1 )

m, n  = input().split()
m = int( m )
n = int( n )
result = -1
fires  = 0

solver = [[],[]]

fire   = []
joe    = [ 0, 0 ]

for j in range( m ):

	line = list( input() )

	solver[0].append( [] )
	solver[1].append( [] )

	for i in range( len( line ) ):

		representer = 0

		if line[i] == '#':
			representer = -1

		elif line[i] == 'F':
			fires   += 1
			fire.append( [j, i] )

		elif line[i] == 'J':
			joe[0]   = j
			joe[1]   = i
			if i == 0 or j == 0 or i == m - 1 or j == m - 1:
				print( 1 )
				exit( 0 )

		solver[0][j].append( representer )
		solver[1][j].append( representer )

floodfill( solver[0], joe[0], joe[1], 1 )

for i in range( fires ):
	floodfill( solver[1], fire[i][0], fire[i][1], 1 )

for i in range( m ):

	if solver[0][i][0] > 0 and \
	   ( solver[0][i][0] < solver[1][i][0] or solver[1][i][0] == 0 ) and \
	   ( solver[0][i][0] < result or result == -1 ):
		result = solver[0][i][0]

	if solver[0][i][-1] > 0 and \
	   ( solver[0][i][-1] < solver[1][i][-1] or solver[1][i][-1] == 0 ) and \
	   ( solver[0][i][-1] < result or result == -1 ):
		result = solver[0][i][-1]

for i in range( 1, n - 1 ):

	if solver[0][0][i] > 0 and \
	   ( solver[0][0][i] < solver[1][0][i] or solver[1][0][i] == 0 ) and \
	   ( solver[0][0][i] < result or result == -1 ):
		result = solver[0][0][i]

	if solver[0][-1][i] > 0 and \
	   ( solver[0][-1][i] < solver[1][-1][i] or solver[1][-1][i] == 0 ) and \
	   ( solver[0][-1][i] < result or result == -1 ):
		result = solver[0][-1][i]

if result == -1:
	print( "IMPOSSIBLE" )
else:
	print( result )
