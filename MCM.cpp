#include <iostream>
#include <climits>
#include <vector>
#include <string>
using namespace std;


void printParenthesis(int i, int j, vector<vector<int>>& split, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, split[i][j], split, name);
    printParenthesis(split[i][j] + 1, j, split, name);
    cout << ")";
}


int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1; 
    vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> split(n + 1, vector<int>(n + 1, 0));

    
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    
    cout << "Minimum number of multiplications: " << M[1][n] << endl;
    cout << "Optimal parenthesization: ";
    char name = 'A';
    printParenthesis(1, n, split, name);
    cout << endl;

    return M[1][n];
}

int main() {
    vector<int> dimensions = {40, 20, 30, 10, 30}; 
    matrixChainOrder(dimensions);
    return 0;
}
