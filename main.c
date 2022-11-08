#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int period_length(int n) {
	int a_0, a, b, c, b_0, c_0, result = 0;
	a_0 = sqrt(n);

	c = c_0 = n - a_0*a_0;
	if (!c) return 0; //perfect square

	b = b_0 = a_0;
	do {
		a = (a_0 + b) / c;
		b = a*c - b;
		c = (n - b*b) / c;
		result++;
	} while ((b != b_0) || (c != c_0));
	return result;
}

int main() {
	int n;

	scanf("%d", &n);

	int count = 0;
	for (int i = 2; i <= n; i++) {
		int plen = period_length(i);
		if (plen & 1)
			count++;
	}

	printf("%d\n", count);

	return 0;
}