#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int calculate(int n, int *gomos, int* memory);

int main() {
    int n;
    int *gomos;

    // reads inputs
    cin >> n;
    gomos = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        cin >> gomos[i];
    }

    int *memory = gomos;

    //int *memory = (int*)calloc(n + 1, sizeof(int));

    int value = calculate(n, gomos, memory);
    cout << value << endl;
    return 0;
}

int calculate(int n, int *gomos, int *memory) {
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < n - j; i++) {
            memory[j + i] = max(memory[j - 1] + memory[i], memory[j + i]);
        }
    }

    return memory[n-1];
}