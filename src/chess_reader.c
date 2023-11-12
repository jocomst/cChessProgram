#include <stdio.h>
#include <stdlib.h>

void readPGNFile(const char *filename) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error:Unable to open file %s\n", filename);
		exit(1);
	}

	char line[256];
	while (fgets(line, sizeof(line), file)) {
		printf("%s", line);
	}

	fclose(file);
}
