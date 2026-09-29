/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/1
 *  prob-DP_Dominok2_Info
 *
 *  Lab10/02
 *
 *  Kijelentés:
 *      Adott n dominó. Határozzuk meg a leghosszabb olyan sorozatot,
 *      mely közvetlenül egymás után következő dominókból áll és betartja
 *      a dominó játék szabályait. Adominókat el lehet forgatni 180 fokkal.
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
//  vector pair
//  vector size
void getData(vector<pair<int, int>>& domino, const int n) {
    for (int i = 0; i<n; i++)
        cin >> domino[i].first >> domino[i].second;
}

// params:
//  vector pair
//  vector size
void print(const vector<pair<int, int>>& domino, const int n) {
    for (int i = 0; i<n; i++)
        cout << domino[i].first << ' ' << domino[i].second << endl;
}

// get maxi cucc
int getMaxi(const int a, const int b) {
    if (a >= b) return a;
    return b;
}

// Get Longest Continuous Sequence
// params:
//  vector pair
//  vector size
int LCS(const vector<pair<int, int>>& domino, const int n) {
    int maxi = 1;
    vector<pair<int, int>> dp(n,make_pair(1,1));

    // dp[0].first = 1;
    // dp[0].second = 1;

    for (int i = 1; i<n; i++) {
        if (domino[i-1].second == domino[i].first) {
            dp[i].first = 1 + dp[i-1].first;
        }
        if (domino[i-1].second == domino[i].second) {
            dp[i].second = getMaxi(dp[i].second,1 + dp[i-1].first);
        }

        if (domino[i-1].first == domino[i].first) {
            dp[i].first = getMaxi(dp[i].first,1 + dp[i-1].second);
        }
        if (domino[i-1].first == domino[i].second) {
            dp[i].second = getMaxi(dp[i].second,1 + dp[i-1].second);
        }

        if (dp[i].first > maxi) maxi = dp[i].first;
        if (dp[i].second > maxi) maxi = dp[i].second;
    }

    return maxi;
}

int main() {
    const int n = getN();
    vector<pair<int, int>> domino(n,make_pair(0,0));
    getData(domino,n);

    cout << LCS(domino,n) << endl;

    return 0;
}

/*

    6

    4 2
    2 3
    3 4
    3 5
    6 9
    5 7

 */