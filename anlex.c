/*
 *	Analizador Léxico	
 *	Curso: Compiladores y Lenguajes de Bajo de Nivel
 *	Práctica de Programación Nro. 1
 *	
 *	Descripcion:
 *	Implementa un analizador léxico que reconoce números, identificadores, 
 * 	palabras reservadas, operadores y signos de puntuación para el lenguaje
 * 	Json simplificado.
 */

/*********** Inclusión de cabecera **************/
#include "anlex.h"

/************* Variables globales **************/
token t;				// token global para recibir componentes del Analizador Lexico

// variables para el analizador lexico
FILE *entrada_json;          // Fuente JSON
FILE *salida;			// Salida esparada
char lexema[TAMLEX];	// Utilizado por el analizador lexico
int numLinea=1;			// Numero de Linea

/**************** Funciones **********************/
// Rutinas del analizador lexico
void error(const char* mensaje){
	printf("Lin %d: Error Lexico. %s.\n",numLinea,mensaje);
}

void getToken(){

}

//Principal
int main(int argc,char* args[])
{
	//initTabla();
	//initTablaSimbolos();

    salida = fopen("salida.txt", "w");
    if(!salida){
        printf("Ocurrio un error en la generacion del archivo salida.\n");
        exit(1);
    }
	
	if(argc > 1){
		if (!(entrada_json=fopen(args[1],"rt"))){
			printf("Archivo no encontrado.\n");
			exit(1);
		}
		while (t.compLex!=EOF){
			getToken();
			//printf("Lin %d: %s -> %d\n",numLinea,t.pe->lexema,t.compLex);
            printf("0");
		}
		fclose(entrada_json);
        fclose(salida);
	}else{
		printf("Debe pasar como parametro el path al archivo fuente.\n");
		exit(1);
	}
	return 0;
}