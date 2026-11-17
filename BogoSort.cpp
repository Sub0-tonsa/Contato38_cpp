/*
	Name: BogoSort.cpp
	Author: Giovanni Tonsa
	Date: 17/11/26 11:23
	Description: Programa para implemntar o metodo de ordenação Bogo Sort (sorteio e teste)
*/

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

//prototipação
bool is_sorted(int *, int); //esta em ordem?
void emparalha(int *, int);
void bogoSort(int *, int);

//Variaveis Globais
int tentativas = 0;

main()
{
	int vet[] = {23, 12 ,17, -2, 20, 24, 157, 50, 81, 53};
	int i;
	int tam = sizeof(vet)/sizeof(int);
	
	puts("Vetor original: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
		
	bogoSort(vet, tam);
	
	puts("\n\nVetor ordenado com o Bogo Sort: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
		
	printf("\nOrdenado em %d tentativas!\n", tentativas);
		
}
//Função principal do Bogo Sort
void bogoSort(int *V, int tam)
{
	while(is_sorted(V, tam) == false)
		emparalha(V, tam);
}

//Função que emparalha os elementos do vetor
void emparalha(int *V, int tam)
{
	int i, temp, r;
	for(i = 0; i < tam; i++)
	{
		temp = V[i];
		r = rand() % tam;
		V[i] = V[r];
		V[r] = temp;
	}
}

//Função que pergunta se esta em ordem
bool is_sorted(int *V, int tam)
{
	while(--tam >= 1)
	{
		if(V[tam] < V[tam - 1])
		{
			tentativas++;
			return false;
		}
	}
	return true;
}
