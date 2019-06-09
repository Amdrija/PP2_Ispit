#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T_MAX 3



typedef struct s_student
{
	int ind_br, ind_g;
	char ime[30], prezime[40], smer[3];
}student;

typedef struct scvor
{
	student inf;
	struct scvor *next, *last;
}cvor;


int ucitaj(FILE* in, FILE *out, cvor **first, cvor **last);
void rezervisi_termine(FILE* in, FILE* out, cvor** first,cvor **last);


void pisi_student(FILE* out, student s, int line);
void pisi_list(FILE* out, cvor* first);

void brisi(cvor* first);
void dodaj(cvor **first, cvor **last, student s);
int duzina_termina(int h_start, int m_start, int h_end, int m_end);
void brisi_prvi(cvor** first, cvor** last);

