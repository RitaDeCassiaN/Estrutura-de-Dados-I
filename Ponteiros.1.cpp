//Lista de Estrutura com Cibelly
//Lista de Ponteiros - Questao 1

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int x, y, *p;
	
	y = 0; //o valor de minha variavel é 0
	
	p = &y; //O ponteiro aponta para o endereco de y
	
	x = *p; //A variavel x recebe o conteudo do meu ponteiro que aponta para y, portanto o valor é 0
	
	x = 4; //A variavel x recebe o valor de 4
	
	(*p)++; //Aqui é incrementado +1, portanto y agora é 1
	
	--x; //Aqui diminui menos 1, portanto x que era 4, agora possui o valor 3
	
	(*p)+=x; //SOmado o valor do endereco de y com o valor de x, y agora é 4
	
	printf ("%i %i %i\n", x, y, *p);
	
	//Os valores de: x = 3, y = 4 , p = 4 (aponta para o endereco de y)
	
	
	
	return 0;
	
}