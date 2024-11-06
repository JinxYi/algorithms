
from collections import defaultdict, deque
from queue import PriorityQueue
import math
from heapq import heappush, heappop, heapify
# Class to represent a graph using adjacency list


class Graph:
    def __init__(self):
        self.adjList = defaultdict(list)
        self.vertices = 0
        self.nodes = 0

    # Function to add an edge to the graph
    def addEdge(self, u, v, g):
        self.nodes += 1
        self.vertices += 1
        self.adjList[u].append((g, v))  # each neighbour node contains node

    def update_node_priority(self, pq, node_to_update, new_priority):
        return [(new_priority, node_to_update) if node == node_to_update else (priority, node) for priority, node in pq]

    
    def ucs(self, startNode, target):
        # Create a queue for BFS
        queue = []
        visited = [False] * self.nodes
        node_cost = [math.inf] * self.nodes
        path = []

        # Mark the current node as visited and enqueue it
        visited[startNode] = True
        heappush(queue, (0, startNode))  # start node has g(n)=0

        # Iterate over the queue
        while queue:
            print("queue", queue)
            # dequeue
            frontier_cost, frontier_node = heappop(queue)
            print("Visiting:", frontier_node, ", cost:", frontier_cost)
            path.append(frontier_node)

            if frontier_node == target:
                print("Found target", target)
                return path

            # queue the elements in the array
            for cost, node in self.adjList[frontier_node]:
                # cost of edge + parent cost
                new_node_cost = cost+frontier_cost
                if not visited[node]:
                    visited[node] = True
                    heappush(queue, (new_node_cost, node))
                    node_cost[node] = new_node_cost
                else:
                    if node_cost[node] > new_node_cost:
                        print("update priority", node, node_cost[node], new_node_cost)
                        node_cost[node] = new_node_cost
                        queue = self.update_node_priority(queue, node, new_node_cost)
                        heapify(queue)
                
        return None


# Create a graph
graph = Graph()

# Add edges to the graph
# addEdge in this order: u, v, cost g(n)
graph.addEdge(0, 1, 2)
graph.addEdge(0, 2, 3)
graph.addEdge(0, 3, 1)
graph.addEdge(1, 3, 1)
graph.addEdge(1, 4, 3)
graph.addEdge(2, 4, 2)

# Perform BFS traversal starting from vertex 0
print("Uniform Cost Search Traversal starting from vertex 0:")
print("Traversal order:", graph.ucs(0, 4))
