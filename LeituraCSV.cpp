//
// Created by joaog on 08/03/2022.
//

#include "headers/LeituraCSV.h"

LeituraCSV::LeituraCSV(string path){
    this->path = path;
}


vector<vector<string>> LeituraCSV::lerArquivo(){

    ifstream file;
    file.open(this->path);
    bool flag = true;
    vector<vector<string>> conteudo;
    vector<string> linha;
    string line, palavra;

    if(file.is_open()){
        while(getline(file, line)){
            linha.clear();

            if(flag == true){
                this->colunas = line;
                flag = false;
            }else{
                stringstream str(line);

                while(getline(str, palavra, ',')){
                    linha.push_back(palavra);
                }

                conteudo.push_back(linha);
            }

        }
        return conteudo;
    }else{
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }

}