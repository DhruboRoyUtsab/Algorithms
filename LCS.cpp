#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> memo;
string X, Y;

int lcsMemo(int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    if (X[i-1] == Y[j-1]) {
        memo[i][j] = lcsMemo(i-1, j-1) + 1;
    } else {
        memo[i][j] = max(lcsMemo(i-1, j), lcsMemo(i, j-1));
    }
    return memo[i][j];
}

int main() {
    X = "AGGTAB";
    Y = "GXTXAYB";
    
    // cout << "Enter first string: ";
    // cin >> X;
    // cout << "Enter second string: ";
    // cin >> Y;
    int n = X.size();
    int m = Y.size();
    memo = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    cout << "Length of LCS: " << lcsMemo(n, m) << endl;
    return 0;
}
