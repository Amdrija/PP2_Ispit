#include "spisci.h"
#include <time.h>

int main(int argc, char *argv[])
{
	clock_t c1 = clock();
	
	char time_str[20];
	time_t t1 = time(NULL);
	strftime(time_str,20, "%H:%M:%S", localtime(&t1));
	printf("%s\n", time_str);


	FILE *ulaz, *izlaz;
	ulaz = fopen(argv[1], "r");
	izlaz = fopen("iazlaz.txt", "w");

	if (!ulaz || !izlaz)
	{
		printf("Greska pri ucitavanju fajla.\n");
		exit(1);
	}

	cvor *first = NULL, *last = NULL;

	ucitaj(ulaz,izlaz, &first, &last);
	pisi_list(stdout, first);

	fclose(ulaz);
	fclose(izlaz);

	FILE *raspolozivosti = fopen(argv[2], "r");
	FILE* termini = fopen("termini.txt", "w");
	if (raspolozivosti == NULL)
	{
		printf("Greska pri ucitavanju fajla raspolozivosti.\n");
		exit(1);
	}
	rezervisi_termine(raspolozivosti, termini, &first,&last);

	fclose(raspolozivosti);
	fclose(termini);


	brisi(first);
	clock_t c2 = clock();
	double delta = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("%.2lf\n", delta*1000);

	t1 = time(NULL);
	strftime(time_str, 20, "%H:%M:%S", localtime(&t1));
	printf("%s\n", time_str);

	return 0;
}