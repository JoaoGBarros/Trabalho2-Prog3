//
// Created by joaog on 08/03/2022.
//

#ifndef TRABPOO_LEITURACSV_H
#define TRABPOO_LEITURACSV_H
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Cidade.h"
using namespace std;
class LeituraCSV {

public:

    string colunas;
    string path;
    LeituraCSV(string path);
    vector<vector<string>> lerArquivo();
};


#endif //TRABPOO_LEITURACSV_H
