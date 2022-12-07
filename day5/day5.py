import re

result = []
file = open('input')

for line in file:
    if line == "\n": break
    result.append([line[1 + 4 * k] for k in range(len(line) // 4)])
result.pop()
result = [list("".join(c).strip()[::-1]) for c in zip(*result)]

for line in file:
    a, b, c = map(int, re.findall("\\d+", line))
    result[c - 1].extend(result[b - 1][-a:])
    result[b - 1] = result[b -1][:-a]

print("".join([a[-1] for a in result]))