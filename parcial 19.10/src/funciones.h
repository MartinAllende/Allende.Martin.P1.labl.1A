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
int listarAutos(eAuto autos[],int tamAutos,eMarca marcas[],int tamMarcas,eColor colores[],int tamColor,eCliente clientes[], int tamClientes);
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
/**
 * funcion con la cual se obtiene un id de un color y se lista los autos con ese color
 * @param autos array donde estan los datos de los autos ingresados
 * @param colores array donde estan los datos de los colores
 * @param marcas array donde estan los datos de las marcas
 * @param clientes array donde estan los datos de los clientes
 * @param tamAutos tamanio del array de autos
 * @param tamColor tamanio del array de colores
 * @param tamMarcas tamanio del array de marcas
 * @param tamClientes tamanio del array de clientes
 * @return 0 en caso de que se haya podido listar correctamente -1 en caso contrario
 */
int listarColor(eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamAutos,int tamColor,int tamMarcas,int tamClientes);
/**
 * funcion para devolver el nombre del cliente al ingresar su id
 * @param destino puntero donde se va a guardar el nombre
 * @param clientes array donde estan los datos de los clientes
 * @param tamClientes tamanio del array de clientes
 * @param tamCadena tamanio maximo de la cadena
 * @param id del nombre que se va a buscar
 */

void buscarCliente(char destino[],eCliente clientes[],int tamClientes,int tamCadena,int id);
/**
 * funcion para listar autos segun una marca ingresada
 * @param autos array donde estan los datos de los autos ingresados
 * @param colores array donde estan los datos de los colores
 * @param marcas array donde estan los datos de las marcas
 * @param clientes array donde estan los datos de los clientes
 * @param tamAutos tamanio del array de autos
 * @param tamColor tamanio del array de colores
 * @param tamMarcas tamanio del array de marcas
 * @param tamClientes tamanio del array de clientes
 * @return 0 en caso de que se haya podido listar correctamente -1 en caso contrario
 */

int listarAutoMarcas(eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamAutos,int tamColor,int tamMarcas,int tamClientes);
/**
 * funcion para contar la cantidad de autos automaticos o manuales que hay
 * @param autos array donde estan los datos de los autos ingresados
 * @param tamAutos tamanio del array de autos
 */

void informarManualAutomatico(eAuto autos[],int tamAutos);
/**
 * funcion para infomar la cantidad de autos que hay de determinado color y marca
 * @param autos array donde estan los datos de los autos ingresados
 * @param tamAutos tamanio del array de autos
 */

void contarColorYMarca(eAuto autos[],int tamAutos);
/**
 * funcion que cuenta los autos de cada marca y muetra la mas elegida
 * @param autos array donde estan los datos de los autos ingresados
 * @param tamAutos tamanio del array de autos
 * @param marcas array donde estan los datos de las marcas
 */

void mostraMarcaMasElegida(eAuto autos[],int tamAutos,eMarca marcas[]);
/**
 * funcion que al ingresar un auto se muetran los trabajos que se le realizaron al mismo
 * @param trabajos array donde se encuentras los datos de los trabajos
 * @param tamTrabajos tamanio de array de trabajos
 * @param servicios array donde se encuentras los datos de los servicios
 * @param tamServicios tamanio del array de servicios
 */

void mostrarTrabajosDeAuto(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios);
/**
 * funcion para sumar los importes de los servicios que se le realziaron a un auto determiando
 * @param trabajos array donde se encuentras los datos de los trabajos
 * @param tamTrabajos tamanio de array de trabajos
 * @param servicios array donde se encuentras los datos de los servicios
 * @param tamServicios tamanio del array de servicios
 */

void sumaImportesDeAuto(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamServicios);
/**
 * funcion que busca el precio de un servicio y lo escribe en un puntero
 * @param destino donde se va a guardar el valor del precio del servicio
 * @param servicios rray donde se encuentras los datos de los servicios
 * @param tamServicios tamanio del array de servicios
 * @param id del cual se busca el precio
 */
void buscarPrecioServicio(float *destino,eServicio servicios[],int tamServicios,int id);
/**
 * funcion para mostrar los autos a los que se le realizo un servicio determinado
 * @param trabajos array donde se encuentras los datos de los trabajos
 * @param tamTrabajos tamanio de array de trabajos
 * @param servicios array donde se encuentras los datos de los servicios
 * @param tamServicios tamanio del array de servicios
 * @param autos array donde estan los datos de los autos ingresados
 * @param tamAutostamanio del array de autos
 * @param colores array donde estan los datos de los colores
 * @param tamColores tamanio del array de colores
 * @param marcas array donde estan los datos de las marcas
 * @param tamMarcas tamanio del array de marcas
 * @param clientes array donde estan los datos de los clientes
 * @param tamClientes tamanio del array de clientes
 */

void mostrarAutosSegunServicio(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamServicios,eAuto autos[],int tamAutos,eColor colores[],int tamColores,eMarca marcas[],int tamMarcas,eCliente clientes[],int tamClientes);

/**
 * se ingresa una fecha y se muestran los servicios que se realizaron en dicha fecha
 * @param trabajos  array donde se encuentras los datos de los trabajos
 * @param tamTrabajos tamanio de array de trabajos
 * @param servicios array donde se encuentras los datos de los servicios
 * @param tamServicios tamanio del array de servicios
 */
void mostrarServiciosRealizadosSegunFecha(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamServicios);

#endif /* FUNCIONES_H_ */
