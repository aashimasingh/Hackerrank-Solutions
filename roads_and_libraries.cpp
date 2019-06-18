#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.

class Graph {
    public:
    int V;
    list<int> *adj;
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge (int u, int v) {
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    void DFS(int v, bool visited[],long &count) {
        visited[v] = true;
        count++;
        list<int>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); ++it) {
            if (!visited[*it])
                DFS(*it, visited, count);
        }
    }
    long connectedComp(int c1, int c2) {
        bool visited[V]; 
        long cost = 0;
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
              long count = 0;
              DFS(i, visited, count);
              cost += (((count - 1) * c1) + c2);
            }
        }
        return cost;
    }
};
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    Graph g(n);
    long cost = 0;
    for (int i = 0; i < cities.size(); i++) {
        g.addEdge(cities[i][0], cities[i][1]);
    }
    if (c_road >= c_lib)
        return ((long)n * (long)c_lib);
    else 
        cost = g.connectedComp(c_road, c_lib);
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
