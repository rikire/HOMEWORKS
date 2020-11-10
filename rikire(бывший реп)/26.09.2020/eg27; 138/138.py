# Списал, но разобрался как тут все работает (еще 137 посмотрел)
def diffD(x, y):
  return (x % D != y % D)


D, C = 37, 7
z = -10001

n = int(input())
L, R = 0, 0
m1, m2 = [z, z], [z, z]

for i in range(n):
  x = int(input())

  p = 0 if x % C == 0 else 1
  q = 1 - p

  if m1[q]+x > L+R and (m1[q]+x) % D > 0:
    L, R = m1[q], x
  if m2[q]+x > L+R and (m2[q]+x) % D > 0:
    L, R = m2[q], x

  if x > m1[p]:
    if diffD(x, m1[p]):
      m2[p] = m1[p]
    m1[p] = x
  elif x > m2[p] and diffD(x, m1[p]):
    m2[p] = x

print(L, R)
