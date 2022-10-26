#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

typedef struct
{

	int dia;
	int anio;
	int mes;

}eFecha;

typedef struct
{

	int idMarca;
	char descripcion[20];

}eMarca;

typedef struct
{

	int idColor;
	char nombreColor[20];

}eColor;

typedef struct
{

	int idAuto;
	int idColor;
	int idMarca;
	int idCliente;
	char caja;
	int isEmpty;

}eAuto;

typedef struct
{

	int idServicio;
	char descripcion[25];
	float precio;

}eServicio;

typedef struct
{

	int idTrabajo;
	int idAuto;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;

typedef struct
{
	int idCliente;
	char nombre[20];
	char sexo;

}eCliente;

#endif /* ESTRUCTURAS_H_ */
