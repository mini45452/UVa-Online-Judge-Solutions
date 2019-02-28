#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <bitset>
#include <limits>
#include <numeric>
using namespace std;
#define sz(x) ((int)(x).size())

void solve() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int xr, yr, zr;
	int found = 0;
	for (int x = 1; x * x - 2 <= c; x++) {
		for (int y = 1; x * x + y * y - 1 <= c; y++) {
			for (int z = 1; x * x + y * y + z * z <= c; z++) {
				if (x == y || x == z || y == z) continue;
				if (x * x + y * y + z * z == c && x * y * z == b && !found) {
					if (-x + -y + z == a) {
						xr = -x;
						yr = -y;
						if (xr > yr) swap(xr, yr);
						zr = z;
						found = 1;
					}
					if (!found) {
						if (x + y + z == a) {
							xr = x;
							yr = y;
							zr = z;
							found = 1;
						}
					}
				}
			}
		}
	}
	if (found) printf("%d %d %d\n", xr, yr, zr);
	else puts("No solution.");
}

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		solve();
	}
	return 0;
}