/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/1
 *  Backtracking_PermutaciokInverziokkal_Vizsga
 *
 *  01
 *
 *  Kijelentés:
 *      Adottak n és k természetes számok. Írassuk ki lexikografikus sorrendben az
 *      összes olyan n elemű permutációt, melyben az inverziók száma szigorúan kisebb,
 *      mint k! Egy p permutáció inverziójának nevezünk egy (i,j) párost, ha i < j és pi > pj.
 */

#include <iostream>
#include <vector>

using namespace std;

int getN() {
    int n;
    cin >> n;
    return n;
}

void print(const vector<int> &t, const int n) {
    for (int i = 0; i<n; i++)
        cout << t[i] << ' ';
    cout << endl;
}

void bt(vector<int> &t, vector<bool> &szamok, const int n, int k, int j, bool marcsere, const int kOG) {
    if (j == n) {
        print(t,n);
        k = kOG;
    } else {
        for (int i = 1; i<=n; i++)
        {
            if (i != (j+1)) {
                if (!szamok[i] && k>0) {
                    t[j] = i;
                    j++;
                    szamok[i] = true;
                    if (!marcsere) {
                        k--;
                        marcsere = true;
                    } else marcsere = false;
                    bt(t,szamok,n,k,j,marcsere,kOG);

                    j--;
                    szamok[i] = false;
                }
            } else if (!szamok[i]) {
                t[j] = i;
                j++;
                szamok[i] = true;
                bt(t,szamok,n,k,j,marcsere,kOG);

                j--;
                szamok[i] = false;
            }
        }
    }
}

int main() {
    const int n = getN();
    const int k = getN();
    vector<int> t(n,0);
    vector<bool> szamok(n+1,false);

    bt(t,szamok,n,k,0,false,k);

    return 0;
}
