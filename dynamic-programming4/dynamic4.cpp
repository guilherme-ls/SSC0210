#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int calculate(int n, int orcamento, int *precos, int *paginas, int *memo, bool **used);

int main() {
    int n, orcamento;
    int *precos, *paginas, *memo;
    bool **used;

    cin >> n >> orcamento;
    precos = (int *)malloc(n * sizeof(int));
    paginas = (int *)malloc(n * sizeof(int));
    memo = (int *)calloc(orcamento + 1, sizeof(int));
    used = (bool **)malloc((orcamento + 1) * sizeof(bool *));

    for(int i = 0; i < n; i++) cin >> precos[i];
    for(int i = 0; i < n; i++) cin >> paginas[i];
    for(int i = 0; i <= orcamento; i++) used[i] = (bool *)calloc(n, sizeof(bool));

    cout << calculate(n, orcamento, precos, paginas, memo, used) << endl;
}

int calculate(int n, int orcamento, int *precos, int *paginas, int *memo, bool **used) {
    for(int i = 0; i < orcamento; i++) {
        for(int j = 0; j < n; j++) {
            if(((i + precos[j]) <= orcamento) && (!used[i][j])) {
                if(memo[i + precos[j]] < (memo[i] + paginas[j])) {
                    memo[i + precos[j]] = memo[i] + paginas[j];
                    for(int k = 0; k < n; k++) used[i + precos[j]][k] = used[i][k];
                    used[i + precos[j]][j] = true;
                }
            }
        }
    }

    int maximo = 0;
    for(int i = 0; i <= orcamento; i++) {
        maximo = max(maximo, memo[i]);
    }
    return maximo;
}