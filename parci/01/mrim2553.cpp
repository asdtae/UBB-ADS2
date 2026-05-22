/*
    Mathe Ruben-Joonathan
    mrim2553
    512/1

    parci3 / 01
    prob-Backtracking_Particiok_Vizsga
*/
#include <iostream>
#include <vector>

using namespace std;

void sort(const int n, vector<int> &a) {
    vector<int> fq(n+1,0);
    int j = 0;

    for (int i = 0; i<n; i++) {
        fq[a[i]]++;
        a[i] = 0;
    }

    for (int i = n; i>=1; i--) {
        while (fq[i] > 0) {
            a[j] = i;
            fq[i]--;
            j++;
        }
    }
}

void print(const int n, vector<int> &a) {
    for (int i=0; i<n; i++)
        if (a[i] != 0) cout << a[i] << ' ';

    cout << endl;
}

void rec(const int n, int k, int &sum, vector<int> &a, int &curr, int max) {
    if (curr <= max) {
        if (sum == n) {
            sort(n,a);
            print(n,a);
            curr++;
        }
        else {
            for (int i = 1; i<=n; i++) {
                if (i + sum <= n) {
                    sum += i;
                    a[k] = i;
                    rec(n,k+1,sum,a,curr, max);
                    sum -= i;
                    a[k] = 0;
                }
                else {
                    break;
                }
            }
        }
    }
}

void run(const int n, vector<int> &a) {
    for (int i = 1; i<=n; i++) {
        a[0] = i;
        int sum = i;
        int curr = 1;

        rec(n,1,sum,a,curr,i);
    }
}

int readN() {
    int n;
    cin >> n;
    return n;
}

int main()
{
    const int n = readN();
    vector<int> a(n,0);

    run(n,a);

    return 0;
}
