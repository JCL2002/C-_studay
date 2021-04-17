#include <stdio.h>
#include <math.h>

int main() {
	long long a, root;
	short int test = 0;
	scanf("%lld", &a);
	root = sqrt(a);
	for (long long i = 2; i <= root; i++) {
		if ((a % i) == 0) {
			printf("not prime\n");
			test = 1;
			break;
			}
		}
	if (!test)
		printf("prime\n");
	return 0;
	}
