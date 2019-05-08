#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Graph {

    int V;
    list<int>* adj;
    public:
        Graph(int n) {
            V = n;
            adj = new list<int>[n];
        }
    
        void add_edge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            vector <int> distances;
            for (int i = 0; i < V; i++) {
                distances.push_back(-1);
            }
            list<int> queue;
            bool* visited = new bool[V];
            list<int>::iterator it;
            for (int i = 0; i < V; i++) {
                visited[i] = false;
            }
            
            visited[start] = true;
            queue.push_back(start);
            distances[start] = 0;

            while (!queue.empty()) {
                start = queue.front();
                queue.pop_front();

                for (it = adj[start].begin(); it != adj[start].end(); ++it) {
                    if (!visited[*it]) {
                        visited[*it] = true;
                        queue.push_back(*it);
                        distances[*it] = distances[start] + 6;
                    }
                }
            }
            return distances;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
