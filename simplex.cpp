/*
 * Input:
 *         m        - number of constraints (integer)
 *         n        - number of variables   (integer)
 *         a        - A m by n array        (list of float)
 *         b        - An array with m value (list of float)
 *         c        - An array with n value (list of float)
 *         P        - Result                (float)
 *
 * output:
 *         P - The maximum/minimum result of function.
 *
 * Detail:
 *         Simplex Matrix will looks like that:
 * 
 *         |   c[1]   c[1]  c[2] ... c[n] |  P   |
 *         |------------------------------+------|
 *         | a[1][1]  ....  ....  a[1][n] | b[1] |
 *         |    .     .        .       .  | b[2] |
 *         |    .         ..           .  | b[3] |
 *         |    .     .        .       .  | .... |
 *         | a[m][1]  ....  ....  a[m][n] | b[m] |
 * 
 *         Relaxation form of above matrix is looks like that:
 *
 *               N:  c[1] ~ c[n]       B
 *             /--------^--------\ /---^---\
 *         |   c[1]   c[1]  c[2] ... c[n+m]    |   P    |
 *         |-----------------------------------+--------|
 *         | a[1][1]  .... .. ....  a[1][n+m]  |  b[1]  |
 *         |    .       .        .      .      |  b[2]  |
 *         |    .           ..          .      |  b[3]  |
 *         |    .       .        .      .      |  ....  |
 *         | a[n+m][1]  .. ... ..  a[n+m][n+m] | b[n+m] |
 *
 * Related Question:
 *         UVa 10498 - Happiness
 *
 * Method:
 *         Suppose we know function A, then we can find a
 *         equivalent function B such that:
 *
 *             A : minimize  c[1]x[1]+c[2]x[2]+...
 *             B : maximize -c[1]x[1]-c[2]x[2]+...
 *
 *             A : f[i](x[1], x[2], ...)  = b[i]
 *             B : f[i](x[1], x[2], ...) >= b[i] and
 *                 f[i](x[1], x[2], ...) <= b[i]
 *
 *             A :  a[1]x[1]+a[2]x[2]+... >=  b
 *             B : -a[1]x[1]-a[2]x[2]-... <= -b
 *
 *             A : x[i] can be negative
 *             B : x[i] = x[i][1] - x[i][2] and
 *                 x[i][1] >= 0 and x[i][2] >= 0
 *
 *         We should convert from any A above to B.
 *
 *         Now convert the standard form to relaxation form:
 *
 *             Add m more new variables. x[n+1] ~ x[n+m].
 *
 *                               m
 *             x[n+i] = b[i] - sigma( a[i][j]x[j] )
 *                             j = 1
 *
 *             We use N represent the [1, n] and B represent [n+1, n+m]
 *             Where N means non-basic and B means basic.
 *
 *         Now give out first function: Pivot.
 *
 *             Pivot will need two parameters 1 and e.
 *             We will exchange p in B with q in N.
 *
 *             Idea is there will have a equation:
 *                 x[p] = b[p] - sigma( a[p][j]x[j] )
 *                               j in N
 *             After exchange, equation will be:
 *                 a[p][q]x[q] = b[p] - sigma( a[p][j]x[j] - x[p] )
 *                                      j in N
 *
 *         Then the second part: Initialization.
 *
 *             Initialization will help to convert each relaxation form
 *             to an all-b-not-negative form, otherwise no solution.
 *
 *         The last past will be: Optimization.
 *
 *             Optimization will keep on pick a good p, q do pivot,
 *             until reach the optimal value.
 *             Use Bland's rule can then avoid inf loop.
 */

/* Pseudocode Here

def pivot( p, q ):

    temp_b[q]    = b[p] / a[p][q]
    temp_a[q][p] = p / a[p][q]

    for ( i in N and i != q ):
        temp_a[q][i] = a[p][i] / a[p][q]

    for ( i in B and i != p ):
        temp_b[i] = b[i] - a[i][q] * temp_b[q]
        for ( j in N and j != q ):
            temp_a[i][j] = a[i][j] - a[i][q] * temp_a[q][j]

    temp_P    = P + temp_b[q] * c[q]
    temp_c[p] = -temp_a[q][p] * c[q]

    for ( i in N and i != q ):
        temp_c[i] = c[i] - c[q] * temp_a[q][i]

    P, a, b, c = temp value
    N = N / q + p
    B = B / p + q

def initialization():

    get min(b) which called b[p]

    if ( b[p] >= 0 ):
        return INITIALIZED

    origional_c = c
    insert 0 to N

    for ( i in B ):
        a[i][0] = -1
    for ( i in N ):
        c[i] = 0

    c[0] = -1
    pivot( 1, 0 )

    optimization()

    if ( v < 0 )
        return NO_SOLUTION

    remove 0 from N
    c = origional_c

    for ( i in B and c[i] > 0 ):
        P = P + c[i] * b[i]
        for ( j in N ):
            c[j] = c[j] - a[i][j]*c[i]
        c[i] = 0

    return INITIALIZED

def optimization():

    while ( True ):

        if ( all i in N have c[i] <= 0 ):
            return SOLUTION_FOUND
        else:
            pick q that c[q] > 0

        delta = INF

        for ( i in B ):
            if ( a[i][q] > 0 and delta > b[i] / a[i][q] ):
                delta = b[i] / a[i][q]
                p     = i

        if ( delta == INF ):
            return P = INF
        else:
            pivot( p, q )

def simplex:
	initialization()
	optimization()

*/

#include <cstdio>
#include <cmath>

#define OPTIMAL    -1
#define UNBOUNDED  -2
#define FEASIBLE   -3
#define INFEASIBLE -4
#define PIVOT_OK    1
#define MAXIMUM     16357

int    n,
       m;

double P,
       a[MAXIMUM][MAXIMUM],
       b[MAXIMUM],
       c[MAXIMUM],
       x[MAXIMUM];

struct LinearProgramming {

	int    basic[MAXIMUM],
	       row  [MAXIMUM],
	       col  [MAXIMUM];
	double c0   [MAXIMUM];

	double eps( double value ) {

		if ( value > 1e-8 )
			return 1;
		else if ( value < -1e-8 )
			return -1;
		else
			return 0;
	}

	void init( int n, int m, double a[MAXIMUM][MAXIMUM], double b[], double c[], double &P ) {

		for ( int i = 0; i <= n + m ; i++ ) {

			for ( int j = 0; j <= n + m; j++ )
				a[i][j] = 0;

			b[i]     = 0;
			c[i]     = 0;

			basic[i] = 0;
			row[i]   = 0;
			col[i]   = 0;
		}

		P = 0;
	}

	int pivot( int n, int m, double a[MAXIMUM][MAXIMUM], double b[], double c[], int &i, int &j ){

		int    k   = -1;
		double min =  0x3f3f3f3f;

		for ( j = 0; j <= n; j++ )
			if ( !basic[j] && eps( c[j] ) > 0 && ( k < 0 || eps( c[j] - c[k] ) > 0 ) )
				k = j;

		j = k;

		if ( k < 0 )
			return OPTIMAL;

		k = -1;
		for ( i = 1; i <= m; i++ )
			if ( eps( a[i][j] ) > 0 && eps(b[i] / a[i][j] - min) < 0 ) {

				min = b[i] / a[i][j];
				k = i;
			}

		i = k;

		if ( k < 0 )
			return UNBOUNDED;
		else
			return PIVOT_OK;
	}

	int optimizationII( int n, int m, double a[MAXIMUM][MAXIMUM], double b[], double c[], double &P, int Status ) {

		int    i, j, k, l;
		double tmp;

		k = pivot( n, m, a, b, c, i, j );
		while ( k == PIVOT_OK || Status ) {

			if ( Status ) {

				i      = Status;
				j      = 0;
				Status = 0;
			}

			basic[row[i]] = 0;
			basic[j]      = 1;
			col[row[i]]   = 0;
			col[j]        = i;
			row[i]        = j;

			tmp           = a[i][j];

			for ( k = 0; k <= n; k++ )
				a[i][k] /= tmp;

			b[i] /= tmp;

			for ( k = 1; k <= m; k++ )
				if ( k != i && eps( a[k][j] ) ) {

					tmp = -a[k][j];

					for ( l = 0; l <= n; l++ )
						a[k][l] +=  tmp * a[i][l];

					b[k] += tmp * b[i];
                }

			tmp = -c[j];

			for ( l = 0; l <= n; l++ )
				c[l] += a[i][l] * tmp;

			P -= tmp * b[i];
			k  = pivot( n, m, a, b, c, i, j );
		}

		return k;
	}

	int optimizationI( int n, int m, double a[MAXIMUM][MAXIMUM], double b[], double c[], double &P ) {

		int    i, j, k = -1;
		double tmp,
		       min = 0,
		       P0  = 0;

		for ( i = 1; i <= m; i++ )
			if ( eps( b[i] - min ) < 0 ) {

				min = b[i];
				k   = i;
			}

		if ( k < 0 )
			return FEASIBLE;

		for ( i = 1; i <= m; i++ )
			a[i][0] = -1;
		for (j = 1; j <= n; j ++)
			c0[j] = 0;

		c0[0] = -1;

		optimizationII( n, m, a, b, c0, P0, k );

		if ( eps( P0 ) < 0 )
			return INFEASIBLE;

		for ( i = 1; i <= m; i++ )
			a[i][0] = 0;
		for ( j = 1; j <= n; j++ )
			if ( eps( c[j] ) && basic[j] ) {

				tmp  = c[j];
				P   += b[col[j]] * tmp;

				for ( i = 0; i <= n; i++ )
					c[i] -= tmp * a[col[j]][i];
			}

		return FEASIBLE;
	}

	int simplex( int n, int m, double a[MAXIMUM][MAXIMUM], double b[], double c[], double &P, double x[] ) {

		int i, j, k;

		for ( i = 1; i <= m; i++ ) {

			for ( j = n + 1; j <= n + m; j++ )
				a[i][j] = 0;

			a[i][n+i] = 1;
			a[i][0]   = 0;
			row[i]    = n+i;
			col[n+i]  = i;
		}

		k = optimizationI( n + m, m, a, b, c, P );

		if ( k == INFEASIBLE )
			return k;

		k = optimizationII( n + m, m, a, b, c, P, 0 );

		for ( j = 0; j <= n + m; j++ )
			x[j] = 0;
		for ( i = 1; i <= m; i++ )
			x[row[i]] = b[i];

		return k;
	}
};

/* Test with UVa 10498
 * https://uva.onlinejudge.org/external/104/10498.pdf
 *
 * Runtime: 0.01s
 * Rank:    11 (Highest 7, but not sure why. Happened when I organize my code)
 */

int main(){

	while(scanf("%d %d", &n, &m) != EOF){

		double            P;
		LinearProgramming ps;

		ps.init( n, m, a, b, c, P );

		for ( int i = 1; i <= n; i++ )
			scanf( "%lf", &c[i] );

		for ( int i = 1; i <= m; i++ ) {

			for ( int j = 1; j <= n; j++ ) {
				scanf("%lf", &a[i][j]);
			}
			scanf("%lf", &b[i]);
		}

		ps.simplex( n, m, a, b, c, P, x );

		printf("Nasa can spend %.0f taka.\n", ceil(m*P));
	}

	return 0;
}
