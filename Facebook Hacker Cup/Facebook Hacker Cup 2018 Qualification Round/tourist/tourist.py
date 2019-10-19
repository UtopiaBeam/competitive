f1 = open('tourist.txt')
f2 = open('tourist_output.txt', 'w')
q = int(f1.readline())
for i in range(1, q+1):
    n, k, v = map(int, f1.readline().split())
    ls = [f1.readline().strip() for _ in range(n)]
    s = k*(v-1) % n
    e = (k*v - 1) % n
    ans = ls[s:e+1] if s <= e else ls[:e+1]+ls[s:]      
    f2.write(' '.join(['Case #{}:'.format(i)] + ans + ['\n']))