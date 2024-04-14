#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

typedef struct shore{
    int missionaries, canibals;
    bool boat;
    bool operator == (shore any){return missionaries == any.missionaries && canibals == any.canibals && boat == any.boat;}
} shore;

vector<pair<int, int>> changes = {{0,1},{0,2},{1,0},{2,0},{1,1}};

bool test(shore test) {
    return (test.missionaries == 0 || test.canibals <= test.missionaries) && test.canibals >= 0 && test.missionaries >= 0 && test.canibals <= 3 && test.missionaries <= 3;
}

bool test_reversed(shore test) {
    return (test.missionaries == 3 || test.canibals >= test.missionaries) && test.canibals >= 0 && test.missionaries >= 0 && test.canibals <= 3 && test.missionaries <= 3;
}

bool test_visited(vector<shore> visited, shore test) {
    for(int i = 0; i < visited.size(); i++){
        if(visited[i] == test)
            return true;
    }
    return false;
}

vector<shore> find_children(shore parent) {
    vector<shore> children;
    shore child;
    for(auto change : changes) {
        child = parent;

        child.canibals -= change.first;
        child.missionaries -= change.second;
        child.boat = !child.boat;

        if(test(child) && test_reversed(child)) {
            children.push_back(child);
        }
    }
    return children;
}

int solve(shore shore1, shore shore2, int step, vector<shore> visited);

int main() {
    for(int i = 0; i < 16; i++) {
        shore shore1, shore2;
        cin >> shore1.missionaries >> shore1.canibals >> shore1.boat;

        shore2.canibals = 3 - shore1.canibals;
        shore2.missionaries = 3 - shore1.missionaries;
        shore2.boat = !shore1.boat;

        vector<shore> visited;
        visited.push_back(shore1);
        int depth;

        if(test(shore1) && test(shore2)) {
            depth = solve(shore1, shore2, 0, visited);
        }
        else {
            depth = -1;
        }
        
        if(depth == -1) {
            cout << "Nao existe sol" << endl;
        }
        else {
            cout << "Profundidade da sol: " << depth << endl;
        }
    }

    return 0;
}

int solve(shore shore1, shore shore2, int step, vector<shore> visited) {
    bool boat = shore1.boat;
    if(shore1.canibals == 0 && shore1.missionaries == 0)
        return step;

    if (step > 12)
        return -1; 

    vector<shore> children = find_children((boat) ? shore1 : shore2);

    int best_sol = 99;
    for(auto child : children){
        shore temp1 = shore1;
        shore temp2 = shore2;
        
        if(boat) {
            temp1 = child;
            temp2.missionaries = 3 - child.missionaries;
            temp2.canibals = 3 - child.canibals;
            temp2.boat = 1;
    
        }
        else {
            temp2 = child;
            temp1.missionaries = 3 - child.missionaries;
            temp1.canibals = 3 - child.canibals;
            temp1.boat = 1;
        }

        if(test_visited(visited, temp1))
            continue;
        else 
            visited.push_back(temp1);
        
        int sol = solve(temp1, temp2, step + 1, visited);

        if (sol != -1 && sol < best_sol)
            best_sol = sol;
    } 

    if(best_sol == 99)
        best_sol = -1;

    return best_sol;
}
