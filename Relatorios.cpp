//
// Created by joaog on 08/03/2022.
//

#include "headers/Relatorios.h"
#include "headers/Candidato.h"


void Relatorios::formatacaoRelatorios2_5(Cidade* cidade, int relatorio, list<Candidato*> candidato){
    int contador = 0;

    for(Candidato* c: candidato){
        contador++;
        string sigla = cidade->partidos[c->getNumeroPartido()]->sigla;

        if(relatorio == 4){
            if(!(c->situacao == "Eleito")){
                printf("%d - %s / %s (%s, %d votos)\n", contador, c->getNome().c_str(), c->nomeUrna.c_str(), sigla.c_str(), c->getVotosNominais());
            }
        }else if(relatorio == 5){
            if(c->situacao == "Eleito"){
                printf("%d - %s / %s (%s, %d votos)\n", contador+cidade->numeroEleitos, c->getNome().c_str(), c->nomeUrna.c_str(), sigla.c_str(), c->getVotosNominais());
            }
        }else{
             printf("%d - %s / %s (%s, %d votos)\n", contador, c->getNome().c_str(), c->nomeUrna.c_str(), sigla.c_str(), c->getVotosNominais());
        }
    }
    printf("\n");
}

void Relatorios::assisteRelatorio6(int votosTotais, int votosNominais, int votosLegenda, int candidatosEleitos){
    if(votosTotais > 1){
        printf("%d votos ", votosTotais);
    }else{
        printf("%d voto ", votosTotais);
    }

    if(votosNominais > 1){
        printf("(%d nominais e %d de legenda), ", votosNominais, votosLegenda);
    }else{
        printf("(%d nominal e %d de legenda), ", votosTotais, votosLegenda);
    }

    if(candidatosEleitos > 1){
        printf("%d candidatos eleitos\n", candidatosEleitos);
    }else{
        printf("%d candidato eleito\n", candidatosEleitos);
    }
}

void Relatorios::assisteRelatorio7(int votos, double porcentagem) {
    if(votos > 1){
        printf("%d votos de legenda ", votos);
    }else{
        printf("%d voto de legenda ", votos);
    }

    if(porcentagem > 0){
        printf("(%.2f%s do total do partido)\n", porcentagem, "%");
    }else{
        if(votos > 1){
            printf("(proporção não calculada, %d votos no partido)\n", votos);
        }else{
            printf("(proporção não calculada, %d voto no partido)\n", votos);
        }
    }
}

void Relatorios::assiteRelatorio8(Candidato *c){
    if(c->getVotosNominais() > 1){
        printf("%s (%s, %d votos)", c->nomeUrna.c_str(), c->numero.c_str(), c->getVotosNominais());
    }else{
        printf("%s (%s, %d voto)",  c->nomeUrna.c_str(), c->numero.c_str(), c->getVotosNominais());
    }
}

void Relatorios::relatorio1(Cidade *cidade){
    printf("Número de vagas: %d\n\n", cidade->numeroEleitos);
}

void Relatorios::relatorio2(Cidade *cidade){
    printf("Vereadores Eleitos: \n");

    cidade->eleitos.sort([] (Candidato* c1, Candidato* c2){
        if(c1->getVotosNominais() == c2->getVotosNominais()){
            return c1->idade > c2->idade;
        }

        return c1->getVotosNominais() > c2->getVotosNominais();
    });

    this->formatacaoRelatorios2_5(cidade, 2, cidade->eleitos);


}
void Relatorios::relatorio3(Cidade *cidade){
    printf("Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):\n");
    list<Candidato*> maisVotados = cidade->maisVotadosGeral(0, cidade->eleitos.size());
    this->formatacaoRelatorios2_5(cidade, 3, maisVotados);


}

void Relatorios::relatorio4(Cidade *cidade){
    printf("Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n");
    printf("(com sua posição no ranking de mais votados)\n");
    list<Candidato*> maisVotados = cidade->maisVotadosGeral(0, cidade->eleitos.size());
    this->formatacaoRelatorios2_5(cidade, 4, maisVotados);
}

void Relatorios::relatorio5(Cidade *cidade){
    printf("Eleitos, que se beneficiaram do sistema proporcional:\n");
    printf("(com sua posição no ranking de mais votados)\n");
    list<Candidato*> maisVotados = cidade->maisVotadosGeral(cidade->eleitos.size(), cidade->qtdCandidatosCadastados);
    this->formatacaoRelatorios2_5(cidade, 5, maisVotados);
}

void Relatorios::relatorio6(Cidade *cidade){
    int contador = 0;
    printf("Votação dos partidos e número de candidatos eleitos:\n");
    list<Partido*> relatorio6 = cidade->resumoPartidos();

    relatorio6.sort([](Partido *p1, Partido* p2){
        if(p1->getVotosTotais() == p2->getVotosTotais()){
            return p1->numeroPartido > p2->numeroPartido;
        }

        return p1->getVotosTotais() > p2->getVotosTotais();
    });

    for(Partido *p: relatorio6){
        contador++;
        printf("%d - %s - %d, ", contador, p->sigla.c_str(), p->numeroPartido);
        this->assisteRelatorio6(p->getVotosTotais(), p->getVotosNominais(), p->getVotosLegenda(), p->qtdEleitos);
    }
    printf("\n");
}

void Relatorios::relatorio7(Cidade *cidade){
    int contador = 0;
    printf("Votação dos partidos (apenas votos de legenda):\n");
    list<Partido*> relatorio7 = cidade->resumoPartidos();

    relatorio7.sort([] (Partido* p1, Partido* p2){
       if(p1->getVotosLegenda() == p2->votosLegenda){
           if(p1->getVotosNominais() == p2->getVotosNominais()){
               return p1->getNumeroPartido() > p2->getNumeroPartido();
           }
           return p1->getVotosNominais() > p2->getVotosNominais();
       }
       return p1->getVotosLegenda() > p2->votosLegenda;
    });

    for(Partido* p: relatorio7){
        contador++;
        double porcentagem = ((p->getVotosLegenda() * 100.0) / (p->getVotosTotais() * 1.0));
        printf("%d - %s - %d, ", contador, p->sigla.c_str(), p->numeroPartido);
        this->assisteRelatorio7(p->votosLegenda, porcentagem);
    }
    printf("\n");
}

void Relatorios::relatorio8(Cidade *cidade){
    int contador = 0;
    printf("Primeiro e último colocados de cada partido:\n");

    list<Partido*> relatorio8 = cidade->resumoPartidos();
    relatorio8.sort([](Partido* p1, Partido* p2){
        if(p1->getQtdMaisVotado() == p2->getQtdMaisVotado()){
            return p1->numeroPartido < p2->numeroPartido;
        }
        return p1->getQtdMaisVotado() > p2->getQtdMaisVotado();
    });

    for(Partido *p: relatorio8){
        if(p->getMaisVotado() != NULL && p->getMenosVotado() != NULL){
            contador++;
            printf("%d - %s - %d, ", contador, p->sigla.c_str(), p->numeroPartido);
            this->assiteRelatorio8(p->getMaisVotado());
            printf(" / ");
            this->assiteRelatorio8(p->getMenosVotado());
            printf("\n");
        }
    }
    printf("\n");
}

void Relatorios::relatorio9(Cidade *cidade){

    int qtdMenor30Anos = 0;
    int qtd30_40Anos = 0;
    int qtd40_50Anos = 0;
    int qtd50_60Anos = 0;
    int qtdMaior60Anos = 0;
    double porcentagem30, porcentagem30_40, porcentagem40_50, porcentagem50_60, porcentagem60;

    for(Candidato* c : cidade->eleitos){
        if(c->idade < 30){
            qtdMenor30Anos++;
        }

        if(c->idade >= 30 && c->idade < 40){
            qtd30_40Anos++;
        }

        if(c->idade >= 40 && c->idade < 50){
            qtd40_50Anos++;
        }

        if(c->idade >= 50 && c->idade < 60){
            qtd50_60Anos++;
        }

        if(c->idade >= 60){
            qtdMaior60Anos++;
        }
    }

    porcentagem30 = (qtdMenor30Anos * 100.0) / cidade->eleitos.size();
    porcentagem30_40 = (qtd30_40Anos * 100.0) / cidade->eleitos.size();
    porcentagem40_50 = (qtd40_50Anos * 100.0) / cidade->eleitos.size();
    porcentagem50_60 = (qtd50_60Anos * 100.0) / cidade->eleitos.size();
    porcentagem60 = (qtdMaior60Anos * 100.0) / cidade->eleitos.size();

    printf("Eleitos, por faixa etária (na data da eleição):\n");
    printf("      Idade < %d: %d (%.2f%s)\n", 30, qtdMenor30Anos, porcentagem30, "%");
    printf("%d <= Idade < %d: %d (%.2f%s)\n", 30, 40, qtd30_40Anos, porcentagem30_40, "%");
    printf("%d <= Idade < %d: %d (%.2f%s)\n", 40, 50, qtd40_50Anos, porcentagem40_50, "%");
    printf("%d <= Idade < %d: %d (%.2f%s)\n", 50, 60, qtd50_60Anos, porcentagem50_60, "%");
    printf("%d <= Idade\t: %d (%.2f%s)\n", 60, qtdMaior60Anos, porcentagem60, "%");
    printf("\n");

}

void Relatorios::relatorio10(Cidade *cidade){
    int genM = 0, genF = 0;
    double porcentagemF, porcentagemM;

    for(Candidato*c : cidade->eleitos){
        if(c->sexo == 'F'){
            genF++;
        }else if(c->sexo == 'M'){
            genM++;
        }
    }

    porcentagemF = (genF * 100.0) / (genF + genM);
    porcentagemM = (genM * 100.0) / (genF + genM);
    printf("Eleitos, por sexo:\n");
    printf("Feminino:  %d (%.2f%s)\n", genF, porcentagemF, "%");
    printf("Masculino: %d (%.2f%s)\n", genM, porcentagemM, "%");
    printf("\n");
}

void Relatorios::relatorio11(Cidade *cidade){
    int votosNominaisTotal = cidade->getVotosNominaisTotal();
    int votosLegendaTotal = cidade->getVotosLegendaTotal();
    int votosValidos = votosNominaisTotal + votosLegendaTotal;
    double porcentagemNominal, porcentagemLegenda;

    porcentagemNominal = (votosNominaisTotal * 100.0) / votosValidos;
    porcentagemLegenda = (votosLegendaTotal * 100.0) / votosValidos;

    printf("Total de votos válidos:    %d\n", votosValidos);
    printf("Total de votos nominais:   %d (%.2f%s)\n", votosNominaisTotal, porcentagemNominal, "%");
    printf("Total de votos de legenda: %d (%.2f%s)\n", votosLegendaTotal, porcentagemLegenda, "%");
}

