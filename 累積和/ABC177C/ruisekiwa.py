N = int(input())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7
ans = 0
ruiseki = [0]

for i in A:
    ruiseki.append(ruiseki[-1] + i)

for i in range(N - 1):
    ans += ((ruiseki[N] - ruiseki[i + 1]) * A[i]) % MOD
    ans %= MOD
print(ans)

