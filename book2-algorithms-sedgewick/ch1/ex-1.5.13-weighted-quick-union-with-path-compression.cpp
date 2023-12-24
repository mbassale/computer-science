#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
 public:
  UnionFind(size_t n) {
    count = n;
    id.resize(count, 0);
    sz.resize(count, 1);
    for (size_t i = 0; i < n; i++) {
      id[i] = i;
    }
  }

  size_t get_count() const { return count; }
  bool is_connected(int p, int q) { return find(p) == find(q); }

  int find(int p) {
    int root = p;
    while (root != id[root]) {
      root = id[root];
    }

    // path compression
    while (p != id[root]) {
      int next = id[p];
      sz[root] += sz[p];
      id[p] = root;
      p = next;
    }

    return root;
  }

  void set_union(int p, int q) {
    int p_id = find(p);
    int q_id = find(q);

    if (p_id == q_id) {
      return;
    }

    // weighted quick-union, we re-root the smallest tree
    if (sz[p_id] < sz[q_id]) {
      id[p_id] = q_id;
      sz[q_id] += sz[p_id];
    } else {
      id[q_id] = p_id;
      sz[p_id] += sz[q_id];
    }

    count--;
  }

 private:
  vector<int> id;
  vector<int> sz;
  size_t count{0};
};

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "Missing parameters" << endl;
    return EXIT_FAILURE;
  }

  ifstream fin(argv[1]);
  size_t count = 0;
  fin >> count;
  cout << "Number of Sites: " << count << endl;

  UnionFind uf(count);
  while (!fin.eof()) {
    int p, q;
    fin >> p;
    fin >> q;
    uf.set_union(p, q);
    cout << "p: " << p << " q: " << q << " Sites: " << uf.get_count() << endl;
  }

  return EXIT_SUCCESS;
}