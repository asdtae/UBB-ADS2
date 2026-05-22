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

// Get Longest Continuous Sequence
// params:
//  vector pair
//  vector size
int LCS(const vector<pair<int, int>>& domino, const int n) {
    int maxi = 0;
    vector<pair<int, int>> dp(n,make_pair(0,0));

    dp[0].first = 1;
    dp[0].second = 1;

    for (int i = 1; i<n; i++) {
        if (domino[i-1].second == domino[i].first) {
            dp[i].first = 1 + dp[i-1].first;
        }
        else if (domino[i-1].second == domino[i].second) {
            dp[i].second = 1 + dp[i-1].second;
        }
        else {
            dp[i].first = 1;
            dp[i].second = 1;
        }

        if (dp[i].first > maxi) maxi = dp[i].first;
        if (dp[i].second > maxi) maxi = dp[i].second;
    }

    if (n>0 && maxi == 0) maxi = 1;

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