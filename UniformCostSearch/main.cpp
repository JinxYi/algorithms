#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int index;
    int cost;

    Node(int i, int c) : index(i), cost(c) {}

    // Overloading operator for comparison in priority queue
    bool operator<(const Node& other) const {
        return cost > other.cost; // For UCS, prioritize lower cost
    }
};

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void ucs(vector<vector<pair<int, int>>> &adjList, int startNode,
         vector<bool> &visited)
{
    // Create a prioirity queue for UCS
    priority_queue<Node> q;


    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(Node(startNode, 0));

    // Iterate over the queue
    while (!q.empty())
    {
        // Dequeue a vertex from queue and print it
        Node cur = q.top();
        q.pop();
        cout << cur.index << " ";

        // Get all adjacent vertices of the dequeued vertex
        // currentNode If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for(pair<int, int> neighbor : adjList[cur.index]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                q.push(Node(neighbor.first, cur.cost + neighbor.second));
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<pair<int, int>>> &adjList, int u, int v, int weight)
{
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight)); // For undirected graph
}

int main()
{
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> adjList(vertices);

    // Add edges to the graph
    addEdge(adjList, 0, 1, 8);
    addEdge(adjList, 0, 2, 2);
    addEdge(adjList, 1, 3, 3);
    addEdge(adjList, 1, 4, 7);
    addEdge(adjList, 2, 4, 5);

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false);

    // Perform BFS traversal starting from vertex 0
    cout << "Uniform Cost Search starting from vertex 0: ";
    ucs(adjList, 0, visited);

    return 0;
}