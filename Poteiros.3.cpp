/*Lista de Ponteiros- Quest�o 3
A saida � : 11, 20, 10 e 30*/

#include <stdio.h>

int main (void){
	int a, b, c, d; //Vari�veis declaradas
	int *p1; //Ponteiro do tipo inteiro
	int *p2 = &a; //p2 aponta para o endereco de a
	int *p3 = &c; //p3 aponta para o endereco de c
	
	p1 = p2; //o valor de p2 atribuido  para p2
	*p2 = 10; //Aqui � o valor de a, que � 10
	b = 20;
	
	int **pp;
	pp = &p1;
	*p3 = **pp;
	int *p4 = &d;
	*p4 = b + (*p1)++;
	
	printf ("%d\t%d\t%d\t%d\t\n", a, b, c, d);
	return 0;
}
	