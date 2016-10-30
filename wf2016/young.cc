// ICPCLA:7580
// Problem E: Forever Young
// BROKEN: TLE

#include<bits/stdc++.h>
using namespace std;

long powl(long a, int b) {
    if (!b) return 1;
    if (b==1) return a;
    if (b%2==1) return a*powl(a*a,b/2);
    return powl(a*a,b/2);
}

bool check(long y, long li, int ld, long b) {
    long res = 0;
    int dig = 0;

    while (y > 0) {
        int cd = y % b;
        if (cd >= 10) return false;
        if (dig < ld) {
            res += powl(10, dig) * cd;
        }
        dig++;
        y /= b;
    }

    //printf("%ld: %d[%ld] * %d", b, dig, res, ld);
    //cout<<endl;

    return (dig > ld) || (res >= li);
}

int main() {
    while (true) {
        long y; string l; cin>>y>>l;
        if(feof(stdin)) exit(0);

        int ldig = l.size();
        long li = stol(l);
        long b = ceil(pow(y, 1.0 / (ldig - 1)));
        while (b > 10) {
            //printf("%ld->", y);
            if (check(y, li, ldig, b)) {
                break;
            }

            b--;
        }
        cout<<b<<endl;
    }
}
