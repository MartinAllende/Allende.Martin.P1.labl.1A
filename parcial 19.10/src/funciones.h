#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "estructuras.h"

/**
 * funcion para otorgar el valor de 1 a la variable isEmpty en cada posicion del array
 * @param autos array en el cual se va a aplicar
 * @param tamAutos tamanio del array
 */
void inicializarAuto(eAuto autos[],int tamAutos);
/**
 * funcion para otorgar el valor de 1 a la variable isEmpty en cada posicion del array
 * @param trabajosarray en el cual se va a aplicar
 * @param tamTrabajos tamanio del array
 */
void inicializarTrabajos(eTrabajo trabajos[],int tamTrabajos);
/**
 * funcion para buscar un isEmpty igual a 1
 * @param autos array en el cual se va a buscar
 * @param tamAutos tamanio del array
 * @return devuelve la primera posicion en la cual is empty es igual a 1 o -1 si no hay ninguna
 */
int searchFree(eAuto autos[],int tamAutos);
/**
 * funcion para poder aplicar datos a una estructura de autos
 * @param autos array que vamos a llenar
 * @param tamAutos tamanio del array
 * @param nextLegajoAuto variable con la cual daremos el valor del id para asi no perder el id anterior
 * @return 0 en caso de que se haya podido ingresar correctamente y -1 en caso de que haya habido un error
 */
int altaAuto(eAuto autos[],int tamAutos,int *nextLegajoAuto);
/**
 * funcion para modificar el id del color o la marca de un auto ya ingresado
 * @param autos array en el cual se encuentras los datos de los autos cargados
 * @param tamAutos tamanio del array
 * @return 0 en caso de que se haya modificado correctamente o -1 en el caso de que no
 */
int modificarAuto(eAuto autos[],int tamAutos);
/**
 * funcion para realizar una baja logica de un auto
 * @param autos array en el cual se encuentras los datos de los autos cargados
 * @param tamAutos tamanio del array
 * @return 0 en caso de que se haya dado de baja correctamente o -1 en caso de que no
 */
int bajaAuto(eAuto autos[],int tamAutos);
/**
 * funcion que ordena segun 2 criterios el array de autos y luego lo muestra en una lista
 * @param autos array en el cual se encuentras los datos de los autos cargados
 * @param tamAutos tamanio del array de autos
 * @param marcas array en el cual se encuentras los datos de las marcas cargados
 * @param tamMarcas tamanio del array de marcas
 * @param colores array en el cual se encuentras los datos de los colores cargados
 * @param tamColor tamanio del array de colores
 * @return 0 en caso de que se haya podido listar correctamente -1 en caso de que haya habido un error
 */
int listarAutos(eAuto autos[],int tamAutos,eMarca marcas[],int tamMarcas,eColor colores[],int tamColor);
/**
 * funcion para listar las marcas
 * @param marcas array en el cual se encuentras los datos de las marcas cargados
 * @param tamMarcas tamanio del array de marcas
 */
void listarMarcas(eMarca marcas[],int tamMarcas);
/**
 * funcion para listar los colores
 * @param colores array en el cual se encuentras los datos de los colores cargados
 * @param tamColor tamanio del array de colores
 */
void listarColores(eColor colores[], int tamColor);
/**
 * funcion para listar los servicios
 * @param servicios array en el cual se encuentras los datos de los servicios cargados
 * @param tamServicio tamanio del array de servicios
 */
void listarServicios(eServicio servicios[],int tamServicio);
/**
 * funcion que mediante un id sobreescribe la varible destino con una cadena de caracteres correspondiente e ese id
 * @param destino puntero a la variable que se va a guardar la cadena
 * @param marcas array en el cual se encuentras los datos de las marcas cargados
 * @param tamMarcas tamanio del array de marcas
 * @param tamDestino tamanio de la varible para guardar la cadena
 * @param id de la cadena que se va a buscar
 */
void buscarMarca(char destino[],eMarca marcas[],int tamMarcas,int tamDestino,int id);
/**
 * funcion que mediante un id sobreescribe la varible destino con una cadena de caracteres correspondiente e ese id
 * @param destino puntero a la variable que se va a guardar la cadena
 * @param color array en el cual se encuentras los datos de los colores cargados
 * @param tamColor tamanio del array de colores
 * @param tamDestino tamanio de la varible para guardar la cadena
 * @param id de la cadena que se va a buscar
 */
void buscarColor(char destino[],eColor color[],int tamColor, int tamDestino,int id);
/**
 * funcio que realizar el alta de una estructura trabajo
 * @param trabajos array de los trabajos
 * @param fechas array de las fechas
 * @param autos array de los autos
 * @param TAM tamanio del array de trabajos
 * @param nextLegajoTrabajo variable con la cual daremos el valor del id para asi no perder el id anterior
 * @return 0 en caso de que se haya podido dar de alta correctamente -1 en caso de que no
 */
int altaTrabajo(eTrabajo trabajos[],eFecha fechas[],eAuto autos[],int TAM,int* nextLegajoTrabajo);
/**
 * funcion para listar los trabajos ya ingresados
 * @param trabajos array que guardar los datos de los trabajos ingresados
 * @param servicios array que guarda los datos de los servicios
 * @param fechas array que guarda las fechas
 * @param tamTrabajos tamanio del array de trabajos
 * @param tamServicios tamanio del array de servicios
 * @param tamFechas tamanio del array de fechas
 */
void listarTrabajos(eTrabajo trabajos[],eServicio servicios[],eFecha fechas[],int tamTrabajos,int tamServicios,int tamFechas);
/**
 * funcion que mediante un id sobreescribe la varible destino con una cadena de caracteres correspondiente e ese id
 * @param destino destino puntero a la variable que se va a guardar la cadena
 * @param servicios array donde se encuentran los datos de los servicios
 * @param tamServicios tamanio del array de servivios
 * @param tamDestino tamanio del array de destino
 * @param id id de la cadena que se va a buscar
 */
void buscarServicio(char destino[],eServicio servicios[],int tamServicios, int tamDestino,int id);


#endif /* FUNCIONES_H_ */
