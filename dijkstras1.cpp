#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

// Function to implement Dijkstra's Algorithm
void dijkstra(int source, vector<vector<pair<int, int>>> &graph, int nodes) {
    // Step 1: Create a distance vector and initialize it with "infinity" (INT_MAX)
    vector<int> distance(nodes, INT_MAX); 
    distance[source] = 0; // Distance to the source is 0

    // Step 2: Create a priority queue to process nodes with the shortest distance first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // {distance, node}

    // Step 3: Process nodes
    while (!pq.empty()) {
        int currentDist = pq.top().first; // Distance of the current node
        int currentNode = pq.top().second; // Current node being processed
        pq.pop();

        // If the current distance is greater than the already found distance, skip it
        if (currentDist > distance[currentNode]) continue;

        // Explore all neighbors of the current node
        for (auto neighbor : graph[currentNode]) {
            int nextNode = neighbor.first;     // Neighboring node
            int edgeWeight = neighbor.second;  // Weight of the edge to the neighbor

            // Check if a shorter path is found
            if (distance[currentNode] + edgeWeight < distance[nextNode]) {
                distance[nextNode] = distance[currentNode] + edgeWeight; // Update the distance
                pq.push({distance[nextNode], nextNode}); // Push the updated distance and node to the queue
            }
        }
    }

    // Step 4: Print the shortest distances
    cout << "Shortest distances from source node " << source << ":\n";
    int totalDistance = 0; // Variable to store the sum of the shortest distances
    for (int i = 0; i < nodes; i++) {
        if (distance[i] == INT_MAX) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << ": " << distance[i] << "\n";
            totalDistance += distance[i]; // Add the distance to the total sum
        }
    }

    // Step 5: Print the sum of shortest distances
    cout << "Sum of shortest distances: " << totalDistance << endl;
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Create a graph as an adjacency list
    vector<vector<pair<int, int>>> graph(nodes);

    cout << "Enter edges (format: from to weight):\n";
    for (int i = 0; i < edges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight}); // Uncomment for undirected graph
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    // Call Dijkstra's Algorithm
    dijkstra(source, graph, nodes);

    return 0;
}
