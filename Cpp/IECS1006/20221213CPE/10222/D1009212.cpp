#include <stdio.h>
#include <stdlib.h>

int main() {
	int count;
	char raw[100];
	char line1_s[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\'};
	char line1_b[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'};
	char line2_s[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\''};
	char line2_b[] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''};
	char line3_s[] = {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
	char line3_b[] = {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'};
	
	scanf("%d\n", &count);
	for (int i = 0; i < count; i++) {
		gets(raw);
		for (int j = 0; raw[j] != '\0'; j++) {	
			if (raw[j] == '\n') {
				break;
			}
			for (int k = 0; line1_s[k] != '\0'; k++) {
				if (raw[j] == line1_s[k]) 
					raw[j] = line1_s[k - 2];
				if (raw[j] == line1_b[k]) 
					raw[j] = line1_s[k - 2];	
			}
			for (int k = 0; line2_s[k] != '\0'; k++) {
				if (raw[j] == line2_s[k]) 
					raw[j] = line2_s[k - 2];
				if (raw[j] == line2_b[k]) 
					raw[j] = line2_s[k - 2];	
			}
			for (int k = 0; line3_s[k] != '\0'; k++) {
				if (raw[j] == line3_s[k]) 
					raw[j] = line3_s[k - 2];
				if (raw[j] == line3_b[k]) 
					raw[j] = line3_s[k - 2];	
			}
		}
		printf("%s\n", raw);
	}
	return 0;
}
