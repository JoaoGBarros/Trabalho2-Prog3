//
// Created by joaog on 08/03/2022.
//

#ifndef TRABPOO_CANDIDATO_H
#define TRABPOO_CANDIDATO_H
#include <iostream>
#include "Data.h"
#include <string>
using namespace std;

class Candidato {
public:
    string numero;
    string situacao;
    string nomeUrna;
    char sexo;
    Data *dataNascimento;
    int numeroPartido;
    int idade;

    Candidato(string numero, int votosNominais, string situacao, string nome, string nomeUrna,
                   char sexo, string dataNascimento, string destinoVoto, int numeroPartido);

    int getNumeroPartido();
    int getVotosNominais();
    string getNome();
    string getDestinoVoto();
    bool candidatoEleito();

    void setIdade(Data *dataEleicao);

private:
    int votosNominais;
    string destinoVoto;
    string nome;
};



#endif //TRABPOO_CANDIDATO_H
