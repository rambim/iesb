#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include "omp.h"

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
	int thQtd = 6, indexTh = 0;
	string textos[thQtd];
	for(auto st : textos)
	{
		st = "";
	}
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
	for(int j = 0; j < thQtd; j++)
	{
		contador += findAll2(textos[j],search);
	}
	
	t2 = omp_get_wtime();
	file.close();
	cout<<"A palavra '"<<search<<"' foi encontrada "<<contador<<" vezes!"<<endl;
	cout<<"tempo : "<<t2 - t1<<endl;
	return 0;
}