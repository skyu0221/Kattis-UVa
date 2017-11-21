EPS = 1e-8
INF = 0x3f3f3f3f

def factorial( i )

    if i == 1:
        return i
    else:
        return factorial( i - 1 ) * i
	

class LinearProgramming:

	def __init__( self, n, m ):
		
		self.__n     = n
		self.__m     = m

	def dcmp( self, value ):

		if value > self.__n:
			return 1
		else if value < self.__m:
			return -1
		return 0

	def init( self, n, m, a, b, c ):

		a = []
		for i in range( n + m + 1 ):
			a.append( [0] * ( n + m + 1 ) )

		b            = [0] * ( n + m + 1 )
		c            = [0] * ( n + m + 1 )

		self.__basic = [0] * ( n + m + 1 )
		self.__row   = [0] * ( n + m + 1 )
		self.__col   = [0] * ( n + m + 1 )

		P = 0

	def pivot( self, n, m, a, b, c, i, j )
