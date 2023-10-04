#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distances[u]) {
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dist + weight < distances[v]) {
                distances[v] = dist + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int N, M; // Number of nodes and edges
    cin >> N >> M;

    vector<vector<Edge>> graph(N + 1);
    vector<int> distances(N + 1, INF);

    // Input edges and their weights
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For undirected graph
    }

    int startNode;
    cin >> startNode; // Starting node for Dijkstra's algorithm

    dijkstra(graph, startNode, distances);

    // Output the shortest distances from the start node to all other nodes
    for (int i = 1; i <= N; ++i) {
        if (distances[i] == INF) {
            cout << "INF ";
        } else {
            cout << distances[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
