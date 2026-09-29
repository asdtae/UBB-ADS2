#include <iostream>
#include <vector>

using namespace std;

void epit(vector <int> &szfa , vector <int> &a, int csucs , int bal , int jobb)
{ if (bal == jobb)
    szfa [ csucs ] = a[bal ];
    else {
        int kozep = (bal + jobb) / 2;
        epit ( szfa , a, csucs * 2, bal , kozep);
        epit ( szfa , a, csucs * 2 + 1, kozep + 1, jobb);
        szfa [ csucs ] = min(szfa [ csucs * 2] , szfa [ csucs * 2 + 1]);
    }
}

int megold(vector <int> &a) {
    vector <int> szfa(a. size () * 3); // itt a hiba;
    epit ( szfa , a, 1, 1, a. size () - 1);
    return szfa [1];
}

void print(int &n) {
    cout << n;
}

int main() {
    vector<int> a;
    a.resize(36,0);

    int n = megold(a);
    print(n);

    return 0;
}
