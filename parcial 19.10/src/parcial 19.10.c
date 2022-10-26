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
	int flagTrabajos = 0;
	int nextLegajoAuto = 1000;
	int nextLegajoTrabajo = 1000;
	int validacion;
	eAuto autos[1000];
	eTrabajo trabajos[1000];
	eFecha fechas[1000];
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
	eCliente clientes[5]=
	{
			{1000,"juan",'m'},
			{1001,"alan",'m'},
			{1002,"pilar",'f'},
			{1003,"fernanda",'f'},
			{1004,"carlos",'m'}
	};

	inicializarAuto(autos,1000);
	inicializarTrabajos(trabajos,1000);

	do
	{
		getNumero(&eleccion,"\n1.Alta auto"
				"\n2.Modificar auto"
				"\n3.Baja auto"
				"\n4.Listar autos"
				"\n5.Listar marcas"
				"\n6.Listar colores"
				"\n7.Listar servicion"
				"\n8.Alta trabajo"
				"\n9.Listar trabajo"
				"\n10.Mostrar autos del color seleccionado por el usuario"
				"\n11.Mostrar autos de una marca seleccionada"
				"\n12.Informar Promedio de autos con caja manual y promedio de autos con caja automática"
				"\n13.Mostrar un listado de los autos separados por tipo de caja"
				"\n14.Elegir un color y una marca y contar cuantos autos hay de ese color y esa marca"
				"\n15.Mostrar la o las marcas más elegidas por los clientes"
				"\n16.Pedir un auto y mostrar todos los trabajos que se le hicieron al mismo"
				"\n17.Pedir un auto e informar la suma de los importes que se le hicieron al mismo."
				"\n18.Pedir un servicio y mostrar los autos a los que se realizo ese servicio y la fecha"
				"\n19.Pedir una fecha y mostrar todos los servicios realizados en la misma"
				"\n20.Salir",19,1);

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
					validacion = bajaAuto(autos,1000);
					if(validacion == 0)
					{
						flag = flag - 1;
					}
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 4:
				if(flag > 0)
				{
					listarAutos(autos,1000,marcas,5,colores,5,clientes,5);
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
			case 8:
				if(flag > 0)
				{
					altaTrabajo(trabajos,fechas,autos,1000,&nextLegajoTrabajo);
					flagTrabajos = 1;
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 9:
				if(flagTrabajos > 0)
				{
					listarTrabajos(trabajos,servicios,fechas,1000,4,1000);
				}
				else
				{
					printf("primero debe ingresar un trabajo");
				}
				break;
			case 10:
				if(flag > 0)
				{
					listarColor(autos,colores,marcas,clientes,1000,5,5,5);
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 11:
				if(flag > 0)
				{
					listarAutoMarcas(autos,colores,marcas,clientes,1000,5,5,5);
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 12:
				if(flag > 0)
				{
					informarManualAutomatico(autos,1000);
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 13:
				if(flag > 0)
				{
					informarSegunCaja(autos,1000,marcas,5,colores,5,clientes,5);
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 14:
				if(flag > 0)
				{
					contarColorYMarca(autos,1000);
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 15:
				if(flag > 0)
				{
					mostraMarcaMasElegida(autos,1000,marcas);
				}
				else
				{
					printf("primero debe ingresar un auto");
				}
				break;
			case 16:
				if(flagTrabajos > 0)
				{
					mostrarTrabajosDeAuto(trabajos,1000,servicios,4);
				}
				else
				{
					printf("primero debe ingresar un trabajo");
				}
				break;
			case 17:
				if(flagTrabajos > 0)
				{
					sumaImportesDeAuto(trabajos,1000,servicios,4);
				}
				else
				{
					printf("primero debe ingresar un trabajo");
				}
				break;
			case 18:
				if(flagTrabajos > 0)
				{
					mostrarAutosSegunServicio(trabajos,1000,servicios,4,autos,1000,colores,5,marcas,5,clientes,5);
				}
				else
				{
					printf("primero debe ingresar un trabajo");
				}
				break;
			case 19:
				if(flagTrabajos > 0)
				{
					mostrarServiciosRealizadosSegunFecha(trabajos,1000,servicios,4);
				}
				else
				{
					printf("primero debe ingresar un trabajo");
				}
				break;
		}

	}while(eleccion != 20);




	return EXIT_SUCCESS;
}
