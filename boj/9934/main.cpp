#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int k;
vector<int> A;
vector<int> tree;

void fillTree(int start, int end, int depth) {
    if (depth == k) return;

    int mid = (start+end)/2;
    tree[]
}

int main() {
    cin >> k; A.resize(pow(2, k)-1); tree.resize(pow(2, k)-1);
    for (int i=0; i<sz(A); i++) cin >> A[i];
    fillTree(0, sz(A), 0);
    printTree();
}