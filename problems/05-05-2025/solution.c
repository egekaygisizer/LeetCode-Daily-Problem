#define MOD 1000000007

int numTilings(int n) {
  if (n < 4) {
    int s[4] = {0, 1, 2, 5};
    return s[n];
  }

  long long s1 = 1, s2 = 2, s3 = 5, s4;

  for (int i = 4; i < n + 1; i++) {
    s4 = 2 * s3 + s1;
    if (s4 > MOD)
      s4 = s4 % MOD;
    s1 = s2;
    s2 = s3;
    s3 = s4;
  }
  
  return s4;
}