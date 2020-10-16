#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(0)->sync_with_stdio(false);
   int n, a[100001];
   cin >> n;
   for (int i = 0; i < n; ++i) cin >> a[i];
   sort(a, a+n);
   int ans = 0;
   for (int i = 1; i < n; i+=2) ans += a[i];
   cout << ans;
}