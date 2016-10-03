'''
 * UVa problem: 11329
 *
 * Topic: State Space Search
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   find the smallest move to get all dot on the dice
 *
 * Solution Summary:
 *
 *   Hardest one. Have to try several times to decrease the size of list.
 *   Build the table of all moves and backtrack from the end status.
 *   table is 00 01 02 03
 *            04 05 06 07
 *            08 09 10 11
 *            12 13 14 15
 *   So assume 1111 - dice position 111111 - dot on dice 111111 - dice face
 *   Thus generate a number 0000-0000-0000-0000-0000-000000 as board plus dice
 *
 * Used Resources:
 *
 *   @ Morris
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 '''

def minimum( a, b ):
	if a == 0:
		return b
	if b == 0:
		return a
	if a < b:
		return a
	else:
		return b

def front( current_state, state, queue, count ):

	a = current_state & 63
	dice = a & 12
	dice |= ( ( a & 32 ) != 0 ) | ( ( ( a & 16 ) != 0 ) << 1 ) | \
	        ( ( ( a & 2 ) != 0 ) << 5 ) | ( ( ( a & 1 ) != 0 ) << 4 )
	a = ( current_state >> 6 ) & 15
	b = a

	if a >= 12 and a <= 15:
		return count

	a += 4

	change = dice | ( ( current_state >> 10 ) << 10 ) | ( a << 6 )

	if ( current_state & 1 ) != 0 and \
	   ( current_state & ( 1 << ( b + 10 ) ) ) == 0:
		change = ( change | ( 1 << ( b + 10 ) ) ) - ( 1 << 4 )
	elif ( current_state & 1 ) == 0 and \
	     ( current_state & ( 1 << ( b + 10 ) ) ) != 0:
		change = ( change - ( 1 << ( b + 10 ) ) ) | ( 1 << 4 )

	if state[change] == 0:
		count += 1
		queue[count] = change

	state[change] = minimum( state[change], state[current_state] + 1 )

	return count

def back( current_state, state, queue, count ):

	a = current_state & 63
	dice = a & 12
	dice |= ( ( ( a & 32 ) != 0 ) << 1 ) | ( ( a & 16 ) != 0 ) | \
	        ( ( ( a & 2 ) != 0 ) << 4 ) | ( ( ( a & 1 ) != 0 ) << 5 )
	a = ( current_state >> 6 ) & 15
	b = a

	if a >= 0 and a <= 3:
		return count

	a -= 4

	change = dice | ( ( current_state >> 10 ) << 10 ) | ( a << 6 )

	if ( current_state & 1 ) != 0 and \
	   ( current_state & ( 1 << ( b + 10 ) ) ) == 0:
		change = ( change | ( 1 << ( b + 10 ) ) ) - ( 1 << 5 )
	elif ( current_state & 1 ) == 0 and \
	     ( current_state & ( 1 << ( b + 10 ) ) ) != 0:
		change = ( change - ( 1 << ( b + 10 ) ) ) | ( 1 << 5 )

	if state[change] == 0:
		count += 1
		queue[count] = change

	state[change] = minimum( state[change], state[current_state] + 1 )

	return count

def right( current_state, state, queue, count ):

	a = current_state & 63
	dice = a & 48
	dice |= ( ( ( a & 8 ) != 0 ) << 1 ) | ( ( a & 4 ) != 0 ) | \
	        ( ( ( a & 2 ) != 0 ) << 2 ) | ( ( ( a & 1 ) != 0 ) << 3 )
	a = ( current_state >> 6 ) & 15
	b = a

	if a in [ 3, 7, 11, 15 ]:
		return count

	a += 1

	change = dice | ( ( current_state >> 10 ) << 10 ) | ( a << 6 )

	if ( current_state & 1 ) != 0 and \
	   ( current_state & ( 1 << ( b + 10 ) ) ) == 0:
		change = ( change | ( 1 << ( b + 10 ) ) ) - ( 1 << 3 )
	elif ( current_state & 1 ) == 0 and \
	     ( current_state & ( 1 << ( b + 10 ) ) ) != 0:
		change = ( change - ( 1 << ( b + 10 ) ) ) | ( 1 << 3 )

	if state[change] == 0:
		count += 1
		queue[count] = change

	state[change] = minimum( state[change], state[current_state] + 1 )

	return count

def left( current_state, state, queue, count ):

	#global maximum

	a = current_state & 63
	dice = a & 48
	dice |= ( ( a & 8 ) != 0 ) | ( ( ( a & 4 ) != 0 ) << 1 ) | \
	        ( ( ( a & 2 ) != 0 ) << 3 ) | ( ( ( a & 1 ) != 0 ) << 2 )
	a = ( current_state >> 6 ) & 15
	b = a

	if a in [ 0, 4, 8, 12 ]:
		return count

	a -= 1

	change = dice | ( ( current_state >> 10 ) << 10 ) | ( a << 6 )

	if ( current_state & 1 ) != 0 and \
	   ( current_state & ( 1 << ( b + 10 ) ) ) == 0:
		change = ( change | ( 1 << ( b + 10 ) ) ) - ( 1 << 2 )
	elif ( current_state & 1 ) == 0 and \
	     ( current_state & ( 1 << ( b + 10 ) ) ) != 0:
		change = ( change - ( 1 << ( b + 10 ) ) ) | ( 1 << 2 )

	if state[change] == 0:
		count += 1
		queue[count] = change

	#if change > maximum:
		#maximum = change
	#if current_state > maximum:
		#maximum = current_state

	state[change] = minimum( state[change], state[current_state] + 1 )

	return count

def main():

	#global maximum

	state = [0] * 66061249
	queue = [0] * 1760896
	count = -1

	for i in range( 16 ):

		for j in range( 64 ):

			state[ ( i << 6 ) | j ] = 1
			count += 1
			queue[count] = ( i << 6 ) | j

	i = 0

	while i <= count:

		count = front( queue[i], state, queue, count )
		count = back( queue[i], state, queue, count )
		count = right( queue[i], state, queue, count )
		count = left( queue[i], state, queue, count )

		i += 1

	#print( maximum )
	#print( count )

	cases = int( input() )

	while cases:

		cases -= 1
		input()

		board = 0

		for i in range( 4 ):

			line = list( input() )

			for j in range( 4 ):

				if line[j] == 'X':
					board |= ( 1 << ( i * 4 + j + 10 ) )
				if line[j] == 'D':
					board += ( 1 << 6 ) * ( i * 4 + j )

		if ( state[board] == 0 ):
			print( "impossible" )
		else:
			print( state[board] - 1 )

if __name__ == "__main__":
	main()
