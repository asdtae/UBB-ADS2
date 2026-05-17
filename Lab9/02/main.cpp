/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/1
 *  prob-DP_Komb_Info
 *
 *  Lab9/02
 *
 *  Kijelentés:
 *      Számoljátok ki n elem k-ad rendű kombinációinak számát feljegyzéses módszerrel!
 *
 *  Források:
 *      (1) - https://hu.wikipedia.org/wiki/Pascal-h%C3%A1romsz%C3%B6g
 *
 */
#include <iostream>
#include <vector>

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

long long komb(const int n, const int k)
{
    vector<vector<long long>> pascal(n+2, vector<long long>(n+2, 0));

    pascal[1][1] = 1;

    for (int i = 2; i <= n+1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            // cout << pascal[i][j] << ' ';
        }

        // cout << endl;
    }

    return pascal[n+1][k+1];
}

int main()
{
    const int n = getN();
    const int k = getN();

    const long long numb = komb(n, k);
    out(numb);

    return 0;
}