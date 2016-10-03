'''
 * UVa problem: 714
 *
 * Topic: Binary Search
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   Find the minimum number of page per person to maximum the worker.
 *
 * Solution Summary:
 *
 *   Because cannot work half book, so set minimum to the number of page
 *   which is the largest. And then set the maximum to sum of all books.
 *   Then each time cut down half and see answer is in which half.
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

def judge( mid, pages, scriber ):
    check = len( pages ) - 1
    for i in range( scriber ):

        all_sum = 0
        
        while all_sum + pages[check] <= mid:

            all_sum += pages[check]
            if check == 0:
                return True
            check -= 1
            
    return False

def main():

    cases = int( input() )

    for case in range( cases ):

        book, scriber = input().split(' ')
        scriber = int( scriber )

        pages = list( map( int, input().split(' ') ) )

        start = min( pages )
        end = sum( pages )

        while start < end:
            
            mid = ( start + end ) / 2
            
            if judge( mid, pages, scriber ):
                if end == mid:
                    break
                end = mid
            else:
                if start == mid:
                    break
                start = mid
        if not judge( mid, pages,scriber ):
            mid += 1

        pages.reverse()
        scribe = 0
        i = 0
        while i < len( pages ):

            if scribe + pages[i] <= mid:
                scribe += pages[i]
                pages[i] = str( pages[i] )
            else:
                scribe = pages[i]
                pages[i] = str( pages[i] )
                pages.insert( i, '/' )
                i += 1

            i += 1
        pages.reverse()
        diff = scriber - len( pages ) + int( book ) - 1
        pos = 0
        while diff != 0:
            if pages[pos] != '/' and pages[pos + 1] != '/':
                pages.insert( pos + 1, '/' )
                diff -= 1
            pos += 1
            
        print( " ".join( pages ) )
if __name__ == "__main__":
    main()
