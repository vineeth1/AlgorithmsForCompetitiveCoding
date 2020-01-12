#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int> > dpair;

// Dijkstra algorithm
int main(void) {
    int n, M;
    cin >> n >> M;
    vector<vector<pair<int, int> > > adj(n);
    for (int i = 0; i < M; i++) {
        int j, k, w;
        cin >> j >> k >> w;

        adj[j].push_back(make_pair(k, w));
        adj[k].push_back(make_pair(j, w));
    }
    
    priority_queue<dpair, vector<dpair>, greater<dpair> > pq;
    vector<int> parent(n, - 1);
    vector<bool> visited(n, false);
    vector<int> distance(n);

    pq.push(make_pair(0, make_pair(0, 0)));

    while (!pq.empty()) {
        dpair temp = pq.top();
        pq.pop();
        int node = temp.second.first;
        if (!visited[node]) {
            int dist = temp.first;
            parent[node] = temp.second.second;
            visited[node] = true;
            distance[node] = dist;

            for (auto i : adj[node]) {
                if (!visited[i.first]) {
                    pq.push(make_pair(dist + i.second, make_pair(i.first, node)));
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << distance[i] << " " << parent[i] << endl;
    }
}