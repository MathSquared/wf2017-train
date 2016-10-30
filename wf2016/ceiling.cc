// ICPCLA:7578
// Problem C: Ceiling Function

#include<bits/stdc++.h>
using namespace std;

struct node {
    node* lf;
    node* rt;
    int val;

    node(int v) : val(v), lf(nullptr), rt(nullptr) { }

    void insert(int v) {
        if (v < val) {
            if (lf == nullptr)
                lf = new node(v);
            else
                lf->insert(v);
        } else {
            if (rt == nullptr)
                rt = new node(v);
            else
                rt->insert(v);
        }
    }

    string fprint() {
        if (lf == nullptr) {
            if (rt == nullptr) {
                return "X";
            } else {
                return "R" + rt->fprint();
            }
        } else {
            if (rt == nullptr) {
                return "L" + lf->fprint();
            } else {
                return "B" + lf->fprint() + rt->fprint();
            }
        }
    }
};

int main() {
    int rs;cin>>rs;
    int k;cin>>k;
    set<string> fp;
    while(rs-->0) {
        int v;cin>>v;
        node t = node(v);
        for (int i = 1; i < k; i++) {
            cin>>v;
            t.insert(v);
        }
        fp.insert(t.fprint());
    }
    cout<<fp.size();
}
