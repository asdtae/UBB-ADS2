/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/1
 *
 *  Labor:
 *
 */

#include <iostream>

using namespace std;

int getN() {
    int n;
    cin >> n;
    return n;
}

void getData(const int n, vector<vector<int>> &a) {
    for (int i = 1; i<n; i++) {
        for (int j = 1; j<n; j++) {
            cin >> a[i][j];
        }
    }
}

void print(const int n, const vector<vector<int>> &a) {
    cout << endl;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cout << a[i][j] << ' ';
        }

        cout << endl;
    }
}

void solvecc(const int n, const int x, vector<vector<int>> &a) {
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for (int j = 1; j<x; j++) {
        for (int i = 1; i<n; i++) {
            int maxi = INT32_MIN;

            for (int o = 1; o<n; o++) {
                if (a[i][o] != 0) {
                    if (maxi < a[i][o] + dp[o][j-1]) {
                        maxi = a[i][o] + dp[o][j-1];
                    }
                }
            }

            dp[i][j] = maxi;
        }
    }

    // ...
}

int main() {
    const int n = getN();
    const int x = getN();

    vector<vector<int>> a(n+1,vector<int>(n+1,0));
    getData(n+1,a);

    print(n+1,a);
    solvecc(n+1,x+1,a);

    return 0;
}


/*

4 3
1 2 3 0
1 3 0 4
0 1 0 0
0 0 4 0

*/