/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  prob-Mintafeladat_HatvanyAtlag
 *
 *  Lab1/01
 *
 *  Kijelentés:
 *  Adott egy n elemű egész számokat tartalmazó sorozat és
 *  egy k természetes szám. Számítsuk ki a sorozat páratlan
 *  értékű elemei k. hatványának 109 + 7-el való osztási
 *  maradékainak átlagát!
 *
 *  Források:
 *      (1) Algo1 - 08 - Rekurzio.pdf / 30
 *
 */
#include <iostream>
#define MOD_NUMB 1000000007

using namespace std;

long long int readNumb()
{
    int n;
    cin >> n;
    return n;
}

int read(const int n)
{
    int temp;
    int newN = 0;

    for (int i = 0; i<n; i++)
    {
        cin >> temp;
        if (temp%2 == 0)
        {
            newN++;

        }
    }

    return newN;
}

long long int quickpow(long long int base, long long int exponent)
{
    if (exponent == 0)
        return 1;

    if (exponent%2 == 1)
        return base * quickpow(base*base,exponent/2);

    return quickpow(base*base,exponent);
}

void powList(int n, long long int k)
{
    
}

int main()
{
    // INIT
    int n = readNumb();
    long long int k = readNumb();

    // READ
    n = read(n);

    // pow
    powList(n,k);


    return 0;
}