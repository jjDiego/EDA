// Garbage_Collector.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>

template <typename T> 
class GarColl
{
	private:
		T* pData;
		int* pCount;
		
	public:
		GarColl():pData(0){
			pCount = new int;
			*pCount = 1;
		}
		
		GarColl(T* pTemp):pData(pTemp){
		    pCount = new int;
			*pCount = 1;
		}
		
		GarColl(const GarColl<T> &pTemp) {copy(pTemp);}
		
		GarColl<T>& operator= (GarColl<T> &pTemp){
			if(this != &pTemp){
				(*pCount)--;				
				if(*pCount == 0){
					delete pData;
					delete pCount;
				}
				copy(pTemp);
			}
			return *this;
		}

		GarColl<T>& operator= (T* pTemp){
			if(pData != pTemp){
				(*pCount)--;
				if(*pCount == 0){
					delete pData;
					delete pCount;
				}
			
				pData = pTemp;
				pCount = new int;
			    *pCount = 1;
			}
			return *this;
		}
		
		void copy(GarColl<T> &pTemp){
			pData = pTemp.get_Data();
		    pCount = pTemp.pCount;
			(*pCount)++;
		}

		void Detach(){
			(*pCount)--;
			
			if(*pCount == 0){
				delete pData;
				delete pCount;
			}
		}
		
		T* get_Data() {return pData;}
		
		int get_Counter() {return *pCount;}
		
		T& operator* () {return *pData;}
		
		T* operator-> () {return pData;}

		~GarColl()
		{
			(*pCount)--;
			
			if(*pCount == 0)
			{
				delete pData;
				delete pCount;
			}
		}
};

