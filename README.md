# Q1)
## a)
### Code

```cpp
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
```

<details>
<summary> Output </summary>
  
```
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ g++ -o a Q1a.cpp
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ ./a
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765
10946
17711
28657
46368
75025
121393
196418
317811
514229
832040
1346269
2178309
3524578
5702887
9227465
14930352
24157817
39088169
63245986
102334155
165580141
267914296
433494437
701408733
1134903170
1836311903
2971215073
4807526976
7778742049
Time spent: 410.978 seconds
```
</details>

### Time for 3 executions

| Execution | Time Spent (seconds) |
|-----------|----------------------|
| First     | 410.978 s             |
| Second    | 412.223 s             |
| Third     | 417.328 s             |


### Average execution time:
Average time = (410.978 + 417.223 + 417.328)/3 = 415.176333333 s

### Median time
Median execution time = 412.233 s

## b)
### Code

```cpp
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

```
<details>
  <summary>Output</summary>

  
```

kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ ./a
0
1
1
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765
10946
17711
28657
46368
75025
121393
196418
317811
514229
832040
1346269
2178309
3524578
5702887
9227465
14930352
24157817
39088169
63245986
102334155
165580141
267914296
433494437
701408733
1134903170
1836311903
2971215073
4807526976
7778742049
Time spent: 0.000242781 secs
```

</details>

### Time taken for 3 executions
| Execution | Time Spent (seconds) |
|-----------|----------------------|
| First     | 0.000242781 s         |
| Second    | 0.000265847 s         |
| Third     | 0.000242290 s         |


### Average time
Average time = (0.000242781 + 0.000265847 + 0.00024229)/3 = 0.000250306 s

### Median time
Median time = 0.000242781 s

## c)
### Code
```cpp
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
```
<details>
<summary>Output</summary>

```

kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ g++ -o a Q1c.cpp
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ ./a
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765
10946
17711
28657
46368
75025
121393
196418
317811
514229
832040
1346269
2178309
3524578
5702887
9227465
14930352
24157817
39088169
63245986
102334155
165580141
267914296
433494437
701408733
1134903170
1836311903
2971215073
4807526976
7778742049
Time spent: 0.000230712 secs
```
</details>

### Time for 3 executions
| Execution | Time Spent (seconds) |
|-----------|----------------------|
| First     | 0.000230712 s         |
| Second    | 0.000228272 s         |
| Third     | 0.000235082 s         |


### Average time
Average time = (0.000230712 + 0.000228272 + 0.000235082)/3 = 0.00023135533 s

### Median time
Median time = 0.000230712 s

## d)
### Code
```cpp
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
```
<details>

  <summary>Output</summary>

```
 
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ g++ -o a Q1c.cpp
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ ./a
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765
10946
17711
28657
46368
75025
121393
196418
317811
514229
832040
1346269
2178309
3524578
5702887
9227465
14930352
24157817
39088169
63245986
102334155
165580141
267914296
433494437
701408733
1134903170
1836311903
2971215073
4807526976
7778742049
Time spent: 0.000152432 secs
```

</details>

### Time for 3 executions
| Execution | Time Spent (seconds) |
|-----------|----------------------|
| First     | 0.000152432 s         |
| Second    | 0.000189024 s         |
| Third     | 0.000164013 s         |


### Average time
Average time = (0.000152432 + 0.000189024 + 0.000164013)/3 = 0.00016848966 s

### Median time
Median time = 0.000164013 s

## e) 
### Median execution times

- (d) Loop with memoization (0.000164013 s)
- (c) Recursion with memoization (0.000230712 s) 
- (b) Loop (0.000242781 s)
- (a) Recursion (412.233 s)

Speedup of (b) wrt (a) = Average time of (a) / Average time of (b)
                                         = 415.176333333  /  0.000250306
                                        = 1658675.11499

Speedup of (c) wrt (a) = Average time of (a) / Average time of (b)
                                         = 415.176333333  /  0.00023135533 
                                        = 1794539.73822

Speedup of (d) wrt (a) = Average time of (a) / Average time of (b)
                                         = 415.176333333  /  0.00016848966
                                        = 2464105.7103

### Reason
- (a) runs in exponential time
- (b) runs in O(N2) time
- (c) runs in O(N) time (but involves recursion, which is slower than iteration)
- (d) runs in O(N) time and is iterative

# Q2)

## C++ (Integer matrix)

For this part, I have shown 3 outputs, and then performed the average of these to get the final times.

### N = 64

The code remains the same for all, the only difference is in the value assigned to variable n

```cpp
#include<bits/stdc++.h>


using namespace std;
using namespace chrono;


int main() {
   int N = 1024;
   vector<vector<int>> A(N, vector<int>(N));
   vector<vector<int>> B(N, vector<int>(N));
   vector<vector<int>> C(N, vector<int>(N, 0));


   for (int i = 0; i < N; ++i) {
       for (int j = 0; j < N; ++j) {
           A[i][j] = rand() % 100;
           B[i][j] = rand() % 100;
       }
   }


   struct timespec start, end;
   clock_gettime(CLOCK_MONOTONIC, &start);


   for (int i = 0; i < N; ++i) {
       for (int j = 0; j < N; ++j) {
           for (int k = 0; k < N; ++k) {
               C[i][j] += A[i][k] * B[k][j];
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

```


Output 1 (done using the terminal command: time ./a):
```
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 0.00616353 secs

real    0m0.013s
user    0m0.008s
sys     0m0.005s
```

Output 2:
```
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 0.00602613 secs

real    0m0.012s
user    0m0.008s
sys     0m0.005s
```

Output 3:
```
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 0.00682563 secs

real    0m0.014s
user    0m0.010s
sys     0m0.004s
```

| Execution | Time Spent (seconds) | Real Time | User Time | Sys Time |
|-----------|----------------------|-----------|-----------|----------|
| First     | 0.00616353            | 0m0.013s  | 0m0.008s  | 0m0.005s |
| Second    | 0.00602613            | 0m0.012s  | 0m0.008s  | 0m0.005s |
| Third     | 0.00682563            | 0m0.014s  | 0m0.010s  | 0m0.004s |



### Average:
Time spent: 0.00633843 secs

Real: 0.013 s
User CPU time : 0.00866 s
Sys CPU time : 0.00466 s

Proportion of meat portion wrt actual program: (0.00633843/0.013) = 0.488


N = 128
Output 1:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 0.0494252 secs

real    0m0.057s
user    0m0.052s
sys     0m0.005s

Output 2:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 0.0595929 secs

real    0m0.068s
user    0m0.067s
sys     0m0.002s

Output 3:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 0.0487691 secs

real    0m0.056s
user    0m0.050s
sys     0m0.006s

Average:
Time spent: 0.05259 secs

real    0.0603 s
user CPU time   0.0563 s
sys  CPU time   0.0043 s

Proportion of meat portion wrt actual program: (0.05259/0.0603) = 0.872







N = 256

Output 1:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 0.358945 secs

real    0m0.373s
user    0m0.371s
sys     0m0.002s

Output 2:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 0.361204 secs

real    0m0.375s
user    0m0.368s
sys     0m0.006s

Output 3:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 0.362392 secs

real    0m0.376s
user    0m0.370s
sys     0m0.005s

Average:
Time spent: 0.360847 secs

real    0.3746 s
user  CPU time  0.3696 s
sys   CPU time  0.0043 s


Proportion of meat portion wrt actual program: (0.360847/0.3746) = 0.963

N = 512

Output 1:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 3.24841 secs

real    0m3.284s
user    0m3.277s
sys     0m0.006s

Output 2:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 3.1496 secs

real    0m3.185s
user    0m3.116s
sys     0m0.008s

Output 3:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 3.20658 secs

real    0m3.244s
user    0m3.236s
sys     0m0.009s

Average:
Time spent: 3.2276 secs

real    3.2376 s
user  CPU time  3.2096 s
sys   CPU time  0.0076 s

Proportion of meat portion wrt actual program: (3.2276/3.2376) = 0.997





N = 1024

Output 1:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 24.2351 secs

real    0m24.354s
user    0m24.315s
sys     0m0.025s

Output 2:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 27.8404 secs

real    0m27.961s
user    0m27.933s
sys     0m0.015s

Output 3:
kishan@kishan-IdeaPad-3-15IIL05:~/Desktop/CompArc$ time ./a
Time spent: 29.0739 secs

real    0m29.198s
user    0m29.140s
sys     0m0.053s

Average:
Time spent: 27.0498 secs

real    27.171 s
user  CPU time  27.1293 s
sys   CPU time  0.031 s


Proportion of meat portion wrt actual program: (27.0498/27.1710) = 0.996


Python (Integer matrix)

import numpy as np
import time


N = 64


matA = np.random.randint(0, 100, (N, N))
matB = np.random.randint(0, 100, (N, N))
matC = np.zeros((N, N), dtype=int)


start = time.time()


for i in range(N):
   for j in range(N):
       for k in range(N):
           matC[i][j] += matA[i][k] * matB[k][j]


end = time.time()


elapsed = end - start


print(f"Time spent: {elapsed} secs")




In this part, I have performed the average of 3 iterations, and only the final average value is shown.

N = 64:


Time spent: 0.5385956764221191 secs

real    0m1.001s
user    0m1.100s
sys     0m1.155s

Proportion of meat portion wrt actual program: (0.5386/1.0010) = 0.538
N = 128:

Time spent: 3.481839179992676 secs

real    0m3.843s
user    0m4.049s
sys     0m1.052s

Proportion of meat portion wrt actual program: (3.4818/3.8430) = 0.906

N = 256:

Time spent: 26.963408946990967 secs

real    0m27.257s
user    0m27.576s
sys     0m1.206s

Proportion of meat portion wrt actual program: (26.9634/27.2570) = 0.989

N = 512:

Time spent: 228.12692141532898 secs

real    3m48.455s
user    3m48.729s
sys     0m1.206s

Proportion of meat portion wrt actual program: (228.1269/228.4550) = 0.99902

N = 1024:

Time spent: 1846.78790787841567 secs

real    30m48.322s
user    30m57.344s
sys     0m1.291s

Proportion of meat portion wrt actual program: (1846.7879/1848.322) = 0.99917





Python (Float matrix)

import numpy as np
import time


N = 1024


matA = np.random.uniform(0, 100, (N, N))
matB = np.random.uniform(0, 100, (N, N))
matC = np.zeros((N, N), dtype=float)


start = time.time()


for i in range(N):
   for j in range(N):
       for k in range(N):
           matC[i][j] += matA[i][k] * matB[k][j]


end = time.time()


elapsed = end - start


print(f"Time spent: {elapsed} secs")


In this part, I have performed the average of 3 iterations, and only the final average value is shown.

N = 64:

Time spent: 0.45248913764953613 secs

real    0m0.742s
user    0m1.066s
sys     0m1.232s

Proportion of meat portion wrt actual program: (0.4525/0.7420) = 0.61


N = 128:
Time spent: 4.212065935134888 secs

real    0m4.510s
user    0m4.806s
sys     0m1.256s

Proportion of meat portion wrt actual program: (4.2121/4.5100) = 0.934

N = 256:
Time spent: 28.8769314289093 secs

real    0m29.182s
user    0m29.399s
sys     0m1.309s

Proportion of meat portion wrt actual program: (28.8769/29.1820) = 0.9895

N = 512:

Time spent: 230.83469247817993 secs

real    3m51.144s
user    3m51.395s
sys     0m1.266s

Proportion of meat portion wrt actual program: (230.8347/231.1440) = 0.9986

N = 1024:

Time spent: 1855.48235671256894 secs

real    30m59.855s
user    31m0.099s
sys     0m1.301s

Proportion of meat portion wrt actual program: (1855.4824/1859.855) = 0.9996






