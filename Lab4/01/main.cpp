/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  prob-Asz2_SzegmensFa
 *
 *  Lab4/01
 *
 *  Kijelentés:
 *      Adott egy n elemű egész számokat tartalmazó a sorozat és q lekérdezés, melyeknek két típusa lehet:
 *          0. Maximum(b,j): Visszatéríti a maximális értéket ab és aj között
 *          1. Módosít(i,x): Végrehajtja az ai ← x értékadást
 *
 *  Források:
 *      (1) Algoritmusok és Adatszerkezetek 2 - 5. előadás.pdf | 14-119
 *
 */

#include <iostream>
#include <vector>
#include "ST.h"

using namespace std;

int getN()
{
    int n;
    cin >> n;
    return n;
}

void getData(vector<int> &t, const int n)
{
    t.push_back(0);

    for (int i = 1; i<=n; i++)
    {
        t.push_back(getN());
    }
}

void initRec(vector<int> &t, vector<int> &fa, const int i, const int left, const int right)
{
    if (left == right)
    {
        fa[i] = t[left];
    }
    else
    {
        int middle = (left + right) / 2;
        initRec(t,fa,i*2,left,middle);
        initRec(t,fa,i*2 + 1,middle + 1,right);
        fa[i] = min(fa[i*2],fa[i*2 + 1]);
    }
}

void init(vector<int> &t, vector<int> &fa)
{
    initRec(t,fa,1,1,t.size() - 1);
}

void run(vector<int> &fa, const int q)
{
    for (int i = 0; i<q; i++)
    {
        int mode = getN();

        if (mode == 0)
        {
            int left = getN();
            int right = getN();

            cout << maxi(fa,left,right);
        }
        else
        {
            int poz = getN();
            int val = getN();

            set(fa,poz,val);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int n = getN();
    const int q = getN();

    vector<int> t, fa(2*n + 1);
    getData(t,n);

    init(t,fa);
    run(fa,q);

    return 0;
}