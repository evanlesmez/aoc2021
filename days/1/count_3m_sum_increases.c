#include <stdlib.h>

#include <stdio.h>
#define MAX_LINE_LENGTH 80

int sum(int arr[], int n)
{
    int sum = 0; // initialize sum
 
    // Iterate through all elements
    // and add them to sum
    for (int i = 0; i < n; i++)
    sum += arr[i];
 
    return sum;
}


int main() {
	char line[MAX_LINE_LENGTH] = {0};
	FILE *fileptr; 
	int increases_count = 0;
	int line_count = 0;
	int i, tmp, window_size = 3;
	int prev_window[3] = {0};
	int window[3] = {0};
	if ((fileptr = fopen("/home/ev/Projects/advent_of_code/days/1/sonar_readings.txt", "r")) == NULL) {
		printf("Error! opening file");
 		exit(1);
	}

	while(fgets(line, MAX_LINE_LENGTH, fileptr)) {
		line_count++;
		int number = atoi(line);
		for(i=0; i<window_size - 1; i++)
    		{
       	 		window[i] = window[i+1];
    		}
		window[window_size-1] = number;
		if (line_count < 4){
			printf("skipping line\n");
			for (i = 0; i < window_size; i++) {
				prev_window[i] = window[i];
			}
			continue;
		}
		if (sum(window, window_size) > sum(prev_window, window_size)){
			printf("i\tWindow\tPrev window\n");
			for (i = 0; i < window_size; i++){
				printf("%d\t%d\t%d\n", i,window[i], prev_window[i]); 
			}
			increases_count++;
		}
		for (i = 0; i < window_size; i++) {
			prev_window[i] = window[i];
		}		
	}
	fclose(fileptr);
	printf("%d\n", increases_count);
	return 0;
}


