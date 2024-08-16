#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main() {
    int N = 1024;
    vector<vector<float>> matA(N, vector<float>(N));
    vector<vector<float>> matB(N, vector<float>(N));
    vector<vector<float>> matC(N, vector<float>(N, 0.0f));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matA[i][j] = static_cast<float>(rand()) / RAND_MAX * 100.0f; 
            matB[i][j] = static_cast<float>(rand()) / RAND_MAX * 100.0f;
        }
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    long long int secs = end.tv_sec - start.tv_sec;
    long long int nsecs = end.tv_nsec - start.tv_nsec;
    double elapsed = secs + nsecs * 1e-9;

    cout << "Time spent: " << elapsed << " secs" << endl;
    return 0;
}
