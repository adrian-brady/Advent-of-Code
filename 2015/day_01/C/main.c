#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PATH "../input.txt" // Hardcoded input path

int read_floor(char* path);
int find_basement(char* path);

int main() {
	int part_1 = read_floor(PATH);
	printf("Part 1: floor=%d\n", part_1);
	int part_2 = find_basement(PATH);
	printf("Part 2: floor=%d\n", part_2);
}

int read_floor(char* path) {
	FILE* fp = fopen(path, "r");
	if (!fp) exit(1);
	
	int c;
	int floor_pos = 0;
	while ((c = getc(fp)) != EOF) {
		if (c == '(') floor_pos++;
		else if (c == ')') floor_pos--;
	}

	fclose(fp);
	return floor_pos;
}

int find_basement(char* path) {
	FILE* fp = fopen(path, "r");
	if (!fp) exit(1);

	int c;
	int floor_pos = 0;
	int position = 0;
	while ((c = getc(fp)) != EOF) {
		position++;
		if (c == '(') floor_pos++;
		else if (c == ')') floor_pos--;
		if (floor_pos == -1) break;
	}

	fclose(fp);
	return position;
}
