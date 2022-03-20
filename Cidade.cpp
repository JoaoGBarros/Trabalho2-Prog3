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

void Cidade::setCandidatosCadastrados(int qtd){
    this->qtdCandidatosCadastados = qtd;
}


void Cidade::qtdCandidatosEleitos(){
    int contadorEleitos = 0;
    int contadorCadastrados = 0;
    int contadorEleitosPartido = 0;
    int numPartido;

    for(auto const& listaCandidato: this->candidatos){
        int maior = 0;
        int menor = 9999;
        Candidato* maisVotado = NULL;
        Candidato* menosVotado = NULL;
        contadorEleitosPartido = 0;
        numPartido = listaCandidato.first;
        for(Candidato *c: listaCandidato.second){
            c->setIdade(this->dataEleicao);
            contadorCadastrados++;
            if(c->getVotosNominais() > maior && c->getDestinoVoto() == "Válido"){
                maior = c->getVotosNominais();
                maisVotado = c;
            }



            if(c->getVotosNominais() < menor && c->getDestinoVoto() == "Válido"){
                menor = c->getVotosNominais();
                menosVotado = c;
            }


            if(c->candidatoEleito()){
                this->eleitos.push_back(c);
                contadorEleitos++;
                contadorEleitosPartido++;
            }

        }
        this->partidos[numPartido]->setMaisVotado(maisVotado);
        this->partidos[numPartido]->setMenosVotado(menosVotado);
        this->partidos[numPartido]->qtdEleitos = contadorEleitosPartido;
    }
    this->setCandidatosCadastrados(contadorCadastrados);
    this->setNumeroEleitos(contadorEleitos);
}

list<Candidato*> Cidade::maisVotadosGeral(int inicio, int limite){
    list<Candidato*> maisVotados;
    list<Candidato*> retorno;
    list<Candidato*>::iterator iterInicio;
    list<Candidato*>::iterator iterFinal;


    for(auto listaCandidatos: this->candidatos){
        maisVotados.merge(listaCandidatos.second);
    }

    maisVotados.sort([] (Candidato* c1, Candidato* c2){
        if(c1->getVotosNominais() == c2->getVotosNominais()){
            return c1->idade > c2->idade;
        }

        return c1->getVotosNominais() > c2->getVotosNominais();
    });

    iterInicio = maisVotados.begin();
    iterFinal = maisVotados.begin();

    if(inicio != 0){
        advance(iterInicio, inicio);
    }

    if(limite != 0){
        advance(iterFinal, limite);
    }

    maisVotados.splice(retorno.begin(), retorno, iterInicio, iterFinal);


    return retorno;
}


int Cidade::votosNominaisPartido(int numeroPartido){
    int votos = 0;

    for(Candidato *c: this->candidatos[numeroPartido]){
        if(c->getDestinoVoto() == "Válido"){
            votos += c->getVotosNominais();
        }
    }

    return votos;
}

list<Partido*> Cidade::resumoPartidos(){
    list<Partido*> retorno;
    for(auto& v: this->partidos){
        v.second->setVotosNominais(this->votosNominaisPartido(v.second->getNumeroPartido()));
        retorno.push_back(v.second);
    }

    return retorno;
}

int Cidade::getVotosNominaisTotal(){
    int contadorVotos = 0;
    for(auto& partidos: this->partidos){
        for(Candidato *c : this->candidatos[partidos.first]){
            if(c->getDestinoVoto() == "Válido"){
                contadorVotos += c->getVotosNominais();
            }
        }
    }

    return contadorVotos;
}

int Cidade::getVotosLegendaTotal(){
    int contadorVotos = 0;

    for(auto& partidos: this->partidos){
        contadorVotos += partidos.second->getVotosLegenda();
    }

    return contadorVotos;
}



