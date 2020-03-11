#include<stdio.h>
#include<windows.h>
#include<locale.h>
#define LIN  6
#define COL  10

void carregadados();
void natela(int aux[LIN][COL]);
void exiberesult();
void savedat();
void contador();//passa elementos a serem procurados e registra suas repeticoes
void repetidolinha();
void repetidocoluna();
void loading();
int busca(int elemento,int achou); //PROCURA REPETICOES
int R[LIN][COL],A[LIN][COL];
int numlinha,numcoluna,replinha=0,repcoluna=0;

main(){
	setlocale(LC_ALL, "Portuguese");
    carregadados(); 
    contador();
    repetidocoluna();
    savedat();
    exiberesult();
    getchar();
    getchar();	  
}
void carregadados(){
	int cont=1;
        for(int l=0;l<LIN;l++)
        {
            for(int c=0;c<COL;c++)
            {
            	A[l][c] = cont++;
            }
        }
    return;
}

int busca(int elemento,int achou){
	FILE *arq;
	int aux;
    if(elemento == -1){
        return -1;
    }
    else{
    	arq = fopen("loterias.txt","r");	
    	if(arq == NULL){
        	printf("\nErro ao abrir arquivo na busca!");
   	 	}
		fseek(arq, 0, SEEK_SET);
    	while(!feof(arq)){
    	fscanf(arq,"%d",&aux);
    		if(aux == elemento){
        	achou = achou+1;	
    		}
    	}fclose(arq);	
    }
return achou;
}
void contador(){ //passa valor para ser procurado e guarda resultado <-- ou erro aqui
    for(int i=0; i < LIN; i++){
        for(int j=0; j < COL; j++){
    		R[i][j]=busca(A[i][j],0);
    		if((R[i][j]>replinha)){
    			numlinha = A[i][j]; //acha numero mais repetido
    			replinha = R[i][j]; //suas repeticoes
			}
        }
    }
}
void exiberesult(){
	char buf[BUFSIZ] ;
    FILE *result;
    result = fopen("resultadomega.txt","r");
    if(result == NULL){
        printf("\nErro ao ler resultado!");
        return;}
        fseek(result,0,SEEK_SET);
     while(!feof(result)) {
        fgets(buf, BUFSIZ, result) ;
        printf("%s", buf) ;
    }
}
void repetidocoluna(){
    {for(int j=0; j < COL; j++)
        for(int i=0; i < LIN; i++){
    		if((R[i][j]>repcoluna)){
    			numcoluna = A[i][j]; //acha numero mais repetido
    			repcoluna = R[i][j]; //suas repeticoes
			}
        }
    }
}
void loading(){
	int i, j;
   system ("cls");
   printf ("\n\n\t\tCARREGANDO ARQUIVOS: \n\n");             
   for (i = 30; i <= 100; i++){                
      //printf ("\r  %d%%", i);      
      printf ("  %d%%\r", i);
      fflush (stdout);                         
      for (j = 0; j < i; j++){
        if (!j) // Da espaco na barra pra nao enconstar na borda da tela
        printf ("");  
        printf ("#");
        Sleep(1);
      }            
	}system ("cls");
}
void savedat(){
FILE *save;
    save = fopen("resultado.txt","wt");
    if(save == NULL){
        printf("\nErro ao salvar data!");
        return;}
    int l,c;
    fprintf(save,"\n----------------------------------------------------------------------------------------\n");
    fprintf(save,"\t\t********** MEGA SENA **********");
    fprintf(save,"\n----------------------------------------------------------------------------------------\n");
    for(l=0;l<LIN;l++){
        for(c=0;c<COL;c++)
        {
            fprintf(save," %d\t",A[l][c]);
        }
        fprintf(save,"\n");
    }
    fprintf(save,"\n----------------------------------------------------------------------------------------\n");
    fprintf(save,"\t\t********** QUANTIDADE DE SORTEIO DE CADA NÚMERO **********");
    fprintf(save,"\n----------------------------------------------------------------------------------------\n");
    for(l=0;l<LIN;l++){
        for(c=0;c<COL;c++)
        {
            fprintf(save," %d\t",R[l][c]);
        }
        fprintf(save,"\n");
    }
    fprintf(save,"\n----------------------------------------------------------------------------------------\n");
    fprintf(save," NUMERO QUE MAIS SE REPETE POR LINHA:\n %d - %d REPETIÇÕES.\n",numlinha,replinha);
    fprintf(save,"\n NUMERO QUE MAIS SE REPETE POR COLUNA:\n %d - %d REPETIÇÕES.",numcoluna,repcoluna);
    fclose(save);
    printf("\n\n\t\tPROGRAMA EXECUTADO COM SUCESSO!"); 
    Sleep(3300);
    loading();
}
