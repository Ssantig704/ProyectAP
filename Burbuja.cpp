#include <iostream>
#include <math.h>
using namespace std;

int arr[5]={4,9,3,6,1};
void cambio(int i, int j){
	int temporal= arr[j];     //creamos una variable temporal y la igualamos al nunmero siguiente
	arr[j]=arr[i];
	arr[i]=temporal;
}

void imprimir(){
	double tamanio, espacio1;
	int longitud=sizeof(arr)/sizeof(arr[0]);
	tamanio=sizeof(arr)/sizeof(arr[0]);
	longitud=tamanio/espacio1;
	tamanio=sizeof(arr);
	for(int i=0; i<longitud; i++){
		cout<< arr[i]<< " ";
	}
}
int main(){
	double tamanio, espacio1, longitud;
	tamanio=sizeof(arr);
	longitud=sizeof(arr)/sizeof(arr[0]);
	longitud=tamanio/espacio1;
	for(int i=0; i<longitud; i++){
		for( int j=0; j<longitud-i-1; j++){
			if(arr[i]>arr[i+1]){
				cambio(i, i+1);
			}
		}
	}
	
	cout<<longitud;
	
	return 0;
}