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

int solve(int n) {
	int ans = (1 << 30);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (n % (i * j) == 0) {
				int k = n / (i * j);
				ans = min(ans, 2 * (i * j + i * k + j * k));
			}
		}
	}
	return ans;
}

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
	return 0;
}