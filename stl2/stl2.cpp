#include<cstdio>
#include <algorithm>
#include<vector>

struct query {
    int ID;
    int T;
    int sum;
};
typedef struct query query;

bool sorter(query const& q1, query const& q2) {
    if (q1.sum != q2.sum)
        return q1.sum < q2.sum;
    return q1.ID < q2.ID;
}

using namespace std;

int main() {
    int ID, T;
    vector<query> queries;

    while(1) {
        if(getchar() == '#') {
            break;
        }
        scanf("uery %d %d", &ID, &T);
        getchar();
        query entry = (query){ID, T, T};
        queries.push_back(entry);
    }

    int number;
    scanf("%d", &number);
    for(int i = 0; i < number; i++) {
        sort(queries.begin(), queries.end(), &sorter);
        int min = queries.front().sum;
        for(int j = 0; j < queries.size(); j++) {
            queries[j].sum -= min;
        }
        queries.front().sum = queries.front().T;
        printf("%d\n", queries.front().ID);
    }
}