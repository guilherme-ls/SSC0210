#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

#define MAX 1000000007

using namespace std;

void calculate(vector<vector<pair<int,long long>>> graph, int size, int posi, int posf);

long long maximum = 0;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,long long>>> graph(n);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        long long dist;
        cin >> n1 >> n2 >> dist;
        graph[n1 - 1].emplace_back(make_pair(n2 - 1, dist));
        maximum += dist;
    }
    ++maximum;

    calculate(graph, n, 0, n-1);

    return 0;
}

struct myComp {
    constexpr bool operator()(pair<int, long long*> const& a, pair<int, long long*> const& b) const noexcept {
        return *(a.second) > *(b.second);
    }
};

// Dijkstra
void calculate(vector<vector<pair<int,long long>>> graph, int size, int posi, int posf) {
    long long dist[size];
    vector<int> paths(size);
    vector<long long> min(size);
    vector<long long> max(size);
    vector<pair<int,long long*>> heap;
    vector<bool> selected(size);

    // initial definition of both vectors
    for(int i = 0; i < size; i++) {
        dist[i] = maximum;
        min[i] = maximum;
        max[i] = 0;
        selected[i] = false;
    }

    // current pos
    dist[posi] = 0;
    min[0] = 0;
    paths[posi] = 1;
    --size;
    int posc = posi;

    // Loop para encontrar menor caminho entre os vertices
    while(1) {
        // define lista de arestas a ser analisada
        vector<pair<int,long long>> vertex = graph[posc];
        for(int i = 0; i < vertex.size(); i++) {
            pair<int,long long> posa = vertex[i];
            if(dist[posc] + posa.second < dist[posa.first]) {
                dist[posa.first] = dist[posc] + posa.second;
                paths[posa.first] = paths[posc]  % MAX;
                min[posa.first] = min[posc] + 1;
                max[posa.first] = max[posc] + 1;

                if(!selected[posa.first]) {
                    selected[posa.first] = true;
                    heap.push_back(make_pair(posa.first, &(dist[posa.first])));
                    push_heap(heap.begin(), heap.end(), myComp());
                }
                else {
                    make_heap(heap.begin(), heap.end(), myComp());
                }
            }
            else if(dist[posc] + posa.second == dist[posa.first]) {
                paths[posa.first] = (paths[posa.first] + paths[posc]) % MAX;
                if(min[posa.first] > min[posc] + 1)
                    min[posa.first] = min[posc] + 1;
                if(max[posa.first] < max[posc] + 1)
                    max[posa.first] = max[posc] + 1;
            }
        }
        // no more vertices
        if(size == 0) {
            break;
        }

        if(heap.size() == 0) {
            cout << "Deu algum problema incrivel" << endl;
            break;
        }

        // selects the heaps' top
        pop_heap(heap.begin(), heap.end(), myComp());
        posc = (*(heap.end() - 1)).first;
        heap.pop_back();
        --size;
    }

    cout << dist[posf] << " " << paths[posf] % MAX << " " << min[posf] << " " << max[posf] << endl;
}