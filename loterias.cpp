#include<stdio.h>
#include<iostream>
#define LIN  4
#define COL  5

void AbreArq();
void exibe(int aux[LIN][COL]);
void savedat(int aux[LIN][COL]);
void contador(int aux[LIN][COL]);//passa elementos a serem procurados e registra suas repeticoes
int procura(int mat[LIN][COL],int elemento);//procura por elementos repetidos
int busca(int ele,int cont); //funcao recursiva de busca
int A[LIN][COL],i,j,am,an, contados[36];
FILE *arq;
FILE *save;

struct reg{ //estrutura dos valores guardados. numero e suas repeticoes <- add linha e coluna do elemento para fazer busca depois
	int ele; // elemento
	int rep; //quantidade de repeticoes
};
struct reg resultado[36];
main(){
  	AbreArq();
  	exibe(A);
  	contador(A);
  	savedat(A);
	printf("\n\tELEMETO\tREPETICOES\n");
}

void AbreArq() 
{ arq = fopen("loterias.txt","r");
	if(arq == NULL){
	printf("\nErro ao abrir arquivo!");
   	return;}
   	for(i = 0; i < LIN; i++){
   		for(j = 0; j < COL; j++){
   			fscanf(arq,"%d",&A[i][j]);
		   }
	   }
	printf("\n#### MATRIZ CARREGADA ####");
  	fclose(arq);
}
int busca(int x,int achou){ // nova funcao recursiva para buscar numeros repetidos
	i=0;j=0;
	if(i < LIN){
		if(j < COL){
			if(x == A[i][j]){
				achou = achou+1;
				j++;
				busca(A[i][j],achou);
			}
			i++;
			busca(A[i][0],achou);
		}
	}return achou;
}
/*int procura(int mat[LIN][COL],int elemento){ //procura por elementos repetidos <--- possivel erro
	int achou;
	for(i=0; i < LIN; i++){
		for(j=0; j < COL; j++){
			if(elemento == mat[i][j]){
				achou = achou+1;
			}
		}
		printf("%d \t %d",mat[i][j],achou);
	}
	
	return achou;
}*/
void contador(int aux[LIN][COL]){ //passa valor para ser procurado e guarda resultado <-- ou erro aqui
	int z=0;
	for(i=0; i < LIN; i++){
		for(j=0; j < COL; j++){
			resultado[z].ele = aux[i][j];
			resultado[z].rep = busca(A[i][j],0);
			//printf("\n%d ",aux[i][j]);
			//printf("\n%d ",procura(A,aux[i][j]));
			z=z+1;
			}
		}
		
	}
void exibe(int aux[LIN][COL]){
	printf("\n--------------------------------------------\n");
	for(i=0;i<LIN;i++){
		for(j=0;j<COL;j++)
		{
			printf("%4d\t",aux[i][j]);
		}
		printf("\n");
	}
	printf("\n--------------------------------------------\n");
}
void savedat(int aux[LIN][COL])
{
	save = fopen("teste.txt","wt");
	if(save == NULL){
		printf("\nErro ao salvar data!");
		return;}
	int l,c;
	for(l=0;l<LIN;l++){
		for(c=0;c<COL;c++)
		{
			fprintf(save,"%4d\t",aux[l][c]);
		}
		fprintf(save,"\n");
	}
	fclose(save);
	printf("\nARQUIVO SALVO COM SUCESSO!\n");
}
