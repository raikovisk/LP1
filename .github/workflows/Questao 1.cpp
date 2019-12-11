#include <iostream>

void ledados();
int calculasalario(float);

char escolha;
int pecastotal, Htotal, Mtotal, totalfolha=0;
float minimo = 908,mediaH, mediaM,somasalario;
float maiorsalario;
float sal,auxM,auxH;

int idoperario,Npecas,idmaiorsal,n;
char sexo;
    
main(){
	do{
    ledados();
    printf("\n Salario: %.2f",sal);
	}while((escolha == 'S') || (escolha == 's'));
	//Mostrando resultados apos o loop
    printf("\n Folha de pagamento: %.2f",totalfolha);
    printf("\n Total pecas fabricadas: %d",pecastotal);
    printf("\n Media de pecas fabricadas por Homens: %.2f",pecastotal/Htotal);
    printf("\n Media de pecas fabricadas por Mulheres: %.2f",pecastotal/Mtotal);
    printf("\n Maior salario: %.2f",idmaiorsal);
}

void ledados(){
        printf("\n Digite o numero do Operario: ");
        scanf("%d",&idoperario);
        printf("\n ######### Operario %d ######### ",idoperario);
        printf("\n Informe: [H] para Homen ou [M] para Mulher: ");
        fflush(stdin);
        scanf("%c",&sexo);
        printf("\n Numero de pecas fabricadas por Mes: ");
        scanf("%d",&Npecas);
        pecastotal += Npecas; // soma numero de peças total
        if ((sexo == 'H') || (sexo == 'h')){
            auxH = auxH + Npecas;
            Htotal++;
        }
        if ((sexo == 'M') || (sexo == 'm')){
        	auxM = auxM + Npecas;
            Mtotal++;
        }
        calculasalario(Npecas); //Chama função e calcula salário
        
        printf("\n Deseja cadastrar outro Operario? ");
        fflush(stdin);
        scanf("%c",&escolha);
        n++; //incrementa numero de Operrios total
    
}

	int calculasalario(float s){
    
    if(s<=30){
        sal=minimo;
    }
    else if(s>30&&s<=35)
    {
        sal = minimo+((minimo*0.03)*(Npecas-30))    ;
    }
    else
    {
        sal = minimo+((minimo*0.05)*(Npecas-30));
    }
    
    if(sal>maiorsalario)
    maiorsalario=sal;
	idmaiorsal=idoperario;        
}
