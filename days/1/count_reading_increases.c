#include <stdlib.h>

#include <stdio.h>
#define MAX_LINE_LENGTH 80

int main() {
	char line[MAX_LINE_LENGTH] = {0};
	FILE *fileptr; 
	int increases_count = 0;
	int prev_number = 0;
	int line_count = 0;
	if ((fileptr = fopen("/home/ev/Projects/advent_of_code/days/1/sonar_readings.txt", "r")) == NULL) {
		printf("Error! opening file");
 		exit(1);
	}

	while(fgets(line, MAX_LINE_LENGTH, fileptr)) {
		line_count++;
		int number = atoi(line);
		if (line_count <= 1) {
			printf("Skipping first line\n");
			prev_number = number;
			continue;
		}
		if (number > prev_number ) {
			increases_count++;
			// printf("Number %d > previous number %d\n", number, prev_number);
		}
		
		prev_number = number; 
	}
	fclose(fileptr);
	printf("%d\n", increases_count);
	return 0;
}
