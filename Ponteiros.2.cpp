//Lista de Ponteiros- Questao 2

/*ALTERNATIVA A
Mensagem de erro.

ALTERNATIVA B
Porque p é um ponteiro do tipo inteiro, e em seguida a variavel x é atribuida 
sem o "&", que é usada para conseguir o endereco de uma variavel, ou seja,
assim o ponteiro aponta para o valor de x e não o endereço.

ALTERNATIVA C
Não.
*/

#include <stdio.h> //Este codigo é a alternativa D

int main (void){
	int x, *p;
	x = 100;
	p = &x;
	
	printf ("Valor de p = %p\tValor de *p = %d\n", (void *)p, *p);
	
	return 0;
	
}
/*ALTERNATIVA E
Execução bem sucedida*/