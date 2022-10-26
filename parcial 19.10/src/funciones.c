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

			validacion = getNumero(&auxId,"\nIngrese el cliente\n1000.Juan\n1001.Alan\n1002.Pilar\n1003.Fernanda\n1004.Carlos\n",1004,1000);

			if(validacion == 0)
			{

				autos[libre].idCliente = auxId;
			}
			else
			{
				printf("\nError al ingresar cliente");
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

int listarAutos(eAuto autos[],int tamAutos,eMarca marcas[],int tamMarcas,eColor colores[],int tamColor,eCliente clientes[], int tamClientes)
{
	int retorno = -1;
	int i;
	int j;
	eAuto aux;
	char auxMarca[20];
	char auxColor[20];
	char auxCliente[20];

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
				printf("\n    ID          COLOR             MARCA              CAJA             CLIENTE");

		for(i=0;i<tamAutos;i++)
		{
			if(autos[i].isEmpty == 0)
			{
				buscarMarca(auxMarca,marcas,5,20,autos[i].idMarca);
				buscarColor(auxColor,colores,5,20,autos[i].idColor);
				buscarCliente(auxCliente,clientes,5,20,autos[i].idCliente);

				printf("\n---------------------------------------------------------------------");
				printf("\n  %4d     %10s          %10s           %c             %10s   ", autos[i].idAuto, auxColor, auxMarca, autos[i].caja,auxCliente);
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


int listarColor(eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamAutos,int tamColor,int tamMarcas,int tamClientes)
{
	int validacion;
	int auxId;
	int i;
	int retorno = -1;
	int id = 0;
	char auxMarca [20];
	char auxColor [20];
	int flag=1;




	if(autos != NULL && colores != NULL && tamAutos > 0 && tamColor > 0)
	{
		validacion = getNumero(&auxId,"\nIngrese el color\n5000.Negro\n5001.Blanco\n5002.Rojo\n5003.Verde\n5004.Azul",5004,5000);
		if(validacion == 0)
		{
			for(i=0;i<tamColor;i++)
			{
				if(auxId == colores[i].idColor)
				{
					id = auxId;
					break;

				}
			}
		}

		if(id != 0)
		{

			printf("\n    ID          COLOR             MARCA              CAJA");

			for(i=0;i< tamAutos;i++)
			{
				if(autos[i].isEmpty == 0 && autos[i].idColor == id)
				{
					buscarMarca(auxMarca,marcas,5,20,autos[i].idMarca);
					buscarColor(auxColor,colores,5,20,autos[i].idColor);

					printf("\n---------------------------------------------------------------------");
					printf("\n  %4d     %10s          %10s           %c", autos[i].idAuto, auxColor, auxMarca, autos[i].caja);

					retorno = 0;

					flag = 0;
				}
			}
			if(flag != 0){
			printf("\nNo hay autos cargados con ese color");

		}
	}



	}
	return retorno;
}

void buscarCliente(char destino[],eCliente clientes[],int tamClientes,int tamCadena,int id)
{
	int i;
	for(i = 0;i<tamClientes;i++)
	{
		if(id == clientes[i].idCliente)
		{
			strcpy(destino,clientes[i].nombre);
			break;
		}
	}

}

int listarAutoMarcas(eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamAutos,int tamColor,int tamMarcas,int tamClientes)
{
	int validacion;
	int auxId;
	int i;
	int retorno = -1;
	int id = 0;
	char auxMarca[20];
	char auxColor[20];
	char auxCliente[20];
	int flag=1;




	if(autos != NULL && colores != NULL && tamAutos > 0 && tamColor > 0)
	{
		validacion = getNumero(&auxId,"\nIngrese la marca\n1000.Reanult\n1001.Ford\n1002.Fiat\n1003Chevrolet\n1004.Peugeot\n",1004,1000);
		if(validacion == 0)
		{
			for(i=0;i<tamMarcas;i++)
			{
				if(auxId == marcas[i].idMarca)
				{
					id = auxId;
					break;

				}
			}
		}

		if(id != 0)
		{

			printf("\n    ID          COLOR             MARCA              CAJA");

			for(i=0;i< tamAutos;i++)
			{
				if(autos[i].isEmpty == 0 && autos[i].idMarca == id)
				{
					buscarMarca(auxMarca,marcas,5,20,autos[i].idMarca);
					buscarColor(auxColor,colores,5,20,autos[i].idColor);
					buscarCliente(auxCliente,clientes,5,20,autos[i].idCliente);

					printf("\n---------------------------------------------------------------------");
					printf("\n  %4d     %10s          %10s           %c             %10s   ", autos[i].idAuto, auxColor, auxMarca, autos[i].caja,auxCliente);
					flag = 0;
					retorno = 0;
				}
			}
			if(flag != 0)
			{
			printf("\nNo hay autos cargados con esa marca");

		}
	}



	}
	return retorno;
}

void informarManualAutomatico(eAuto autos[],int tamAutos)
{
	int i;
	int contManual=0;
	int contAuto=0;
	float porcentajeM;
	float porcentajeA;
	int total = 0;
	for(i=0;i<tamAutos;i++)
	{
		if(autos[i].caja == 'm' && autos[i].isEmpty == 0)
		{
			contManual = contManual + 1;
			total ++;
		}
		else if(autos[i].caja == 'a' && autos[i].isEmpty == 0)
		{
			contAuto = contAuto + 1;
			total ++;
		}
	}

	porcentajeM = contManual * 100 / total;
	porcentajeA = contAuto * 100 / total;

	printf("\nEl porcentaje de autos manuales es de: %f", porcentajeM);
	printf("\nEl porcentaje de autos automaticos es de: %f", porcentajeA);

}

void contarColorYMarca(eAuto autos[],int tamAutos)
{
	int i;
	int auxidMarca;
	int auxIdColor;
	int cont = 0;

	getNumero(&auxidMarca,"\nIngrese la marca\n1000.Reanult\n1001.Ford\n1002.Fiat\n1003Chevrolet\n1004.Peugeot\n",1004,1000);
	getNumero(&auxIdColor,"\nIngrese el color\n5000.Negro\n5001.Blanco\n5002.Rojo\n5003.Verde\n5004.Azul",5004,5000);

	for(i=0;i<tamAutos;i++)
	{
		if(autos[i].idMarca == auxidMarca && autos[i].idColor == auxIdColor)
		{
			cont = cont +1;
		}
	}

	if(cont == 0)
	{
		printf("\nNo hay ningun auto con esas caracteristicas");
	}

}

void mostraMarcaMasElegida(eAuto autos[],int tamAutos,eMarca marcas[])
{
		int i;
		int cont[5];
		int masGrande;
		int posMasGrande;
		int flag = 1;

		for(i=0;i<5;i++)
		{
			cont[i]= 0;
		}
		for(i=0;i<tamAutos;i++)
		{
			if(autos[i].idMarca == 1000)
			{
				cont[0]++;
			}
			else if(autos[i].idMarca == 1001)
			{
				cont[1]++;
			}
			else if(autos[i].idMarca == 1002)
			{
				cont[2]++;
			}
			else if(autos[i].idMarca == 1003)
			{
				cont[3]++;
			}
			else if(autos[i].idMarca == 1004)
			{
				cont[4]++;
			}
		}

		for(i=0;i<5;i++)
		{
			if(flag == 1 || cont[i] > masGrande)
			{
				masGrande = cont[i];
				posMasGrande = i;
			}
		}

		printf("\nLa marca que tiene mas autos es %10s", marcas[posMasGrande].descripcion);



}

void mostrarTrabajosDeAuto(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios)
{
	int idAuto;
	int i;
	char auxServicio[20];
	int flag = 0;

	printf("\nIngrese el id del auto que quiere mostrar");
	scanf("%d",&idAuto);

	for(i=0;i<tamTrabajos;i++)
	{
		if(trabajos[i].idAuto == idAuto)
		{

			flag = 1;
			buscarServicio(auxServicio,servicios,4,25,trabajos[i].idServicio);

			printf("\n%4d       %4d            %10s             %2d/%2d/%4d",trabajos[i].idTrabajo,trabajos[i].idAuto,auxServicio,trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
		}
	}

	if(flag==0)
	{
		printf("\nEse auto no tiene ningun trabajo");
	}

}

void sumaImportesDeAuto(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamServicios)
{

	int idAuto;
	int i;
	float auxPreciServicio;
	int flag = 0;
	float acum = 0;

		printf("\nIngrese el id del auto que quiere mostrar lo gastado");
		scanf("%d",&idAuto);

		for(i=0;i<tamTrabajos;i++)
		{
			if(trabajos[i].idAuto == idAuto)
			{
				flag=1;
				buscarPrecioServicio(&auxPreciServicio,servicios,4,trabajos[i].idServicio);
				acum = acum + auxPreciServicio;

			}
		}
		if(flag ==1 )
		{
			printf("\nSe gasto un total de $%f en ese auto",auxPreciServicio);
		}
		else
		{
			printf("\nEse auto no tiene ningun trabajo");
		}
}

void buscarPrecioServicio(float *destino,eServicio servicios[],int tamServicios,int id)
{
	int i;
	for(i=0;i<tamServicios;i++)
	{
		if(servicios[i].idServicio == id)
		{
			*destino = servicios[i].precio;
		}
	}
}

void mostrarAutosSegunServicio(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamServicios,eAuto autos[],int tamAutos,eColor colores[],int tamColores,eMarca marcas[],int tamMarcas,eCliente clientes[],int tamClientes)
{
	int i;
	int j;
	int idServicio;
	int flag = 1;
	char auxMarca[20];
	char auxColor[20];
	char auxCliente[20];


	getNumero(&idServicio,"\nIngrese el id del servicio\n20000.Lavado\n20001. Pulido\n20002.Encerado\n20003Completo",20003,20000);

	for(i=0;i<tamTrabajos;i++)
	{
		if(idServicio == trabajos[i].idServicio)
		{
			for(j=0;j<tamAutos;j++)
			{
				if(trabajos[i].idAuto == autos[j].idAuto)
				{
					flag = 0;
					printf("\n    ID          COLOR             MARCA              CAJA             CLIENTE            FECHA");
					printf("\n-----------------------------------------------------------------------------------------------------------------------");
					buscarMarca(auxMarca,marcas,tamMarcas,20,autos[j].idMarca);
					buscarColor(auxColor,colores,tamColores,20,autos[j].idColor);
					buscarCliente(auxCliente,clientes,tamClientes,20,autos[j].idCliente);


					printf("\n  %4d     %10s          %10s           %c             %10s             %d/%d/%d", autos[j].idAuto, auxColor, auxMarca, autos[j].caja,auxCliente,trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);

				}
			}

		}

		if(flag!= 0)
		{
			printf("\nEste servicio no se le realizo a ningun auto");
		}
	}
}

void mostrarServiciosRealizadosSegunFecha(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamServicios)
{
	int auxDia;
	int auxMes;
	int i;
	char auxServicio[20];

	getNumero(&auxDia,"\nIngrese el dia",30,1);
	getNumero(&auxMes,"\nIngrese el mes",12,1);

	for(i=0;i<tamTrabajos;i++)
	{
		if(auxDia == trabajos[i].fecha.dia && auxMes == trabajos[i].fecha.mes)
		{
			printf("\nID        ID auto        Servicio          ");
			printf("\n----------------------------------------------");

			buscarServicio(auxServicio,servicios,4,25,trabajos[i].idServicio);

			printf("\n%4d       %4d            %10s          ",trabajos[i].idTrabajo,trabajos[i].idAuto,auxServicio);



		}
	}
}

void informarSegunCaja(eAuto autos[],int tamAutos,eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
	int i;
	char auxMarca[20];
	char auxColor[20];
	char auxCliente[20];
	int flagAuto = 1;
	int flagManual =1;

	for(i=0;i<tamAutos;i++)
	{
		if(autos[i].isEmpty == 0 && autos[i].caja == 'm')
		{
			flagAuto = 0;
			buscarMarca(auxMarca,marcas,tamMarcas,20,autos[i].idMarca);
			buscarColor(auxColor,colores,tamColores,20,autos[i].idColor);
			buscarCliente(auxCliente,clientes,tamClientes,20,autos[i].idCliente);

			printf("\n---------------------------------------------------------------------");
			printf("\n  %4d     %10s          %10s           %c             %10s   ", autos[i].idAuto, auxColor, auxMarca, autos[i].caja,auxCliente);
		}

	}

	for(i=0;i<tamAutos;i++)
	{
		if(autos[i].isEmpty == 0 && autos[i].caja == 'a')
		{
			flagManual = 0;
			buscarMarca(auxMarca,marcas,tamMarcas,20,autos[i].idMarca);
			buscarColor(auxColor,colores,tamColores,20,autos[i].idColor);
			buscarCliente(auxCliente,clientes,tamClientes,20,autos[i].idCliente);

			printf("\n---------------------------------------------------------------------");
			printf("\n  %4d     %10s          %10s           %c             %10s   ", autos[i].idAuto, auxColor, auxMarca, autos[i].caja,auxCliente);
		}

	}

	if(flagAuto != 0)
	{
		printf("\nNo hay automaticos ingresado");
	}
	if(flagManual != 0)
	{
		printf("\nNo hay manuales ingresados");
	}


}

