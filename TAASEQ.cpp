#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl

#define SIZE(a) ((int) a.size())

#define oo 2000000000
#define maxn 112345

typedef pair<int, int> pii;

int n, a[maxn];
bool f[maxn], g[maxn];

int calc() {
  //if n <= 3 we can remove any number
  if (n <= 3) {
    int res = oo;
    FOR(i, 1, n) {
      res = min(res, a[i]);
    }
    return res;
  }

  //calculate f[]
  f[0] = f[1] = f[2] = true;
  FOR(i, 3, n) {
    f[i] = (a[i] - a[i - 1] == a[i - 1] - a[i - 2] && f[i - 1]);
  }
    for(int i=1;i<=n;i++)
        cout<<f[i]<<" ";
        cout<<endl;
  //calculate g[]
  g[n + 1] = g[n] = g[n - 1] = true;
  FORD(i, n - 2, 1) {
    g[i] = (a[i + 1] - a[i + 2] == a[i] - a[i + 1] && g[i + 1]);
  }
      for(int i=1;i<=n;i++)
        cout<<g[i]<<" ";
        cout<<endl;
  int res = oo;
  //resolve some corner cases
  //# remove a[1]
  if (g[2]) {
    res = min(res, a[1]);
  }

  //# remove a[n]
  if (f[n - 1]) {
    res = min(res, a[n]);
  }

  //# remove a[n - 1]
  if (f[n - 2] && a[n - 3] - a[n - 2] == a[n - 2] - a[n]) {
    res = min(res, a[n - 1]);
  }

  //# remove a[2]
  if (g[3] && a[1] - a[3] == a[3] - a[4]) {
    res = min(res, a[2]);
  }

  //now we try remove i = 3 -> n - 2 and see if the left and
  //right part can merge into one arithmetic progression
  FOR(i, 3, n - 2) {
    if (f[i - 1] && g[i + 1] && a[i - 2] - a[i - 1] == a[i - 1] - a[i + 1]
                             && a[i + 1] - a[i + 2] == a[i - 1] - a[i + 1]) {
      res = min(res, a[i]);
    }
  }

  if (res == oo) {
    res = -1;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    FOR(i, 1, n)
      cin >> a[i];

    cout << calc() << endl;
  }
  return 0;
}
