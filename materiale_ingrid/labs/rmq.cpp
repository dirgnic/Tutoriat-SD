#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5;
int a[NMAX + 1];
int rmq[NMAX + 1][20], LOG[NMAX + 1];

//query in O(1), functioneaza doar pentru functii idempotente
int query1(int x, int y) {
    int k = LOG[y - x + 1];
    return min(rmq[x][k], rmq[y - (1 << k) + 1][k]);
}

//query in O(log(n)), merge si pe functii neidempotente
int query2(int x, int y) {
    int diff = y - x + 1;
    int st = x;
    int sol = 1e9;
    for(int i = 0; (1 << i) <= diff; i++) {
        if((1 << i) & diff) {
            sol = min(sol, rmq[st][i]);
            st += (1 << i);
        }
    }
    return sol;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++) {
        LOG[i] = LOG[i / 2] + 1;
    }
    for(int i = 1; i <= n; i++) {
        rmq[i][0] = a[i];
    }
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    cout << query1(2, 7) << '\n';
    cout << query2(2, 7);
    return 0;
}
/*
https://infoarena.ro/problema/rmq
https://www.pbinfo.ro/probleme/1735/divquery
https://www.pbinfo.ro/probleme/3860/consecutive1
https://www.infoarena.ro/problema/stramosi
https://www.infoarena.ro/problema/lca
https://www.youtube.com/watch?v=0jWeUdxrGm4
https://www.youtube.com/watch?v=oib-XsjFa-M

*/