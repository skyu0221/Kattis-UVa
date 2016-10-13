EPS = 1e-8
INF = 0x3f3f3f3f

class LinearProgramming:

	def __init__( self, n, m ):

		self.__basic = list()
		self.__row   = list()
		self.__col   = list()
		self.__c0    = list()
		self.__n     = 0
		self.__m     = 0

	def dcmp( value ):

		if value > EPS:
			return 1
		else if value < -EPS:
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
