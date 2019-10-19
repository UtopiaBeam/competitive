from collections import Counter
from math import sqrt
def suf(s, t):
    s, t = s[::-1], t[::-1]
    for i in range(len(s)):
        if s[:i+1] != t[:i+1]:
            return s[:i][::-1]
    return s[::-1]

for q in range(int(input())):
    n = int(input())
    ls = [input().strip() for _ in range(n)]
    cnt = Counter(suf(s, t) for s in ls for t in ls if s != t)
    dc = dict((k, int((1+sqrt(1+4*v))//2)) for k, v in cnt.items() if k)
    print('Case #{}: {}'.format(q+1, dc))

