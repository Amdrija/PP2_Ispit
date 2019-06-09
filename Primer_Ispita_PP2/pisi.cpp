#include "spisci.h"

void pisi_student(FILE* out, student s,int line)
{
	fprintf(out,"%d.\t%.4d/%.2d   %s %s\n", line ,s.ind_br, s.ind_g, s.ime, s.prezime);
}

void pisi_list(FILE* out, cvor* first)
{
	int line = 1;
	while (first)
	{
		pisi_student(out, first->inf, line++);
		first = first->next;
	}
}