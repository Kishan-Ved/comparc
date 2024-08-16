#include<bits/stdc++.h>
using namespace std;

long long int f(int a, vector<long long int>& v){
    if(a==0 || a==1) return a;
    if(v[a]!=-1) return v[a];
    return v[a] = f(a-1,v) + f(a-2,v);
}

int main(){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    vector<long long int> v(50,-1);
    for(int i=0;i<50;i++){
        cout<<f(i,v)<<endl;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long int secs = end.tv_sec - start.tv_sec;
    long long int nsecs = end.tv_nsec - start.tv_nsec;
    double elapsed = secs + nsecs * 1e-9;

    cout << "Time spent: " << elapsed << " secs" << endl;
    return 0;
}