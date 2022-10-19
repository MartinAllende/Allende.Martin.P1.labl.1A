#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"
#include "estructuras.h"

int main(void) {

	setbuf(stdout,NULL);

	int eleccion;
	int flag = 0;
	int nextLegajoAuto = 1000;
	eAuto autos[1000];
	eMarca marcas[5] =
	{
			{1000,"Reanult"},
			{1001,"Ford"},
			{1002,"Fiat"},
			{1003,"Chevrolet"},
			{1004,"Peugeot"}
	};
	eColor colores[5] =
	{
			{5000,"Negro"},
			{5001,"Blanco"},
			{5002,"Rojo"},
			{5003,"Verde"},
			{5004,"Azul"}
	};
	eServicio servicios[4]=
	{
			{20000,"Lavado",450},
			{20001,"Pulido",500},
			{20002,"Encerado",600},
			{20003,"Completo",900}
	};

	inicializarAuto(autos,1000);

	do
	{
		getNumero(&eleccion,"\n1.Alta auto\n2.Modificar auto\n3.Baja auto\n4.Listar autos\n5.Listar marcas\n6.Listar colores\n7.Listar servicion\n8.Alta trabajo\n9.Listar trabajo\n10.Salir",10,1);

		switch(eleccion)
		{
			case 1:
				altaAuto(autos,1000,&nextLegajoAuto);
				flag = flag + 1;
				break;
			case 2:
				if(flag > 0)
				{
					modificarAuto(autos,1000);
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 3:
				if(flag > 0)
				{
					bajaAuto(autos,1000);
					flag = flag - 1;
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 4:
				if(flag > 0)
				{
					listarAutos(autos,1000,marcas,5,colores,5);
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 5:
				listarMarcas(marcas,5);
				break;
			case 6:
				listarColores(colores,5);
				break;
			case 7:
				listarServicios(servicios,4);
				break;
			case 8: printf("Alta trabajo");
				break;
			case 9: printf("Listar trabajo");
				break;
		}

	}while(eleccion != 10);




	return EXIT_SUCCESS;
}