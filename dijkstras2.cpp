#include<iostream>
#include<queue>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

void dijkstra(int src, vector<vector<pair<int, int>>> &graph, int nodes){

    vector<int> distance(nodes, INT_MAX);
    distance[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        //for the elements which are at top position of queue
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop(); //remove the corrent src from queue

        if(currDist > distance[currNode]) continue;  //continue if current node is greater than preexiting node

//loop for other neighboring nodes
        for(auto neighbor : graph[currNode]){
            int nxtNode = neighbor.first;
            int edgewt = neighbor.second;

            if(distance[currNode] + edgewt < distance[nxtNode] ){
                distance[nxtNode] = distance[currNode] + edgewt;
                pq.push({distance[nxtNode], nxtNode});
            }
        }
    }

    cout<<"shortest distance from source " << src << endl;
    int totalDist = 0;
    for(int i = 0; i<nodes; i++){
        if(distance[i] == INT_MAX){
            cout<<"Node "<<i<< ": unreachable"<<endl;
        } else{
            cout<<"Node "<<i<<": "<<distance[i]<<endl;
            totalDist += distance[i];
        }
    }

    cout<<"Total distance is: "<<totalDist<<endl;

}
int main(){
    int nodes, edges;
    cout<<"Enter the number of nodes and edges:";
    cin>>nodes>>edges;

    vector<vector<pair<int, int>>> graph(nodes);

    cout<<"Enter the edges(source, destination, weight):\n";
    for(int i=0; i<edges; i++){
        int source, destination, weight;
        cin>>source>>destination>>weight;

        graph[source].push_back({destination, weight});
        graph[destination].push_back({source, weight});
    }

    int src;
    cout<<"Enter the source node: ";
    cin>>src;

    dijkstra(src, graph, nodes);

    return 0;
}

// Enter the number of nodes and edges: 
// 5 6
// Enter edges (format: from to weight):
// 0 1 4
// 0 2 1
// 2 1 2
// 1 3 1
// 2 3 5
// 3 4 3
// Enter the source node:
// 0
