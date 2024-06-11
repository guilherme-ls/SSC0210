#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<algorithm>
#include<list>

using namespace std;

vector<int> calculate(vector<vector<int>> graph, vector<vector<int>> graph_t, int n);

int main() {
    int n, m, r;

    while(1) {
        cin >> n >> m;

        if(m == 0 && n == 0)
            break;
        
        vector<vector<int>> graph(n);
        vector<vector<int>> graph_tr(n);

        for(int i = 0; i < m; i++) {
            int n1, n2;
            cin >> n1 >> n2 >> r;
            graph[n1 - 1].emplace_back(n2 - 1);
            graph_tr[n2 - 1].emplace_back(n1 - 1);
            if(r == 2) {
                graph[n2 - 1].emplace_back(n1 - 1);
                graph_tr[n1 - 1].emplace_back(n2 - 1);
            }
        }

        vector<int> groups = calculate(graph, graph_tr, n);

        if(groups.size() == 1)
            cout << "amor total" << endl;
        else {
            for(int i = 0; i < groups.size(); i++)
                cout << "[" << i+1 << "," << groups[i] << "]";
            cout << endl;
        }
    }

    return 0;
}

void dfs(int curr, vector<vector<int>>* adj, int* vis, stack<int>* visit_stack) {
    stack<int> lista;
    lista.push(curr);

    int current;
    while(lista.size() != 0) {
        current = lista.top();
        if(vis[current] == 2) {
            lista.pop();
            continue;
        }

        stack<int> prelist;
        bool added = false;
        for(auto x : (*adj)[current]) {
            if (vis[x] == 0) {
                prelist.push(x);
                added = true;
            }
        }

        if(vis[current] == 0) {
            while(prelist.size() != 0) {
                lista.push(prelist.top());
                prelist.pop();
            }
        
            vis[current] = 1;
        }

        if(!added) {
            lista.pop();
            vis[current] = 2;
            (*visit_stack).push(current);
        }
    }
}

int dfs_t(int curr, vector<vector<int>>* adj, int* vis, int cor){
    stack<int> lista;
    lista.push(curr);

    int count = 0;
    int current;
    while(lista.size() != 0) {
        current = lista.top();
        lista.pop();

        if(vis[current] == 0) {
            stack<int> prelist;
            for(auto x : (*adj)[current]) {
                if(vis[x] == 0) {
                    prelist.push(x);
                }
            }

            while(prelist.size() != 0) {
                lista.push(prelist.top());
                prelist.pop();
            }
            
            vis[current] = cor;
            ++count;
        }
    }
    return count;
}

vector<int> calculate(vector<vector<int>> graph, vector<vector<int>> graph_t, int n) {
    int vis[n]; // 0 (branco) - Nao descoberto; 1 (cinza) - Descoberto; 2 (preto) - Finalizado
    stack<int> visit_stack;

    // Inicializa cor branca (= 0) em todos
    for(int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    
    // Loop para busca em profundidadae no grafo normal
    for(int i = 0; i < n; i++) {
        // Caso ainda haja vertices nao descobertos
        if(vis[i] == 0) {
            dfs(i, &graph, vis, &visit_stack);
        }
    }

    // Reinicializa cor branca (= 0) em todos
    for(int i = 0; i < n; i++){
        vis[i] = 0;
    }

    int groups[n+1];

    int cont;
    int idAtual;
    // Loop para busca em profundidadae no grafo transposto
    int cor = 1;
    while(visit_stack.size() != 0) {
        // Caso ainda haja vertices nao descobertos
        idAtual = visit_stack.top();
        visit_stack.pop();

        if(vis[idAtual] == 0) {
            cont = dfs_t(idAtual, &graph_t, vis, cor++);
            groups[cor - 1] = cont;
        }
    }

    vector<int> group;
    bool cores[cor];
    for(int i = 0; i < cor; i++) cores[i] = false;

    for(int i = 0; i < n; i++) {
        if(!cores[vis[i]]) {
            cores[vis[i]] = true;
            group.emplace_back(groups[vis[i]]);
        }
    }

    return group;
}