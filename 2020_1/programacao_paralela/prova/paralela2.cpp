#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include "omp.h"
#define threads_desejadas 3

using namespace std; 

int findAll2(string texto, string search)
{
	int size_of_search = search.length(), contador = 0, size_of_text = texto.length();
	for(int i = 0; i <= size_of_text - size_of_search; i++)
	{
		if(texto.substr(i,size_of_search) == search)
		{
			contador++;
		}
	}
	return contador;
}


int main(int argc, char * argv[]) {  
	double t1,t2;
	t1 = omp_get_wtime();
	const clock_t initTime = clock();
	string line = "";
	char * name = argv[1] , * search = argv[2];
	ifstream file;
	int indexSearch, contador = 0,fileSize,i;
	int thQtd = threads_desejadas, indexTh = 0;
	string textos[thQtd];
	int contadores[thQtd] = {0};
	for(auto st : textos)
	{
		st = "";
	}
	omp_set_num_threads(threads_desejadas);
	file.open(name);
	if(file.is_open())
	{
		while(!file.eof())
		{
			getline(file,line,'\n');
			textos[indexTh] += line;
			indexTh++;
			if(indexTh >= thQtd)
			{
				indexTh = 0;
			}
		}
	}
	
	#pragma omp parallel for
	for(int j = 0; j < thQtd; j++)
	{
		int id = omp_get_thread_num();
		contadores[id] += findAll2(textos[j],search);
	}
	
	for(int cc = 0; cc < thQtd; cc++)
	{
		contador += contadores[cc];
	}
	
	t2 = omp_get_wtime();
	file.close();
	cout<<"A palavra '"<<search<<"' foi encontrada "<<contador<<" vezes!"<<endl;
	cout<<"tempo : "<<t2 - t1<<endl;
	return 0;
}