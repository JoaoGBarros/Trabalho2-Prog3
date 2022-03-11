cmake_minimum_required(VERSION 3.19)
project(TrabPOO)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrabPOO main.cpp Partido.cpp headers/Partido.h Candidato.cpp headers/Candidato.h Data.cpp headers/Data.h Cidade.cpp headers/Cidade.h Relatorios.cpp headers/Relatorios.h LeituraCSV.cpp headers/LeituraCSV.h)