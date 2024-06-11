#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<string.h>

#define MAX 1000000000000007

using namespace std;

long long calculate(vector<vector<pair<int,long long>>> graph, int size, int posi, int posf);

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,long long>>> graph(n);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        int flow;
        cin >> n1 >> n2 >> flow;

        bool found = false;
        for(int i = 0; i < graph[n1 - 1].size(); i++) {
            if(graph[n1 - 1][i].first == n2 - 1) {
                graph[n1 - 1][i].second += flow;
                found = true;
                break;
            }
        }
        if(!found)
            graph[n1 - 1].emplace_back(make_pair(n2 - 1, flow));

        found = false;
        for(auto x : graph[n2 - 1]) {
            if(x.first == n1 - 1) {
                found = true;
                break;
            }
        }
        if(!found)
            graph[n2 - 1].emplace_back(make_pair(n1 - 1, 0));
    }

    cout << calculate(graph, n, 0, n-1) << endl;

    return 0;
}

bool dfs(int curr, vector<vector<pair<int,long long>>> adj, vector<pair<int,int>>* parent) {
    stack<int> lista;
    lista.push(curr);

    bool vis[adj.size()];
    memset(vis, 0, sizeof(vis));

    int current;
    while(lista.size() != 0) {
        current = lista.top();
        lista.pop();

        stack<int> prelist;
        int count = 0;
        for(auto x : adj[current]) {
            if(vis[x.first] == false && x.second > 0) {
                prelist.push(x.first);
                (*parent)[x.first].first = current;
                (*parent)[x.first].second = count;
                if(x.first == adj.size() - 1) {
                    return true;
                }
            }
            ++count;
        }

        if(!vis[current]) {
            while(prelist.size() != 0) {
                lista.push(prelist.top());
                prelist.pop();
            }
        
            vis[current] = true;
        }
    }

    return false;
}

// Ford-Fulkerson
long long calculate(vector<vector<pair<int,long long>>> graph, int size, int posi, int posf) {
    // residual graph
    vector<vector<pair<int,long long>>> rgraph(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            rgraph[i].emplace_back(graph[i][j]);
        }
    }

    // starts variables
    vector<pair<int,int>> parent(size);
    long long maximum_flow = 0;
 
    // for each path augments flow
    bool new_path = true;
    int count = 0;
    while(dfs(posi, rgraph, &parent)) {
        //cout << count++ << endl;

        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the maximum flow through the path found.
        long long path_flow = MAX;
        for (int j = posf; j != posi; j = parent[j].first) {
            int i = parent[j].first;
            int x = parent[j].second;
            
            path_flow = min(path_flow, rgraph[i][x].second);
        }
 
        // update residual capacities of the edges and reverse edges along the path
        for (int j = posf; j != posi; j = parent[j].first) {
            int i = parent[j].first;
            int x = parent[j].second;

            int y = 0;
            for(y = 0; y < rgraph[j].size(); y++)
                if(rgraph[j][y].first == i)
                    break;

            rgraph[i][x].second -= path_flow;
            rgraph[j][y].second += path_flow;
        }
 
        // Add path flow to overall flow
        maximum_flow += path_flow;
    }
 
    // Return the overall flow
    return maximum_flow;

}