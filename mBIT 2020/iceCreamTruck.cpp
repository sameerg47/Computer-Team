#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
   cin.tie(0)->sync_with_stdio(false);
   
   int a, b, n;
   cin >> a >> b >> n;
   
   if (5*a > b) {
      cout << (n/5)*b + (n%b)*a;
   } else {
      cout << n*a;
   }
}