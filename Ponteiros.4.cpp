//Lista de Ponteiros - Questão 4

#include <stdio.h>
#include <math.h>


void calcula_hexagono (float l, float *area, float *perimetro) {
	*area = (3 * pow(l, 2)* sqrt(3)) / 2; //cálculo da área do hexágono
	*perimetro = 6 * l; //cálculo do perímetro
}

int main (){
	float l, area, perimetro;
	
	printf ("Digite o lado do hexagono: "); //Solicitando para digitar um lado
	scanf ("%f", &l);
	
	calcula_hexagono (l, &area, &perimetro); //A função é chamada
	printf ("Area: %.2f\n", area);
	printf ("Perimetro: %.2f\n", perimetro);
	
	return 0;
}