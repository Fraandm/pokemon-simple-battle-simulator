/* 
 * File:   main.cpp
 * Author: Franco
 *
 * Created on 13 de noviembre de 2022, 09:16 PM
 */

#include "funciones.h"
#include "Movement.h"
#include "Pokemon.h"

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    struct Pokemon PokemonsList[200];
    struct Movement MoveList[1000];
    int cantidadP=0,cantidadM=0;
    int TeamA[6],TeamB[6];
    int lvlA[6],lvlB[6];
    int idA,idB;
    int nvlA,nvlB;
    int psA=0,psB=0;
    fillPokemons(PokemonsList,cantidadP);
    fillMoves(MoveList,cantidadM);
    pkmoves(PokemonsList,MoveList,cantidadP);
    ofstream battle("Batalla.txt",ios::out);
    battle<<"Resumen de batalla pokemon"<<endl;
    line(battle,'=');
    battle<<setw(15)<<"Team A"<<setw(26)<<"Team B"<<endl;
    for(int i=0;i<6;i++){
        idA=rand()%150;
        idB=rand()%150;
        nvlA=rand()%14+50;
        nvlB=rand()%14+50;
        TeamA[i]=idA;
        TeamB[i]=idB;
        lvlA[i]=nvlA;
        lvlB[i]=nvlB;
        battle<<left<<setw(15)<<PokemonsList[idA].name<<" lvl "<<nvlA<<"  |  "
                                   <<setw(15)<<PokemonsList[idB].name<<" lvl "<<nvlB<<"  |"<<endl;
        psA=psA+PokemonsList[idA].stat[0];
        psB=psB+PokemonsList[idB].stat[0];
    }
    line(battle,'=');
    battle<<right<<setw(12)<<psA<<" hp"<<setw(23)<<psB<<" hp"<<endl;
    line(battle,'=');
    compare(TeamA,TeamB,PokemonsList,battle);
    line(battle,'=');
    if(psA>psB){battle<<"Equipo A ganador"<<endl;}
    else{battle<<"Equipo B ganador"<<endl;}
    
    return 0;
}

