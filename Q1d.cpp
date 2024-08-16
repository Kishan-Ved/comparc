#include<bits/stdc++.h>
using namespace std;

int main(){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    vector<long long int> v(50);
    v[0] = 0;
    v[1] = 1;
    for(int i=0;i<50;i++){
        v[i] = v[i-1]+v[i-2];
        cout<<v[i]<<endl;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long int secs = end.tv_sec - start.tv_sec;
    long long int nsecs = end.tv_nsec - start.tv_nsec;
    double elapsed = secs + nsecs * 1e-9;

    cout << "Time spent: " << elapsed << " secs" << endl;
    return 0;
}