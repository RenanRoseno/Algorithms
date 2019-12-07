#include <stdio.h>

int main(void) {
 FILE *p;
 char car;

 //Criando arquivo (tratamento de exceção)
 p = fopen("aluno","a+");
 if(p == NULL){
   p = fopen("aluno","w+");
   if(p == NULL){
     printf("erro ao abrir arquivo");
   }
 }

// Escrevendo no arquivo
do {
  car = getchar();
  fputc(car, p);
} while(car != '-');


//Escrevendo um caractere
/*  car = getchar();
    fputc(car, p);
*/

//Problema do cursor pois o ponteiro aponta para o fim do arquivo e para isso, usamos rewind()
  rewind(p);

//Lendo e mostrando conteudo
  while(!feof(p)){
     printf("%c", getc(p));
  }
  
  fclose(p);
}
