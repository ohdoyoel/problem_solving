#include <bits/stdc++.h>
// #include "bits/stdc++.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cnt = 0;
vector<vector<bool>> gameBoard;
int moveX[4] = {0, 1, 0, 1};
int moveY[4] = {0, 0, 1, 1};

bool isBoardAllCovered() {
    for (int i = 0; i < sz(gameBoard); ++i) {
        for (int j = 0; j < sz(gameBoard[0]); ++j) {
            if (gameBoard[i][j] == true) return false;
        }
    }
    return true;
}

bool isWhite(bool b) {
    return b;
}

int numOfWhiteIn2x2Board(int x, int y) {
    int num = 0;
    for (int i = 0; i < 4; ++i) {
        if (isWhite(gameBoard[x + moveX[i]][y + moveY[i]])) num++;
    }
    return num;
}

bool isBoardIncludeUnfillablePiece() {
    for (int i = 0; i < sz(gameBoard) - 1; ++i) {
        for (int j = 0; j < sz(gameBoard[0]) - 1; ++j) {
            if (numOfWhiteIn2x2Board(i, j) == 3) return false;
        }
    }
    return true;
}

void fill2x2Board(int x, int y, int flag) {
    for (int i = 0; i < 4; ++i) {
        if (i != flag) gameBoard[x + moveX[i]][y + moveY[i]] = false;
    }
    return;
}

void erase2x2Board(int x, int y, int flag) {
    for (int i = 0; i < 4; ++i) {
        if (i != flag) gameBoard[x + moveX[i]][y + moveY[i]] = true;
    }
    return;
}

void coverBoard() {
    if ( isBoardAllCovered() ) { cnt++; return; }
    // if ( isBoardIncludeUnfillablePiece() ) { return; }
    
    for (int i = 0; i < sz(gameBoard) - 1; ++i) {
        for (int j = 0; j < sz(gameBoard[0]) - 1; ++j) {
            if (numOfWhiteIn2x2Board(i, j) == 4) {
                for (int k = 0; k < 4; ++k) {
                    fill2x2Board(i, j, k);
                    coverBoard();
                    erase2x2Board(i, j, k);
                }
            } else if (numOfWhiteIn2x2Board(i, j) == 3) {
                if (!isWhite(gameBoard[i][j])) {
                    fill2x2Board(i, j, 0);
                    coverBoard();
                    erase2x2Board(i, j, 0);
                } else if (!isWhite(gameBoard[i + 1][j])) {
                    fill2x2Board(i, j, 1);
                    coverBoard();
                    erase2x2Board(i, j, 1);
                } else if (!isWhite(gameBoard[i][j + 1])) {
                    fill2x2Board(i, j, 2);
                    coverBoard();
                    erase2x2Board(i, j, 2);
                }
                else if (!isWhite(gameBoard[i + 1][j + 1])) {
                    fill2x2Board(i, j, 3);
                    coverBoard();
                    erase2x2Board(i, j, 3);
                }
            }
        }
    }
    
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;

    for (int i = 0; i < c; ++i) {
        int h, w;
        cin >> h >> w;
        gameBoard.resize(h);
        for (int j = 0; j < h; ++j) {
            gameBoard[j].resize(w);
        }
        for (int j = 0; j < h; ++j) {
            string line;
            cin >> line;
            for (int k = 0; k < w; ++k) {
                gameBoard[j][k] = (line[k] == '.') ? true : false;
            }
        }

        cnt = 0;
        coverBoard();
        cout << cnt << endl;
    }

    return 0;
}
