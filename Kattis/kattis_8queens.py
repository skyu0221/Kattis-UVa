'''
 * Kattis ID: 8queens
 *
 * Topic: Backtracking
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   Check if give queen board valid or not.
 *
 * Solution Summary:
 *
 *   Each queen should have unique x, y, x+y, x-y
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

    checker = []
    checker_tl_lr = []
    checker_ll_tr = []
    row = 0
    valid = True

    while row < 8 and valid:

        line = input()
        
        try:
            col = line.index('*')

            if '*' in line[col + 1:]:
                raise ValueError()
            
            if col in checker:
                raise ValueError()
            else:
                checker.append( col )

            if ( col - row ) in checker_tl_lr:
                raise ValueError()
            else:
                checker_tl_lr.append( col - row )

            if ( col + row ) in checker_ll_tr:
                raise ValueError()
            else:
                checker_ll_tr.append( col + row )

        except ValueError:
            print( "invalid" )
            valid = False

        else:
            row += 1

    if valid:
        print( "valid" )

if __name__ == "__main__":
    main()
