#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "sha0.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "%s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	const char *infile = argv[1];

	struct stat statbuf;
	if (stat(infile, &statbuf)) {
		perror(infile);
		exit(EXIT_FAILURE);
	}

	SHA0Context ctx;
	SHA0Reset(&ctx);



	FILE *f = fopen(infile, "r");
	if (!f) {
		perror("data");
		exit(EXIT_FAILURE);
	}

	uint8_t *buffer = malloc(statbuf.st_size);
	if (!buffer) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	size_t r = fread(buffer, 1, statbuf.st_size, f);
	if (r != statbuf.st_size) {
		perror("short read");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "SHA0 over %ld bytes of %s: ", r, infile);

	SHA0Input(&ctx, buffer, r);
	SHA0FinalBits(&ctx, 0, 0);
	uint8_t dgst[SHA0HashSize];
	SHA0Result(&ctx, dgst);

	for (int i = 0; i < SHA0HashSize; i++) {
		fprintf(stderr, "%02x", dgst[i]);
	}
	fprintf(stderr, "\n");
	free(buffer);
	return 0;
}
