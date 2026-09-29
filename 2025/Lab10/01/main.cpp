/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/1
 *  prob-DP_LegnagyobbNegyzet_Info
 *
 *  Lab10/01
 *
 *  Kijelentés:
 *      Adott egy n soros és m oszlopos bitmátrix.
 *      Határozzuk meg a legnagyobb olyan négyzet oldalhosszát,
 *      amely a mátrixban található és csak 1-eseket tartalmaz!
 *
 *  Források:
 *      (1) - aa10 - Dinamikus programozas.pdf
 */

#include <iostream>
#include <vector>

using namespace std;

int getN() {
    int n;
    cin >> n;
    return n;
}

// params:
//  2D vector
//  vector size: dxw
void getData(vector<vector<int>>& bitmap, const int n, const int m) {
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) {
            cin >> bitmap[i][j];
        }
}

// params:
//  2D vector
//  vector size: dxw
void print(const vector<vector<int>>& bitmap, const int n, const int m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cout << bitmap[i][j] << ' ';
        }
        cout << endl;
    }
}

// Get Largest Square Size
// params:
//  2D vector
//  vector size: dxw
int lSquare(const vector<vector<int>>& bitmap, const int n, const int m) {
    vector<vector<int>> dp(n, vector<int>(m,0));
    int maxi = 0;

    // setup
    for (int i = 0; i<n; i++) {
        dp[i][0] = bitmap[i][0];
        if (dp[i][0] > maxi) {
            maxi = dp[i][0];
        }
    }

    for (int j = 0; j<m; j++) {
        dp[0][j] = bitmap[0][j];
        if (dp[0][j] > maxi) {
            maxi = dp[0][j];
        }
    }

    // dp resze
    for (int i = 1; i<n; i++)
    {
        for (int j = 1; j<m; j++)
        {
            if (bitmap[i][j] == 1) {
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));

                if (dp[i][j] > maxi) {
                    maxi = dp[i][j];
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}

int main() {
    // INIT
    const int n = getN();
    const int m = getN();

    vector<vector<int>> bitmap(n, vector<int>(m,0));
    getData(bitmap,n,m);

    // get height cucc
    cout << lSquare(bitmap,n,m) << endl;

    return 0;
}

/*

    4 5

    1 1 0 1 0
    0 1 1 1 1
    1 0 1 1 1
    1 1 1 1 0

 */