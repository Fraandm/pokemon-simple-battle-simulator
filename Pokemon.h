/* 
 * File:   Pokemon.h
 * Author: Franco
 *
 * Created on 13 de noviembre de 2022, 09:17 PM
 */

#ifndef POKEMON_H
#define POKEMON_H

struct Pokemon{
    int id;
    char *name;
    char *type1;
    char *type2;
    int totalStats;
    int stat[6];
    int gen;
    char *isLegendary;
    struct Movement movements[200];
    int movLvl[200];
    struct Movement moveset[4];
};

#endif /* POKEMON_H */

