#define _CRT_NONSTDC_NO_DEPRECATE
#include "spisci.h"

int ucitaj(FILE* in, FILE *out, cvor **first, cvor **last)
{
	char c;

	student s;
	int line = 1;

	while ((c = fgetc(in)) != EOF)
	{
		s.ind_g = (c - '0') * 10;
		c = fgetc(in);
		s.ind_g += (c - '0');
		c = fgetc(in);
		s.ind_br = (c - '0') * 1000;
		c = fgetc(in);
		s.ind_br += (c - '0') * 100;
		c = fgetc(in);
		s.ind_br += (c - '0') * 10;
		c = fgetc(in);
		s.ind_br += (c - '0');

		c = fgetc(in); // Proguta space

		fscanf(in, "%s", s.prezime);
		fscanf(in, "%s", s.ime);
		fscanf(in, "%s", s.smer);

		pisi_student(out, s,line++);
		dodaj(first, last, s);

		c = fgetc(in);
		if (c == EOF)
			break;
	}
	return 1;

}


void rezervisi_termine(FILE* in,FILE *out, cvor **first, cvor **last)
{
	char c;
	int h_start, h_end, m_start, m_end,d,m,y , i = 0;
	while ((c = fgetc(in)) != EOF)
	{
		d = (c - '0') * 10;
		c = fgetc(in);
		d += (c - '0');
		fscanf(in, ".%d.%d.-%d:%d#%d:%d\n",&m,&y,&h_start,&m_start,&h_end,&m_end);
		int min = duzina_termina(h_start, m_start, h_end, m_end);
		if (min >= 20 * T_MAX)
		{
			fprintf(out,"%.2d.%.2d.%.4d %.2d:%.2d - %.2d:%.2d\n", d, m, y, h_start, m_start, h_end, m_end);

			char t[15] = "term_";
			char buffer[4];
			itoa(i++, buffer, 10);
			strcat(t, buffer);
			strcat(t, ".txt");
			FILE* term = fopen(t, "w");

			fprintf(term,"%.2d.%.2d.%.4d %.2d:%.2d - %.2d:%.2d\n", d, m, y, h_start, m_start, h_end, m_end);

			for (int j = 0; j < 20 && *first != NULL; j++)
			{
				pisi_student(term, (*first)->inf, j + 1);
				//brisi_prvi(first,last);
				(*first) = (*first)->next;
			}

			fclose(term);

		}
	}
}