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



#### Median:
- **Time spent on matrix multiplication:** 0.00616353 secs
- **Real CPU time**: 0.013 s
- **User CPU time** : 0.008 s
- **Sys CPU time**: 0.005 s

Proportion of meat portion wrt actual program: (0.00616353/0.013) = 0.47412


### N = 128

| Execution | Meat portion (seconds) | Real Time | User Time | Sys Time |
|-----------|----------------------|-----------|-----------|----------|
| First     | 0.0494252             | 0m0.057s  | 0m0.052s  | 0m0.005s |
| Second    | 0.0595929             | 0m0.068s  | 0m0.067s  | 0m0.002s |
| Third     | 0.0487691             | 0m0.056s  | 0m0.050s  | 0m0.006s |


#### Median:
- **Time spent**: 0.0494252 secs
- **real CPU time**:   0.057s
- **user CPU time**:   0.052s
- **sys  CPU time**:   0.005s


Proportion of meat portion wrt actual program: (0.0494252/0.057) = 0.86711

### N = 256
| Execution | Time Spent (seconds) | Real Time | User Time | Sys Time |
|-----------|----------------------|-----------|-----------|----------|
| First     | 0.358945              | 0m0.373s  | 0m0.371s  | 0m0.002s |
| Second    | 0.361204              | 0m0.375s  | 0m0.368s  | 0m0.006s |
| Third     | 0.362392              | 0m0.376s  | 0m0.370s  | 0m0.005s |

#### Median Values:
- **Median Time Spent:** 0.361204 seconds
- **Median Real Time:** 0m0.375s
- **Median User Time:** 0m0.370s
- **Median Sys Time:** 0m0.005s


Proportion of meat portion wrt actual program: (0.361204/0.375) = 0.96321

## N = 512

| Execution | Time Spent (seconds) | Real Time | User Time | Sys Time |
|-----------|----------------------|-----------|-----------|----------|
| First     | 3.24841               | 0m3.284s  | 0m3.277s  | 0m0.006s |
| Second    | 3.14960               | 0m3.185s  | 0m3.116s  | 0m0.008s |
| Third     | 3.20658               | 0m3.244s  | 0m3.236s  | 0m0.009s |

### Median Values:
- **Median Time Spent:** 3.20658 seconds
- **Median Real Time:** 0m3.244s
- **Median User Time:** 0m3.236s
- **Median Sys Time:** 0m0.008s

Proportion of meat portion wrt actual program: (3.20658/3.244) = 0.98846

### N = 1024

| Execution | Time Spent (seconds) | Real Time | User Time | Sys Time |
|-----------|----------------------|-----------|-----------|----------|
| First     | 24.2351               | 0m24.354s | 0m24.315s | 0m0.025s |
| Second    | 27.8404               | 0m27.961s | 0m27.933s | 0m0.015s |
| Third     | 29.0739               | 0m29.198s | 0m29.140s | 0m0.053s |

#### Median Values:
- **Median Time Spent:** 27.8404 seconds
- **Median Real Time:** 0m27.961s
- **Median User Time:** 0m27.933s
- **Median Sys Time:** 0m0.025s

Proportion of meat portion wrt actual program: (27.8404/27.961) = 0.99569


## Python (Integer matrix)

```python
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
```

**In this part, I have performed 3 iterations and taken the median (as done above), and only the median value is mentioned below.**

### N = 64:


- **Time spent**: 0.5385956764221191 secs
- **real**    0m1.001s
- **user**    0m1.100s
- **sys**     0m1.155s

Proportion of meat portion wrt actual program: (0.5386/1.0010) = 0.538

### N = 128:

- **Time spent**: 3.481839179992676 secs
- **real**    0m3.843s
- **user**    0m4.049s
- **sys**     0m1.052s

Proportion of meat portion wrt actual program: (3.4818/3.8430) = 0.906

### N = 256:

- **Time spent**: 26.963408946990967 secs
- **real**    0m27.257s
- **user**    0m27.576s
- **sys**     0m1.206s

Proportion of meat portion wrt actual program: (26.9634/27.2570) = 0.989

### N = 512:

- **Time spent**: 228.12692141532898 secs
- **real**    3m48.455s
- **user**    3m48.729s
- **sys**     0m1.206s

Proportion of meat portion wrt actual program: (228.1269/228.4550) = 0.99902

### N = 1024:

- **Time spent**: 1846.78790787841567 secs
- **real**    30m48.322s
- **user**    30m57.344s
- **sys**    0m1.291s

Proportion of meat portion wrt actual program: (1846.7879/1848.322) = 0.99917

## Plot of Real CPU time for C++ vs Python
![image](https://github.com/user-attachments/assets/76dc206c-e9b8-4691-868d-e984532879ee)

## Plot of User CPU time for C++ vs Python
![image](https://github.com/user-attachments/assets/01ceb303-e077-4bf3-9adf-e0f1a740bd7f)


## Plot of System CPU time for C++ vs Python
![image](https://github.com/user-attachments/assets/d09d78bf-54f0-487a-96dc-8baf3599ad25)

## C++ (Float matrix)

**In this part, I have performed 3 iterations and taken the median (as done above), and only the median value is mentioned below.**

```cpp
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main() {
    int N = 64;
    vector<vector<double>> matA(N, vector<float>(N));
    vector<vector<double>> matB(N, vector<float>(N));
    vector<vector<double>> matC(N, vector<float>(N, 0.0f));

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

```

### N = 64
- **Time spent**: 0.0118847 secs
- **real**    0m0.018s
- **user**    0m0.018s
- **sys**     0m0.001s

Proportion of meat portion wrt actual program: (0.01188/0.018) = 0.66

### N = 128
- **Time spent**: 0.0641931 secs
- **real**    0m0.072s
- **user**    0m0.068s
- **sys**     0m0.002s

Proportion of meat portion wrt actual program: (0.06419/0.072) = 0.8915

### N = 256
- **Time spent**: 0.364272 secs
- **real**    0m0.379s
- **user**    0m0.375s
- **sys**     0m0.004s

Proportion of meat portion wrt actual program: (0.3643/0.379) = 0.9612

### N = 512
- **Time spent**: 3.11515 secs
- **real**    0m3.156s
- **user**    0m3.154s
- **sys**     0m0.001s

Proportion of meat portion wrt actual program: (3.1152/3.156) = 0.98707

### N = 1024
- **Time spent**: 26.5513 secs
- **real**    0m26.669s
- **user**    0m26.659s
- **sys**     0m0.007s

Proportion of meat portion wrt actual program: (26.5513/26.669) = 0.99559

## Python (Float matrix)

```python
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
```

**In this part, I have performed 3 iterations and taken the median (as done above), and only the median value is mentioned below.**


### N = 64:

- **Time spent**: 0.45248913764953613 secs
- **real**    0m0.742s
- **user**    0m1.066s
- **sys**    0m1.232s

Proportion of meat portion wrt actual program: (0.4525/0.7420) = 0.61


### N = 128:
- **Time spent**: 4.212065935134888 secs
- **real**   0m4.510s
- **user**   0m4.806s
- **sys**   0m1.256s

Proportion of meat portion wrt actual program: (4.2121/4.5100) = 0.934

### N = 256:
- **Time spent**: 28.8769314289093 secs
- **real**  0m29.182s
- **user**   0m29.399s
- **sys**    0m1.309s

Proportion of meat portion wrt actual program: (28.8769/29.1820) = 0.9895

### N = 512:

- **Time spent**: 230.83469247817993 secs
- **real**   3m51.144s
- **user**   3m51.395s
- **sys**   0m1.266s

Proportion of meat portion wrt actual program: (230.8347/231.1440) = 0.9986

### N = 1024:

- **Time spent**: 1855.48235671256894 secs
- **real**    30m59.855s
- **user**   31m0.099s
- **sys**   0m1.301s

Proportion of meat portion wrt actual program: (1855.4824/1859.855) = 0.9996

## Plot of Real CPU time for C++ vs Python
![image](https://github.com/user-attachments/assets/6fc091e1-d048-4c63-9f91-b85962c75219)

## Plot of User CPU time for C++ vs Python
![image](https://github.com/user-attachments/assets/ff4092b2-1d8c-4c99-809d-e396b0bd7673)

## Plot of System CPU time for C++ vs Python
![image](https://github.com/user-attachments/assets/166e2fd6-8bcd-4b15-8d99-8261193fc23e)

## Observations
- System CPU time is much lower than User CPU time
- The System CPU time is nearly constant (or increases very slightly on increasing the value of N), this is because it is the amount of time the CPU was busy executing code in kernel space. This does not include the meat portion of the program.
- The time taken for the meat portion of the program is included in the user CPU time
- The time taken for executing C++ code is much lesser than the time taken by the Python code
- The real CPU time is almost equal to the user CPU time, as the system CPU time is very low
- As the value of N increases, the time taken increases. Roughly, when N is doubled, the total CPU time becomes 8 times. This is because matrix multiplication is an O(N^3) operation, and 2^3 = 8
- As the value of N increases, the proportion of meat protion's time wrt actual program's time becomes closer to 1, this is because the system time is nearly constant and the user CPU time increases (as the number of operations to be performed increase) on increasing the value of N.
- The number of operations perfomed in a unit time is larger for C++ when compared to Python. This is because of the language design
- For both Python and C++, the integer operations are faster (based on total CPU time), this is becuase they require lesser memory (int datatype in C++ is 4 bytes while double is 8 bytes), moreover, integer operations are simpler, they involve basic circuitry (if translated to circuit based operations), double datatype on the other hand requires more complex handling of the decimal and the fractional part (which increases the number of operations needed, as they have more precision when compared to int). Converting int from decimal to binary is also simpler (requires lesser operations) than converting a double value to binary

