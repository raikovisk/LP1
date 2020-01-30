#include <iostream>

	main() {
	int t[4]; //Tempos de prova
	int P[4]; // Etapas
	int ins = 0, vencedor, nvencedor, i, Tpadrao, pontos = 0;
	float Delta;
	printf ("\n\t  ------| Classificacao Toneio de Rally |------ \t\n");
	printf("\n Informe o tempo padrao da prova(em minutos): ");
	scanf("%d",&Tpadrao);
	while (ins!=9999)
	{
		printf("\n Numero de inscricao da equipe: ");
		scanf("%d",&ins);
		if (ins != 9999)
		{
		system("cls");	
		for(i=1;i<=3;i++){
			vencedor = 0;
			printf("\n %do tempo(em minutos) da Equipe %d: ",i,ins);
			scanf("%d",&t[i]);
			Delta = (t[i]-Tpadrao);
			if(Delta < 3){
				P[i] = 100;
				}
			else if((Delta >= 3) && (Delta <= 5)){
				P[i] = 80;
				}
			else if (Delta > 5){
			P[i] = 80-(Delta-5)/5;
			}
			pontos = pontos+P[i];
		}
		if (vencedor < pontos){
			vencedor = pontos;
			nvencedor = ins;
			}
	}
	printf ("\n ----------------- \n");		
	printf ("\n Equipe: %d",ins);
	printf ("\n Pontos da 1a Etapa %d \n Pontos da 2a Etapa %d \n Pontos da 3a Etapa %d",P[1],P[2],P[3]);
	printf ("\n Total de Pontos Obtidos: %d \n",pontos);
	printf ("\n Obs: inscricao 9999 para Sair");
	printf ("\n ----------------- \n");
	}
	printf("\n A equipe vencedora foi %d com %d pontos \n", nvencedor, vencedor);	
}
