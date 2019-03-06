def GCD_R(A, B):
    if not(B):
      return A
    return GCD_R(int(B), int(A % B))

def GCD_BRUTE_FORCE(A, B):
  g_c_d = 1
  for i in range(2, min(A, B) + 1):
    if A % i == 0 and B % i == 0:
      g_c_d = i
  
  return g_c_d

def GCD_I(A, B):
  while B > 0:
    tmp = A
    A = B
    B = int(tmp % A)
  return A

print("HI")
print(GCD_R(14,26));
print(GCD_BRUTE_FORCE(128,256))
print(GCD_I(128,256))