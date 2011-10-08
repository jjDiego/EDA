#include <iostream>
#include "Garbage_Collector.h"

using namespace std;


int main()
{
	int* tmp1 = new int[1];
	tmp1[0] = 10;

	int* tmp2 = new int[1];
	tmp2[0] = 20;

	GarColl<int> GC1;
	GarColl<int> GC2;
	GarColl<int> GC3;
	GarColl<int> GC4;

	GC1 = tmp1;
	GC2 = GC1;
	GC3 = GC1;
	GC4 = tmp2;
	GC1 = GC1;
	GC4 = GC4;

	printf("Contenido\tCantidad\n\n");
	printf("GC1 = %d\t\t%d\n",GC1.get_Data()[0],GC1.get_Counter());
	printf("GC2 = %d\t\t%d\n",GC2.get_Data()[0],GC2.get_Counter());
	printf("GC3 = %d\t\t%d\n\n",GC3.get_Data()[0],GC3.get_Counter());

	GC3 = GC4;
	GC3 = GC3;
	GC4 = GC4;

	printf("GC1 = %d\t\t%d\n",GC1.get_Data()[0],GC1.get_Counter());
	printf("GC4 = %d\t\t%d\n\n",GC4.get_Data()[0],GC4.get_Counter());

	return 0;
}

