//Lista de Alocação Dinâmica de vetores
//Questao 1
//Resolvida
#include <stdio.h>
#include <stdlib.h>

int main (){
	
	/*Nesta funcao foram criados duas variaveis, dois ponteiros e a variavel do sexo que gostou e o que nao gostou do produto
	todas do tipo inteiro*/
	int n, i, *sexo, *opiniao, gostaram_F = 0, nao_gostaramM =0; 
	float porcentagem_F, porcentagem_Nao_GostaramM;
	
	
	printf ("Digite a quantidade dos entrevistados: ");
	scanf ("%d", &n);
	printf ("\n");
	
	
	sexo = (int*) malloc(n * sizeof (int)); //alocando na memoria
	opiniao = (int*) malloc (n * sizeof (int)); //alocando
	
	for (i=0; i < n; i++){ //minha variavel inicia em zero e enquanto for menor que a variavel n é incrementado
		printf ("Digite qual o sexo do entrevistado (1 = masculino, 2 = feminino)" );
     	scanf ("%d", &sexo[i]);
     	printf ("\n");
     	
     	printf ("Digite 1 = Gostou do produto, ou 0 = Nao Gostou ");
     	scanf ("%d", &opiniao[i]);
     	printf ("\n");
     	
     	if (sexo[i] == 2 && opiniao[i] == 1){ //Se o sexo for igual ao do sexo feminino e igual a 1, é a mulher que gostou
			 gostaram_F++; 
		 }
		 else if (sexo[i] == 1 && opiniao[i] == 0) { //se nao: é do sexo masculino que nao gostou
			 nao_gostaramM++;
		 }
	}
		 
	porcentagem_F = (float)gostaram_F/n * 100; //Calculo da porcentagem do sexo feminino que gostou
	porcentagem_Nao_GostaramM = (float) nao_gostaramM/n * 100; //Calculo da porcentagem do sexo masculino que não gostou
	
	//Exibindo a porcentagem da mulheres que gostam e dos homens que nao gostaram
	printf ("\nPorcentagem de mulheres que gostaram do produto: %.2f%%\n", porcentagem_F);
	printf ("\nPorcentagem de homens que nao gostaram do produto: %.2f%%\n", porcentagem_Nao_GostaramM);
	
	free (sexo); //libera memoria
	free (opiniao); //libera memoria
	
	return 0;
}