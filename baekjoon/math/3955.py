def euclidean(a, b):
    if a==0: return b
    if b==0: return a
    return euclidean(b, a%b)

def extended_euclidean(a, b):
    if a==0: return 0, 1
    if b==0: return 1, 0

    xp, yp = extended_euclidean(b, a%b)
    x = ((yp % b) + b) % b
    y = (1 - a * x) // b
    return x, y

if __name__=='__main__':
    N = int(input())
    for _ in range(N):
        K, C = list(map(int, input().split()))
        if euclidean(K, C) != 1:
            print("IMPOSSIBLE")
            continue
        a, b = extended_euclidean(C, K)
        while C*a<=K: a+=K      # 이부분 중요
        if a > 1e9: print("IMPOSSIBLE")
        else: print(a)
