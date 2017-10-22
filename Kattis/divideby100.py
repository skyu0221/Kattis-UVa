a = input()
b = input()

b     = len(b)
len_a = len(a)

a     = '0' * ( b - len_a ) + a
len_a = len(a)

while ( b > 1 and a[-1] == '0' ):
	b -= 1
	a  = a[:-1]

len_a = len(a)

if b > 1:
	print( a[:len_a - b + 1] + "." + a[len_a - b + 1:] )
else:
	print( a )
