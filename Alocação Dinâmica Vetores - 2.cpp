//Alocação Dinâmica Vetores - Questão 2

#include <stdio.h>
#include <stdlib.h>

int main (){
	//Começo declarando variáveis, ponteiro e ponteiro para ponteiro
	int n, i, j, acertos;
	float nota, media, porcentagem_Ap;
	char *gabarito, **respostas;
	
	printf ("O numero das questoes: ");
	scanf ("%d", &n); //Leitura o números de questões e aloca o gabarito
	gabarito = (char*)malloc(n* sizeof(char));
	
	printf ("O gabarito da prova:\n");
	for (i =0; i <n; i++){
		scanf ("%c", &gabarito[i]); //Leitura de gabarito
	}
	
	respostas = (char**)malloc (10 * sizeof(char*));//aloca vetor de respostas dos alunos
	for (i=0; i<10; i++){
		respostas[i] = (char*)malloc (n* sizeof (char));
	}
	for (i= 0; i<10; i++){
		printf ("Digite as respostas dos alunos %d:\n", i+1);
		for (j = 0; j< n; j++){
			scanf ("%c", &respostas[i][j]);

			}	
	}
	//Calcula a nota e porcentagem
	media = 0;
	for (i = 0; i < 10; i++){
		acertos = 0;
		for (j = 0; j< n; j++){
			if (respostas [i][j]==gabarito[j]){
				acertos++;
			}
		}
		nota = 10.0 * acertos / n;
		printf ("A nota do aluno %d e %.1f\n", i+1, nota);
		media += nota;
		if (nota >= 6){
			porcentagem_Ap++;
		}
	}
	media /= 10;
	porcentagem_Ap = 100 *porcentagem_Ap / 10;
	
	//Mostra a media e a porcentagem de Aprovação
	printf ("A media da turma foi %.1f\n", media);
	printf ("A porcentagem de aprovados foi %.1f\n", porcentagem_Ap);
	
	free (gabarito); //Libera memória
	for (i = 0; i< 10; i++) {
		free (respostas[i]);
	}
	free(respostas);
	
	return 0;	
}