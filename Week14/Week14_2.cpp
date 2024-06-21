#include <iostream>
using namespace std;

#define MAX 100

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void BFS(int startVertex);

private:
    int numVertices;
    int adjMatrix[MAX][MAX];
    bool visited[MAX];
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = false;
    }
}

void Graph::addEdge(int v, int w) {
    adjMatrix[v][w] = 1;
}

void Graph::BFS(int startVertex) {
    int queue[MAX];
    int front = 0, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int vertex = queue[front++];

        cout << vertex << " ";

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "Breadth First Traversal starting from vertex 0:" << endl;
    g.BFS(0);

    return 0;
}
