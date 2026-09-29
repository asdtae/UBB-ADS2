/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *
 *  Labor 07
 *
 */
#include <iostream>

using namespace std;

int getN() {
    int n;
    cin >> n;
    return n;
}

void outPerm(vector<int> &t) {
    for (int i = 1; i <= t.size(); i++) {
        cout << t[i] << ' ';
    }
    cout << endl;
}

void outVar(vector<int> &t, int k) {
    for (int i = 1; i <= k; i++) {
        cout << t[i] << ' ';
    }
    cout << endl;
}

void perm(int n, int k, vector<int> &t, vector<bool> &fq)
{
    if (k > n) {
        outPerm(t);
    }
    else {
        for (int i = 1; i<=n; i++)
        {
            if (fq[i] == false) {
                t[k] = i;
                fq[k] = true;
            }
            else continue;

            perm(n,k + 1,t,fq);

            fq[k] = false;
        }
    }
}

void var(int n, int k, int lvl, vector<int> &t, vector<bool> &fq)
{
    if (lvl > k)
    {
        outVar(t,k);
    }
    else
    {
        for (int i = 1; i<=n; i++)
        {
            if (fq[i] == false) {
                t[lvl] = i;
                fq[i] = true;
            }
            else continue;

            var(n,k,lvl + 1,t,fq);

            fq[i] = false;
        }
    }
}

void comb(int n, int k, int lvl, vector<int> &t, vector<bool> &fq)
{
    if (lvl > k)
    {
        outVar(t,k);
    }
    else
    {
        for (int i = 1; i<=n; i++)
        {
            if (fq[i] == false) {
                t[lvl] = i;
                fq[i] = true;
            }
            else continue;

            var(n,k,lvl + 1,t,fq);
        }
    }
}

int main()
{
    const int n = getN();
    const int k = getN();
    vector<int> t;
    vector<bool> fq;

    t.resize(n);
    fq.resize(n+1);

    //perm(n,1,t,fq);
    //var(n,k,1,t,fq);

    comb(n,k,1,t,fq);
}