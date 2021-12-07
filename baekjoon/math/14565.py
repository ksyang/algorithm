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
    N, A = list(map(int, input().split()))
    print(N-A, end=' ')
    if euclidean(A, N) == 1: 
        a, b = extended_euclidean(A, N)
        print(a)
    else: print(-1)
