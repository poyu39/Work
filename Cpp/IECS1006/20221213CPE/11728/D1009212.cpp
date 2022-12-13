#include <stdio.h>
#include <stdlib.h>

int main() {
	int s;
	int div_sum = 0;
	int case_count = 1;
	int now, div;
	
	while (scanf("%d", &s)) {
		if (s == 0) {
			break;
		}
		for (now = s; now > 0; now--) {
			for (div = 1; div <= now; div++) {
				if (now % div == 0) {
					div_sum += div;
				} 
			}
			if (div_sum == s) {
				printf("Case %d: %d\n", case_count, now);
				break;
			}
			div_sum = 0;
		}
		if(div_sum == 0) {
			printf("Case %d: -1\n", case_count);
		}
		case_count++;
	}
	return 0;
} 
