#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long

class UnionFind {  
private:
    vi p, rank, setSize;                     
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);             
        setSize.assign(N, 1);              
        numSets = N;                               
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }    
    int sizeOfSet(int i) { return setSize[findSet(i)]; } 

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;            
        int x = findSet(i), y = findSet(j);        
        if (rank[x] > rank[y]) swap(x, y);    
        p[x] = y;                        
        if (rank[x] == rank[y]) ++rank[y];   
        setSize[y] += setSize[x];  
        --numSets;
    }
};

int main() {
   cin.tie(0)->sync_with_stdio(false);
   int n, m, sum = 0;
   cin >> n >> m;
   vector<tuple<int, int, int>> edgeList(m);
   for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      edgeList[i] = {c, a, b};
      sum += c;
   }
   sort(edgeList.begin(), edgeList.end());
   
   int num_taken = 0;
   UnionFind UF(n);
   for (int i = 0; i < m; ++i) {
      auto [w, u, v] = edgeList[i];
      if (UF.isSameSet(u, v)) continue;
      sum -= w;
      UF.unionSet(u, v);
      ++num_taken;
      if (num_taken == n-1) break;
   }
   
   cout << sum;
}