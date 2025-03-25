#include <bits/stdc++.h>

using namespace std;

ifstream f("radixsort.in");
ofstream g("radixsort.out");

const int NMAX = 1e6;
int a[NMAX + 1];
queue<int> q[11];

int main() {
    int n;
    f >> n;
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        f >> a[i];
        mx = max(mx, a[i]);
    }
    int nrc = 0;
    while(mx > 0) {
        nrc++;
        mx /= 10;
    } // nr cif max
    int p = 1;
    for(int i = 1; i <= nrc; i++) {
        for(int j = 1; j <= n; j++) {
            int c = (a[j] / p) % 10;
            q[c].push(a[j]);
        }
        int k = 0;
        for(int j = 0; j <= 9; j++) {
            while(!q[j].empty()) {
                k++;
                a[k] = q[j].front();
                q[j].pop();
            }
        }
        p *= 10;
    }
    for(int i = 1; i <= n; i++) {
        g << a[i] << ' ';
    }
    return 0;
}

//https://www.pbinfo.ro/probleme/2700/radixsort