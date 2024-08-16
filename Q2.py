import numpy as np
import time

N = 512

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
