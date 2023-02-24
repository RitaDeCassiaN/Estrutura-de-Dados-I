//Struct e Vetores de struct - Questao 1

//Incio colocando tr�s bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fa�o uma estrutura pra guardar as informa��es do Funcion�rio
typedef struct Funcionario {
	char nome [50];
	float salario;
	int identificador;
	char cargo[50];
	
} Funcionarios; //Renomeio

//Fa�o uma fun��o
void preencherFuncionario (Funcionario *f){
printf ("Nome do funcionario: ");
scanf ("%s", f->nome); //Leitura

printf ("Digite o salario do funcionario: ");
scanf ("%f", &f->salario);

printf ("Digite o identificador: ");
scanf ("%d", &f->identificador);
printf ("cargo: %s\n", f->cargo);
}

//Fun��o
void imprimirFuncionario (Funcionario *f) {
	printf ("Nome: %s\n", f->nome);
	printf ("Salario: %.2f\n", f->salario);
	printf ("Identificador: %d\n", f->identificador);
	printf ("Cargo: %s\n", f->cargo);
}

void alterarSalario(Funcionario *f, float novoSalario){
	f->salario = novoSalario;
}

//Fun��o
void imprimirMaiorEMenorSalario (Funcionario f[], int n){
	
	int i, indiceMaiorSalario = 0, indiceMenorSalario = 0;
	for (i = 1; i < n; i++){
		if (f[i].salario > f[indiceMaiorSalario].salario){
			indiceMaiorSalario = i;
		}
		if (f[i].salario < f[indiceMenorSalario].salario){
			indiceMenorSalario = i;
		}
	}
    printf ("Funcionario com o maior salario:\n");
    printf ("Cargo: %s\n", f[indiceMaiorSalario].cargo);
	printf ("Salario: %.2f\n", f[indiceMaiorSalario].salario);
	
	printf ("Funcionario com o menor salario:\n");
	printf ("Cargo: %s\n", f[indiceMenorSalario].cargo);
	printf ("Salario: %.2f\n", f[indiceMenorSalario].salario);
}

//C�digo cria um vetor de 3 Funcionario, os campos s�o preenchidos com valores dos usu�rios
int main (){
	int i;
	
	Funcionario f[3];
	
	for (i = 0; i < 3; i++){
		preencherFuncionario(&f[i]);
	}
	for (i = 0; i < 3; i++){
		imprimirFuncionario(&f[i]);
	}
	alterarSalario(&f[1], 2500.0);
	
	for (i = 0; i < 3; i++){
		imprimirFuncionario(&f[i]);
	
	}
	imprimirMaiorEMenorSalario(f, 3);
	
	return 0;
}