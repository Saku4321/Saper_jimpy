#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "generuj_mape.h"
#include "tablica_graf.h"

#define MAX_SIZE 100
#define MAX_WYNIKI 5

void zapisz_wynik(int wynik) {
    FILE *plik = fopen("wyniki.txt", "r");
    int wyniki[MAX_WYNIKI];
    int liczba_wynikow = 0;
    
    if (plik) {
        while (liczba_wynikow < MAX_WYNIKI && fscanf(plik, "%d", &wyniki[liczba_wynikow]) == 1) {
            liczba_wynikow++;
        }
        fclose(plik);
    }
    
    if (liczba_wynikow < MAX_WYNIKI) {
        wyniki[liczba_wynikow++] = wynik;
    } else {
        int min_index = 0;
        for (int i = 1; i < MAX_WYNIKI; i++) {
            if (wyniki[i] < wyniki[min_index]) {
                min_index = i;
            }
        }
        if (wynik > wyniki[min_index]) {
            wyniki[min_index] = wynik;
        } else {
            return;
        }
    }
    
    // Sortowanie wyników malejąco
    for (int i = 0; i < liczba_wynikow - 1; i++) {
        for (int j = i + 1; j < liczba_wynikow; j++) {
            if (wyniki[j] > wyniki[i]) {
                int temp = wyniki[i];
                wyniki[i] = wyniki[j];
                wyniki[j] = temp;
            }
        }
    }
    
    // Zapisz najlepsze 5 wyników do pliku
    plik = fopen("wyniki.txt", "w");
    if (plik) {
        for (int i = 0; i < liczba_wynikow; i++) {
            fprintf(plik, "%d\n", wyniki[i]);
        }
        fclose(plik);
    }
    
    printf("Najlepsze wyniki:\n");
    for (int i = 0; i < liczba_wynikow; i++) {
        printf("%d\n", wyniki[i]);
    }
}
int main(int argc, char **argv){
	srand(time(NULL));
	int sizex,sizey;
	char mapa[MAX_SIZE][MAX_SIZE];
	char mapagraf[MAX_SIZE][MAX_SIZE];	
	if(argc!=2 && argc != 3){
		printf("Zbyt duza liczba argumentow \n");
		return 1;
	}
	int trudnosc= atoi(argv[1]);
	if(trudnosc<0 || trudnosc >3){
		printf("Wybrany poziom trudnosci nie istnieje \n");
		return 1;
	}
	memset(visited, 0, sizeof(visited));
	if(trudnosc==0){
		sizex=9;
		sizey=9;
	}
	if(trudnosc==1){
		sizex=16;
		sizey=16;
	}
	if(trudnosc==2){
		sizex=16;
		sizey=30;
	}
	else if(trudnosc ==3){
		printf("Podaj nazwe pliku z mapa: ");
		char nazwa_pliku[100];
		scanf("%99s", nazwa_pliku);
		wczytaj_mape_z_pliku(mapa,&sizex,&sizey,nazwa_pliku);
	}
	generuj_mape(mapa,sizex,sizey,trudnosc);
	//testowe do sprawdzenia czy mapa ok?	drukuj_mape_test1(mapa,sizex,sizey);
	generuj_tab_start(mapagraf,sizex,sizey);
	odpowiedz(mapagraf,sizex,sizey);
	int checkgraf =0;
	int i,j;
	int opcja;
	int x,y;
	int moves=0;
	int wynik=0;
	while(checkgraf!=1){
		checkgraf=1;
		
		for(i=0;i<sizex;i++){
			for(j=0;j<sizey;j++){
				if(mapagraf[i][j]=='.'|| (mapagraf[i][j]=='F'&& mapa[i][j]!=mapagraf[i][j]))checkgraf=0;
			}
		}
		if(checkgraf==1){
			printf("WYGRALES\n");
			break;
		}
		wybierz_pole(sizex,sizey,&x,&y,&opcja);
		if(mapagraf[x][y]=='*'&& moves==0){
			while(mapa[x][y]!='*'){
				generuj_mape(mapa,sizex,sizey,trudnosc);
			}
		}
		sprawdz_pola(mapa,mapagraf,sizex,sizey,x,y,opcja,trudnosc,&wynik);
		odpowiedz(mapagraf,sizex,sizey);
		if(mapa[x][y]=='*'&&opcja==1){
                        checkgraf=1;
                        printf("PRZEGRALES\n");
                        break;
                }
		moves++;
		printf("Liczba ruchow to: %d\nTwoj wynik wynosi: %d\n",moves,wynik);
	}
	zapisz_wynik(wynik);
	return 0;
}
