//Proyecto 3 


#include <stdio.h>
#include<stdlib.h>
#define N 20

int out;
int array[N];
int r;
int i;
int elemento;
int x;
int opcion;
int posicion;
int repetidos=0;

void rellenar(int arreglo[]){
	
	for (i=0;i<=N;i++){
	r = (rand() % 20)+1;
	arreglo[i]=r;
	}
	
}

void mostrar(){
	//Funcion de mostrar vector 
	printf("\n");
	printf("\tPosicion ");
		for (i=0;i<=N;i++){
	if (i<10){
	
		printf("|%d ",i);
	}else {
	
		printf("|%d",i);
		}
		
	}
	printf("\n");
	
	printf("\tValor    ");
	
	
		for (i=0;i<=N;i++){
			
		if(array[i]<10) { 

		printf("|%d ",array[i]);
	} else {
		printf("|%d",array[i]);
		
	}
	
	}
		printf("\n");
	
}

void mostrarrepetido (int valor) {
	//Mostrar vector solo con un valor en caso de estar repetido
	printf("\n");
		printf("\tPosicion ");
		for (i=0;i<=N;i++){
	if (i<10){
	
		printf("|%d ",i);
	}else {
	
		printf("|%d",i);
		}
		
	}
	printf("\n");
	
	printf("\tValor    ");
	
		for (i=0;i<=N;i++){
			
		if(array[i]!=valor) { 

		printf("|  ");
	} else {
		if (valor<10){
		
		printf("|%d ",array[i]);
	}else {
		printf("|%d",array[i]);
	}
		
	}
	
	}
		printf("\n");
}

void ordenar(int arreglo[]){
	//Ordenar de manera ascendente el vector
	int aux,d,c;
	
	for (c=0;c<N;c++){
		for (d=0;d<N;d++){
			
			
			
			if (arreglo[d]>arreglo[d+1]){
				
			aux=arreglo[d];
			arreglo[d]=arreglo[d+1];
			arreglo[d+1]=aux;
			
			}
		
		}
	}
	
}

void reordenar(int arreglo[]){
	//Poner las "casillas" de valores vacios al final
	int aux,d,c;
	
	for (c=0;c<N;c++){
		for (d=0;d<N;d++){
			
			if (arreglo[d]=='\0'){
				
			aux=arreglo[d];
			arreglo[d]=arreglo[d+1];
			arreglo[d+1]=aux;
			
			}
		
		}
	}	
}

void limpiar(int arreglo[]){
 	//Quitar valores repetidos del vector generado por el programa
 	int aux,d,c;
 	for (c=0;c<N;c++){
 		for (d=0;d<N;d++){
 			if (arreglo[d]==arreglo[d+1]){
 				
 				arreglo[d+1]='\0';
 				arreglo[d+1]=arreglo[d+2];
			 }
		 }
	 }
 	
 }

int comparar(int arreglo[],int value){
 	//Comparar si el valor insertado por el usuario ya esta en el vector
	int aux=0,d,c;
 	for (c=0;c<N;c++){
 		for (d=0;d<N;d++){
 			if (value==arreglo[d]){
 				
 				aux = 1;
 				
			 }
			 
		 }
	 }
	 return aux;
}

void insertar(int arreglo[],int value){
	//Insertar valor en el vector
	int c=0;
	while (arreglo[c]!='\0'){
		c++;
	}
	
	if (arreglo[c]=='\0'){
		
		arreglo[c]=value;
	}	
}

void eliminar (int arreglo[],int value){
	//Eliminar valor del vector
	arreglo[value]='\0';
	
}



main (){
	
	system("COLOR F0");	
	
	//Pantalla de presentación
	printf("\n\n\t\t");
	printf("Universidad tecnologica de Panama");
	printf("\n\t\t");
	printf("Licenciatura en Ingenieria de Software");
	printf("\n\t\t");
	printf("Estudiante: Ives De La Cruz");
	printf("\n\t\t");
	printf("Fecha: 6 de Julio del 2016");
	
	printf("\n\n\t\t");
	printf("Para continuar presione enter ");
	getchar();
	system("cls");
	

	srand (time(NULL)); 
	//Permite que haya valores random diferentes en cada ejecucion
	rellenar (array);
	ordenar (array);
	limpiar(array);

	
	do {
	
		mostrar (array);
	
		
		printf("\n\n\tQue desea hacer?: ");
		printf("\n\t1.Insertar");
		printf("\n\t2. Eliminar ");
		
		scanf("%d",&opcion);
		
			system("cls");
		
		
		
	switch (opcion){
			
			
		case 1:
			
			//Caso insertar
			mostrar (array);
			printf("\n\tInserte elemento: ");
			scanf("%d",&elemento);
			x = comparar (array,elemento);
			
			if (x==0){
					
			insertar(array,elemento);
			ordenar (array);
			reordenar(array);
		//	printf("\n");
			mostrar (array);
			}	
			else	
			{
			// system("COLOR 0C");	
			
			mostrarrepetido(elemento);
			printf("\n\tEl valor ya existe ");
			repetidos++;
			
			printf("\n");
			}
			
				
			break; //break case 1
	
		case 2:
			//Caso eliminar
			mostrar (array);
			printf("\n\tInserte posicion del elemento que desea eliminar: ");
			scanf("%d",&posicion);
			printf("\n");
			eliminar(array,posicion);
			reordenar (array);
			mostrar(array);
		
			
		
			break;
			
		default: 
		//Caso de otra opcion 
		
		printf("\n\tOpcion no valida");
		printf("\n");
		
		break;
			
	} //llave switch 
	
		//Mensaje de si desea salir
		printf("\n\tDesea salir? ( 0=si / 1=no ): ");
		scanf("%d",&out);
		
		
		
			system("cls");
			
	} while (out);
	printf("\n\tVector Final");
	mostrar(array);
	printf("\n\t El total de valores repetidos fue: %d",repetidos);
	printf("\n");
	
}



