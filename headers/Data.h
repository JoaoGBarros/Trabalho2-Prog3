//
// Created by joaog on 08/03/2022.
//

#ifndef TRABPOO_DATA_H
#define TRABPOO_DATA_H
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Data {
public:

    int dia;
    int mes;
    int ano;

    Data(string data);
    void imprimeData();

private:
    void setDia(int dia);

    void setMes(int mes);

    void setAno(int ano);

    void separaString(const string &data, vector<string> &array, const char delim = '/');

};


#endif //TRABPOO_DATA_H
