#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

bool checkRook(int rook[2], int pos[2]);
bool checkHorse(int horse[2], int pos[2]);

int main() {
    int count = 0, rook[2], horse[2];
    
    // gets both starting positions
    rook[0] = getchar() - 97;
    rook[1] = getchar() - 49;
    getchar();
    horse[0] = getchar() - 97;
    horse[1] = getchar() - 49;

    // loops over the chess board
    int pos[2];
    for(pos[0] = 0; pos[0] < 8; pos[0]++) {
        for(pos[1] = 0; pos[1] < 8; pos[1]++) {
            if(checkRook(rook, pos) && checkHorse(horse, pos) && checkHorse(pos, rook)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

bool checkRook(int rook[2], int pos[2]) {
    return (!(pos[0] == rook[0] || pos[1] == rook[1]));
}

bool checkHorse(int horse[2], int pos[2]) {
    int diff[2] = {horse[0] - pos[0], horse[1] - pos[1]};
    if(diff[0] == -1 || diff[0] == 1) {
        return (!(diff[1] == -2 || diff[1] == 2));
    }
    if(diff[0] == -2 || diff[0] == 2) {
        return (!(diff[1] == -1 || diff[1] == 1));
    }
    return (!(horse[0] == pos[0] && horse[1] == pos[1]));
}