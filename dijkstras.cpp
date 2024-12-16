#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijikstra(int src,int nodes,vector<vector<pair<int,int>>> &adj)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int inf = 999999;
    vector<int> dist(nodes,inf);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        pair<int,int> it = pq.top();
        pq.pop();
        int node = it.second;
        int curr_dist = it.first;
        for(auto &i:adj[node])
        {
            int weight = i.first;
            int neighbour = i.second;
            if(dist[neighbour]>(curr_dist+weight))
            {
                dist[neighbour] = curr_dist+weight;
                pq.push({dist[neighbour],neighbour});
            }
        }
    }
    return dist;
}
int main()
{
    int m,n,src;
    cout<<"Enter no.of nodes: ";
    cin>>m;
    cout<<"Enter no. of edges: ";
    cin>>n;
    vector<vector<pair<int,int>>> adj(m);
    for(int i=0;i<n;i++)
    {
        int u,v,w;
        cout<<"Enter edge(u,v,w): ";
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    cout<<"Enter source: ";
    cin>>src;
    vector<int> ans = dijikstra(src,m,adj);
    for(int i=0;i<m;i++)
    {
        cout<<"Minimum distance from "<<src<<" to "<<i<<" : "<<ans[i]<<endl;
    }

}