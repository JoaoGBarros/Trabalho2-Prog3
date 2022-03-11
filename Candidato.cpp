//
// Created by joaog on 08/03/2022.
//

#include "headers/Candidato.h"



Candidato::Candidato(string numero, int votosNominais, string situacao, string nome, string nomeUrna,
                          char sexo, string dataNascimento, string destinoVoto, int numeroPartido){

    this->numero = numero;
    this->votosNominais = votosNominais;
    this->situacao = situacao;
    this->nome = nome;
    this->nomeUrna = nomeUrna;
    this->sexo = sexo;
    this->destinoVoto = destinoVoto;
    this->numeroPartido = numeroPartido;
    this->dataNascimento = new Data(dataNascimento);
}

int Candidato::getNumeroPartido(){
    return this->numeroPartido;
}

int Candidato::getVotosNominais(){
    return this->votosNominais;
}

string Candidato::getNome(){
    return this->nome;
}

string Candidato::getDestinoVoto(){
    return this->destinoVoto;
}

bool Candidato::candidatoEleito(){
    if(this->situacao == "Eleito"){
        return true;
    }else{
        return false;
    }

}