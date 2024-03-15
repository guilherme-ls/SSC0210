#include<cstdio>
#include<cstdlib>

using namespace std;

int main() {
    int cases;
    int n, m;
    int max_line, min_column, max_column;
    char tile;

    scanf("%d", &cases);

    for(int i = 0; i < cases; i++) {
        int black = 0;
        scanf("%d %d", &n, &m);
        getchar();
        max_line = max_column = 0;
        min_column = m;

        for(int j = 0; j < n; j++) {
            for(int h = 0; h < m; h++) {
                tile = getchar();
                if(tile == 'B') {
                    black++;
                    if(n - j > max_line) {
                        max_line = n - j;
                    }
                    if(h > max_column) {
                        max_column = h;
                    }
                    if(h < min_column) {
                        min_column = h;
                    }
                }
            }
            getchar();
        }
        if(black > 0) {
            printf("%d %d\n", max_line, max_column - min_column + 1);
        }
        else {
            printf("0 0\n");
        }
    }

    return 0;
}