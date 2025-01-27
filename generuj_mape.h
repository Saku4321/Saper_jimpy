#ifndef _GENERUJ_MAPE_H_
#define _GENERUJ_MAPE_H_ 

#define MAX_SIZE 100

void wczytaj_mape_z_pliku(char mapa[][MAX_SIZE], int *sizex, int *sizey, const char *nazwa_pliku);

void generuj_mape(char mapa[][MAX_SIZE],int sizex,int sizey,int trudnosc);

void drukuj_mape_test1(char mapa[][MAX_SIZE],int sizex,int sizey);

#endif

