#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
   cin.tie(0)->sync_with_stdio(false);
   
   int a, b;
   cin >> a >> b;
   
   ll sum = 0;
   
   for (int i = a; i <= b; ++i) {
      bool seven = false;
      int temp = i;
      ll x = 0;
      while (temp > 0) {
         if (temp%10 != 7) {
            x += temp%10;
         } else {
            seven = true;
            break;
         }
         temp /= 10;
      }
      if (!seven) {
         sum += i + x;
      }
   }
   cout << sum;
}