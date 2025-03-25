#include <iostream>
#include <fstream>
using namespace std;
//divquery
ifstream f("divquery.in");
ofstream g("divquery.out");

const int NMAX = 100000;
int a[NMAX + 1];
int rmq[NMAX + 1][20], LOG[NMAX + 1];

int cmmdc(int a, int b)
{
    if (b == 0) return a;
    int r;
    r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}


//query in O(log(n)), merge si pe functii neidempotente
int query2(int x, int y) {
    int diff = y - x + 1;
    int st = x;
    int sol = a[st];
    for(int i = 0; (1 << i) <= diff; i++) {
        if((1 << i) & diff) {
            sol = cmmdc(sol, rmq[st][i]);
            st += (1 << i);
        }
    }
    return sol;
}


int main() {
   int n, q;
   f >> n >> q;

    for(int i = 1; i <= n; i++) {
        f >> a[i];
    }
    for(int i = 2; i <= n; i++) {
        LOG[i] = LOG[i / 2] + 1;
    }
    for(int i = 1; i <= n; i++) {
        rmq[i][0] = a[i];
    }

     for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmq[i][j] = cmmdc(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }

    int a, b;
    
    for(int i=0; i<q-1; i++) {
      f>>a>>b;
      g <<  query2(a, b) << "\n";
    }
    f>>a>>b;
      g <<  query2(a, b);

    return 0;
}


