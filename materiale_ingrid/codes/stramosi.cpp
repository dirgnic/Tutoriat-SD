#include <bits/stdc++.h>
using namespace std;

const int NMAX = 250000;
const int LOGMAX = 18; // log2(250000) is approximately 18

int up[NMAX + 1][LOGMAX + 1]; // up[i][j] = 2^j-th ancestor of i
int ancestors[NMAX + 1];

// "Care este al P-lea stramos al membrului cu numarul Q?".
void preprocess(int n) {
    for (int i = 1; i <= n; ++i) {
        up[i][0] = ancestors[i];
    }
    for (int j = 1; j <= LOGMAX; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (up[i][j - 1] != 0) {
                up[up[i][j - 1]][j - 1] = ancestors[i];
                up[i][j] = up[up[i][j - 1]][j - 1];
            } else {
                up[i][j] = 0;
            }
        }
    }
}

int getKthAncestor(int node, int k) {
    for (int j = 0; j <= LOGMAX && node != 0; ++j) {
        if (k & (1 << j)) { // daca al j ulea bit e setat pt val k
            node = up[node][j];
        }
    }
    return node;
}

int main() {
    ifstream f("stramosi.in");
    ofstream g("stramosi.out");

    int n, m;
    f >> n >> m;

    for (int i = 1; i <= n; ++i) {
        f >> ancestors[i];
    }

    preprocess(n);

    for (int i = 0; i < m; ++i) {
        int q, p;
        f >> q >> p;
        g << getKthAncestor(q, p) << "\n";
    }

    f.close();
    g.close();
    return 0;
}
