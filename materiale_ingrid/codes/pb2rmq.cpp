#include <iostream>
#include <fstream>
using namespace std;

ifstream f("consecutive.in");
ofstream g("consecutive.out");

/*consecutive1: Se dă un șir (a[1], a[2], ..., a[n]) de numere naturale cuprinse între 1 și n. Se dau de asemenea Q interogări, 
fiecare prin două numere x, y: dacă s-ar ordona a[x], a[x+1], ..., a[y], se obține sau nu o secvență de numere consecutive? 
(De exemplu, 5,3,6,4 dacă e ordonată se obține 3,4,5,6, care este o secvență de numere consecutive).*/

const int NMAX = 100000;
int a[NMAX + 1];
int rmq[NMAX + 1][20], rmq1[NMAX + 1][20], LOG[NMAX + 1];

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



int query1min(int x, int y) {
    int k = LOG[y - x + 1];
    return min(rmq[x][k], rmq[y - (1 << k) + 1][k]);
}
int query1max(int x, int y) {
    int k = LOG[y - x + 1];
    return max(rmq1[x][k], rmq1[y - (1 << k) + 1][k]);
}

   int v[100001];

int query(int x, int y)
{   
    int mini = query1min(x, y);
    int maxi = query1max(x, y);
    int k = (maxi - mini + 1 == y - x + 1);
    if(!k)
        return 0;
    for(int i =0; i<y-x+1; i++) v[i] = 0;
  
    for(int i = x; i <=y; i++)
    {
        v[a[i] - mini] ++;

    }
    for(int i = 0; i < y-x+1; i++)
    {
        //cout << v[i]   << " ";
        if(v[i] ==0)
            return 0;
    }
   
  //  cout << endl;
    return 1;

}

int main() {
   int n, q;
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

       for(int i = 1; i <= n; i++) {
        rmq1[i][0] = a[i];
    }
    //val minime
     for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    // val maxime
     for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmq1[i][j] = max(rmq1[i][j - 1], rmq1[i + (1 << (j - 1))][j - 1]);
        }
    }

    int a, b;
    int vect[200001] = {0};
    cin>> q;
    for(int i=0; i<q; i++) {
      cin>>a>>b;
      vect[i] = query(a, b) ;
    }
    
    for(int i=0; i<q; i++) cout << vect[i];


    return 0;
}


