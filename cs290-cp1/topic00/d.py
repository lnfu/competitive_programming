from heapq import *
class PQ:
    class PQnode:
        def __init__(self, value, key, neg): self.key, self.value, self.neg = key, value, neg
        def __eq__(self, that): return self.key == that.key
        def __gt__(self, that): return self.key < that.key if self.neg else self.key > that.key
        def __lt__(self, that): return self.key > that.key if self.neg else self.key < that.key
        def __str__(self): return str(self.value)
        def __repr__(self): return str(self.value)
    def __init__(self, arr = [], byMin = True, key = lambda x:x):
        self.neg = not byMin
        self.key = key
        self.pq = [self.PQnode(x, self.key(x), self.neg) for x in arr]
        heapify(self.pq)
    def push(self, x): heappush(self.pq, self.PQnode(x, self.key(x), self.neg))
    def pop(self): return heappop(self.pq).value
    def top(self): return self.pq[0].value
    def size(self): return len(self.pq)
    def __repr__(self): return str(self.pq)
    def __len__(self): return len(self.pq)
    def __bool__(self): return self.size() != 0


N, Q = map(int, input().split())

data = list()
for i in range(N):
    F, C = map(int, input().split())
    data.append((F, C))

f = list(map(int, input().split()))
for i in range(Q):
    F = f[i]
    diff = list(map(lambda t : (abs(F - t[0]), t[1]), data))
    # print(diff)
    # find 1st
    mini = 10**19
    weight = 0
    ans = 0
    for d in diff:
        if d[0] < mini:
            mini = d[0]
            weight = d[1]
    ans += weight
    mini2 = 10**19
    for d in diff:
        if d[0] == mini:
            continue
        if d[0] < mini2:
            mini2 = d[0]
            weight = d[1]
    ans += weight
    mini3 = 10**19
    for d in diff:
        if d[0] == mini:
            continue
        if d[0] == mini2:
            continue
        if d[0] < mini3:
            mini3 = d[0]
            weight = d[1]
    ans += weight
    occu = False
    for d in diff:
        if d[0] == mini3 and d[1] == weight:
            occu = True
            weight = 0
        if occu and d[0] == mini3:
            weight = d[1]
            break
    ans += weight

    if ans == 0:
        print(0, end=' ')
    elif ans > 0:
        print(1, end=' ')
    else:
        print(-1, end=' ')
        