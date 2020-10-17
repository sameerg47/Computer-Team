#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(0)->sync_with_stdio(false);
   int n; cin >> n;
   unordered_map<int, int> m;
   int res = 0;
   while (n--) {
      int t; cin >> t;
      m[t]++;
      res = max(res, m[t]);
   }
   cout << res;
}
