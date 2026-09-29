/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  prob-Greedy_MatrixOsszeg_Info
 *
 *  Lab7/01
 *
 *  Kijelentés:
 *      Adott egy n × m-es mátrix. Határozzuk meg azt a legnagyobb
 *      n elemű összeget, amelyet úgy kapunk meg, hogy minden elem
 *      a mátrix különböző soraiból “származik” és az i. sorból
 *      kiválasztott elem kisebb mint az i+1. sorból kiválasztott elem.
 *
 *  Források:
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int getN() {
    int n;
    cin >> n;
    return n;
}

void getdata(const int n, const int m, vector<vector<long>> &a) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            long tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }
}

long progi(const int n, const int m, vector<vector<long>> &a, bool &err)
{
    long sum = 0;
    long prev = 0;

    long maxi = INT32_MIN;
    for (int j = 0; j<m; j++) {
        if (a[n-1][j] > maxi ) maxi = a[n-1][j];
    }

    prev = maxi;
    sum += maxi;

    for (int i = n-2; i>=0; i--)
    {
        long maxi = INT32_MIN;

        for (int j = 0; j<m; j++) {
            if (a[i][j] > maxi && prev>a[i][j]) maxi = a[i][j];
        }

        if (maxi == INT32_MIN) {
            err = true;
            return 0;
        }

        prev = maxi;
        sum += maxi;
    }

    return sum;
}

void test(const int n, const int m, vector<vector<long>> &a) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    const int n =getN();
    const int m = getN();
    bool err = false;
    vector<vector<long>> a(n,vector<long>(m));

    getdata(n,m,a);
    long res = progi(n,m,a,err);

    if (!err) cout << res << endl;
    else cout << "nincs megoldas" << endl;

    //test(n,m,a);

    return 0;
}
