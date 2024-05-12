#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

#define MAX 1000000007

int calculate(int n, int** memory);

int main() {
    int n;
    cin >> n;

    int **memory = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) memory[i] = (int*)malloc(n * sizeof(int));

    char entrada;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> entrada;
            if(entrada == '.')
                memory[i][j] = 0;
            else
                memory[i][j] = -1;
        }
    }

    cout << calculate(n, memory) << endl;

    for(int i = 0; i < n; i++) free(memory[i]);
    free(memory);

    return 0;
}

int calculate(int n, int **memory) {

    if(memory[0][0] == -1) return 0;
    if(memory[n-1][n-1] == -1) return 0;
    memory[n-1][n-1] = 1;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(memory[i][j] != -1 && memory[i][j] != 0) {
                if(i > 0 && memory[i-1][j] != -1) {
                    if(memory[i-1][j] == 0) memory[i-1][j] = memory[i][j];
                    else memory[i-1][j] = (memory[i][j] + memory[i-1][j]) % MAX;
                }
                if(j > 0 && memory[i][j-1] != -1) {
                    if(memory[i][j-1] == 0) memory[i][j-1] = memory[i][j];
                    else memory[i][j-1] = (memory[i][j] + memory[i][j-1]) % MAX;
                }
            }
        }
    }

    return memory[0][0];
}