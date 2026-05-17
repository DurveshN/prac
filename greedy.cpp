#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; 


void primMST(int V, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    
    key[0] = 0;
    pq.push({0, 0}); 

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;

       
        for (auto it : adj[u]) {
            int weight = it.first;
            int v = it.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

   
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }
}


int main() {
    int V = 5;

    vector<vector<pii>> adj(V);

 
    adj[0].push_back({2, 1});
    adj[1].push_back({2, 0});

    adj[0].push_back({6, 3});
    adj[3].push_back({6, 0});

    adj[1].push_back({3, 2});
    adj[2].push_back({3, 1});

    adj[1].push_back({8, 3});
    adj[3].push_back({8, 1});

    adj[1].push_back({5, 4});
    adj[4].push_back({5, 1});

    adj[2].push_back({7, 4});
    adj[4].push_back({7, 2});

    primMST(V, adj);

    return 0;
}
