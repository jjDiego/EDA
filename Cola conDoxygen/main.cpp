/**
* @file main.cpp
* @brief en este documento se programa una cola sincronizada
* presentando sus funciones básicas y las que se requieren.
*
* @author Diego Velásquez Ríos
*
* @date 10/10/2011
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <tbb/tbb.h>
#include <tbb/mutex.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

//using namespace tbb;
using namespace std;


/**
* Esta clase representa a un nodo dentro de la cola, el cual contiene su dato y un puntero
* que contiene la direccion de memoria de otro nodo, o de nada (vacio-cuando temrina la cola)
* @param CNodo Clase que contiene los nodos que de la cola
* @param iDato Es la variable que contiene el dato (en este caso de tipo entero)
* @param pSiguiente Es el puntero que contiene la direccion de memoria (que apunta) al nodo siguiente
*/
class CNodo{
	public:
		CNodo();
		int iDato;
		CNodo * pSiguiente;
};


/**
* Este es el constructor del nodo el cual tomara como datos
* iniciales 0 y una direccion de memoria vacia (NULL)
*/
CNodo::CNodo(){
	iDato=0;
	pSiguiente=NULL;
}


/**
* @param myMutex es un mutex de la librería TBB (Threading Building Blocks)
*/
tbb::mutex myMutex;


/**
* Esta clase representa a la cola
* @param pCabeza parametro que contiene la direccion de memoria a la cabeza de la cola
* @param pFinal Parametro que apunta al último nodo de la cola
* @param total es un parámetro de tipo entero que almacenará la cantidad actual de nodos que tiene la cola
*/
class Cola{
		CNodo * pCabeza;
		CNodo * pFinal;
		int total;

	public:
		
		Cola();
		void MeterEnCola(int);
		int SacarDeCola();
		int VerPrimerElto();
		int EsColaVacia();
		int DevElto();
};


/**
* @brief Constructor por defecto de la cola
*/
Cola::Cola(){

    pCabeza=NULL;
	pFinal=NULL;
	total=0;
};


/**
* @brief Funcion que devuelve el tamaño actual de la cola
* 
* @param total Tamaño actual de la cola
*/
int Cola::DevElto(){return total;}



/**
* @brief Si la cola se encuentra vacía retorna un valor de 1
* en caso contrario retorna 0
*/
int Cola::EsColaVacia(){

    if(pCabeza==NULL){
        return 1;
    }
	else{return 0;}
}

/**
* @brief Ingresa un nuevo nodo al final de la cola
* @param n Nuevo dato de tipo entero que será ingresado como nodo a la cola
* @param 
*/
void Cola::MeterEnCola(int n){

    CNodo*nodo=new CNodo();
	nodo->iDato=n;
	/**@a myMutex.lock() el mutex se bloquea para que en caso de que otra hebra 
	* quiera modificar este elemento, se detenga hasta que se desbloquee
	*/
	myMutex.lock();
	/** @brief en caso que la cola este vacía el dato o nodo ingresado sera la cabeza y final de la cola*/
	if (EsColaVacia()==1){
		pCabeza=nodo;
		pFinal=pCabeza;
		total ++;
	}
	/** @brief en caso que la cola NO este vacía el dato o nodo será ingresado al final de la cola*/
	else{

        pFinal->pSiguiente=nodo;
		nodo->pSiguiente=NULL;
		pFinal=nodo;
		total ++;
	}
	/**@a myMutex.unlock() una vez que se termine la operacion de MeterEnCola() del nodo apuntado 
	* el mutex será liberado (desbloqueado) y cualquier otra hebra podrá modificarlo
	*/
    myMutex.unlock();
}


/**@brief Retorna el primer elemento de la cola
*/
int Cola::VerPrimerElto(){

    if (EsColaVacia()==1){
        cout<<"La cola esta vacia."<<endl;
        return 0;
	}
    else{

        cout<<pCabeza->iDato<<endl;
		return pCabeza->iDato;
    }

}

/**@brief Elimina el último elemento de la cola
*/
int Cola::SacarDeCola(){

    if (EsColaVacia()==1){cout<<"La cola esta vacia."<<endl;}
	else{
		/**@a myMutex.lock() el mutex se bloquea para que en caso de que otra hebra 
		* quiera modificar este elemento, se detenga hasta que se desbloquee
		*/
        myMutex.lock();
        int resp=pCabeza->iDato;
        CNodo*Aux;
        Aux=pCabeza;
        pCabeza=pCabeza->pSiguiente;
        delete Aux;
        total --;
		/**@a myMutex.unlock() una vez que se termine la operacion de SacarDeCola() del nodo apuntado 
		* el mutex será liberado (desbloqueado) y cualquier otra hebra podrá modificarlo
		*/
        myMutex.unlock();
        return resp;
	}
    return 0;

}



int main(){

    CNodo nodo;
	Cola colita;

    
	int seleccion=1;
	while (seleccion != 0){

        
        cout<<"Seleccione una opcion: "<<endl<<endl;
		cout<<" 1- Ver si esta la cola vacia"<<endl<<" 2- Meter datos en cola"<<endl;
        cout<<" 3- Ver el primer elemento"<<endl<<" 4- Sacar datos de cola"<<endl<<" 5- Ver el total"<<endl<<" 0- * SALIR *"<<endl;
        cin>>seleccion;

        switch (seleccion){

            case 1:

                int estado;
                estado=colita.EsColaVacia();
                if (estado==1){

                    cout<<estado<<"Cola vacia"<<endl;
                    break;
                }
                else{

                    cout<<estado<<"Cola cargada"<<endl;
                    break;
                }
                break;

            case 2:

                int metere;
                int c;
				c=0;
                cout<<"Cuantos elementos vas a meter: "<<endl;
                cin>>metere;
				/*int n;
                cout<<"Valor a meter: ";
                cin>>n;
				parallel_for(blocked_range<metere>(0, metere), colita.MeterEnCola(n););
				c++;*/
                while(c<metere){

                    int n;
                    cout<<"Valor a meter: ";
                    cin>>n;
                    colita.MeterEnCola(n);
                    c++;
                }
                break;

            case 3:

                colita.VerPrimerElto();
                break;

            case 4:

                cout<<"Cuantos elementos quieres sacar"<<endl;
                int saco;
                saco=0;
                cin>>saco;

				/*parallel_for(blocked_range<saco>(0, saco), colita.SacarDeCola(););
				saco--;*/

                while (saco>0){

                    int dato=colita.SacarDeCola();
                    cout<<dato<<endl;
                    saco--;
                }
                break;

            case 5:

                int total;
                total=colita.DevElto();
                cout<<"Total: "<<total<<endl;
                break;               
        }

    }

    cout<<"***************************************************"<<endl<<"***************************************************"<<endl;

}

