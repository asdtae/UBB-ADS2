/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *
 *  prob-Rendezesek2_Sort
 *  Lab2/01
 *
 *  Kijelentés:
 *      Rendezzünk egy n elemű tömböt!
 *
 *  Források:
 *      (1) Algoritmusok és Adatszerkezetek 2 - 2. előadás.pdf | 54-55
 *      (2) 06 - Programozási tételek.pdf | 50
 */
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<long long> &t, int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int size = 0;

    vector<long long> r;

    while (i <= middle && j <= right)
    {
        if (t[i] <= t[j])
        {
            r.push_back(t[i]);
            size++;
            i++;
        }
        else
        {
            r.push_back(t[j]);
            size++;
            j++;
        }
    }

    while (i <= middle)
    {
        r.push_back(t[i]);
        size++;
        i++;
    }

    while (j <= right)
    {
        r.push_back(t[j]);
        size++;
        j++;
    }

    for (i = 0; i<size; i++, left++)
    {
        t[left] = r[i];
    }
}

void mergesort(vector<long long> &t, const int left, const int right)
{
    if (left < right)
    {
        const int middle = ( left + right ) / 2;

        mergesort(t,left,middle);
        mergesort(t,middle + 1, right);

        merge(t,left,middle,right);
    }
}

int getN()
{
    int n;
    cin >> n;
    return n;
}

void getDaData(vector<long long> &t, const int n)
{
    long long tmp;

    for (int i = 0; i<n; i++)
    {
        cin >> tmp;
        t.push_back(tmp);
    }
}

void outp(vector<long long> &t, const int n)
{
    for (int i = 0; i<n; i++)
    {
        cout << t[i] << endl;
    }
}

int main()
{
    int n = getN();
    vector<long long> t;
    getDaData(t,n);

    mergesort(t,0,n-1);
    outp(t,n);

    return 0;
}
