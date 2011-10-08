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

class CNodo{
	public:
		CNodo();
		int iDato;
		CNodo * pSiguiente;
};


CNodo::CNodo(){
	iDato=0;
	pSiguiente=NULL;
}


tbb::mutex myMutex;


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



Cola::Cola(){

    pCabeza=NULL;
	pFinal=NULL;
	total=0;
};


int Cola::DevElto(){return total;}

int Cola::EsColaVacia(){ //Devuelve 1 si esta vacia y 0 si esta cargada.

    if(pCabeza==NULL){
        return 1;
    }
	else{return 0;}
}


void Cola::MeterEnCola(int n){

    CNodo*nodo=new CNodo();
	nodo->iDato=n;
	myMutex.lock();
	if (EsColaVacia()==1){
		pCabeza=nodo;
		pFinal=pCabeza;
		total ++;
	}
	else{

        pFinal->pSiguiente=nodo;
		nodo->pSiguiente=NULL;
		pFinal=nodo;
		total ++;
	}
    myMutex.unlock();
}



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


int Cola::SacarDeCola(){

    if (EsColaVacia()==1){cout<<"La cola esta vacia."<<endl;}
	else{

        myMutex.lock();
        int resp=pCabeza->iDato;
        CNodo*Aux;
        Aux=pCabeza;
        pCabeza=pCabeza->pSiguiente;
        delete Aux;
        total --;
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

