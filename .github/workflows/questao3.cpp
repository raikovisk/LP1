#include <stdio.h>
#include <iostream>
void ledados();
void mostradados();
int opc;
int totalH, totalM,maioridade,idadecomxp,menoridade;
float mediaHH, mediaMM;

struct ficha_candidato{ //criando struct ficha do candidato
		int inscricao,idade;
		char sexo,experiencia;
	};

main(){
	ledados();
	mostradados();



	
}
void ledados(){
		struct ficha_candidato candidato; // variavel candidato com struct ficha de candidao
	do{
	printf("\n---------- Cadastro do Candidato -----------\n\n\n");
	
	printf("Numero de inscricao : ");
	scanf("%d",&candidato.inscricao);
	
	printf("Idade ......: ");
	scanf("%d",&candidato.idade);
	
	printf("Sexo: [H] ou [M] : ");
	fflush(stdin);	
	scanf("%c",&candidato.sexo);
	
	printf("Possui Experiencia: [S] ou [N] : ");
	fflush(stdin);	
	scanf("%c",&candidato.experiencia);
	
	if ((&candidato.sexo == "H")||(&candidato.sexo == "h")){
		totalH++;
		if (candidato.idade>45){
			maioridade++;
			mediaHH = maioridade/totalH;
		}
	}
	/*else if ((&candidato.sexo == "M")||(&candidato.sexo == "m")){
		totalM++;
		if ((candidato.idade<35)&&((&candidato.experiencia == 's')||(&candidato.experiencia == 'S'))){
			idadecomxp++;
			if(&candidato.idade<menoridade)
			menoridade = candidato.idade;
		}
	}*/
	printf("\n Digite 0 para sair, ou qualquer tecla para continuar. ");
	fflush(stdin);
	scanf("%d",&opc);
	}while(opc =! 0);
}
void mostradados(){
	system("cls");
	printf("\n Candidatos Sexo Feminino: %d \t Candidatos Sexo Masculino: %d",totalM,totalH);
	printf("\n Idade media dos Homens com mais de 45: %d",mediaHH);
	printf("\n Mulheres com idade inferior a 35 anos com experiencia: %d",idadecomxp);
	printf("\n Menor idade mulheres que ja tem experiencia: %d",menoridade);	
}
