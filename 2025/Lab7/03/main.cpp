/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  prob-Greedy_CiposdobozokLepesek..
 *
 *  Lab7/03
 *
 *  Kijelentés:
 *      Adva van n+1 cipősdoboz és n pár cipő,amelyek meg vannak számozva 1-től n-ig.
 *      Az n párcipő n+1 dobozban található,a dobozok közül az egyik üres.
 *      El kell rendezni a cipőket úgy,hogy minden cipő a saját dobozába kerüljön
 *      és az üres doboz a sor végére. Munka közben csak egy pár cipőt szabad ki
 *      venni a dobozból, amelyben található,és azonnal be kell tenni az üres dobozba.
 *      Állapítsuk meg a költöztetések sorozatát minimális számúművelettel.
 *
 *  Források:
 *
 *  Megj:
 *      (1) https://share.icloud.com/photos/069hSJKzxSGkbWQJbtaIGMhjA
 *
 */

// #define Black "\033[30m"
// #define Red "\033[31m"
// #define Green "\033[32m"
// #define Yellow "\033[33m"
// #define Blue "\033[34m"
// #define Magenta "\033[35m"
// #define Cyan "\033[36m"
// #define White "\033[37m"
//
// #define Bright_Black "\033[90m"
// #define Bright_Red "\033[91m"
// #define Bright_Green "\033[92m"
// #define Bright_Yellow "\033[93m"
// #define Bright_Blue "\033[94m"
// #define Bright_Magenta "\033[95m"
// #define Bright_Cyan "\033[96m"
// #define Bright_White "\033[97m"

#include <iostream>
#include <vector>

using namespace std;

int getN() {
    int n;
    cin >> n;
    return n+1;
}

void getData(const int n, vector<int> &a) {
    for (int i = 0; i<n; i++) {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
}

// void printe(const int n, const vector<int> &a) {
//     printf("%s", Bright_Cyan);  for (int i = 0; i<n; i++) cout << a[i] << ' ';
//     printf("\n%s", Bright_White);
// }

void solvecc(const int n, vector<int> &a, vector<vector<int>> &res) {
    vector<int> poz(n+1);
    int nullPoz = 0;

    for (int i = 0; i<n; i++) {
        poz[a[i]] = i;
        if (a[i] == 0) {
            nullPoz = i;
        }
    }

    int i = 0;

    while (1) {
        while (i < n-1 && a[i] == i+1) i++;

        if (i == n-1) break;

        if (nullPoz != n-1) {
            int curr = poz[nullPoz+1];
            res.push_back({curr+1,nullPoz+1});
            swap(a[curr],a[nullPoz]);

            poz[0] = curr;
            poz[nullPoz+1] = nullPoz;
            nullPoz = curr;

        } else {
            int curr = a[i];

            res.push_back({i+1,nullPoz+1});
            swap(a[i],a[nullPoz]);

            poz[0] = i;
            poz[curr] = nullPoz;
            nullPoz = i;
        }

        // printe(n,a);
    }

}

void oup(const int n, const vector<vector<int>> &res) {
    cout << res.size() << endl;
    for (int i = 0; i<res.size(); i++) cout << res[i][0] << ' ' << res[i][1] << endl;
}

int main() {
    const int n = getN();
    vector<int> a(n);
    vector<vector<int>> res;

    getData(n,a);
    solvecc(n,a,res);
    oup(n,res);

    return 0;
}
