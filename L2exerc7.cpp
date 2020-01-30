#include<iostream>
//Ler Matriz de forma recursiva
int l,c, soma;
int mat[4][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }

void lermat(int i, int j, int soma);

void lermat(int i, int j, int soma)
{
	if(i<4)
	{
		if(j<4)
		{
			if((i==j))
			soma=soma+mat[i][j];
		}
	lermat(i,j+1,soma);
	}
	else 
	{
		lermat(i+1,0,soma);
	}
}
int main(){
	lermat(mat);
	printf("\n soma = %d",soma);
}
