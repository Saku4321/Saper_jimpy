#ifndef _TABLICA_GRAF_H_
#define _TABLICA_GRAF_H_ 

#define MAX_SIZE 100
extern bool visited[MAX_SIZE][MAX_SIZE];
void generuj_tab_start(char tablica[][MAX_SIZE],int sizex,int sizey);
void wybierz_pole(int sizex, int sizey, int *x, int *y, int *opcja);
void sprawdz_pola(char mapa[][MAX_SIZE], char tablica_graf[][MAX_SIZE], int sizex,int sizey,int x,int y,int opcja,int trudnosc,int *wynik);
void odpowiedz(char tablica_graf[][MAX_SIZE],int sizex, int sizey);
#endif

