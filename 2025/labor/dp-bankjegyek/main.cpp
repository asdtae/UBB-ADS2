/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/1
 *
 *  12. labor
 *
 *  1. bankjegyek
 */

#include <iostream>
#include <vector>

#define Black "\033[30m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Cyan "\033[36m"
#define White "\033[37m"

#define Bright_Black "\033[90m"
#define Bright_Red "\033[91m"
#define Bright_Green "\033[92m"
#define Bright_Yellow "\033[93m"
#define Bright_Blue "\033[94m"
#define Bright_Magenta "\033[95m"
#define Bright_Cyan "\033[96m"
#define Bright_White "\033[97m"

using namespace std;

int getN() {
    int n;
    cin >> n;
    return n;
}

void getData(vector<int> &bjegyek, const int n) {
    for (int i = 1; i<n; i++) {
        cin >> bjegyek[i];
    }
}

void print(const vector<int> &t, const int n) {
    for (int i = 0; i<n; i++) {
        if (t[i] != -1) {
            printf("%s%d%s ",Bright_Cyan,t[i],White);
        } else {
            printf("%s%d%s ",Bright_Red,t[i],White);
        }
    }
    printf("\n");
}

void printMatrix(const vector<vector<int>> &t, const vector<int> &m, const int n, const int S) {
    printf("     ");

    for (int i = 1; i<S; i++) {
        printf("%s%d ",Bright_White,i);
    }
    printf("\n");

    for (int i = 1; i<n; i++) {
        printf("%s%d ",Bright_White,m[i]);

        for (int j = 0; j<S; j++) {
            if (t[i][j] != 0 && t[i][j] != -1) {
                if (i == 1 || t[i-1][j] == 0) {
                    if (t[i][j] != j) {
                        printf("%s%d ",Bright_Yellow,t[i][j]);
                    } else {
                        printf("%s%d ",Bright_Cyan,t[i][j]);
                    }
                } else {
                    if (t[i][j] != j) {
                        printf("%s%d ",Yellow,t[i][j]);
                    } else {
                        printf("%s%d ",Cyan,t[i][j]);
                    }
                }
            }
            else printf("%s%d ",White,t[i][j]);
        }
        printf("\n");
    }
    printf("%s\n",Bright_White);
}

vector<int> getMinSol(const vector<int> &bjegyek, const int n, int S) {
    vector<int> sol;
    vector<vector<int>> dp(n+1, vector<int>(S+1, 0));

    for (int i = 0; i<=n; i++) dp[i][0] = -1;

    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=S; j++)
        {
            if (dp[i-1][j] != 0)
            {
                dp[i][j] = dp[i-1][j];
            }
            else if (j >= bjegyek[i] && dp[i-1][j-bjegyek[i]] != 0)
            {
                dp[i][j] = i;
                // printf("%sDEBUG: %sj:%s%d%s bjegyek[i]:%s%d%s i:%s%d%s j-bjegyek[i]:%s%d%s dp[i-1][j-bjegyek[i]]:%s%2d %s\n",
                //     Bright_Magenta,Magenta,Bright_White,j,Magenta,
                //     Bright_White,bjegyek[i],Magenta,
                //     Bright_White,i,Magenta,
                //     Bright_White,j-bjegyek[i],Magenta,
                //     Bright_White,dp[i-1][j-bjegyek[i]]
                //     ,White);
            }
        }
    }

    // printMatrix(dp,bjegyek,n+1,S+1);

    int i = n;
    int j = S;
    int oldS = S;
    int timeOut = n;

    while (S > 0 && timeOut > 0) {
        if (dp[i][j] != 0) sol.push_back(bjegyek[dp[i][j]]);
        S -= bjegyek[dp[i][j]];

        j = oldS - bjegyek[dp[i][j]];
        while (dp[i][j] != i && i>0) i--;

        oldS = S;
        timeOut--;
    }

    if (timeOut == 0 && sol.empty()) {
        sol.clear();
        sol.push_back(-1);
        return sol;
    }

    return sol;
}

void uTest(const vector<int> &bjegyek, const int n, const int nrOfTests) {
    for (int i = 1; i<=nrOfTests; i++) {
        const vector<int> sol = getMinSol(bjegyek,n,i);

        if (sol[0] == -1) {
            printf("%s%d%s : ",Bright_Red,i,White);
        } else {
            printf("%s%d%s : ",Bright_Green,i,White);
        }
        print(sol,sol.size());
    }
}

int main() {
    const int n = getN();
    // const int S = getN();

    vector<int> bjegyek(n+1,0);
    getData(bjegyek,n+1);

    cout << endl;

    // const vector<int> sol = getMinSol(bjegyek,n,S);
    // print(sol,sol.size());

    cout << "nr of tests: ";
    int S;
    cin >> S;

    uTest(bjegyek,n,S);

    return 0;
}
