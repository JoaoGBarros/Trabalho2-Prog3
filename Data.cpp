//
// Created by joaog on 08/03/2022.
//

#include <cstdlib>
#include "headers/Data.h"

Data::Data(string data){

    vector<string> array;
    this->separaString(data, array);
    this->setDia(stoi(array.at(0)));
    this->setMes(stoi(array.at(1)));
    this->setAno(stoi(array.at(2)));
}

void Data::setDia(int dia){

    if(dia > 31 || dia < 1){
        exit(1);
    } else {
        this->dia = dia;
    }
}
void Data::setMes(int mes){
    if(mes > 12 || mes < 1){
        exit(1);
    }else{
        this->mes = mes;
    }
}

void Data::setAno(int ano){

    if(ano >= 0){
        this->ano = ano;
    }else{
        exit(1);
    }

}

void Data::separaString(string const &data, vector<string> &array, const char delim){
    stringstream ss(data);
    string s;

    while(getline(ss, s, delim)){
        array.push_back(s);
    }
}

void Data::imprimeData(){
    printf("%d/%d/%d", this->dia, this->mes, this->ano);
}