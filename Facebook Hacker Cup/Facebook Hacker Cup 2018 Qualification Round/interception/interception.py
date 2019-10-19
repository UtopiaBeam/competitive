inp = open('interception.txt')
out = open('interception_output.txt', 'w')
q = int(inp.readline())
for t in range(1, q+1):
    n = int(inp.readline())
    ls = [int(inp.readline()) for _ in range(n+1)]
    if n == 1:      out.write('Case #{}: 1\n0.0\n'.format(t))
    else:       out.write('Case #{}: 0\n'.format(t))
