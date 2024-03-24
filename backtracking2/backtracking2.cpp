#include<iostream>
#include<vector>

using namespace std;

bool build(vector<pair<int, int>> dominoes, int n, int pos, pair<int, int> limits);

int main() {
    while(1) {
        int n, m;
        cin >> n >> m;
        if(n == 0) {
            break;
        }

        pair<int, int> left, right, middle;
        vector<pair<int, int>> dominoes;

        cin >> left.first >> left.second;
        cin >> right.first >> right.second;

        for(int i = 0; i < m; i++) {
            cin >> middle.first >> middle.second;
            dominoes.push_back(middle);
        }

        if(build(dominoes, n, 0, make_pair(left.second, right.first))) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

bool build(vector<pair<int, int>> dominoes, int n, int pos, pair<int, int> limits) {
    if(n == 0) {
        return limits.first == limits.second;
    }

    for(int i = 0; i < dominoes.size(); i++) {
        pair<int, int> temp = dominoes[i];
        dominoes.erase(dominoes.cbegin()+i);

        if(limits.first == temp.first) {
            if(build(dominoes, n-1, pos+1, make_pair(temp.second, limits.second))) {
                return true;
            }
        }
        else if(limits.first == temp.second) {
            if(build(dominoes, n-1, pos+1, make_pair(temp.first, limits.second))) {
                return true;
            }
        }
        
        dominoes.emplace(dominoes.cbegin()+i, temp);
    }

    return false;
}