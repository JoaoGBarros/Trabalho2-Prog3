//
// Created by joaog on 08/03/2022.
//

#include "headers/Cidade.h"

void Cidade::setDataEleicao(string data){
    this->dataEleicao = new Data(data);
}

void Cidade::setNumeroEleitos(int numeroEleitos){
    this->numeroEleitos = numeroEleitos;
}

void Cidade::adicionaCandidato(Candidato *c){
    this->candidatos[c->getNumeroPartido()].push_back(c);

}

void Cidade::adicionaPartido(Partido *p){
    this->partidos[p->getNumeroPartido()] = p;
}

void Cidade::imprimeCandidatosPartidoEspecifico(int num){
    for(auto v: this->candidatos[num]){
        cout << v->getNome() << endl;
    }
}

void Cidade::imprimePartidos(){
    for(auto v: this->partidos){
        cout << v.second->getNumeroPartido() << endl;
    }

}

void Cidade::inserirDadosCandidatos(vector<vector<string>> conteudoCandidatos){

    for(auto& v: conteudoCandidatos){
        Candidato *c = new Candidato(v[0], stoi(v[1]), v[2], v[3], v[4], v[5].at(0), v[6], v[7], stoi(v[8]));
        this->adicionaCandidato(c);
    }
}

void Cidade::inserirDadosPartidos(vector<vector<string>> conteudoPartidos){
    for(auto& v: conteudoPartidos){
        Partido *p = new Partido(stoi(v[0]), stoi(v[1]), v[2], v[3]);
        this->adicionaPartido(p);
    }
}


void Cidade::qtdCandidatosEleitos(){
    int contador = 0;
    for(auto const& listaCandidato: this->candidatos){
        for(Candidato *c: listaCandidato.second){
            if(c->candidatoEleito()){
                this->eleitos.push_back(c);
                contador++;
            }
        }
    }
    this->setNumeroEleitos(contador);
}



