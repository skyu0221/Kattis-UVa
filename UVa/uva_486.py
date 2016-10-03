'''
 * UVa problem: 486
 *
 * Topic: Dynamic Programming
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Given an English sentence and translate it to number.
 *
 * Solution Summary:
 *
 *   Keep all key words need to do times. Transfer all others to numbers.
 *   Then start from the smallest 'times', keep doing this until all finished.
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

translator = { "zero": 0, "one": 1, "two": 2, "three":3, "four": 4, \
               "five": 5, "six": 6, "seven": 7, "eight": 8, "nine": 9, \
               "ten": 10, "eleven": 11, "twelve": 12, "thirteen": 13, \
               "fourteen": 14, "fifteen": 15, "sixteen": 16, \
               "seventeen": 17, "eighteen": 18, "nineteen": 19, \
               "twenty": 20, "thirty": 30, "forty": 40, "fifty": 50, \
               "sixty": 60, "seventy": 70, "eighty": 80, "ninety": 90 }

times = { "hundred": 100, "thousand": 1000, "million": 1000000 }

def short( result, target ):
    i = 0
    while i < len( result ):
        if result[i] == target:
            temp = result.pop( i - 1 ) * times[target]
            if i < len( result ):
                if result[i] not in times:
                    temp += result.pop( i )
            result[i - 1] = temp
        i += 1
    return result

def main():

    while True:

        try:
            line   = input().strip(' ').split(" ")
            if len( line[0] ) == 0:
                raise
            result = list()
            temp   = 0
            for element in line:
                if element == "negative":
                    pass
                elif element in translator:
                    temp   += translator[element]
                else:
                    result.append( temp )
                    temp = 0
                    result.append( element )

            result.append( temp )

            result = short( short( short( result, "hundred" ), \
                                   "thousand" ), "million" )[0]
            if line[0] == "negative":
                result = -result

            print(result)
                    
                    
        except:
            break
        
if __name__ == "__main__":
    main()
