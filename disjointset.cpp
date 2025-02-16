#include<iostream>
using namespace std;


class DisjointSet{
    vector<int> rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i =0;i<=n;i++) parent[i] =i;
    }

    int findParent(int node){
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u,int v) {
       int ultimateParent_u = findParent(u);
       int ultimateParent_v = findParent(v);
       if(ultimateParent_u == ultimateParent_v) return;

       if(rank[ultimateParent_u] < rank[ultimateParent_v]) parent[ultimateParent_u] = ultimateParent_v;
       else if(rank[ultimateParent_v] < rank[ultimateParent_u]) parent[ultimateParent_v] = ultimateParent_u;
       else {
        parent[ultimateParent_v] = ultimateParent_u;
        rank[ultimateParent_u]++;
       } 
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
if(ds.findParent(3) == ds.findParent(7)) cout <<"SAME";
else cout << "Not Same";
cout << endl;
ds.unionByRank(3,7);
if(ds.findParent(3) == ds.findParent(7)) cout <<"SAME";
else cout << "NOT Same";

}
