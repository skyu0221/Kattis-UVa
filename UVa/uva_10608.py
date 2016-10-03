'''
 * UVa problem: 10608
 *
 * Topic: Data Structures
 *
 * Level: 1 points
 * 
 * Brief problem description: 
 *
 *   If friend's friend is considering as a friend, find the biggest
 *   group in all given relation.
 *
 * Solution Summary:
 *
 *   Consider it as a graph. Just find all strong connect component and
 *   print the size of SCC which has the most nodes.
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
def dfs( graph, node, seen, count, c ):

    seen[node] = True
    count[c]  += 1
    for neighbour in graph[node]:
        if not seen[neighbour]:
            dfs( graph, neighbour, seen, count, c )

def generateS( graph, node, seen, S ):

    seen[node] = True
    for neighbour in graph[node]:
        if not seen[neighbour]:
            generateS( graph, neighbour, seen, S )
    S.append(node)

def transpose( G ):

    T = dict()
    for v in G:
        T[v] = list()
    for v in G:
        for w in G[v]:
            T[w].append(v)
    return T

def scc( graph ):

    seen  = dict()
    count = list()
    S     = list()
    c     = 0

    for node in graph:
        seen[node] = False

    T = transpose(graph)
    for node in sorted(T):
        if not seen[node]:
            generateS( T, node, seen, S )

    for node in graph:
        seen[node] = False
        count.append(0)

    while len(S) > 0:
        node = S.pop()
        if not seen[node]:
            dfs( graph, node, seen, count, c )
            c += 1

    return max( count )

def main():

    cases = int( input() )

    for case in range( cases ):

        relation       = dict()
        citizen, pairs = input().split(' ')

        for i in range( int( citizen ) ):
            relation[i + 1] = list()

        for pair in range( int( pairs ) ):

            a, b = input().split(' ')
            a    = int(a)
            b    = int(b)
            if b not in relation[a]:
                relation[a].append(b)
            if a not in relation[b]:
                relation[b].append(a)

        print( scc( relation ) )

if __name__ == "__main__":
    main()
