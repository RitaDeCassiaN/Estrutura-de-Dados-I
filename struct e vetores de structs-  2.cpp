//Struct e Vetores de struct - Questao 2

//Começo adicionando duas bibliotecas
#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 5

typedef struct {
    char nome[50];
    int documento;
    int idade;
} Pessoa; //Defini o nome da minha struct como Pessoa

//Função
void preencher_pessoa(Pessoa* p) {
    printf("Digite o nome: ");
    fgets(p->nome, 50, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0'; 
    
    printf("Digite o numero do documento: ");
    scanf("%d", &p->documento);
    
    printf("Digite a idade: ");
    scanf("%d", &p->idade); //Leitura
    getchar();  // consome o \n deixado pelo scanf
}

void imprimir_pessoa(Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Documento: %d\n", p.documento);
    printf("Idade: %d\n", p.idade);
}

void atualizar_idade(Pessoa* p, int nova_idade) {
    p->idade = nova_idade;
}

void imprimir_pessoas_extremas(Pessoa pessoas[], int num_pessoas) {
    Pessoa pessoa_mais_nova = pessoas[0];
    Pessoa pessoa_mais_velha = pessoas[0];

    for (int i = 1; i < num_pessoas; i++) {
        if (pessoas[i].idade < pessoa_mais_nova.idade) {
            pessoa_mais_nova = pessoas[i];
        }
        if (pessoas[i].idade > pessoa_mais_velha.idade) {
            pessoa_mais_velha = pessoas[i];
        }
    }

    printf("Pessoa mais nova: %s\n", pessoa_mais_nova.nome);
    printf("Pessoa mais velha: %s\n", pessoa_mais_velha.nome);
}

int main() {
    Pessoa pessoas[MAX_PESSOAS];

    // preencher as pessoas
    for (int i = 0; i < MAX_PESSOAS; i++) {
        printf("Digite os dados da pessoa %d:\n", i + 1);
        preencher_pessoa(&pessoas[i]);
        printf ("\n");
	}
	//imprime as pessoas
	printf ("Pessoas cadastradas:\n");
	for (int i = 0; i < MAX_PESSOAS; i++){
		imprimir_pessoa(pessoas[i]);
		printf ("\n");
	}
	
	//Atualiza
	int indice_pessoa;
	printf ("Digite o indice da pessoa que deseja atualizar a idade (0 a %d): ", MAX_PESSOAS - 1);
	scanf ("%d", &indice_pessoa);
	
	int nova_idade;
        printf ("Digite a nova idade: ");
        scanf ("%d", &nova_idade);
        atualizar_idade(&pessoas[indice_pessoa], nova_idade);
        
        //Imprimir as pessoas
        imprimir_pessoas_extremas(pessoas, MAX_PESSOAS);
        
        return 0;
        
}
        
        
        
        
        