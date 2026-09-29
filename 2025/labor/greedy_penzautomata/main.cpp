/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *
 */

#include <iostream>

using namespace std;

int getN() {
    int n;
    cin >> n;
    return n;
}

void getData(vector<pair<int,int>> &inter, const int n) {
    for (int i = 0; i<n; i++) {
        int left, right;
        cin >> left >> right;

        inter.emplace_back(left,right);
    }
}

void print(const vector<pair<int,int>> &inter, const unsigned long n) {
    for (int i = 0; i<n; i++) {
        cout << inter[i].first << ' ' << inter[i].second << endl;
    }
}

void sort(vector<pair<int,int>> &inter, const int n) {
    vector<pair<int,int>> newInter;

    for (int i = 0; i<n; i++) {
        int mini = INT16_MAX;
        int poz = 0;

        for (int j = 0; j<n; j++) {
            if (inter[j].first < mini) {
                mini = inter[j].first;
                poz = j;
            }
        }

        newInter.emplace_back(inter[poz]);
        inter[poz].first = INT16_MAX;
        inter[poz].second = INT16_MAX;
    }

    for (int i = 0; i<n; i++) {
        inter[i] = newInter[i];
    }
}

int getTill(const vector<pair<int,int>> &inter, const int from, const int n, const int x) {
    int i = from;

    while (inter[i].first <= x && i < n) {
        i++;
    }

    return i;
}

int getMaxi(const vector<pair<int,int>> &inter, const int from, const int till) {
    int maxi = INT16_MIN;
    int poz = 0;

    for (int i = from; i<till; i++) {
        if (inter[i].second > maxi) {
            maxi = inter[i].second;
            poz = i;
        }
    }

    return poz;
}

void del(vector<pair<int,int>> &inter, const int from, const int till) {
    for (int i = from; i<till; i++) {
        inter[i] = make_pair(INT16_MAX,INT16_MAX);
    }
}

void solve(vector<pair<int,int>> &inter, const int n, const int end) {
    vector<pair<int,int>> solution;
    int curr = 0;
    int from = 0;
    int till = getTill(inter,0,n,0);
    int maxi = getMaxi(inter,0,till);

    solution.emplace_back(inter[maxi]);
    curr += inter[maxi].second;
    del(inter,0,till);
    from = till;

    while (curr < end) {
        till = getTill(inter,from,n,curr);
        maxi = getMaxi(inter,from,till);

        solution.emplace_back(inter[maxi]);
        curr += inter[maxi].second;
        del(inter,from,till);
        from = till;
    }

    print(solution,solution.size());
}

int main()
{
    const int n = getN();
    const int k = getN();
    vector<pair<int,int>> inter;

    getData(inter,n);
    sort(inter,n);
    // print(inter,n);

    solve(inter,n,k);
}
