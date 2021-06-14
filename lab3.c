#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *abre_arquivo(const char *arquivo){
	FILE *ptr_arquivo = fopen(arquivo,"r");

	return ptr_arquivo;
}

int fecha_arquivo(FILE *arq){
	if(fclose(arq) != 0)
		return 1;

	return 0;
} 

double *le_valores(const char *arquivo, unsigned int *qtd_numeros){
	if(qtd_numeros == NULL){
		return NULL;}

	FILE *ptr_arq = abre_arquivo(arquivo);

	if(ptr_arq == NULL){
		fecha_arquivo(ptr_arq);
		*qtd_numeros = 0;
		return NULL;
	}

	int tam_arquivo =0, cont;
	double j;
	cont = feof(ptr_arq);
	while(cont == 0){
		fscanf(ptr_arq,"%lf", &j);
		tam_arquivo++;
		printf("%d",tam_arquivo);
		cont = feof(ptr_arq);
	}
	printf("%d", tam_arquivo);
	
	*qtd_numeros = tam_arquivo;

	double *valores = (double*)malloc(sizeof(double)*tam_arquivo);
	if(valores == NULL){
		*qtd_numeros = 0;
		fecha_arquivo(ptr_arq);
		return NULL;
	}

	rewind(ptr_arq);
	cont = feof(ptr_arq);
	int i=0;
	while(cont == 0){
		fscanf(ptr_arq, "%lf %lf", &valores[i], &valores[i+1]);
		i+=2;
		cont = feof(ptr_arq);
	}

	return valores;
}
double maior(double* valores, unsigned int qtd_numeros){
	if(valores == NULL){
		return HUGE_VAL;
	}

	int i;
	double maior = valores[0];
	for(i=0; i<qtd_numeros; i++){
		if(maior < valores[i]){
			maior = valores[i];
		}
	}

	return maior;
}
double menor(double* valores, unsigned int qtd_numeros){
	if(valores == NULL){
		return HUGE_VAL;
	}

	int i;
	double menor = valores[0];
	for(i=0; i<qtd_numeros; i++){
		if(menor > valores[i]){
			menor = valores[i];
		}
	}

	return menor;
}
double media(double* valores, unsigned int qtd_numeros){
	if(valores == NULL){
		return HUGE_VAL;
	}
	
	int i;
	double media=0;
	for(i=0;i<qtd_numeros; i++){
		media += valores[i];
	}

	media = media/qtd_numeros;

	return media;
}

double desvio(double* valores, unsigned int qtd_numeros){
	if(valores == NULL){
		return HUGE_VAL;
	}

	int i;
	double media_numeros = media(valores, qtd_numeros);
	double desvio_numeros=0;
	for(i=0;i<qtd_numeros; i++){
		desvio_numeros += pow((valores[i] - media_numeros), 2);
	}

	desvio_numeros = pow((desvio_numeros/qtd_numeros), 0.5);

	return desvio_numeros;
}
/*
double mediana(double* valores, unsigned int qtd_numeros){
    
	if(valores == NULL){
		return HUGE_VAL;
	}

	int i;
	double vetor[qtd_numeros];

	for(i=0;i<qtd_numeros; i++){
		if()*/
		return;
*/
double amplitude(double* valores, unsigned int qtd_numeros){
	if(valores == NULL){
		return HUGE_VAL;
	}

	double menor_num, maior_num, amplitude_velores;
	menor_num = menor(valores, qtd_numeros);
	maior_num = maior(valores, qtd_numeros);

	amplitude_valores = maior_num - menor_num;

	return amplitude_valores;
}

double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){
	if(valores == NULL){
		return HUGE_VAL;
	}
	if(posicao == NULL){
		return HUGE_VAL;
	}

	double valor_posicao;
	valor_posicao = valores[posicao];

	return valor_posicao;
}
/*
double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
	if(valores == NULL){
		*qtd_repeticao = 0;
		return HUGE_VAL;
	}

	int i;
	double num_repetido atual = valores[0];

	for(i=0; i<qtd_numeros; i++){
		if()
	return;
}
*/

