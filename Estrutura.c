//Tipos de Estruturas - Questao 1
//Nao resolvido

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 5
#define MAX_TURMAS 2

struct aluno {
	int mat;
	char nome[81];
	float notas[3];
	float media;
};
 typedef struct aluno Aluno;
 
struct turma{
	char id; /* caractere que identifica a turma, por exemplo, A ou B */
	int vagas; /* numeros de vagas disponiveis para fechar a turma */
	Aluno* alunos[MAX_VAGAS];
};
typedef struct turma Turma; //STRUCT RENOMEADA

Turma* turmas [MAX_TURMAS];

Turma* cria_turma(char id){
	Turma *t = (Turma*) malloc(sizeof(Turma));
	if (t != NULL) { //Se diferente de NULL
		 t->id = id;
		 t->vagas = MAX_VAGAS;
		
		for (int i = 0; i < MAX_VAGAS; i++) {
			t->alunos[i] = NULL;
		}
		printf("turma criada!\n");
		return t;
	}
};
//Funcao para a matricula do aluno
void matricula_aluno(Turma* turma, int mat, char* nome) {
    if (turma == NULL) { //Se igual a NULL
        printf("Turma nao existe\n");
        return;
    }
    else if (turma->vagas == 0){ //Se nao, vai printar turma cheia
  		printf ("Turma cheia\n");
  		return;
  	}
	
    for (int i = 0; i < MAX_VAGAS; i++) {
      if (turma->alunos[i] == NULL) {
          Aluno* a = (Aluno*) malloc(sizeof(Aluno));
          a->mat = mat;
          strcpy(a->nome, nome);
          
          for (int j = 0; j< 3; j++){
            a->notas[j] = 0;
          }
          a->media =0;
          turma->alunos[i] = a;
          turma->vagas--;
          printf ("Aluno matriculado na turma %c\n", turma->id);
          return;
    }
  }
};
void lanca_notas(Turma* turma) {
  
	if (turma == NULL){
		printf ("Turma nao existe\n");
		return;
	}
  
	float soma = 0;
    for (int i = 0; i < MAX_VAGAS; i++) {
		if (turma->alunos[i] != NULL){
			printf ("Informe as notas do aluno %s: ", turma->alunos[i]->nome);
			
			for(int j=0; j< 3; j++){
				soma += turma->alunos[i]->notas[i];
			}
			turma->alunos[i]->media = soma / 3;
			soma = 0;
		}
	}
}

void imprime_alunos(Turma* turma) {
	if (turma == NULL){
		printf ("Turma nao existe\n");
		return;
	}
    printf("Alunos da turma %c:\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++) {
    	if(turma->alunos[i] != NULL){
        	printf ("Matricula: %d, Nome: %s, Media: %2f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
		}
	}
}
//Funcao para mostrar as turmas
void imprime_turmas (Turma** turmas){
  int i =0;
  printf("Listando turmas...\n");
  while (turmas[i] != NULL){
    printf ("Turma %c - %d vagas disponiveis.\n", turmas[i]->id, turmas[i]->vagas);
    i++;
  }
	/*for (int i = 0; i < n; i++){
		if (turmas[i] != NULL){
			printf ("Turma %c: \n", turmas[i]->id);
			imprime_alunos (turmas[i]);
			printf ("\n");
		}
	}*/
}
Turma* procura_turma (Turma** turmas, int n, char id){
	for (int i = 0; i < n; i++){
		if (turmas[i] != NULL && turmas[i]->id ==id) {
			return turmas[i];
		}
	}
	return NULL;
}
void menu(){ //O menu para mmostrar as opcoes do usuario
	printf("Escolha uma opcao: \n");
	printf("1 - Criar turma \n");
	printf("2 - Listar turmas \n");
	printf("3 - Matricular aluno \n");
	printf("4 - Lancar notas \n");
	printf("5 - Listar alunos \n");
	printf("6 - Sair \n");
}
int main(){
	Turma t;
	int op, cont = 0;


	do{
    menu();
    scanf("%d", &op);
		if(op == 1){ //Se igual a 1, vai mostrar o id
			printf("Informe o id da turma \n");
			char id;
			scanf("%s", &id);
			turmas[cont] = cria_turma(id);
      cont++;
		}else if(op == 2){ //Se for a opcao 2, imprime turmas
		
			/*printf("Qual turma voce deseja imprimir?");
			int n;*/
			//scanf("%d" ,&n);
			imprime_turmas(turmas);
		}else if(op == 3){
			int mat;
			char nome[25];
			printf("informe a matricula: ");
			scanf("%d", &mat);
			printf("informe o nome");
			scanf("%s", nome);
			matricula_aluno(&t, mat, nome);
		}else if(op == 4){
			lanca_notas(&t);
		}else if(op == 5){
			imprime_alunos(&t);
		}
	}while(op != 6);
  return 0;	
}