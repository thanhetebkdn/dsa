#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
#include <chrono> // Thư viện đo thời gian

using namespace std;
using namespace std::chrono;

struct Edge
{
    int to, weight;
};

vector<vector<Edge>> adj;
vector<int> dist, parent;
int V, E, S, D;

// Dijkstra không dùng Heap
void dijkstraNoHeap(int start)
{
    dist.assign(V + 1, INT_MAX);
    parent.assign(V + 1, -1);
    dist[start] = 0;

    vector<bool> visited(V + 1, false);

    for (int i = 0; i < V; ++i)
    {
        int u = -1;

        for (int j = 1; j <= V; ++j)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        if (dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (auto edge : adj[u])
        {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
}

// Dijkstra dùng Min-Heap (priority queue)
void dijkstraHeap(int start)
{
    dist.assign(V + 1, INT_MAX);
    parent.assign(V + 1, -1);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto edge : adj[u])
        {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

// In ra đường đi ngắn nhất
void printPath(int node, ofstream &output)
{
    if (node == -1)
        return;
    printPath(parent[node], output);
    output << node << " ";
}

int main()
{
    ifstream input("FindPath.inp");
    ofstream output("FindPath.out");

    input >> V >> E >> S >> D;
    adj.resize(V + 1);

    for (int i = 0; i < E; ++i)
    {
        int A, B, W;
        input >> A >> B >> W;
        adj[A].push_back({B, W});
        adj[B].push_back({A, W});
    }

    // Đo thời gian cho Dijkstra không dùng Heap
    auto start1 = high_resolution_clock::now();
    dijkstraNoHeap(S);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    output << dist[D] << endl;
    printPath(D, output);
    output << endl;

    cout << "Thoi gian chay Dijkstra khong dung Heap: " << duration1.count() << " microseconds" << endl;

    // Đo thời gian cho Dijkstra dùng Heap
    auto start2 = high_resolution_clock::now();
    dijkstraHeap(S);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    output << dist[D] << endl;
    printPath(D, output);
    output << endl;

    cout << "Thoi gian chay Dijkstra dung Heap: " << duration2.count() << " microseconds" << endl;

    return 0;
}
