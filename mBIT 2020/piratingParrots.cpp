#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
   cin.tie(0)->sync_with_stdio(false);
   
   int n, crateX, crateY, x = 0, y = 0;
   string s;
   cin >> n >> s >> crateX >> crateY;
   
   for (char c : s) {
      if (c == 'U') {
         ++y;
      } else if (c == 'D') {
         --y;
      } else if (c == 'R') {
         ++x;
      } else {
         --x;
      }
   }
   
   cout << abs(x - crateX) + abs(y - crateY);
}