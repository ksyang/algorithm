import sys

def eu(a, b):       # ax + by = 1의 해를 구함
    if a==0: return 0, 1
    if b==0: return 1, 0

    prvx, prvy = eu(b, a%b)     # b, r 로 문제 분해
    x = ((prvy % b) + b) % b    # x = y' mod b (y' = x 이므로)
    y = (1 - a * x) // b        # ax + by = 1, 굳이 x' = qx+y에 넣지 않아도 되니까
    return x, y


if __name__=='__main__':
    print(eu(int(sys.argv[1]), int(sys.argv[2])))
