dic  = { "A":0, "A#":1, "B":2 ,"C":3, "C#":4, "D":5, "D#":6,
         "E":7, "F":8, "F#":9 ,"G":10, "G#":11 }
dic1 = [ "A", "A#", "B","C", "C#", "D", "D#", "E", "F", "F#" ,"G", "G#" ]
poss = { 
         0:  [0, 2, 4, 5, 7, 9,  11],
         1:  [0, 1, 3, 5, 6, 8,  10],
         2:  [1, 2, 4, 6, 7, 9,  11],
         3:  [0, 2, 3, 5, 7, 8,  10],
         4:  [1, 3, 4, 6, 8, 9,  11],
         5:  [0, 2, 4, 5, 7, 9,  10],
         6:  [1, 3, 5, 6, 8, 10, 11],
         7:  [0, 2, 4, 6, 7, 9,  11],
         8:  [0, 1, 3, 5, 7, 8,  10],
         9:  [1, 2, 4, 6, 8, 9,  11],
         10: [0, 2, 3, 5, 7, 9,  10],
         11: [1, 3, 4, 6, 8, 10, 11] }


cases = int( input() )
notes = input().split()

list_num = [0] * 12

for i in range( len( notes ) ):
	list_num[dic[notes[i]]] = 1

notes = []

for i in range( 12 ):
	if list_num[i] == 1:
		notes.append(i)

notes.sort()

result = []

for i in range( 12 ):

	printout = True

	for j in notes:
		if j not in poss[i]:
			printout = False
			break

	if printout:
		result.append( dic1[i] )

answer = " ".join( result )

if len( answer ) == 0:
	answer = "none"

print( answer )

'''
for i in range(12):
	temp = [0] * 7
	for j in range(7):
		temp[j] = poss[0][j]
	for j in range(7):
		temp[j] += i
		temp[j] = temp[j] % 12
	temp.sort()
	print(temp)
'''
