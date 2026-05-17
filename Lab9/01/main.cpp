/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  prob-DP_Fakt_Info
 *
 *  Lab9/01
 *
 *  Kijelentés:
 *      Számoljátok ki n faktoriálisát a dinamikus programozás módszerével!
 *
 *  Források:
 *      (1) - aa09 - Dinamikus programozas.pdf
 */
#include <iostream>

using namespace std;

int getN()
{
    int n;
    cin >> n;
    return n;
}

void out(const long long &n)
{
    cout << n << endl;
}

long long fakt(long long n)
{
    long long fakt = 1;

    for (int i = 1; i <= n; i++)
    {
        fakt *= i;
    }

    return fakt;
}

int main()
{
    long long n = getN();

    n = fakt(n);
    out(n);

    return 0;
}