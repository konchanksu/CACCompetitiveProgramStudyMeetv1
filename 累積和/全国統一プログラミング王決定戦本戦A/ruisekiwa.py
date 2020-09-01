N = int(input())
A = list(map(int, input().split()))

# tmp = 0
# S = [0] +[(tmp := (tmp + i)) for i in A] # python3.8以降であれば省略可能
S = [0]
for i in A:
    S.append(S[-1] + i)

for i in range(1, N + 1):
    print(max(iter(S[j] - S[j - i] for j in range(i, N + 1))))
