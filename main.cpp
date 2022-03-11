#include <iostream>
#include <locale>
#include "headers/Partido.h"
#include "headers/Data.h"
#include "headers/Cidade.h"
#include "headers/LeituraCSV.h"
#include "headers/Relatorios.h"
#include <fstream>
#include <windows.h>

void imprimeRelatorios(Cidade *cidade){
    Relatorios *relatorios = new Relatorios();
    relatorios->relatorio1(cidade);
    /*
    relatorios->relatorio2(cidade);
    relatorios->relatorio3(cidade);
    relatorios->relatorio4(cidade);
    relatorios->relatorio5(cidade);
    relatorios->relatorio6(cidade);
    relatorios->relatorio7(cidade);
    relatorios->relatorio8(cidade);
    relatorios->relatorio9(cidade);
    relatorios->relatorio10(cidade);
    relatorios->relatorio11(cidade);
     */
}

void inicializacao(Cidade *cidade){
    LeituraCSV *candidatos = new LeituraCSV("C:\\Users\\joaog\\CLionProjects\\TrabPOO\\candidatos.csv");
    //LeituraCSV *partidos = new LeituraCSV("C:\\Users\\joaog\\CLionProjects\\TrabPOO\\partidos.csv");
    vector<vector<string>> conteudoCandidatos = candidatos->lerArquivo();
    //vector<vector<string>> conteudoPartidos = partidos->lerArquivo();
    cidade->inserirDadosCandidatos(conteudoCandidatos);
    //cidade->inserirDadosPartidos(conteudoPartidos);
}


int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    Cidade *cidade = new Cidade();
    inicializacao(cidade);
    cidade->qtdCandidatosEleitos();
    imprimeRelatorios(cidade);


    return 0;
}

