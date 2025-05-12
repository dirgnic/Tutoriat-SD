/*
 kruskal_mst.cpp
 Kruskal's algorithm for MST using Union-Find.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {int u,v,w;};

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0){ for(int i=0;i<n;i++) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

int main(){
    int n,m; cin>>n>>m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++) cin>>edges[i].u>>edges[i].v>>edges[i].w;
    sort(edges.begin(), edges.end(), [](Edge&a,Edge&b){return a.w<b.w;});
    DSU dsu(n);
    cout<<"Edges in MST:\n";
    for(auto &e: edges){
        if(dsu.unite(e.u,e.v))
            cout<<e.u<<" - "<<e.v<<" : "<<e.w<<endl;
    }
    return 0;
}