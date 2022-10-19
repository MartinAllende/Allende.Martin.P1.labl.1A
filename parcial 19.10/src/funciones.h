#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "estructuras.h"



void inicializarAuto(eAuto autos[],int tamAutos);
int searchFree(eAuto autos[],int tamAutos);
int altaAuto(eAuto autos[],int tamAutos,int *nextLegajoAuto);
int modificarAuto(eAuto autos[],int tamAutos);
int bajaAuto(eAuto autos[],int tamAutos);
int listarAutos(eAuto autos[],int tamAutos,eMarca marcas[],int tamMarcas,eColor colores[],int tamColor);
void listarMarcas(eMarca marcas[],int tamMarcas);
void listarColores(eColor colores[], int tamColor);
void listarServicios(eServicio servicios[],int tamServicio);
void buscarMarca(char destino[],eMarca marcas[],int tamMarcas,int tamDestino,int id);
void buscarColor(char destino[],eColor color[],int tamColor, int tamDestino,int id);
int altaTrabajo(eTrabajo trabajos[],eFecha fechas[],eAuto autos[],int TAM,int* nextLegajoTrabajo);


#endif /* FUNCIONES_H_ */
