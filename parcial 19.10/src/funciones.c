#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"
#include "estructuras.h"



void inicializarAuto(eAuto autos[],int tamAutos)
{
	int i;
	for(i=0;i<tamAutos;i++)
	{
		autos[i].isEmpty = 1;
	}

}

void inicializarTrabajos(eTrabajo trabajos[],int tamTrabajos)
{
	int i;
	for(i=0;i<tamTrabajos;i++)
	{
		trabajos[i].isEmpty = 1;
	}

}

int searchFree(eAuto autos[],int tamAutos)
{
	int i;
	int retorno = -1;

	if(autos != NULL && tamAutos > 0)
	{
		for(i=0;i<tamAutos;i++)
		{
			if(autos[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int altaAuto(eAuto autos[],int tamAutos,int *nextLegajoAuto)
{
	int libre;
	int retorno = -1;
	int auxId;
	char auxCaja;
	int validacion;

	if(autos != NULL && tamAutos > 0 && nextLegajoAuto != NULL)
	{
		libre = searchFree(autos,tamAutos);

		if(libre != -1)
		{
			autos[libre].idAuto = *nextLegajoAuto;

			do
			{
				printf("\nIngrese el tipo de caja, m manual o a automatica");
				fflush(stdin);
				scanf("%c",&auxCaja);

			}while(auxCaja != 'm' && auxCaja != 'a');

			autos[libre].caja = auxCaja;

			validacion = getNumero(&auxId,"\nIngrese la marca\n1000.Reanult\n1001.Ford\n1002.Fiat\n1003Chevrolet\n1004.Peugeot\n",1004,1000);

			if(validacion == 0)
			{

				autos[libre].idMarca = auxId;
			}
			else
			{
				printf("\nError al ingresar marca");
			}

			validacion = getNumero(&auxId,"\nIngrese el color\n5000.Negro\n5001.Blanco\n5002.Rojo\n5003.Verde\n5004.Azul",5004,5000);

			if(validacion == 0)
			{
				autos[libre].idColor = auxId;
			}

			}
			else
			{
				printf("\nError al ingresar el color");
			}

			autos[libre].isEmpty = 0;

			*nextLegajoAuto = *nextLegajoAuto + 1;

	}

	return retorno;
}

int modificarAuto(eAuto autos[],int tamAutos)
{
	int auxId;
	int idModificar;
	int retorno = -1;
	int i;
	int decicion;
	int flag = 1;
	int validacion;

	if(autos != NULL && tamAutos > 0)
	{

		printf("\nIngrese el id que quiere modificar");
		scanf("%d",&idModificar);

		for(i=0;i<tamAutos;i++)
		{
			if(autos[i].idAuto == idModificar)
			{
				getNumero(&decicion,"\nQue desea modificar\n1. Color\n2. Marca",2,1);
				switch(decicion)
				{
					case 1:
						validacion = getNumero(&auxId,"\nIngrese el color\n5000.Negro\n5001.Blanco\n5002.Rojo\n5003.Verde\n5004.Azul",5004,5000);
						if(validacion == 0)
						{
							autos[i].idColor = auxId;
						}
						else
						{
							printf("\nError al ingresa color");
						}
						break;
					case 2:
						validacion = getNumero(&auxId,"\nIngrese la marca\n1000.Reanult\n1001.Ford\n1002.Fiat\n1003Chevrolet\n1004.Peugeot\n",1004,1000);
						if(validacion == 0)
						{
							autos[i].idMarca = auxId;
						}
						else
						{
							printf("\nError al ingresar marca");
						}
						break;
				}

				flag=0;
				break;
			}
		}

		retorno = 0;

		if(flag == 1)
		{
			printf("\nId de auto inexistente");
		}
	}
	return retorno;
}


int bajaAuto(eAuto autos[], int tamAutos)
{
	int retorno = -1;
	int idModificar;
	int i;
	int flag = 1;

	if(autos != NULL && tamAutos > 0)
	{

		printf("\nIngrese el id que quiere modificar");
		scanf("%d",&idModificar);

		for(i=0;i<tamAutos;i++)
		{
			if(autos[i].idAuto == idModificar)
			{
				autos[i].isEmpty = 1;
				flag = 0;
				break;
			}
		}
		if(flag == 1)
		{
			printf("\nId inexistente");
		}

		retorno = 0;
	}

	return retorno;
}

int listarAutos(eAuto autos[],int tamAutos,eMarca marcas[],int tamMarcas,eColor colores[],int tamColor)
{
	int retorno = -1;
	int i;
	int j;
	eAuto aux;
	char auxMarca[20];
	char auxColor[20];

	if(autos != NULL && tamAutos > 0)
	{
		for(i=0;i<tamAutos;i++)
		{
			for(j=0;j<tamAutos;j++)
			{
				if(autos[j].idMarca>autos[j+1].idMarca && autos[j].isEmpty == 0 && autos[j+1].isEmpty == 0)
				{
					aux = autos[j];
					autos[j] = autos[j+1];
					autos[j+1] = aux;
				}
				else if(autos[j].idMarca == autos[j+1].idMarca && autos[j].caja > autos[j+1].caja && autos[j].isEmpty == 0 && autos[j+1].isEmpty == 0)
				{
					aux = autos[j];
					autos[j] = autos[j+1];
					autos[j+1] = aux;
				}
			}
		}
				printf("\n    ID          COLOR             MARCA              CAJA");

		for(i=0;i<tamAutos;i++)
		{
			if(autos[i].isEmpty == 0)
			{
				buscarMarca(auxMarca,marcas,5,20,autos[i].idMarca);
				buscarColor(auxColor,colores,5,20,autos[i].idColor);

				printf("\n---------------------------------------------------------------------");
				printf("\n  %4d     %10s          %10s           %c", autos[i].idAuto, auxColor, auxMarca, autos[i].caja);
			}

		}
		retorno = 0;
	}

	return retorno;
}

void listarMarcas(eMarca marcas[],int tamMarcas)
{
	int i;

		printf("\n  ID           descripcion");
	for(i=0;i<tamMarcas;i++)
	{
		printf("\n------------------------------------------------");
		printf("\n  %4d          %10s   ",marcas[i].idMarca, marcas[i].descripcion);
	}
}

void listarColores(eColor colores[], int tamColor)
{
	int i;

		printf("\n  ID           descripcion");
	for(i=0;i<tamColor;i++)
	{
		printf("\n------------------------------------------------");
		printf("\n  %4d          %10s   ",colores[i].idColor,colores[i].nombreColor);
	}
}

void listarServicios(eServicio servicios[],int tamServicio)
{
	int i;

		printf("\n  ID           Descripcion    Precio");
	for(i=0;i<tamServicio;i++)
	{
		printf("\n------------------------------------------------");
		printf("\n  %4d          %10s           $%5f",servicios[i].idServicio,servicios[i].descripcion, servicios[i].precio);
	}
}

void buscarMarca(char destino[],eMarca marcas[],int tamMarcas,int tamDestino,int id)
{
	int i;
	for(i = 0;i<tamMarcas;i++)
	{
		if(id == marcas[i].idMarca)
		{
			strcpy(destino,marcas[i].descripcion);
			break;
		}

	}
}

void buscarColor(char destino[],eColor color[],int tamColor, int tamDestino,int id)
{
	int i;
	for(i = 0;i<tamColor;i++)
	{
		if(id == color[i].idColor)
		{
			strcpy(destino,color[i].nombreColor);
			break;
		}
	}
}

int altaTrabajo(eTrabajo trabajos[],eFecha fechas[],eAuto autos[],int TAM,int* nextLegajoTrabajo)
{
	int retorno = -1;
	int i;
	int auxId;
	int libre;


	if(trabajos != NULL && fechas != NULL && autos != NULL && TAM > 0 && nextLegajoTrabajo != NULL)
	{
		for(i=0;i<TAM;i++)
		{
			if(trabajos[i].isEmpty == 1)
			{
				libre = i;
				getNumero(&auxId,"\nIngrese el id de su auto",2000,1000);

				for(i=0;i<TAM;i++)
				{
					if(auxId == autos[i].idAuto)
					{
						trabajos[libre].idTrabajo = *nextLegajoTrabajo;
						trabajos[libre].idAuto = auxId;

						getNumero(&auxId,"\nIngrese el id del servicio\n20000.Lavado\n20001. Pulido\n20002.Encerado\n20003Completo",20003,20000);
						trabajos[libre].idServicio = auxId;

						trabajos[libre].fecha.dia = rand () % (30-1+1) + 1;
						trabajos[libre].fecha.mes = rand () % (12-1+1) + 1;
						trabajos[libre].fecha.anio = 2022;
						trabajos[libre].isEmpty=0;

						*nextLegajoTrabajo = *nextLegajoTrabajo +1;
						retorno = 0;

						printf("\nSu trabajo tiene fecha para el: %d/%d/%d",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);

						break;
					}

				}

				break;
			}
		}
	}
	return retorno;
}

void listarTrabajos(eTrabajo trabajos[],eServicio servicios[],eFecha fechas[],int tamTrabajos,int tamServicios,int tamFechas)
{
		int i;
		char auxServicio[25];

		printf("\nID        ID auto        Servicio           Fecha");
		printf("\n--------------------------------------------------------");

		for(i=0;i<tamTrabajos;i++)
		{
			if(trabajos[i].isEmpty==0)
			{

				buscarServicio(auxServicio,servicios,4,25,trabajos[i].idServicio);

				printf("\n%4d       %4d            %10s             %2d/%2d/%4d",trabajos[i].idTrabajo,trabajos[i].idAuto,auxServicio,trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);

			}
		}
}

void buscarServicio(char destino[],eServicio servicios[],int tamServicios, int tamDestino,int id)
{
	int i;
	for(i = 0;i<tamServicios;i++)
	{
		if(id == servicios[i].idServicio)
		{
			strcpy(destino,servicios[i].descripcion);
			break;
		}
	}
}


