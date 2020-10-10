#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

vector<vii> adj, adjT;
vi num, s;

void scc(int i, int p) {
    num[i] = 1;
    vii &neighbor = (p == 1)? adj[i] : adjT[i];
    for (auto &[v, w] : neighbor) {
        if (num[v] == 0) {
            scc(v, p);
        }
    }
    s.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    adj.assign(n, vii()), adjT.assign(n, vii());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back({b, 1}), adjT[b].push_back({a, 1});
    }

    s.clear();
    num.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (num[i] == 0) {
            scc(i, 1);
        }
    }
    int ans = 0;
    num.assign(n, 0);
    for (int i = n-1; i >= 0; --i) {
        if (num[s[i]] == 0) {
            ++ans;
            scc(s[i], 2);
        }
    }

    cout << ans << "\n";
}