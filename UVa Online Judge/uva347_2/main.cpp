#include <stdio.h>
#define S 10000005

int num[S];

int rep(int n) {
  int v[10] = {};
  while (n) {
    if (v[n % 10]) return 1;
    if (!(n % 10)) return 1;
    v[n % 10] = 1;
    n /= 10;
  }
  return 0;
}

int chk(int n) {
  if (rep(n)) return 0;
  char s[20];
  sprintf(s, "%d", n);
  int i, l;
  for (l = 0; s[l]; l++);
  int now = 0, cnt = s[0] - '0', v[20] = {};
  for (i = 0; i < l; i++) {
    now = (now + cnt) % l;
    if (v[now]) return 0;
    v[now] = 1;
    cnt = s[now] - '0';
  }
  return 1;
}

int main() {
  int n, C = 1;
  for (n = 9999999; n > 9; n--)
    if (chk(n)) num[n] = n;
    else num[n] = num[n + 1];
  while (scanf("%d", &n) && n)
    printf("Case %d: %d\n", C++, num[n]);
  return 0;
}
