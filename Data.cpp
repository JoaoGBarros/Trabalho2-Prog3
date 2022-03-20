//
// Created by joaog on 08/03/2022.
//

#include <cstdlib>
#include "headers/Data.h"


const int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

int Data::qtdAnoBissexto(Data *d){
    int ano = d->ano;
    int qtd;

    if(d->mes <= 2){
        ano--;
    }

     qtd = (ano / 4) - (ano/ 100) + (ano/400);
    return qtd;
}

unsigned int Data::diferencaAnosEntreDatas(Data* d1, Data* d2){

    long int n1 = d1->ano * 365 + d1->dia;
    long int n2 = d2->ano * 365 + d2->dia;

    for(int i = 0; i < d1->mes - 1; i++){
        n1 += diasDoMes[i];
    }

    n1 += qtdAnoBissexto(d1);

    for(int i = 0; i < d2->mes - 1; i++){
        n2 += diasDoMes[i];
    }

    n2 += qtdAnoBissexto(d2);

    return (n1-n2) / 365;

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