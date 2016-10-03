'''
 * UVa problem: 10672
 *
 * Topic: Graph
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   The smallest move to make sure each node have one marble.
 *   Marble only move to the adjacent node.
 *
 * Solution Summary:
 *
 *   Consider it as a graph. Find out the number of neighbors, then move
 *   all marbles to it's neighbor.
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

result = 0

class Node:

	def __init__( self ):

		self.marble   = int()
		self.neighbor = list()

def move( pos, visit, tree ):

	global result

	visit[pos] = True
	count      = 0

	for i in tree[pos].neighbor:

		if not visit[i]:
			count += move( i, visit, tree )
			tree[pos].marble += tree[i].marble

	result += abs( tree[pos].marble - count - 1 )

	return count + 1

def main():

	global result

	vertices = int( input() )

	while vertices != 0:

		tree   = dict()
		visit  = list()
		result = 0

		for i in range( vertices + 1 ):

			visit.append( False )
			tree[i] = Node()

		for i in range( vertices ):

			line = list( map( int, input().split(' ') ) )

			tree[line[0]].marble = line[1]
			tree[line[0]].neighbor.extend( line[3:] )

			for j in line[3:]:
				tree[j].neighbor.append( line[0] )

		move( 1, visit, tree )

		print( result )

		vertices = int( input() )

if __name__ == "__main__":
	main()
