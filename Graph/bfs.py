
from collections import defaultdict, deque
from queue import PriorityQueue
# Class to represent a graph using adjacency list
 
 
class Graph:
    def __init__(self):
        self.adjList = defaultdict(list)
        self.vertices = 0
        self.nodes = 0
 
    # Function to add an edge to the graph
    def addEdge(self, u, v):
        self.nodes+=1
        self.vertices+=1
        self.adjList[u].append(v)
 
    # Function to perform Breadth First Search on a graph represented using adjacency list
    def bfs(self, startNode, target):
        print("received graph", self.adjList)
        # Create a queue for BFS
        queue = deque()
        visited = [False] * self.nodes
        path = []
 
        # Mark the current node as visited and enqueue it
        visited[startNode] = True
        queue.append(startNode)
 
        # Iterate over the queue
        while queue:
            # dequeue
            temp = queue.popleft()
            print("array at", temp, self.adjList[temp])
            print("Visiting:", temp)
            path.append(temp)

            # queue the elements in the array
            for val in self.adjList[temp]:
                if not visited[val]:
                    visited[val] = True
                    queue.append(val)
                    if val == target:
                        print("Found target", target)
                        return path
    
 
# Create a graph
graph = Graph()
 
# Add edges to the graph
graph.addEdge(0, 1)
graph.addEdge(0, 2)
graph.addEdge(1, 3)
graph.addEdge(1, 4)
graph.addEdge(2, 4)
 
# Perform BFS traversal starting from vertex 0
print("Breadth First Traversal starting from vertex 0:")
print("Final path:", graph.bfs(0, 4))
