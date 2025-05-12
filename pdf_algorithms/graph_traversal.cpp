/*
 graph_traversal.cpp
 DFS and BFS for adjacency-list representation.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    cout << u << " ";
    for(int v: adj[u]) if(!vis[v]) DFS(v, adj, vis);
}

void BFS(int src, vector<vector<int>>& adj) {
    vector<bool> vis(adj.size(), false);
    queue<int> q;
    vis[src] = true; q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v: adj[u]) if(!vis[v]) {
            vis[v] = true; q.push(v);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0] = {1,2}; adj[1] = {0,3,4}; adj[2] = {0}; adj[3] = {1}; adj[4] = {1};
    vector<bool> vis(n,false);
    cout << "DFS: "; DFS(0, adj, vis); cout << endl;
    cout << "BFS: "; BFS(0, adj); cout << endl;
    return 0;
}