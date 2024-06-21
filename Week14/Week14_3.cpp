#include <iostream>
#include <climits>
using namespace std;

#define MAX 100
#define INF INT_MAX

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    void dijkstra(int startVertex);

private:
    int numVertices;
    int adjMatrix[MAX][MAX];
    int minDistance(int dist[], bool sptSet[]);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = INF;
        }
    }
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
}

int Graph::minDistance(int dist[], bool sptSet[]) {
    int min = INF, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v], minIndex = v;
        }
    }
    return minIndex;
}

void Graph::dijkstra(int startVertex) {
    int dist[MAX];
    bool sptSet[MAX];

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }

    dist[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (!sptSet[v] && adjMatrix[u][v] != INF && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    Graph g(9);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << "Dijkstra's Algorithm starting from vertex 0:" << endl;
    g.dijkstra(0);

    return 0;
}
