#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int calculate(string s1, string s2);

int main() {
    int n;
    string sn;
    getline(cin, sn);
    n = stoi(sn);

    string s1, s2;

    for(int i = 0; i < n; i++) {
        getline(cin, s1);
        getline(cin, s2);
        //cout << s1.length() << " and " << s2.length() << endl;
        cout << calculate(s1, s2) << endl;
    }

    return 0;
}

// Levenshtein distance
int calculate(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    int **matrix = (int**)malloc((len1 + 1) * sizeof(int*));
    for(int i = 0; i <= len1; i++) matrix[i] = (int*)calloc((len2 + 1), sizeof(int));

    // sets minimum and maximum
    for(int i = 0; i <= len1; i++) matrix[i][0] = i;
    for(int i = 0; i <= len2; i++) matrix[0][i] = i;
    
    string temp;
    int count = 0;

    for(int i = 1; i <= len2; i++) {
        for(int j = 1; j <= len1; j++) {
            int substitute = 0;
            if(s1[j-1] != s2[i-1]) substitute = 1;

            // selects the minimum cost between insertion, deletion and substitution
            matrix[j][i] = min(min(matrix[j-1][i] + 1, matrix[j][i-1] + 1), matrix[j-1][i-1] + substitute);
        }
    }

    return matrix[len1][len2];
}