#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    vector<int> queries;
    int entry;
    int objective;

    scanf("%d", &objective);

    for(int i = 0; i < 12; i++) {
        scanf("%d", &entry);
        queries.push_back(entry);
    }
    sort(queries.begin(), queries.end());

    int sum = 0;
    for(int i = 0; i < 12; i++) {
        if(sum >= objective) {
            printf("%d", i);
            return 0;
        }
        sum += queries[11-i];
    }

    printf("nao cresce");
    return 0;
}