// ICPCLA:7577
// Problem B: Branch Assignment

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define mp make_pair

int n,b,s,r;
vector<vector<pair<int, int>>> Gf;
vector<vector<pair<int, int>>> Gr;

vector<int> dijk(const vector<vector<ii>> G) {
    priority_queue<ii> q;
    vector<int> d(n, 0x7fffffff);
    vector<bool> vis(n);
    q.emplace(0, b);
    d[b] = 0;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (ii vl : G[u]) {
            int v = vl.first;
            int l = vl.second;
            if (d[v] > d[u] + l) {
                d[v] = d[u] + l;
                q.emplace(-d[v], v);
            }
        }
    }

    return d;
}

int main() {
    while (true) {
        cin>>n>>b>>s>>r;
        if (feof(stdin)) return 0;
        Gf.clear();
        Gr.clear();
        for (int i = 0; i < n; i++) {
            Gf.emplace_back();
            Gr.emplace_back();
        }

        for (int i = 0; i < r; i++) {
            int u,v,l; cin>>u>>v>>l;
            Gf[u-1].emplace_back(v-1,l);
            Gr[v-1].emplace_back(u-1,l);
        }

        auto df = dijk(Gf);
        auto dr = dijk(Gr);
        vector<int> d(b);
        for (int i = 0; i < b; i++)
            d[i] = df[i] + dr[i];
        sort(d.begin(), d.end());
        int extra = b - s + 1;
        for (int i = 0; i < extra; i++)
            d[i] *= extra;
        cout<<accumulate(d.begin(), d.end(), 0)<<endl;
    }
}
