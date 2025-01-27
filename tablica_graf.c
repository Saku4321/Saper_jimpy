#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tablica_graf.h"

#define MAX_SIZE 100
void generuj_tab_start(char tablica[][MAX_SIZE],int sizex,int sizey){
	int i,j;
	char znak='a';
	tablica[0][0]=' ';
        for(i=1;i<sizex;i++){
                if (znak=='z'){
                        tablica[i][0]=znak;
                        znak='A';
                }
                else{
                        tablica[i][0]=znak;
                        znak++;
                }


	}
	znak ='a';
        for(j=1;j<sizey;j++){
                if (znak=='z'){ 
			tablica[0][j]=znak;
			znak='A';
		}
		else{
			tablica[0][j]=znak;
        		znak++;
		}
		
        }
	for(i=1;i<sizex+1;i++){
		for(j=1;j<sizey+1;j++){
			tablica[i][j]='.';
		}
	}
}
void wybierz_pole(int sizex, int sizey,int *x, int *y,int *opcja){
	char komenda;
	char wiersz, kolumna;
	if (scanf(" %c %c %c", &komenda, &wiersz, &kolumna) != 3) {
   	printf("Błędne wejście, spróbuj ponownie\n");
	while(getchar() != '\n');
	wybierz_pole(sizex, sizey, x, y, opcja);
    	return;
	}
	if(wiersz<=(sizex +'a') && wiersz>='a') *x= wiersz - 'a'+1 ;
       	else if(wiersz>='A'&& wiersz<=(sizex+'A')) *x=wiersz - 'A'+1;
	if(kolumna<=(sizey+'a')&&kolumna>='a') *y=kolumna - 'a'+1;
	else if(kolumna >='A'&&kolumna<=(sizey+'A')) *y=kolumna -'A'+1;
	if(komenda == 'f') *opcja = 2;
	else if(komenda =='r') *opcja =1;
}
bool visited[MAX_SIZE][MAX_SIZE];
void sprawdz_pola(char mapa[][MAX_SIZE], char tablica_graf[][MAX_SIZE], int sizex,int sizey,int x,int y, int opcja,int trudnosc,int *wynik){
	int i,j;
	if(opcja==1){
	if (x < 1 || x >= sizex || y < 1 || y >= sizey) return;
	if (visited[x][y]) return;	
	if (mapa[x][y] == '*'){
        	for(i=1;i<sizex;i++){
                	for(j=1;j<sizey;j++){
                        	if(mapa[i][j]=='*')tablica_graf[i][j]='*';
                                }
                }
		return;
	}
	if (mapa[x][y] != '0'){
	      	tablica_graf[x][y]=mapa[x][y];
		return;
	}
	visited[x][y] = true;
	tablica_graf[x][y]=mapa[x][y];

	sprawdz_pola(mapa,tablica_graf,sizex,sizey,x+1,y,opcja,trudnosc,wynik);
	sprawdz_pola(mapa,tablica_graf,sizex,sizey,x-1,y,opcja,trudnosc,wynik);
	sprawdz_pola(mapa,tablica_graf,sizex,sizey,x,y+1,opcja,trudnosc,wynik);
	sprawdz_pola(mapa,tablica_graf,sizex,sizey,x,y-1,opcja,trudnosc,wynik);
	sprawdz_pola(mapa,tablica_graf,sizex,sizey,x+1,y+1,opcja,trudnosc,wynik);
	sprawdz_pola(mapa,tablica_graf,sizex,sizey,x+1,y-1,opcja,trudnosc,wynik);
	sprawdz_pola(mapa,tablica_graf,sizex,sizey,x-1,y+1,opcja,trudnosc,wynik);
	sprawdz_pola(mapa,tablica_graf,sizex,sizey,x-1,y-1,opcja,trudnosc,wynik);
	}
	else if(opcja==2){
		if(tablica_graf[x][y]!='F'){
			tablica_graf[x][y]='F';
		}
		else if(tablica_graf[x][y]=='F'){
			tablica_graf[x][y]='.';
		}
	}
	int showed=0;
	int mnoznik = trudnosc+1;
	for(i=1;i<sizex;i++){
		for(j=1;j<sizey;j++){
			if(tablica_graf[i][j] != '.' && tablica_graf[i][j] != '*'){
				showed++;
			}
		}
	}
	*wynik = showed * mnoznik;
}

void odpowiedz(char tablica_graf[][MAX_SIZE],int sizex, int sizey){
	int i,j;
        for(i=0;i<sizex;i++){
                for(j=0;j<sizey;j++){
                        printf("%c",tablica_graf[i][j]);
                }
                printf("\n");
	}
}
