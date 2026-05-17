#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
int V;
vector<vector<int>> adj;

public:
Graph(int V) {
this->V = V;
adj.resize(V);
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void DFS(int v, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited);
        }
    }
}


void BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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
g.addEdge(2, 5);

vector<bool> visited(6, false);

cout << "DFS Traversal: ";
g.DFS(0, visited);

cout << endl;

cout << "BFS Traversal: ";
g.BFS(0);

return 0;
}

