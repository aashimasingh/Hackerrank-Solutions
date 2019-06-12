#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    //struct Edge* edges;
    vector<Edge> edges;
};

struct Edge* createEdge(int src, int dest, int weight) {
    struct Edge* e = new Edge;
    e->src = src;
    e->dest = dest;
    e->weight = weight;
    return e;
}
 
struct Graph* createGraph (int V, int E) {
    struct Graph* g = new Graph;
    g->V = V;
    g->E = E;
    //g->edges = new Edge[E];
    for (int i = 0; i < E; i++)
        g->edges.push_back(*createEdge(0,0,0));
    return g;
}

struct subset {
    int parent;
    int rank;
};

int myComp(const void *a, const void *b) {
  struct Edge *a1 = (struct Edge *)a;
  struct Edge *b1 = (struct Edge *)b;
  return (a1->weight > b1->weight) ||
         (a1->weight == b1->weight && (a1->src + a1->dest > b1->src + b1->dest));
}

bool comp( Edge a1, Edge b1 ) {
  return (a1.weight < b1.weight) ||
         (a1.weight == b1.weight &&
          (a1.src + a1.dest < b1.src + b1.dest));
} 

int find ( struct subset subsets[], int i ) {
    if (subsets[i].parent != i) 
        find( subsets, subsets[i].parent );
    return subsets[i].parent;
}

void Union( struct subset subsets[], int x, int y ) {
    int xroot = find( subsets, x );
    int yroot = find( subsets, y );

    if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot;
    else if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int kruskalMST(struct Graph* graph) {
    int tot = 0;
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    //qsort(graph->edges, graph->E, sizeof(graph->edges[0]), myComp);
    sort(graph->edges.begin(), graph->edges.end(), comp);

    /*for (int i = 0; i < graph->E; i++) {
        cout << graph->edges[i].src << " " << graph->edges[i].dest << " " << graph->edges[i].weight << "\n";
    }*/

    struct subset* subsets = (struct subset*) malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V-1) {
        struct Edge nextEdge = graph->edges[i++];

        int x = find( subsets, nextEdge.src );
        int y = find( subsets, nextEdge.dest );

        if (x != y) {
            result[e++] = nextEdge;
            tot += nextEdge.weight;
            //cout << nextEdge.src << " " << nextEdge.dest << "\n";
            Union(subsets, x, y);
        }
    }
    return tot;
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    struct Graph* graph = createGraph(g_nodes, g_weight.size());

    for (int i = 0; i < g_weight.size(); i++) {
        graph->edges[i].src = g_from[i]-1;
        //std::cout << graph->edges[i].src << " ";
        graph->edges[i].dest = g_to[i] - 1;
        //std::cout << graph->edges[i].dest << "\n";
        graph->edges[i].weight = g_weight[i];
    }

    int ans = kruskalMST(graph);
    //cout << ans << "\n";
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.
    fout << res;

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
