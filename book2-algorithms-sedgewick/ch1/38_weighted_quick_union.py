import sys
import random


class UnionFind:

    def __init__(self, n) -> None:
        self.n = n
        self.id = [i for i in range(n)]
        self.size = [1 for _ in range(n)]
        self._count = n
    
    def union(self, p: int, q: int) -> None:
        i = self.find(p)
        j = self.find(q)
        if i == j: return
        if self.size[i] < self.size[j]:
            self.id[i] = j
            self.size[j] += self.size[i]
        else:
            self.id[j] = i
            self.size[i] += self.size[j]
        self._count -= 1

    def find(self, p: int) -> int:
        while p != self.id[p]:
            parent = self.id[p]
            self.id[p] = parent # path compression
            p = parent
        return p

    def connected(self, p: int, q: int) -> bool:
        return self.find(p) == self.find(q)

    def count(self) -> int:
        return self._count
    


def main():
    print('UnionFind Problem - Quick Union Algorithm.')
    if len(sys.argv) <= 1:
        print('Missing data filename.')
        exit(1)
    with open(sys.argv[1]) as f:
        N = int(f.readline())
        uf = UnionFind(N)
        print(f'N={N}')
        while True:
            line = f.readline()
            if not line:
                break
            parts = line.split()
            if len(parts) < 2:
                break
            p = int(parts[0])
            q = int(parts[1])
            if N < 1000:
                print(f'Connection: {p} -> {q}')
            uf.union(p, q)

        print(f'Components: {uf.count()}')
        
        random.seed(42)
        tests = 10
        while tests > 0:
            p = random.randint(0, N - 1)
            q = p
            while q == p:
                q = random.randint(0, N - 1)
            print(f'Connected {p}->{q}: ', uf.connected(p, q))
            tests -= 1

if __name__ == '__main__':
    main()
