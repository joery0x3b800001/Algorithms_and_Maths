#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1005;
const int MOD = 1000000007;

int n, k;
int adjMat[MAXN][MAXN], temp[MAXN][MAXN];

void multiply(int A[MAXN][MAXN], int B[MAXN][MAXN])
{
    memset(temp, 0, sizeof(temp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                temp[i][j] = (temp[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    memcpy(A, temp, sizeof(temp));
}

void binary_exponentiation(int A[MAXN][MAXN], int b)
{
    int res[MAXN][MAXN];
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= n; i++) res[i][i] = 1;

    while (b > 0) {
        if (b & 1) {
            multiply(res, A);
        }
        multiply(A, A);
        b >>= 1;
    }
    memcpy(A, res, sizeof(res));
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adjMat[i][j];
        }
    }

    // Convert adjacency matrix to number of paths of length 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adjMat[i][j] == 1) {
                adjMat[i][j] = 1;
            } else {
                adjMat[i][j] = 0;
            }
        }
    }

    binary_exponentiation(adjMat, k);

    int num_paths = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            num_paths = (num_paths + adjMat[i][j]) % MOD;
        }
    }

    cout << "Number of paths of length " << k << ": " << num_paths << endl;

    return 0;
}