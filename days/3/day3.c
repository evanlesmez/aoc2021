#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 20

/*
int bin_to_int(char bin[]){
	unsigned int i = 0;
	unsigned int l = sizeof bin / sizeof *bin;
	unsigned int ans;
	for (i = 0, i < (l - 1), i++){
		bin[i];
	}
	return ans;
} 
*/

int calc_part_one_power() {
	FILE *fp;
	char line[MAX_LINE_LEN] = {0};
	unsigned int bin1_cnt[12] = {0};
	unsigned int gamma_rate;
	unsigned int epsilon_rate;
	char gamma_bits[13];
	int line_cnt = 0;
	int i = 0;

	fp = fopen("input_data.txt", "r");
	while (fgets(line, MAX_LINE_LEN, fp)) {
		for (i = 0; i < 12; i++) {
			if (line[i] == '1') {
				bin1_cnt[i] ++;
			}
		}
		line_cnt += 1;
	}
	fclose(fp);
	printf("Binary 1 counts\n");
	for (i = 0; i < 12; i++) {
		printf("%d: %d\n", i, bin1_cnt[i]);
	}
	printf("Line count: %d\n", line_cnt);
	
	printf("Test g bits %s\n", gamma_bits);	
	for (i = 0; i < 12; i++) {
		if (line_cnt/2 < bin1_cnt[i]) {
			gamma_bits[i] = '1';
		}
		else {
			gamma_bits[i] = '0';
		}

		printf("%s\n", gamma_bits);
	}

	printf("Gamma bits %s\n", gamma_bits);
	gamma_rate = strtol(gamma_bits, NULL, 2);
	printf("Gamma rate: %d\n", gamma_rate); 

	epsilon_rate = 4095 - gamma_rate;
	printf("Epsilon_rate: %d\n", epsilon_rate);
	// Get opposite bits of gamma for 
	return gamma_rate * epsilon_rate;
}

int main () {
	printf("%d",calc_part_one_power());
	return 0;
}
