#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<list>

using namespace std;

bool calculate(vector<vector<int>> graph, vector<vector<int>> graph_t, int n);

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n);
    vector<vector<int>> graph_tr(n);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1 - 1].emplace_back(n2 - 1);
        graph_tr[n2 - 1].emplace_back(n1 - 1);
    }

    if(calculate(graph, graph_tr, n))
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;

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

void dfs_t(int curr, vector<vector<int>>* adj, int* vis){
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
        }
    }
}

// Kosaraju
bool calculate(vector<vector<int>> graph, vector<vector<int>> graph_t, int n) {
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
    
    int cont = 0;
    int idAtual;
    // Loop para busca em profundidadae no grafo transposto
    while(visit_stack.size() != 0) {
        // Caso ainda haja vertices nao descobertos
        idAtual = visit_stack.top();
        visit_stack.pop();

        if(vis[idAtual] == 0){
            cont++;
            dfs_t(idAtual, &graph_t, vis);
        }
    }
    
    if(cont == 1)
        return true;
    return false;
}