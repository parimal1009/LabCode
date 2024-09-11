#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A class to represent an edge in the graph
class Edge {
public:
    int src, dest, weight;
};

// A class to represent the graph
class Graph {
public:
    int V, E; // V: Number of vertices, E: Number of edges
    vector<Edge> edges; // List of edges

    // Constructor
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    // Function to find the subset of an element i (uses path compression)
    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }

    // Function to unite two subsets into a single subset (Union by rank)
    void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    // Function to implement Kruskal's algorithm to find MST
    void kruskalMST() {
        vector<Edge> result; // This will store the resultant MST
        int e = 0; // An index variable for the number of edges in the MST
        int i = 0; // An index variable used to sort edges

        // Step 1: Sort all the edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        // Allocate memory for creating V subsets
        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Create V single-item subsets
        for (int v = 0; v < V; ++v)
            parent[v] = v;

        // Number of edges to be taken is equal to V-1
        while (e < V - 1 && i < E) {
            // Step 2: Pick the smallest edge and increment the index for the next iteration
            Edge next_edge = edges[i++];

            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            // If including this edge doesn't cause a cycle, include it in the result
            // and increment the index of the result for the next edge
            if (x != y) {
                result.push_back(next_edge);
                Union(parent, rank, x, y);
                e++;
            }
        }

        // Print the resultant MST
        cout << "Following are the edges in the constructed MST:\n";
        for (i = 0; i < e; ++i)
            cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    }
};

int main() {
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph graph(V, E);

    // Add edges to the graph (src, dest, weight)
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Function call to perform Kruskal's algorithm
    graph.kruskalMST();

    return 0;
}
