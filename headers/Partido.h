//
// Created by joaog on 08/03/2022.
//

#ifndef TRABPOO_PARTIDO_H
#define TRABPOO_PARTIDO_H
#include <iostream>
#include "Candidato.h"
using namespace std;

class Partido {
public:
    int numeroPartido;
    int votosLegenda;
    string nome;
    string sigla;
    int votosNominais = 0;
    int qtdEleitos = 0;
    Candidato *menosVotado = NULL;
    Candidato *maisVotado = NULL;

    Partido(int numeroPartido, int votosLegenda, string nome, string sigla); //Construtor

    void setQtdEleitos(int qtdEleitos);

    void setVotosNominais(int qtdEleitos);

    int getNumeroPartido();

    int getVotosLegenda();

    int getVotosNominais();

    int getVotosTotais();

    void setMenosVotado(Candidato *c);

    void setMaisVotado(Candidato *c);

    Candidato* getMenosVotado();

    Candidato* getMaisVotado();

    int getQtdMaisVotado();

    int getQtdMenosVotado();

    //~Partido();
};


#endif //TRABPOO_PARTIDO_H
