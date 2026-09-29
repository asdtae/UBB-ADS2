/*
Mathe Ruben-Joonathan
    mrim2553
    512/1

    parci3 / 03
    prob-Kartyak_Vizsga
*/
#include <iostream>
#include <vector>

using namespace std;

void kartyak(const int n, const vector<long long int> &a) {
    long long top = 0;
    int sum = 0;

    for (int i = 0; i<n; i++) {
        if (a[i] > top) {
            top = a[i];
        }
        else if (a[i] == 0) {
            sum += top;
            top = 0;
        }
    }

    cout << sum;
}

void read(const int n, vector<long long int> &a) {
    long long int tmp;
    for (int i = 0; i<n; i++) {
        cin >> tmp;
        a[i] = tmp;
    }
}

int readN() {
    int n;
    cin >> n;
    return n;
}

int main() {
    const int n = readN();
    vector<long long int> a(n);

    read(n,a);
    kartyak(n,a);

    return 0;
}
