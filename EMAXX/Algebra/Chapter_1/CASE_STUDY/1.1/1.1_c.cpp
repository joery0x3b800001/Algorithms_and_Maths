#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix_multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    vector<vector<int>> C(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < B.size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vector<vector<int>> matrix_pow(vector<vector<int>>& A, int k) {
    if (k == 0) {
        // return identity matrix
        int n = A.size();
        vector<vector<int>> I(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            I[i][i] = 1;
        }
        return I;
    } else if (k % 2 == 0) {
        // A^k = (A^(k/2))^2
        vector<vector<int>> B = matrix_pow(A, k/2);
        return matrix_multiply(B, B);
    } else {
        // A^k = A * A^(k-1)
        vector<vector<int>> B = matrix_pow(A, k-1);
        return matrix_multiply(A, B);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    int u, v;
    cin >> u >> v;

    vector<vector<int>> Ak = matrix_pow(A, k);
    int num_paths = Ak[u][v];

    cout << "Number of paths of length " << k << " from vertex " << u << " to vertex " << v << ": " << num_paths << endl;

    return 0;
}