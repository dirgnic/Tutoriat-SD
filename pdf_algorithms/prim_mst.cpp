/*
 prim_mst.cpp
 Prim's algorithm for Minimum Spanning Tree using adjacency matrix.
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n; cin>>n;
    vector<vector<int>> cost(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>cost[i][j];
    vector<bool> inMST(n,false);
    vector<int> dist(n, numeric_limits<int>::max()), parent(n,-1);
    dist[0]=0;
    for(int i=0;i<n;i++){
        int u=-1;
        for(int j=0;j<n;j++) 
            if(!inMST[j] && (u==-1 || dist[j]<dist[u])) u=j;
        inMST[u]=true;
        for(int v=0;v<n;v++){
            if(cost[u][v] && !inMST[v] && cost[u][v]<dist[v]){
                dist[v]=cost[u][v];
                parent[v]=u;
            }
        }
    }
    cout<<"Edges in MST:\n";
    for(int i=1;i<n;i++)
        cout<<parent[i]<<" - "<<i<<" : "<<cost[parent[i]][i]<<endl;
    return 0;
}