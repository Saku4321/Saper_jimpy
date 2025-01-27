#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generuj_mape.h"

#define MAX_SIZE 100
void wczytaj_mape_z_pliku(char mapa[][MAX_SIZE], int *sizex, int *sizey, const char *nazwa_pliku) {
    FILE *plik = fopen(nazwa_pliku, "r");
    if (!plik) {
        printf("Błąd: Nie można otworzyć pliku %s\\n", nazwa_pliku);
        exit(1);
    }

    fscanf(plik, "%d %d", sizex, sizey); // Odczytanie rozmiaru mapy

    for (int i = 0; i < *sizex; i++) {
        for (int j = 0; j < *sizey; j++) {
            fscanf(plik, " %c", &mapa[i][j]);
        }
    }

    fclose(plik);
}

void generuj_mape(char mapa[][MAX_SIZE],int sizex,int sizey,int trudnosc){
	//generowanie bomb
	int i,j;
	int tmpx;
	int tmpy;
	int max;
	char znak='A';
	mapa[0][0]=' ';
	for(i=1;i<sizex;i++){
		mapa[i][0]=znak;
		znak++;
	}
	znak='A';
	for(j=1;j<sizey;j++){
		mapa[0][j]=znak;
		znak++;
	}
	if(trudnosc ==0){
		max=10;
		i= 0;
		while(i<max){
			tmpx=1+ rand()%(sizex-1);
			tmpy=1+ rand()%(sizey-1);
			if(mapa[tmpx][tmpy]!='*'){
				mapa[tmpx][tmpy]='*';
				i++;
			}
		}
	}
		for(i=1;i<sizex;i++){
			for(j=1;j<sizey;j++){
				if(mapa[i][j]!='*'){
					mapa[i][j]='.';
				}
			}
		}

		if(trudnosc ==1){
                	max=40;
                	i= 0;
                	while(i<max){
                       		tmpx=1 + rand()%(sizex-1);
                        	tmpy=1 + rand()%(sizey-1);
                        	if(mapa[tmpx][tmpy]!='*'){
                                	mapa[tmpx][tmpy]='*';
                                	i++;
                        	}
                	}
		}
                for(i=1;i<sizex;i++){
                        for(j=1;j<sizey;j++){
                                if(mapa[i][j]!='*'){
                                        mapa[i][j]='.';
                                }
                        }
                }

		if(trudnosc ==2){
                max=99;
                i= 0;
                	while(i<max){
                        	tmpx=1 + rand()%(sizex-1);
                        	tmpy=1 + rand()%(sizey-1);
                        	if(mapa[tmpx][tmpy]!='*'){
                                	mapa[tmpx][tmpy]='*';
                                	i++;
                        	}
                	}
		}	
                for(i=1;i<sizex;i++){
                        for(j=1;j<sizey;j++){
                                if(mapa[i][j]!='*'){
                                        mapa[i][j]='.';
                                }
                        }
                }

	for(i=1;i<sizex+1;i++){
		for(j=1;j<sizey+1;j++){
			if(mapa[i][j]=='*')continue;
			int tmp=0;
			if(i>0 && mapa[i-1][j]=='*')tmp++;
			if(i>0 && j>0 && mapa[i-1][j-1]=='*')tmp++;
			if(i>0 && j<sizey && mapa[i-1][j+1]=='*')tmp++;
			if(i<sizex && mapa[i+1][j]=='*')tmp++;
			if(i<sizex && j>0 && mapa[i+1][j-1]=='*')tmp++;
			if(i<sizex && j<sizey && mapa[i+1][j+1]=='*')tmp++;
			if(j>0 && mapa[i][j-1]=='*')tmp++;
			if(j<sizey && mapa[i][j+1]=='*')tmp++;
			mapa[i][j]=tmp + '0';
		}
	}
}
void drukuj_mape_test1(char mapa[][MAX_SIZE],int sizex,int sizey){
	int i,j;
	for(i=0;i<sizex;i++){
		for(j=0;j<sizey;j++){
			printf("%c",mapa[i][j]);
		}
		printf("\n");
	}
}
