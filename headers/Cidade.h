//
// Created by joaog on 08/03/2022.
//

#ifndef TRABPOO_CIDADE_H
#define TRABPOO_CIDADE_H
#include <iostream>
#include <map>
#include <list>
#include "Candidato.h"
#include "Partido.h"
#include "Data.h"


using namespace std;
class Cidade {
public:
    map<int, list<Candidato*>> candidatos;
    map<int, Partido*> partidos;
    int numeroEleitos;
    list<Candidato*> eleitos;
    Data *dataEleicao;
    int qtdCandidatosCadastados;

    void setDataEleicao(string data);

    void setNumeroEleitos(int numeroEleitos);

    void adicionaCandidato(Candidato *c);

    void adicionaPartido(Partido *p);

    void imprimeCandidatosPartidoEspecifico(int num);

    void imprimePartidos();


    void inserirDadosCandidatos(vector<vector<string>> conteudoCandidatos);

    void inserirDadosPartidos(vector<vector<string>> conteudoPartidos);

    void qtdCandidatosEleitos();

    list<Candidato *> maisVotadosGeral(int inicio, int limite);

    void setCandidatosCadastrados(int qtd);

    int votosNominaisPartido(int numeroPartido);

    list<Partido *> resumoPartidos();

    int getVotosNominaisTotal();

    int getVotosLegendaTotal();
};


#endif //TRABPOO_CIDADE_H
