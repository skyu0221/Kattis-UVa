import heapq
while 1:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    graph = {str(i):dict() for i in range(n)}
    for _ in range(m):
        x, y, f = input().split()
        f = float(f)
        graph[x][y] = f
        graph[y][x] = f

    frontier = [(-1, '0')]
    visited = dict()
    while frontier:
        node = heapq.heappop(frontier)
        if node[1] in visited:
            continue
        elif node[1] == str(n - 1):
            print(f"{-node[0]:.4f}")
        visited[node[1]] = node[0]
        for neighbor in graph[node[1]]:
            value = graph[node[1]][neighbor] * node[0]
            heapq.heappush(frontier, (value, neighbor))
