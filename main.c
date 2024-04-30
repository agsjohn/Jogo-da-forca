#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHANCES 5

main(){
  char palavra[255], dica[255], letras[255], usados[CHANCES];
  char atual[255], p, dica2[255];
  int tamp, x, chances = CHANCES, cont = 0, foi, ganhar = 0, rep;
  strcpy(usados, "");
  printf("Digite uma palavra para forca: ");
  gets(palavra);
  tamp = strlen(palavra);
  for(x = 0; x < tamp; x++){
    if(palavra[x] != ' '){
      atual[x] = '_';
    }
    else{
      atual[x] = ' ';
    }
  }
  printf("Digite uma dica para a palavra: ");
  gets(dica);
  strcpy(dica2, dica);
  do{
    system("clear");
    printf("Dica da forca: %s", dica2);
    printf("\npalavra atual: ");
    for(x = 0; x < tamp; x++){
      printf("%c", atual[x]);
    }
    printf("\n");
    printf("Chances: %i\n", chances);
    if(chances != CHANCES){
      printf("Letras usadas: ");
      for(x = CHANCES; x > chances; x--){
        if(x == CHANCES){
          printf("%c", usados[x]);
        }
        else{
          printf(" - %c", usados[x]);
        }
      }
    }
    printf("\n");
    printf("Digite uma letra: ");
    scanf("%c", &p);
    while(p == ' '){
      printf("Digite novamente: ");
      scanf("%c", &p);
    }
    getchar();
    rep = 0;
    for(x = CHANCES; x > 0; x--){
      if(usados[x] == p){
        rep = 1;
      }
    }
    foi = 0;
    ganhar = 0;
    if(rep == 0){
      for(x = 0; x < tamp; x++){
        if(p == palavra[x]){
          atual[x] = p;
          foi++;
        }
      }
      if(foi == 0){
        usados[chances] = p;
        chances--;
      }
      for(x = 0; x < tamp; x++){
        if(atual[x] != '_'){
          ganhar++;
        }
      }
    }
  }while(chances != 0 && ganhar != tamp);
  if(ganhar == tamp){
    printf("\nParabéns!! Você ganhou! A palavra era: %s\n", palavra);
  }
  else{
    printf("\nInfelizmente você perdeu, a palavra era: %s", palavra);
  }
  getchar();
}