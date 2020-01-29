#include <stdio.h>

int Inscricao;
float Tpadrao,pontos;
float t[3];
float P[3];

void letempo();
float calcula();

/*float calcule (float t){
	float Delta, Result;

}*/
	void letempo(){
		int i;
		float Delta, Result;
		for(i=1;i<=3;i++){
			printf("\n %d^ tempo(em minutos) da Equipe %d: ",i,Inscricao);
			scanf("%f",&t[i]);
				Delta = (Tpadrao-t[i]);
			if(Delta<3){
				P[i] = 100;
				}
			if((Delta >= 3) && (Delta <= 5)){
				P[i] = 80;
				}
			else{
			P[i] = 80-(Delta-5)/5;
			}
		}
	}
	void mostradados(){
		system ("cls");
		printf ("\n Equipe: %d",Inscricao);
		printf ("\n Pontos da 1^ Etapa %.2f \n Pontos da 2^ Etapa %.2f \n Pontos da 3^ Etapa %.2f",P[1],P[2],P[3]);
		printf ("\n Total de Pontos Obtidos: %.2f",P[1]+P[2]+P[3]);
	}
	main(){	
		while(Inscricao != 9999){
		printf("\n Informe o Numero da Inscricao ou 9999 para Sair: ");
		scanf("%d",&Inscricao);
		printf("\n Informe o tempo minimo de prova(em minutos) de prova: ");
		scanf("%d",&Tpadrao);
		letempo();
		mostradados();
	}
}
