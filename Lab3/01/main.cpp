/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  prob-Asz2_DiszjunktHalmazok
 *
 *  Lab3/01
 *
 *  Kijelentés:
 *      Adott n számhalmaz, melyek kezdetben egyetlen elemet
 *      tartalmaznak 1-től n-ig és q művelet. A következő két
 *      műveletet hajthatjuk végre rajtuk:
 *
 *  Források:
 *      (1) Algoritmusok és Adatszerkezetek 2 - 3. előadás.pdf | 44
 *
 */
#include <iostream>
#include <vector>
#include "DSU.h"

using namespace std;

void setup(vector<int> &t, const int n)
{
    for (int i=1; i<=n; i++)
    {
        t.push_back(i);
    }
}

int getN()
{
    int n;
    cin >> n;
    return n;
}

void print(vector<int> &t)
{
    for (int i=0; i<t.size(); i++)
    {
        cout << i << " ";
    }

    cout << endl;

    for (int i=0; i<t.size(); i++)
    {
        cout << t[i] << " ";
    }

    cout << endl;
}

void getData(int &mode, int &x, int &y)
{
    cin >> mode >> x >> y;
}

void run(vector<int> &t, const int q)
{
    int mode, x, y;

    for (int i = 0; i<q; i++)
    {
        getData(mode,x,y);

        if (mode == 1)
        {
            egyesit(t,x,y);
        }
        else
        {
            keres(t,x,y);
        }
    }
}

int main()
{
    const int n = getN();
    const int q = getN();
    vector<int> t = {0};

    setup(t,n);
    run(t,q);

    return 0;
}