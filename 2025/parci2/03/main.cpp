/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/1
 *  prob_Divide_Morton_Vizsga
 *
 *  03
 *
 *  Kijelentés:
 *      ....
 *      Ismerve n értékét, határozzuk meg az adott (x,y) pozíciójú cellához tartozó sorszámot a bejárás során!
 */

#include <iostream>
#include <cmath>

using namespace std;

int getN() {
    int n;
    cin >> n;
    return n;
}

void divImp(const long long size, const long long sizePow, const long long x, const long long y, long long &sum) {
    const long long l1 = sizePow / 4;
    const long long l2 = 2 * l1;
    const long long l3 = l2 + l1;
    const long long l4 = 4 * l1;

    if (sizePow >= 1 && l1 > 0) {
        if (x <= size/2) {
            if (y <= size/2) {
                if (sizePow == 4) sum += 2 ;
                divImp(size,l1,x,y,sum);
            } else {
                sum += l1;
                if (y-size/2 > 0) divImp(size,sizePow-l2,x,y-size/2,sum);
            }
        } else {
            if (y <= size/2) {
                sum += l2;
                if (x-size/2 > 0) divImp(size,sizePow-l3,x-size/2,y,sum);
            } else {
                sum += l3;
                if (x-size/2 > 0 && y-size/2 > 0) divImp(size,sizePow-l4,x-size/2,y-size/2,sum);
            }
        }
    }
}

int main() {
    const int n = getN();
    const int x = getN();
    const int y = getN();
    const long long size = pow(2,n);
    const long long sizePow = size * size;

    long long sum = 0;
    divImp(size,sizePow,x,y,sum);
    cout << sum;

    return 0;
}
