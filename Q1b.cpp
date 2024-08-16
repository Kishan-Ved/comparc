#include<bits/stdc++.h>
using namespace std;

int main(){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i=0;i<50;i++){
        long long int x=0,y=1;
        if(i==0) cout<<x<<endl;
        else if(i==1) cout<<y<<endl;
        else{
            for(int j=2;j<=i;j++){
                long long int t = x+y;
                x=y;
                y=t;
            }
        }
        cout<<y<<endl;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long int secs = end.tv_sec - start.tv_sec;
    long long int nsecs = end.tv_nsec - start.tv_nsec;
    double elapsed = secs + nsecs * 1e-9;

    cout << "Time spent: " << elapsed << " secs" << endl;
    return 0;
}