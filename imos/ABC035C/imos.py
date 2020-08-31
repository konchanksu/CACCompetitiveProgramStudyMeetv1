N, Q = map(int, input().split())
A = [0 for i in range(N + 1)]

for _ in range(Q):
    tmp = list(map(lambda x: int(x) - 1, input().split()))
    A[tmp[0]] += 1
    A[tmp[1] + 1] -= 1

tmp = 0
for i in A[:-1]:
    tmp += i
    print(tmp % 2, end='')
print()
