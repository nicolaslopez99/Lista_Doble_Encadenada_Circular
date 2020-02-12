#include <iostream>
using namespace std;
struct nodo{
	nodo*sig;
	int valor;
	nodo*ant;
};
class lista{
	nodo*cab;
	nodo*col;
	int tam;
	public :
		lista(){
			tam=0;
			cab=NULL;
			col=NULL;
		}
		void insertar_final(nodo*apuntador);
		bool lista_vacia();
		int tamano_lista();
		void insertar(int valor,int pos);
		void eliminar(int pos);
		void imprimir_lista_asc();
		void imprimir_lista_des();
		void imprimir_dato(int pos);
};

bool lista :: lista_vacia(){
	if (tam==0){
		return true;
	}else{
		return false;
	}	
}
int lista :: tamano_lista(){
	return tam;	
}
void lista :: insertar(int info,int pos){
	nodo *nuevo= new nodo;
	nodo *aux;
	nuevo->valor = info;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	if (pos>tam){
		insertar_final(nuevo);
	} else{
		aux = cab;
		for (int i =1;i<pos-1;i++){
			aux=aux->sig;
		}
		nuevo->sig = aux->sig;
		aux->sig= nuevo;
		aux = col;
		for (int i=tam;i>pos+1;i--){
			aux=aux->ant;
		}
		nuevo->ant = aux->ant;
		aux->ant= nuevo;
		
		tam = tam+1;	
	}	
}
void lista :: insertar_final(nodo *nuevo){
	nodo *aux=cab;
	if (tam==0){
		cab= nuevo;
		tam = tam+1;
	} else {
		for (int i=1;i<tam;i++){
			aux=aux->sig;
		}
		aux->sig = nuevo;
		nuevo->ant = aux;
		
		cab->ant = nuevo;
		nuevo->sig = cab;
		col = nuevo;
		tam = tam+1;	
	}
}
void lista :: imprimir_lista_asc(){
	nodo *aux = cab;
	for (int i=0;i<tam;i++){
		cout<<aux->valor<<endl;
		aux= aux->sig;
	}
}
void lista :: imprimir_lista_des(){
	nodo *aux = col;
	for (int i=0;i<tam;i++){
		cout<<aux->valor<<endl;
		aux= aux->ant;
	}
}
void lista :: eliminar(int pos){
	nodo *aux;
	nodo *eliminar;
	nodo *aux1;
	if (pos>tam){
		cout<<"No existe esta posicion"<<endl;
	} else if(pos==1){
		cout<<"No se puede elimina esta posicion"<<endl;
	}else{
		aux = cab;
		eliminar = cab;
		aux1=col;
		for (int i =1;i<pos-1;i++){
			aux=aux->sig;
		}
		for (int i =1;i<pos;i++){
			eliminar=eliminar->sig;
		}
		for (int i =tam;i>pos+1;i--){
			aux1=aux1->ant;
		}
		aux->sig = eliminar->sig;
		eliminar->sig = NULL;
		
		aux1->ant = eliminar->ant;
		eliminar->ant = NULL;
		tam = tam-1;	
	}
}
void lista :: imprimir_dato(int pos){
	nodo *aux = cab;
	if (pos>tam){
		cout<<"No existe esa posicion dentro del arreglo "<<endl;
	}else{
		for (int i=0;i<pos-1;i++){
			aux= aux->sig;
		}
		cout<<aux->valor<<endl;
	}
}

int main(){
	lista a;
	int aux=0;
	int n;
	int valor;
	int pos;
	do{
		cout<<"1.Saber el tamano de la lista"<<endl;
		cout<<"2.Saber si la lista esta vacia"<<endl;
		cout<<"3.Ingresar un nuevo elemento"<<endl;
		cout<<"4.Mostrar la lista ascendentemente"<<endl;
		cout<<"5.Mostrar la lista descendentemente"<<endl;
		cout<<"6.Eliminar elemento"<<endl;
		cout<<"7.Mostrar un elemento de la lista"<<endl;
		cout<<"8.Salir del menu"<<endl;
		cin>>n;
		if(n==1){
			cout<<"EL tamano de la lista es: "<<a.tamano_lista()<<endl;
		}else if(n==2){
			if(a.lista_vacia()==0){
				cout<<"La lista no esta vacia"<<endl;
			} else{
				cout<<"La lista esta vacia"<<endl;
			}
		} else if(n==3){
			cout<<"Ingrese el nuevo valor y la posicion en la que se encuentra "<<endl;
			cin>>valor;
			cin>>pos;
			a.insertar(valor,pos);	
		}else if(n==4){
			cout<<"La lista es "<<endl;
			a.imprimir_lista_asc();
		} else if(n==5){
			cout<<"La lista es "<<endl;
			a.imprimir_lista_des();
		} else if(n==6){
			cout<<"Ingresar la posicion que desea eliminar "<<endl;
			cin>>pos;
			a.eliminar(pos);
		}else if(n==7){
			cout<<"Ingresar la posicion del dato desea ver "<<endl;
			cin>>pos;
			a.imprimir_dato(pos);
		}else if(n==8){
			aux=aux+1;
		}else{
			cout<<"Opcion incorrecta"<<endl;
		}
		
	}while(aux==0);
	return 0;
}
