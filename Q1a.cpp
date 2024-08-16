#include<bits/stdc++.h>
using namespace std;

long long int f(int a){
    if(a==0 || a==1) return a;
    return f(a-1) + f(a-2);
}

int main(){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i=0;i<50;i++){
        cout<<f(i)<<endl;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long int secs = end.tv_sec - start.tv_sec;
    long long int nsecs = end.tv_nsec - start.tv_nsec;
    double elapsed = secs + nsecs * 1e-9;

    cout << "Time spent: " << elapsed << " secs" << endl;
    return 0;
}