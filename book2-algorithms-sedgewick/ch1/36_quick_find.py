import sys
import random


class UnionFind:

    def __init__(self, n) -> None:
        self.n = n
        self.id = [i for i in range(n)]
        self._count = n
    
    def union(self, p: int, q: int) -> None:
        pval = self.id[p]
        qval = self.id[q]
        if pval == qval: return
        for i in range(len(self.id)):
            if self.id[i] == pval:
                self.id[i] = qval
        self._count -= 1

    def find(self, p: int) -> int:
        return self.id[p]

    def connected(self, p: int, q: int) -> bool:
        return self.find(p) == self.find(q)

    def count(self) -> int:
        return self._count


if __name__ == '__main__':
    print('Union-Find Problem.')
    if len(sys.argv) <= 1:
        print('Missing data filename.')
        exit(1)

    with open(sys.argv[1]) as f:
        N = int(f.readline())
        print(f'N={N}')

        uf = UnionFind(N)

        while True:
            line = f.readline()
            if not line:
                break
            parts = line.split()
            if len(parts) < 2:
                break
            p = int(parts[0])
            q = int(parts[1])
            print(f'Connection: {p} -> {q}')
            uf.union(p, q)
        
        print(f'Components: {uf.count()}')
        
        random.seed(42)
        tests = 20
        while tests > 0:
            p = random.randint(0, N - 1)
            q = p
            while q == p:
                q = random.randint(0, N - 1)
            print(f'Connected {p}->{q}: ', uf.connected(p, q))
            tests -= 1
