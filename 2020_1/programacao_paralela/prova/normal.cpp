#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#define tam 150

using namespace std;


int main()
{
    double t1,t2;
    size_t found;
    ifstream inFile;
    string word, line, File;
    string arquivo;

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

    t1 = omp_get_wtime();

    int count = 0;

    found = arquivo.find(word);
    for (int i = 0; i < arquivo.size(); ++i)
    {
        if(arquivo.substr(i, word.length()) == word)
            count++;
    }

    // cout << arquivo << endl;
    t2 = omp_get_wtime();
    printf("\n Tempo total: %lf\n",t2-t1);
    cout << "Contagem = " << count << endl;
    return 0;
}
