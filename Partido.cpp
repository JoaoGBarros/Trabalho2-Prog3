//
// Created by joaog on 08/03/2022.
//

#include "headers/Partido.h"

Partido::Partido(int numeroPartido, int votosLegenda, string nome, string sigla){
    this->votosLegenda = votosLegenda;
    this->numeroPartido = numeroPartido;
    this->nome = nome;
    this->sigla = sigla;
}

void Partido::setQtdEleitos(int qtdEleitos){
    this->qtdEleitos = qtdEleitos;
}
void Partido::setVotosNominais(int votosNominais){
    this->votosNominais = votosNominais;
}

int Partido::getNumeroPartido(){
    return this->numeroPartido;
}

int Partido::getVotosNominais(){
    return this->votosNominais;
}

int Partido::getVotosLegenda(){
    return this->votosLegenda;
}

int Partido::getVotosTotais(){
    return (this->votosLegenda + this->votosNominais);
}

void Partido::setMenosVotado(Candidato *c){
    if(c != NULL){
        this->menosVotado = c;
    }

}
void Partido::setMaisVotado(Candidato *c){
    if(c != NULL){
        this->maisVotado = c;
    }
}

Candidato* Partido::getMenosVotado(){
    return this->menosVotado;
}
Candidato* Partido::getMaisVotado(){
    return this->maisVotado;
}

int Partido::getQtdMaisVotado(){
    if(this->maisVotado != NULL){
        return this->maisVotado->getVotosNominais();
    }else{
        return -1;
    }
}

int Partido::getQtdMenosVotado(){
    if(this->menosVotado != NULL){
        return this->menosVotado->getVotosNominais();
    }else{
        return 9999999;
    }
}
