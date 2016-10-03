'''
 * Kattis ID: haypoints
 *
 * Topic: ?
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Given a dict, word -> points, and given some description.
 *   Print the points in this description
 *
 * Solution Summary:
 *
 *   Use dictionary and for loop check each word in dict or not.
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
def main():

	dict_length, desc_num = input().split(' ')
	desc_num = int( desc_num )
	dictionary = dict()
	total_value = 0

	for i in range( int( dict_length ) ):

		word, value = input().split(' ')
		dictionary[word] = int( value )

	while desc_num != 0:

		line = input()

		if line != '.':
			line = line.split(' ')
			for word in line:
				if word in dictionary.keys():
					total_value += dictionary[word]

		else:
			desc_num -= 1
			print(total_value)
			total_value = 0

if __name__ == "__main__":
	main()
