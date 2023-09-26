#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const double PI = acos(-1.0);

struct Matrix {
    double m[3][3];

    Matrix() {
        memset(m, 0, sizeof(m));
    }

    void make_identity() {
        for (int i = 0; i < 3; i++) {
            m[i][i] = 1.0;
        }
    }

    void make_rotation(double theta) {
        make_identity();
        m[0][0] = cos(theta);
        m[0][1] = sin(theta);
        m[1][0] = -sin(theta);
        m[1][1] = cos(theta);
    }

    void make_scaling(double sx, double sy) {
        make_identity();
        m[0][0] = sx;
        m[1][1] = sy;
    }

    void make_translation(double tx, double ty) {
        make_identity();
        m[0][2] = tx;
        m[1][2] = ty;
    }
};

// Multiplies two 3x3 matrices
Matrix multiply(Matrix A, Matrix B)
{
    Matrix res;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res.m[i][j] += A.m[i][k] * B.m[k][j];
            }
        }
    }
    return res;
}

// Applies the transformation matrix T to the point (x, y)
pair<double, double> transform_point(Matrix T, double x, double y)
{
    double new_x = T.m[0][0] * x + T.m[0][1] * y + T.m[0][2];
    double new_y = T.m[1][0] * x + T.m[1][1] * y + T.m[1][2];
    return {new_x, new_y};
}

// Applies all the transformations in ops to the point p
pair<double, double> apply_operations(vector<Matrix> &ops, double x, double y)
{
    Matrix T;
    T.make_identity();
    for (int i = ops.size() - 1; i >= 0; i--) {
        T = multiply(ops[i], T);
    }
    return transform_point(T, x, y);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<double, double>> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i].first >> P[i].second;
    }

    vector<Matrix> ops(m);
    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;
        if (op == "rotate") {
            double theta;
            cin >> theta;
            ops[i].make_rotation(theta * PI / 180.0);
        } else if (op == "scale") {
            double sx, sy;
            cin >> sx >> sy;
            ops[i].make_scaling(sx, sy);
        } else {
            double tx, ty;
            cin >> tx >> ty;
            ops[i].make_translation(tx, ty);
        }
    }

    for (int i = 0; i < n; i++) {
        double x = P[i].first;
        double y = P[i].second;
        auto new_point = apply_operations(ops, x, y);
        cout << new_point.first << " " << new_point.second << endl;
    }

    return 0;
}