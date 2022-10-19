#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNumero(int *destino,char *mensaje,int maximo,int minimo)
{
	int retorno = -1;
	int validacion;
	char auxNumero[51];
	int i;
	int numero;

	if(destino != NULL && mensaje != NULL && maximo >= minimo)
	{

		do
		{

			printf("%s",mensaje);
			fflush(stdin);
			scanf("%s",auxNumero);

			do
			{
				validacion = 0;

				for(i=0;i<strlen(auxNumero);i++)
				{
					if(!(auxNumero[i] >= 47 && auxNumero[i] <= 57))
					{
						printf("debe ingresar solo numeros\n");
						fflush(stdin);
						scanf("%s",auxNumero);
						validacion = -1;
					}
				}

			}while(validacion != 0);

			numero = atoi(auxNumero);

			if(!(numero >= minimo && numero <= maximo))
			{
				printf("el numero debe estar entre %d y %d\n",minimo, maximo);
				validacion = -1;
			}

		}while(validacion != 0);

		retorno = 0;
		*destino = numero;

	}

	return retorno;

}

int getString(char destino[],char *mensaje,int tam)
{
	char auxString[tam];
	int retorno = -1;
	int validacion;
	int i;

	if(destino != NULL && mensaje != NULL && tam > 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", auxString);

			do
			{
				validacion = 0;
				for(i=0;i<strlen(auxString);i++)
				{

					if(!((auxString[i] >= 65 && auxString[i] <= 90) || (auxString[i] >= 97 && auxString[i] <= 122)))
					{
						printf("Solo ingresa letras\n");
						fflush(stdin);
						scanf("%s", auxString);
						validacion = -1;
						break;
					}

				}
			}while(validacion != 0);

			if(strlen(auxString) > tam)
			{
				printf("maximo %d caracteres\n", tam);
				validacion = -1;
			}

		}while(validacion != 0);

		strcpy(destino,auxString);

		retorno = 0;
	}

	return retorno;
}


