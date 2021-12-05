#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 30

int main () {
	int depth = 0;
	int horizontal = 0;
	int aim = 0;
	char line[MAX_LINE_LEN] = {0};
	char *string, *found;
	char *drect;
	FILE *fp;
	fp = fopen("moves.txt", "r");
	while(fgets(line, MAX_LINE_LEN, fp)) {
    		string = strdup(line);
		int i = 0;

    		while( (found = strsep(&string," ")) != NULL ) {
			
			if (i < 1) {
				drect = strdup(found);
			}	
			else {
				int mag = atoi(found);
				printf("%s -> %d", drect, mag);
				if (strcmp(drect, "forward") == 0) {
					horizontal += mag;
					depth += aim*mag;			
				}
				else if (strcmp(drect,"up") == 0) {
					aim -= mag;
				}	
				else {
					aim += mag; 
				}
				printf("\t%d\t%d", horizontal, depth);
			}
			i++;
		}
		printf("\n");
	}
	fclose(fp);
	printf("%d", horizontal*depth);
	return 0;
}
