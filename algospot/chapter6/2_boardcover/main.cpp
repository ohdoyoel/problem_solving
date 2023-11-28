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

void printBoard() {
  for (int i = 0; i < sz(gameBoard); ++i) {
    string line;
    for (int j = 0; j < sz(gameBoard[0]); ++j) {
      if (gameBoard[i][j]) line += "W";
      else line += "B";
    }
    cout << line << endl;
  }
}

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
            if (numOfWhiteIn2x2Board(i, j) >= 3) return false;
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

bool isRowAndColAllCovered(int x, int y) {
  for (int j = 0; j < sz(gameBoard); ++j) {
    for (int i = 0; i < sz(gameBoard[0]); ++i) {
      if (gameBoard[x][i] == true || gameBoard[j][y] == true) return false;
    }
  }
  return true;
}

void coverBoard(int x, int y) {
    cout << "{" << endl;
    printBoard();

    if ( isBoardAllCovered() ) {
      cnt++;
      cout << "cnt = " << cnt << endl;
      cout << "}" << endl;
      return;
    }
    
    if ( isBoardIncludeUnfillablePiece() ) {
      cout << "Unfillable" << endl;
      cout << "}" << endl;
      return;
    }
    
    if ( isRowAndColAllCovered(x, y) ) {
      coverBoard(x + 1, y + 1);
      return;
    }
    
    for (int i = x; i < sz(gameBoard) - 1; ++i) {
        if (numOfWhiteIn2x2Board(i, y) == 4) {
            for (int k = 3; k >= 0; --k) {
                fill2x2Board(i, y, k);
                coverBoard(x, y);
                erase2x2Board(i, y, k);
                printBoard();
            }
        } else if (numOfWhiteIn2x2Board(i, y) == 3) {
            if (!isWhite(gameBoard[i][y])) {
                fill2x2Board(i, y, 0);
                coverBoard(x, y);
                erase2x2Board(i, y, 0);
                printBoard();
            } else if (!isWhite(gameBoard[i + 1][y])) {
                fill2x2Board(i, y, 1);
                coverBoard(x, y);
                erase2x2Board(i, y, 1);
                printBoard();
            } else if (!isWhite(gameBoard[i][y + 1])) {
                fill2x2Board(i, y, 2);
                coverBoard(x, y);
                erase2x2Board(i, y, 2);
                printBoard();
            }
            else if (!isWhite(gameBoard[i + 1][y + 1])) {
                fill2x2Board(i, y, 3);
                coverBoard(x, y);
                erase2x2Board(i, y, 3);
                printBoard();
            }
        }
    }
    
    for (int j = y; j < sz(gameBoard[0]) - 1; ++j) {
        if (numOfWhiteIn2x2Board(x, j) == 4) {
            for (int k = 3; k >= 0; --k) {
                fill2x2Board(x, j, k);
                coverBoard(x, y);
                erase2x2Board(x, j, k);
                printBoard();
            }
        } else if (numOfWhiteIn2x2Board(x, j) == 3) {
            if (!isWhite(gameBoard[x][j])) {
                fill2x2Board(x, j, 0);
                coverBoard(x, y);
                erase2x2Board(x, j, 0);
                printBoard();
            } else if (!isWhite(gameBoard[x + 1][j])) {
                fill2x2Board(x, j, 1);
                coverBoard(x, y);
                erase2x2Board(x, j, 1);
                printBoard();
            } else if (!isWhite(gameBoard[x][j + 1])) {
                fill2x2Board(x, j, 2);
                coverBoard(x, y);
                erase2x2Board(x, j, 2);
                printBoard();
            }
            else if (!isWhite(gameBoard[x + 1][j + 1])) {
                fill2x2Board(x, j, 3);
                coverBoard(x, y);
                erase2x2Board(x, j, 3);
                printBoard();
            }
        }
    }

    cout << "}" << endl;
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
        coverBoard(0, 0);
        cout << cnt << endl;
    }

    return 0;
}
