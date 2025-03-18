import sys

def main():
    input = sys.stdin.read().split()
    t = int(input[0])
    idx = 1
    for _ in range(t):
        x = int(input[idx])
        y = int(input[idx+1])
        idx += 2
        if x == y:
            print(0)
            continue
        xor = x ^ y
        mask = 1
        cost = 0
        used = set()
        a, b = max(x, y), min(x, y)
        while a != b:
            # 找到最大的k，使得 a // (2^k) >= b 或者 b // (2^k) >= a
            if a > b:
                delta = a - b
                k = delta.bit_length()
                while True:
                    temp = a >> k if k !=0 else a
                    if temp >= b and k not in used:
                        break
                    k -= 1
                    if k < 0:
                        break
                if k < 0:
                    k = 0
                used.add(k)
                cost += (1 << k)
                a >>= k
            else:
                delta = b - a
                k = delta.bit_length()
                while True:
                    temp = b >> k if k !=0 else b
                    if temp >= a and k not in used:
                        break
                    k -= 1
                    if k < 0:
                        break
                if k < 0:
                    k = 0
                used.add(k)
                cost += (1 << k)
                b >>= k
        print(cost)

if __name__ == "__main__":
    main()