#include <stdio.h>

int main() {
	FILE *in, * out;
	char fam[30], name[30], otch[30];
	int year;
	in = fopen("asd.txt", "r");
	out = fopen("asd2.txt", "w");
	while (fscanf(in, "%s %s %s %d", fam, &name, otch, &year) == 4) {
		if (year > 1980) {
			fprintf(out, "%s %s %s %d\n", fam, name, otch, year);
		}
	}
	fclose(in);
	fclose(out);
	printf("complete\n");
	return 0;
}
