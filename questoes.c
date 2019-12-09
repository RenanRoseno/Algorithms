#include <stdio.h>
#include <string.h>

// QUESTÂO 1
struct aluno{
  char nome[30];
  char endereco[30];
  long int telefone;
  char cpf[11];
  int idade;
};

void init(FILE *p);
void insert();
void show();
void clear();

FILE *p;

int main(void) {
//-------Abrir arquivo ----
  p = fopen("cadastro","a+");
  
//------- Funções ----------
  init(p);
  insert();
  show();
  //Fechar arquivo
  clear();
  fclose(p);
}

void init(FILE *p){
//-------- Tratamento de exceção ------------
  if(p == NULL){
   p = fopen("cadastro","w+");
   if(p == NULL){
     printf("erro ao abrir arquivo");
   }
 }
}

// QUESTÃO 2
void insert(){
  struct aluno aluno1;
  
  printf("Nome: ");
  fgets(aluno1.nome, 30, stdin);
  fprintf(p, "\nNome: %s", aluno1.nome);

  printf("Endereco: ");
  fgets(aluno1.endereco, 30, stdin);
  fprintf(p, "Endereco: %s", aluno1.endereco);

  printf("Telefone: ");
  scanf("%li", &aluno1.telefone);
  getchar();
  fprintf(p, "Telefone: %li", aluno1.telefone);
  
  printf("CPF: ");
  fgets(aluno1.cpf, 30, stdin);
    fprintf(p, "\nCPF: %s", aluno1.cpf);
  
  printf("Idade:");
  scanf("%i", &aluno1.idade);
   fprintf(p, "Idade: %i\n", aluno1.idade);
}

// QUESTÃo 3
void show(){
    rewind(p);
    char c[100000];
    fread(c, 100000, 1, p);
    printf("%s", c);
    //while(!feof(p)){
    // printf("%c", getc(p));
  //}
}

//QUESTÃO 4
void clear(){
  p = fopen("cadastro", "w+");
}
