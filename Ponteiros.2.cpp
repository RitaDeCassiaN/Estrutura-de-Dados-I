//Lista de Ponteiros- Questao 2

/*ALTERNATIVA A
Mensagem de erro.

ALTERNATIVA B
Porque p � um ponteiro do tipo inteiro, e em seguida a variavel x � atribuida 
sem o "&", que � usada para conseguir o endereco de uma variavel, ou seja,
assim o ponteiro aponta para o valor de x e n�o o endere�o.

ALTERNATIVA C
N�o.
*/

#include <stdio.h> //Este codigo � a alternativa D

int main (void){
	int x, *p;
	x = 100;
	p = &x;
	
	printf ("Valor de p = %p\tValor de *p = %d\n", (void *)p, *p);
	
	return 0;
	
}
/*ALTERNATIVA E
Execu��o bem sucedida*/