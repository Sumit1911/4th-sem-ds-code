#include <iostream>
using namespace std;

#define MAX 100

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void DFS(int startVertex);

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

void Graph::DFS(int startVertex) {
    int stack[MAX];
    int top = -1;
    stack[++top] = startVertex;

    while (top >= 0) {
        int vertex = stack[top--];

        if (!visited[vertex]) {
            cout << vertex << " ";
            visited[vertex] = true;
        }

        for (int i = numVertices - 1; i >= 0; i--) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                stack[++top] = i;
            }
        }
    }
}

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

    cout << "Depth First Traversal starting from vertex 0:" << endl;
    g.DFS(0);

    return 0;
}
