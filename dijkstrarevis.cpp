#include<iostream>
#include<queue>
using namespace std;

vector<int> shortestPath(vector<vector<pair<int,int>>>& adj,vector<int> distance,int start){
    distance[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        int node = p.second;
        int weight = p.first;
        pq.pop();
        for(auto pair : adj[node]){
            int edgeWeight = pair.second;
            int currNode = pair.first;
            if(weight + edgeWeight < distance[currNode]) {
                distance[currNode] = weight + edgeWeight;
                pq.push({weight+edgeWeight,currNode});
            }
        }

    }

return distance;


}


int main(){
    int V;
    cin >>V;
vector<int> distance(V,10000);

}