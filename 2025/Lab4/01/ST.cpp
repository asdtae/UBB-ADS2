#include <vector>

using namespace std;

int maxi(vector<int> &fa, const int left, const int right)
{

}

void setRec(vector<int> &fa, const int poz, const int value, const int i, const int left, const int right)
{

}

void set(vector<int> &fa, const int poz, const int value)
{
    int middle = fa.size() / 2;

}


// if (left == right)
// {
//     fa[i] = t[left];
// }
// else
// {
//     int middle = (left + right) / 2;
//     initRec(t,fa,i*2,left,middle);
//     initRec(t,fa,i*2 + 1,middle + 1,right);
//     fa[i] = min(fa[i*2],fa[i*2 + 1]);
// }