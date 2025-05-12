#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Numar noduri: ";
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Matrice cost (0 daca nu exista muchie):\n";
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> cost[i][j];

    vector<bool> inMST(n,false);
    vector<int> dist(n, numeric_limits<int>::max());
    vector<int> parent(n,-1);

    dist[0] = 0;
    for (int k = 0; k < n; ++k) {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!inMST[i] && (u==-1 || dist[i] < dist[u]))
                u = i;
        inMST[u] = true;
        for (int v = 0; v < n; ++v) {
            if (cost[u][v] > 0 && !inMST[v] && cost[u][v] < dist[v]) {
                dist[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Muchii MST (u - v : cost):\n";
    for (int v = 1; v < n; ++v)
        cout << parent[v] << " - " << v << " : " << cost[parent[v]][v] << "\n";
    return 0;
}
