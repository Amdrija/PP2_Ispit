#include "spisci.h"

void brisi(cvor* first)
{
	while (first)
	{
		cvor* t = first;
		first = first->next;
		free(t);
	}
}

void dodaj(cvor **first, cvor **last, student s)
{
	cvor *novi = (cvor*)malloc(sizeof(cvor));
	if (novi == NULL)
	{
		printf("Greska pri alokaciji memorije.\n");
	}
	novi->inf = s;
	novi->next = NULL;
	novi->last = *last;
	if (*first == NULL)
	{
		*first = novi;
		*last = *first;
	}
	else
	{
		(*last)->next = novi;
		*last = novi;
	}
}

int duzina_termina(int h_start, int m_start, int h_end, int m_end)
{
	int delta = (h_end - h_start) * 60 + m_end - m_start;

	if (h_start > h_end)
		delta += 24 * 60;
	
	return delta;
}

void brisi_prvi(cvor** first, cvor **last)
{
	cvor *t = *first;
	if (t == NULL)
		return;
	if (t->next == NULL)
	{
		free(t);
		*first = NULL;
		*last = NULL;
	}

	*first = t->next;
	(*first)->last = NULL;
	
	free(t);
}

