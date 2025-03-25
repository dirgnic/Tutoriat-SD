
#include <bits/stdc++.h>
using namespace std;

const int NMAX = 250000;
const int LOGMAX = 18; // log2(NMAX) este aproximativ 18

vector<int> graph[NMAX + 1];
int euler[2 * NMAX]; // Reprezentarea Euler a arborelui
int level[2 * NMAX]; // Nivelul nodurilor în reprezentarea Euler
int firstOccurrence[NMAX + 1]; // Prima apariție a fiecărui nod în reprezentarea Euler
int idx; // Indexul curent în reprezentarea Euler
int RMQ[2 * NMAX][LOGMAX + 1]; // Sparse Table pentru RMQ

void dfs(int node, int lvl, int parent) {
    euler[idx] = node;
    level[idx] = lvl;
    firstOccurrence[node] = idx;
    idx++;
    
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            dfs(neighbor, lvl + 1, node);
            euler[idx] = node;
            level[idx] = lvl;
            idx++;
        }
    }
}

void preprocessRMQ(int n) {
    for (int i = 0; i < n; ++i) {
        RMQ[i][0] = i;
    }
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; (i + (1 << j) - 1) < n; ++i) {
            if (level[RMQ[i][j - 1]] < level[RMQ[i + (1 << (j - 1))][j - 1]]) {
                RMQ[i][j] = RMQ[i][j - 1];
            } else {
                RMQ[i][j] = RMQ[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int queryRMQ(int l, int r) {
    int j = log2(r - l + 1);
    if (level[RMQ[l][j]] <= level[RMQ[r - (1 << j) + 1][j]]) {
        return RMQ[l][j];
    } else {
        return RMQ[r - (1 << j) + 1][j];
    }
}

int getLCA(int u, int v) {
    int left = firstOccurrence[u];
    int right = firstOccurrence[v];
    if (left > right) {
        swap(left, right);
    }
    int lcaIndex = queryRMQ(left, right);
    return euler[lcaIndex];
}

int main() {
    ifstream f("stramosi.in");
    ofstream g("stramosi.out");

    int n, m;
    f >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int parent;
        f >> parent;
        if (parent != 0) {
            graph[parent].push_back(i);
            graph[i].push_back(parent);
        }
    }

    idx = 0;
    dfs(1, 0, -1); // Rădăcina arborelui este considerată nodul 1

    preprocessRMQ(2 * n - 1);

    for (int i = 0; i < m; ++i) {
        int q, p;
        f >> q >> p;
        g << getLCA(q, p) << "\n";
    }

    f.close();
    g.close();
    return 0;
}

/*
### Explicația codului:
1. **DFS pentru Euler Tour**:
   - Parcurgem arborele în pre-order și salvăm nodurile vizitate și nivelele acestora în `euler` și `level`.
   - Stocăm prima apariție a fiecărui nod în `firstOccurrence`.

2. **Preprocesare RMQ**:
   - Construim un Sparse Table pentru a răspunde eficient la interogările de tip RMQ pe nivelele nodurilor din reprezentarea Euler.

3. **Interogări LCA**:
   - Pentru fiecare pereche de noduri, folosim pozițiile lor în reprezentarea Euler și Sparse Table pentru a găsi nivelul minim dintre aceste poziții, ceea ce corespunde celui mai apropiat strămoș comun.

Această soluție utilizează eficient algoritmul RMQ pentru a rezolva problema LCA,
 oferind o complexitate de O(NlogN + M) și folosind O(NlogN) memorie, ceea ce este
  optim pentru restricțiile problemei. */