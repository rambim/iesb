#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#define tam 150

using namespace std;


int main(int argc, char * argv[])
{
    double t1,t2;
    size_t found;
    ifstream inFile;
    string word, line, File;
    string arquivo;
    int threads_desejadas;

    // cout << "Nome do arquivo" << endl;
    cin >> File;
    inFile.open(File);

    if (!inFile)
    {
        // cout << "Teste" << endl;
    }else{


        ostringstream ss;
        ss << inFile.rdbuf();
        arquivo = ss.str();

        // cout<<"word"<<endl;
        cin>> word;
    }

    threads_desejadas = atoi(argv[1]);
    omp_set_num_threads(threads_desejadas);

    t1 = omp_get_wtime();

    int count = 0;
    long int i;
    int size = word.size();
    #pragma omp parallel for
    for (int i = 0; i < arquivo.size(); ++i)
    {
        if(arquivo.substr(i, word.length()) == word)
            count++;
    }
    int id = omp_get_thread_num();

    cout << "found: " << count << endl;

    t2 = omp_get_wtime();
    printf("\n Tempo total: %lf\n",t2-t1);

    return 0;
}
