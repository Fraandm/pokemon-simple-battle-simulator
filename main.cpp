/* 
 * File:   main.cpp
 * Author: Franco
 *
 * Created on 13 de noviembre de 2022, 09:16 PM
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;

struct Movement{
    int id;
    char *name;
    int type;
    int power;
    int powerpoints;

};

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

void gotoXY(int x,int y){
    HANDLE hCon;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void bordes(){
    char hori=205;
    char vert=186;
    char e1=201,e2=200,e3=187,e4=188;
    //horizontal
    for(int i = 0;i<119;i++){
        if(i==0){
            gotoXY(i,0);
            cout<<e1;}
        else{
            if(i==118){
            gotoXY(i,0);
            cout<<e3;    
            }
            else{gotoXY(i,0);
            cout<<hori;}
        }       
    }
    //vertical
    for(int i=1;i<43;i++){
        gotoXY(0,i);
        cout<<vert;
        gotoXY(118,i);
        cout<<vert;
    }
    //linea abajo
    for(int i = 0;i<119;i++){
        if(i==0){
            gotoXY(i,42);
            cout<<e2;}
        else{
            if(i==118){
            gotoXY(i,42);
            cout<<e4;    
            }
            else{gotoXY(i,42);
            cout<<hori;}
        }       
    }
}

void box(){
    char hori=205;
    char vert=186;
    char e1=201,e2=200,e3=187,e4=188;
    //horizontal
    for(int i = 2;i<117;i++){
        if(i==2){
            gotoXY(i,36);
            cout<<e1;}
        else{
            if(i==116){
            gotoXY(i,36);
            cout<<e3;    
            }
            else{gotoXY(i,36);
            cout<<hori;}
        }       
    }
    //vertical
    for(int i=37;i<41;i++){
        gotoXY(2,i);
        cout<<vert;
        gotoXY(116,i);
        cout<<vert;
    }
    //linea abajo
    for(int i = 2;i<117;i++){
        if(i==2){
            gotoXY(i,41);
            cout<<e2;}
        else{
            if(i==116){
            gotoXY(i,41);
            cout<<e4;    
            }
            else{gotoXY(i,41);
            cout<<hori;}
        }       
    }    
}

void atackBox(int x,int y,int i,struct Movement *moves){
    char hori=205;
    char vert=186;
    char e1=201,e2=200,e3=187,e4=188;
    //horizontal
    for(int i = x;i<x+20;i++){
        if(i==x){
            gotoXY(i,y);
            cout<<e1;}
        else{
            if(i==x+19){
            gotoXY(i,y);
            cout<<e3;    
            }
            else{gotoXY(i,y);
            cout<<hori;}
        }       
    }
    //vertical
    for(int i=y+1;i<y+3;i++){
        gotoXY(x,i);
        cout<<vert;
        gotoXY(x+19,i);
        cout<<vert;
    }
    //linea abajo
    for(int i = x;i<x+20;i++){
        if(i==x){
            gotoXY(i,y+3);
            cout<<e2;}
        else{
            if(i==x+19){
            gotoXY(i,y+3);
            cout<<e4;    
            }
            else{gotoXY(i,y+3);
            cout<<hori;}
        }       
    }
    gotoXY(x+1,y+1);
    cout<<i+1<<"|"<<moves[i].name;
    gotoXY(x+1,y+2);
    cout<<"Power: "<<moves[i].power<<'|'<<"PP: "<<moves[i].powerpoints;
}

void pintarLogo(int x,int y){
gotoXY(x,y);cout<<"                                                    ,                                            ";
gotoXY(x,y+1);cout<<"                                                    &&&&                                         ";
gotoXY(x,y+2);cout<<"                                   *     *      **&&,  *                                         ";
gotoXY(x,y+3);cout<<"         *&&&&&&&&&*           &&&&&&   &&&       ****       &&&&   &&&        *      *          ";
gotoXY(x,y+4);cout<<"    *&&&&&&&&&&&&&&&&&      ***  &&&& &&&&&&* *&&&&&&&&&&   *&&&&& &&&& *      * *&&&&&  **      ";
gotoXY(x,y+5);cout<<" ***  &&&&&&&&&    &&&&     **** *&&&&&&&&&  *&&&   &&&* ** &&&&&&&&&&&   .      *&&&&&   &&&&*  ";
gotoXY(x,y+6);cout<<"  ****** &&&&&&&&&  *&&   *&&&&   &&&&&&  *  &&&&&&&&  **  *&&&&&&&&&&&  &&&&&&&&  &&&&* *&&&* * ";
gotoXY(x,y+7);cout<<"   ****** *&&&&&&&&&&  &&& ,&&&&&& &&&&&&&&&* &&&&&&&&&&&* *&&&**&&&&& &&&&     &&* &&&&&&&&&    ";
gotoXY(x,y+8);cout<<"     * ***  &&&&&&*   &&&&&    &&& &&   &&&&&&*         *  &&&&* && *& &&&&&&&&&&* &&*&&&&&&     ";
gotoXY(x,y+9);cout<<"        *** &&&&&& ** *&&&&&&&&&& &&&  **   &&&&&&* *****  **** *    && *&&&&&&&**&&* &&&&&      ";
gotoXY(x,y+10);cout<<"         *** *&&&&  **  &&&&&&&   &&&  *******   &*     ************ &&&&     *  &&&  &&&&*      ";
gotoXY(x,y+11);cout<<"          ***  &&&&* ****************       ******                *****************   &&&&       ";
gotoXY(x,y+12);cout<<"           *****&&     *****   ******            **                 ******    ******   **        ";
gotoXY(x,y+13);cout<<"            ***  ***                                                               ******        ";
gotoXY(x,y+14);cout<<"             *****                                                                     **        ";
}

void pintar0(int x,int y){
gotoXY(x,y );cout<<"                          @@@                     ";
gotoXY(x,y+1 );cout<<"                       @@@@@ @                    ";
gotoXY(x,y+2 );cout<<"                       @@ ,,,@,,@@@@              ";
gotoXY(x,y+3 );cout<<"                  ,@@,,  ,  ,,@@@,,,,,,@@@        ";
gotoXY(x,y+4 );cout<<"               @  ,   ,  ,  ,,,,,,,,@@@,,,,@/     ";
gotoXY(x,y+5 );cout<<"             .,   ,  , ,, ,,,,,,,,,,,,,@  ,,#@    ";
gotoXY(x,y+6 );cout<<"      @@@@@  #@,@@@@@@,,,@@@  ,,@,,,,,,,@@ ,. @   ";
gotoXY(x,y+7 );cout<<"     @  ,@@@,,,,@@@,,,,,,   ,,,,@,,,,,,,,,@,. @   ";
gotoXY(x,y+8 );cout<<"    @,,,,,,,,,,@@@,,,,,,,,,,,,,,,@@,,,,,,,@,,,@   ";
gotoXY(x,y+9 );cout<<"    @,,,,,,,,,,,,,,@@,,@@@,,,,,,,@@,,,,,@@,,#@    ";
gotoXY(x,y+10 );cout<<"    @ @@,,,@@(,,,,@,,@@     @,,,,,,@@*,@,,,@/     ";
gotoXY(x,y+11 );cout<<"  @@, ((@,,,,,,,,,,@@ (@@   @,,,,,,@,,,,,,,@/     ";
gotoXY(x,y+12 );cout<<"  @@,,,,@,,,,%@,,,,,,,,,,,@@@@,,,,,,,,,,,,,,#@    ";
gotoXY(x,y+13 );cout<<"    @@***,,*******@@@@@..@((@@,,,@@,,**,,,,**,@   ";
gotoXY(x,y+14 );cout<<"     @@@,@@@@@@@((((((((((@@,,,,@@@@,,,@,,,@(,@   ";
gotoXY(x,y+15 );cout<<"    @,,,,@@@,,,@@@@@@@@,,,,,@@,,,,,@@*,@@@,,,,,@@ ";
gotoXY(x,y+16 );cout<<"    @,,,,,,,,,,@@@@@@@@   @@@,,,,,,,,,,@@@,,#@@   ";
gotoXY(x,y+17 );cout<<"  @@.%..,,,%***             @.%%.,,,%**   **.     ";
gotoXY(x,y+18 );cout<<"    @@@@@@@                  @@@@@@@              ";
cout<<endl;
}
void pintar1(int x,int y){

gotoXY(x,y );cout<<"                       ,##              ,#%@@@@#/,       ";
gotoXY(x,y+1 );cout<<"                ( (# #(#            *(##@@@#######(*    ";
gotoXY(x,y+2 );cout<<"              #,#/(/###            ,############## %    ";
gotoXY(x,y+3 );cout<<"             ###/(###               ############## .    ";
gotoXY(x,y+4 );cout<<"           .####/(/(              ,###############. #   ";
gotoXY(x,y+5 );cout<<"           #/####/(/#              ###################/ ";
gotoXY(x,y+6 );cout<<"          #.#.###/#/(/.           /#############((.. *  ";
gotoXY(x,y+7 );cout<<"          ######///#/(#          (###########////..     ";
gotoXY(x,y+8 );cout<<"           ####////#/#         /%###########/*          ";
gotoXY(x,y+9 );cout<<"             #.//.#          /&%&##########@@&/         ";
gotoXY(x,y+10 );cout<<"             *###          .@%@###########/######.      ";
gotoXY(x,y+11 );cout<<"            ,/###/,       /&%&%#############..##///.    ";
gotoXY(x,y+12 );cout<<"             @####.      @#@#############@@@*   /*(*    ";
gotoXY(x,y+13 );cout<<"            /*@&####//   ,,/###########&@@@#/           ";
cout<<endl; 
}

void pintarRed(int x,int y){
gotoXY(x,y);cout<<"                       %&&&&##                    ";
gotoXY(x,y+1);cout<<"                *@@@*************%@               ";
gotoXY(x,y+2);cout<<"             &@@&####(*(#********%@               ";
gotoXY(x,y+3);cout<<"          @%#############**#*******@@             ";
gotoXY(x,y+4);cout<<"          @%###########**#(*(#*****@@@@@          ";
gotoXY(x,y+5);cout<<"           *###@@@@@##########       @@@          ";
gotoXY(x,y+6);cout<<"           /@############@@@@@###&@@@             ";
gotoXY(x,y+7);cout<<"           /@@@@@@@@@@@@@@@@/*@% #@               ";
gotoXY(x,y+8);cout<<"             &@@@@@@@@@@@@@@/*@%   ##             ";
gotoXY(x,y+9);cout<<"               #%@@@@@@##********%@               ";
gotoXY(x,y+10);cout<<"          #%@@@@@@#####&@@&###@&#,                ";
gotoXY(x,y+11);cout<<"     (/*##***********(@@@##@, &&(.                ";
gotoXY(x,y+12);cout<<"     @%#**#/*##*/#**@@@##@&*     #@               ";
gotoXY(x,y+13);cout<<"   @@@@@...(@#####@@#####@&***&%.  ..&&&...  &&   ";
gotoXY(x,y+14);cout<<" #@  ###@@@@@@@@@@#######@&*&@*,     @(*     &@   ";
gotoXY(x,y+15);cout<<" #@@@###########%@#####&@&&&//*****   (&..(,   &# ";
gotoXY(x,y+16);cout<<"   @@###########%@###%@####@/*********%@   /@**@# ";
gotoXY(x,y+17);cout<<"   .,&&&##########&&&&#&&/(&,.&%*****&&@%%.....   ";
gotoXY(x,y+18);cout<<"        @@@@@@@@@@##@&###@%    .@@@@@@*           ";
}

void pintarBlue(int x,int y){
gotoXY(x,y);cout<<"                       (      @(*#,         ";
gotoXY(x,y+1);cout<<"                      #*@@#/***(%.          ";
gotoXY(x,y+2);cout<<"                 @*(%@**((/(((//(((((#      ";
gotoXY(x,y+3);cout<<"                  %(//****//**/(#((////(#,  ";
gotoXY(x,y+4);cout<<"                  ,/(***#/(((#(///##((      ";
gotoXY(x,y+5);cout<<"                  @#/%,#/@@&#(/@,((/##      ";
gotoXY(x,y+6);cout<<"   @@&             /@@/#..,,,.,,,,(#        ";
gotoXY(x,y+7);cout<<" @##,*#@@////*         @#..,/%*,/&*         ";
gotoXY(x,y+8);cout<<"@/,*##*/(#.....,,/@%(((%((##/@@             ";
gotoXY(x,y+9);cout<<"     .@#    *@@/,,%#((((((#(/%%@@,          ";
gotoXY(x,y+10);cout<<"                 %%%%#&#((((((%(%.          ";
gotoXY(x,y+11);cout<<"                       @%%%#(((((&*         ";
gotoXY(x,y+12);cout<<"                       @%%%%%((%%@*         ";
gotoXY(x,y+13);cout<<"                        @%%%%%%%%%@@   ##.  ";
gotoXY(x,y+14);cout<<"                       ((((*,,((@@@@(@#,/,.@";
gotoXY(x,y+15);cout<<"                      ,,,,,,,((%%%%%@/,/@@@ ";
gotoXY(x,y+16);cout<<"                     ..    .,/%@####%%      ";
gotoXY(x,y+17);cout<<"                      @((#((((#######@      ";
gotoXY(x,y+18);cout<<"                    ,#**#****(@#######@     ";
gotoXY(x,y+19);cout<<"                    ,###*****@@#######@     ";
gotoXY(x,y+20);cout<<"                    ,#/****/#  @#######@.   ";
gotoXY(x,y+21);cout<<"                   *(((**((*    #######@    ";
gotoXY(x,y+22);cout<<"                  #(((#/(%*    ,@%##((#     ";
gotoXY(x,y+23);cout<<"                 #/((((#@      @####((@     ";
gotoXY(x,y+24);cout<<"                #(#(((#@        @%#####@    ";
gotoXY(x,y+25);cout<<"                @(#####@        @%###(@@.   ";
gotoXY(x,y+26);cout<<"                @%%#((@@          #@@%%%%@@ ";    
}

void line(ofstream &arch,char c){
    for(int i=0;i<=75;i++){
        arch.put(c);
    }
    arch<<endl;
}

char * assignString(const char *buffer){
    char * str;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

void guion(char *buffer){
    char aux[strlen(buffer)+1];
    if(not(buffer[0]>='0' and buffer[0]<='9'))aux[0]=buffer[0]+('A'-'a');
    else{aux[0]=buffer[0];}
    for(int i=1;i<=strlen(buffer);i++){
        if(buffer[i]=='-'){
            aux[i]=' ';
            if(buffer[i+1]>='a' and buffer[i+1]<='z'){
                aux[i+1]=buffer[i+1]+('A'-'a');
                i++;
            }
        }
        else{
            aux[i]=buffer[i];
        }
    }
    aux[strlen(buffer)+1]=0;
    strcpy(buffer,aux);
}

void readLine(ifstream &arch,struct Pokemon &poke){
    char aux[20];
    //id
    arch>>poke.id;
    arch.get();
    //name
    arch.getline(aux,20,',');
    poke.name=assignString(aux);
    //type1
    arch.getline(aux,20,',');
    poke.type1=assignString(aux);
    //type2
    arch.getline(aux,20,',');
    poke.type2=assignString(aux);
    //total stats
    arch>>poke.totalStats;    
    arch.get();
    //individual stats
    for(int i=0;i<=5;i++){
        arch>>poke.stat[i];
        arch.get();
    }
    //generation
    arch>>poke.gen;
    arch.get();
    //is legendary?
    arch.getline(aux,20,'\n');
    poke.isLegendary=assignString(aux);
    arch>>ws;
}

void fillPokemons(struct Pokemon *PokeList,int &cant){
    struct Pokemon aux;
    struct Movement maux;
    ifstream pokes("pokemon.csv",ios::in);
    ifstream pokemove("pokemon_moves.csv",ios::in);
    while(1){
        if(pokes.eof())break;
        readLine(pokes,aux);
        PokeList[cant]=aux;
        //cout<<PokeList[cant].name<<endl;
        pokes>>ws;
        cant++;
        }
}

void lineMove(ifstream &arch,struct Movement &move){
    char aux[40];
    //id
    arch>>move.id;
    arch.get();
    //nombre
    arch.getline(aux,40,',');
    guion(aux);
    move.name=assignString(aux);
    //tipo
    arch>>move.type;  
    arch.get();
    //power
    arch>>move.power;
    if(arch.fail())arch.clear();
    arch.get();
//    arch.getline(aux,40,',');
//    if(strlen(aux)==0)strcpy(aux,"--");
//    move.power=assignString(aux);
    //powerpoints
    arch>>move.powerpoints;
    arch>>ws;
}

void fillMoves(struct Movement *MoveList,int &cant){
    struct Movement aux;
    ifstream moves("moves.csv",ios::in);
    while(1){
        if(moves.eof())break;
        lineMove(moves,aux);
        MoveList[cant]=aux;
        //cout<< MoveList[cant].name<<"  "<<MoveList[cant].power<<endl;
        moves>>ws;
        cant++;
    }
}

void pkmoves(struct Pokemon *pk,struct Movement *move,int cantpk){
    struct Movement aux;
    int pkid,mvid,mvlvl;
    bool leerId=1;
    int id=1;
    ifstream pkmove("pokemon_moves.csv",ios::in);
     ofstream xd("xd.txt",ios::out);
    for(int i=0;i<=cantpk;i++){
        for(int j=0;j<200;j++){
            if(leerId)pkmove>>pkid; 
            if(pkmove.eof() or not(pkid==pk[i].id)){
                leerId=0;
                id++;
                pkid=id;
                break;}
            pkmove.get();
            pkmove>>mvid;
            pkmove.get();
            pkmove>>mvlvl;
            aux=move[mvid-1];
            pk[i].movements[j]=aux;
            pk[i].movLvl[j]=mvlvl;         
            xd<<pk[i].name<<" "<<pk[i].movements[j].name<<" "<<pk[i].movLvl[j]<<endl;           
            leerId=1;      
        }
    }
}

void compare(int *A,int *B,struct Pokemon *list,ofstream &out){
    out<<"Resumen de estadisticas"<<endl;
    line(out,'=');
    out<<"Equipo A"<<endl;
    int rapA=0,defA=0,ofA=0,lentA=300;
    int idA[4];
    for(int i=0;i<6;i++){
        //out<<setw(4)<<list[A[i]].stat[5]<<setw(4)<<list[A[i]].stat[2]<<setw(4)<<list[A[i]].stat[1]<<endl;
        if(list[A[i]].stat[5]>rapA){
            rapA=list[A[i]].stat[5];
            idA[0]=A[i];
        }
        if(list[A[i]].stat[2]>defA){
            defA=list[A[i]].stat[2];
            idA[1]=A[i];
        }
        if(list[A[i]].stat[1]>ofA){
            ofA=list[A[i]].stat[1];
            idA[2]=A[i];
        }
        if(list[A[i]].stat[5]<lentA){
            lentA=list[A[i]].stat[5];
            idA[3]=A[i];
        }
    }
    //
    //idA[3]=3;
    //
    out<<"Pokemon mas rapido: "<<list[idA[0]].name<<endl;
    out<<"Pokemon mas defensivo: "<<list[idA[1]].name<<endl;
    out<<"Pokemon mas ofensivo: "<<list[idA[2]].name<<endl;
    out<<"Pokemon mas lento: "<<list[idA[3]].name<<endl;
    
    out<<"Moveset del pokemon mas lento: "<<endl;
    struct Movement movesA[4];
    out<<endl;
    line(out,'-');
    int tam=0;
    for(int i=0;i<200;i++){
        if(list[idA[3]].movements[i].id>0)tam++;
    }
    //cout<<tam<<endl;
    for(int i=1;i<=4;i++){
        int jeje=rand()%tam;
        out<<'|'<<setw(20)<<left<<list[idA[3]].movements[jeje].name<<'|';
        movesA[i-1]=list[idA[3]].movements[jeje];
        if(list[idA[3]].movements[jeje].power==0)out<<setw(40)<<left<<"Movimiento de estado o de poder variable"<<'|'<<endl;
        else{out<<list[idA[3]].movements[jeje].power<<endl;}
        line(out,'-');
    }
    out<<endl;
    //
    line(out,'=');
    out<<"Equipo B"<<endl;
    int rapB=0,SdefB=0,SofB=0,lentB=300;
    int idB[4];
    for(int i=0;i<6;i++){
        //out<<setw(4)<<list[B[i]].stat[5]<<setw(4)<<list[B[i]].stat[4]<<setw(4)<<list[B[i]].stat[3]<<endl;
        if(list[B[i]].stat[5]>rapB){
            rapB=list[B[i]].stat[5];
            idB[0]=B[i];
        }
        if(list[B[i]].stat[4]>SdefB){
            SdefB=list[B[i]].stat[4];
            idB[1]=B[i];
        }
        if(list[B[i]].stat[3]>SofB){
            SofB=list[B[i]].stat[3];
            idB[2]=B[i];
        }
        if(list[B[i]].stat[5]<lentB){
            lentB=list[B[i]].stat[5];
            idB[3]=B[i];
        }
    }
    //
    //idB[3]=0;
    //
    out<<"Pokemon mas rapido: "<<list[idB[0]].name<<endl;
    out<<"Pokemon mas especialmente defensivo: "<<list[idB[1]].name<<endl;
    out<<"Pokemon mas especialmente ofensivo: "<<list[idB[2]].name<<endl;
    out<<"Pokemon mas lento: "<<list[idB[3]].name<<endl;
    
    out<<"Moveset del pokemon mas lento: "<<endl;
    struct Movement movesB[4];
    out<<endl;
    line(out,'-');
    tam=0;
    for(int i=0;i<200;i++){
        if(list[idB[3]].movements[i].id>0)tam++;
    }
    //cout<<tam<<endl;
    for(int i=1;i<=4;i++){
        int jeje=rand()%tam;
         out<<'|'<<setw(20)<<left<<list[idB[3]].movements[jeje].name<<'|';
         movesB[i-1]=list[idB[3]].movements[jeje];
        if(list[idB[3]].movements[jeje].power==0)out<<"Movimiento de estado o de poder variable"<<endl;
        else{out<<list[idB[3]].movements[jeje].power<<endl;}
        line(out,'-');
    }
    out<<endl;
    //
    //Pantalla de inicio
    //
    pintarLogo(11,7);
    bordes();
    gotoXY(40,30);
    system("pause");
    system("cls");
    //
    
    //
    //Ingreso de los nombres
    //
    char Jugador[20],Rival[20];
    pintarLogo(11,7);
    bordes();
    gotoXY(40,30);
    cout<<"Ingresa tu nombre: ";
    cin>>Jugador;
    gotoXY(40,31);
    cout<<"Ingresa el nombre de tu rival: ";
    cin>>Rival;
    gotoXY(40,32);
    system("pause");
    system("cls");
    
    //
    //Inicio de combate con sprites de entrenadores
    //
    system("color 70");
    bordes();
    box();
    pintarBlue(68,1);
    pintarRed(4,17);
    gotoXY(3,38);
    system("pause");
    system("cls");
    //
    //Sistema de combate  
    //
    ofstream waza("waza.txt",ios::out);
    struct Pokemon TeamA[6]={
        list[A[0]],list[A[1]],list[A[2]],list[A[3]],list[A[4]],list[A[5]]
    };
    struct Pokemon TeamB[6]={
        list[B[0]],list[B[1]],list[B[2]],list[B[3]],list[B[4]],list[B[5]]
    };
    for(int i=0;i<6;i++){waza<<TeamB[i].name<<endl;}
    //generacion de movimientos de los equipos a y b
    for(int j=0;j<6;j++){
        tam=0;
        for(int i=0;i<200;i++){
            if(TeamA[j].movements[i].id>0)tam++;
        }
        for(int i=0;i<4;i++){
            int jeje=rand()%tam;
            TeamA[j].moveset[i]=TeamA[j].movements[jeje];
            //cout<<TeamA[j].moveset[i].name<<endl;
        }
    }
    for(int j=0;j<6;j++){
        tam=0;
        for(int i=0;i<200;i++){
            if(TeamB[j].movements[i].id>0)tam++;
        }
        for(int i=0;i<4;i++){
            int jeje=rand()%tam;
            TeamB[j].moveset[i]=TeamB[j].movements[jeje];
            //cout<<TeamB[j].moveset[i].name<<endl;
        }
    }
    system("cls");
    //pantalla de combate
        bool reiniciarHPa = true;
        bool reiniciarHPb = true;
        int hpA,hpB; 
        int nA=0;
        int nB=0;
        int pkResA=6;
        int pkResB=6;
    while(1){
        system("cls");
        
        if(reiniciarHPa){
        hpA=TeamA[nA].stat[0]*2;}
        if(reiniciarHPb){
        hpB=TeamB[nB].stat[0]*2;}
        int hpInicialA=TeamA[nA].stat[0]*2,hpInicialB=TeamB[nB].stat[0]*2;
        int porA,porB;
        int guiA,guiB;
        int opcionA,opcionB;
        int ppA[4]={TeamA[nA].moveset[0].powerpoints,TeamA[nA].moveset[1].powerpoints,TeamA[nA].moveset[2].powerpoints,TeamA[nA].moveset[3].powerpoints};

        while(hpA>0 and hpB>0){        
            //sprite del pokemon B   
                pintar0(60,1);
                //healthbar del pokemon rival
                gotoXY(65,21);
                cout<<TeamB[nB].name;
                cout<<" Hp:"<<hpB<<' ';
                porB=((double) hpB/ hpInicialB)*100;
                porB=porB/10;
                porB=porB*2;
                guiB=20-porB;
                cout.put('/');
                for(int i=1;i<=porB;i++){
                    cout.put('=');}
                for(int i=1;i<=guiB;i++){
                    cout.put('-');}
                cout.put('/');        
                //
             //sprite del pokemonA          
                pintar1(0,20);
                //healthbar del pokemon aliado
                cout<<endl;
                cout<<setw(10)<<" "<<setw(12)<<left<<TeamA[nA].name;
                cout<<" Hp:"<<hpA<<' ';
                porA=((double) hpA/ hpInicialA)*100;
                porA=porA/10;
                porA=porA*2;
                guiA=20-porA;
                cout.put('/');
                for(int i=1;i<=porA;i++){
                    cout.put('=');}
                for(int i=1;i<=guiA;i++){
                    cout.put('-');}
                cout.put('/');
                cout<<endl;
                cout<<endl;
                //
                bordes();
                box();
                atackBox(35,37,0,TeamA[nA].moveset);
                atackBox(55,37,1,TeamA[nA].moveset);
                atackBox(75,37,2,TeamA[nA].moveset);
                atackBox(95,37,3,TeamA[nA].moveset);
                gotoXY(3,38);
                cout<<"Elige el movimiento: ";
                cin>>opcionA;
             //   
                //ingreso de opcion de ataque pokemon aliado
                while(1){
                    if(opcionA<=4 and opcionA>=0 and TeamA[nA].moveset[opcionA-1].powerpoints>0)break;
                    if(opcionA>4 or opcionA<0){
                    gotoXY(3,38);
                    cout<<"Opcion de ataque invalida   "; 
                    gotoXY(3,39);
                    cout<<"Elige otro movimiento: ";
                    cin>>opcionA;
                    }
                    if(TeamA[nA].moveset[opcionA-1].powerpoints==0){
                    gotoXY(3,38);
                    cout<<"Ataque no disponible     "; 
                    gotoXY(3,39);
                    cout<<"Elige otro movimiento: ";
                    cin>>opcionA;
                    } 
                }
                opcionB=rand()&3;
                system("cls");

                //pantalla de movimientos
                           //sprite del pokemon B   
                            pintar0(60,1);
                            //healthbar del pokemon rival
                            gotoXY(65,21);
                            cout<<TeamB[nB].name;
                            cout<<" Hp:"<<hpB<<' ';
                            porB=((double) hpB/ hpInicialB)*100;
                            porB=porB/10;
                            porB=porB*2;
                            guiB=20-porB;
                            cout.put('/');
                            for(int i=1;i<=porB;i++){
                                cout.put('=');}
                            for(int i=1;i<=guiB;i++){
                                cout.put('-');}
                            cout.put('/');        
                            //
                        //sprite del pokemonA          
                            pintar1(0,20);
                            //healthbar del pokemon aliado
                            cout<<endl;
                            cout<<setw(10)<<" "<<setw(12)<<left<<TeamA[nA].name;
                            cout<<" Hp:"<<hpA<<' ';
                            porA=((double) hpA/ hpInicialA)*100;
                            porA=porA/10;
                            porA=porA*2;
                            guiA=20-porA;
                            cout.put('/');
                            for(int i=1;i<=porA;i++){cout.put('=');}
                            for(int i=1;i<=guiA;i++){cout.put('-');}
                            cout.put('/');
                            cout<<endl;
                            cout<<endl;
                            //
                        bordes();
                        box();
                        //
                //procesamiento de los movimientos        
                int time1=time(NULL);
                int critA=rand()%10;
                int critB=rand()%10;
                TeamA[nA].moveset[opcionA-1].powerpoints--;
                gotoXY(3,38);    
                if(critA>7){
                cout<<TeamA[nA].name<<" usa "<< TeamA[nA].moveset[opcionA-1].name<<" y resulta critico"<<endl;
                hpB=hpB -  TeamA[nA].moveset[opcionA-1].power*1.5;
                }
                else{
                cout<<TeamA[nA].name<<" usa "<< TeamA[nA].moveset[opcionA-1].name<<endl;
                hpB=hpB -  TeamA[nA].moveset[opcionA-1].power;
                }
                gotoXY(3,39);   
                if(critB>7){
                cout<<TeamB[nB].name<<" usa "<<TeamB[nB].moveset[opcionB].name<<" y resulta critico"<<endl;
                hpA=hpA - TeamB[nB].moveset[opcionB].power*1.5;
                }
                else{
                cout<<TeamB[nB].name<<" usa "<<TeamB[nB].moveset[opcionB].name<<endl;
                hpA=hpA - TeamB[nB].moveset[opcionB].power;
                }
                gotoXY(3,40);
                cout<<"...";
                bordes();
                while(1){
                    int time2=time(NULL);
                    if(time2==(time1+2))break;
                }           
                system("cls");
                //
        }
        //resultado de la batalla
        if(hpA<=0 and hpB<=0){//empate
            gotoXY(3,38);
            cout<<"Ambos pokemon han sido debilitados"<<endl;
            gotoXY(3,39);
            cout<<"El resultado es un empate"<<endl<<endl;
            reiniciarHPa=true;
            reiniciarHPb=true;
            pkResA--;
            pkResB--;         
            nA++;
            nB++;
            bordes();
            box();
            if(pkResA>=0 and pkResB>=0){
                gotoXY(3,40);
                cout<<Rival<<" saca a "<<TeamB[nB].name<<" y "<<Jugador<<" saca a "<<TeamA[nA].name<<endl;
            }
            int time1=time(NULL);
            while(1){
                    int time2=time(NULL);
                    if(time2==(time1+2))break;
                } 
        }
        else{
        if(hpA<=0){//Victoria del pokemon rival
            //sprite del pokemon B   
                pintar0(60,1);
                gotoXY(65,21);
                cout<<TeamB[nB].name;
                cout<<" Hp:"<<hpB<<' ';

                porB=((double) hpB/ hpInicialB)*100;
                porB=porB/10;
                porB=porB*2;
                guiB=20-porB;

                cout.put('/');
                for(int i=1;i<=porB;i++){
                    cout.put('=');}
                for(int i=1;i<=guiB;i++){
                    cout.put('-');}
                cout.put('/');                
                //
            //barra de vida del pokemon aliado;
                gotoXY(0,35);
                cout<<setw(10)<<" "<<setw(12)<<left<<TeamA[nA].name;
                cout<<" Hp:"<<0<<' ';
                porA=((double) hpA/ hpInicialA)*100;
                porA=porA/10;
                porA=porA*2;
                guiA=20-porA;
                if(guiA>20){guiA=20;}
                cout.put('/');
                for(int i=1;i<=porA;i++){
                    cout.put('=');}
                for(int i=1;i<=guiA;i++){
                    cout.put('-');}
                cout.put('/');
            //    
            gotoXY(3,38);
            cout<<TeamA[nB].name<<" no puede continuar"<<endl;
            gotoXY(3,39);
            cout<<TeamB[nB].name<<" es el ganador!"<<endl<<endl;
            reiniciarHPb=false;
            reiniciarHPa=true;
            pkResA--;
            nA++;
            bordes();
            box();
            if(nA<=5){
                gotoXY(3,40);
                cout<<Jugador<<" saca a "<<TeamA[nA].name<<endl;
            }
            int time1=time(NULL);
            while(1){
                    int time2=time(NULL);
                    if(time2==(time1+2))break;
                } 
        }
        if(hpB<=0){//Victoria del pokemon aliado
             //barra de vida del pokemon rival
                gotoXY(66,21);
                cout<<TeamB[nB].name;
                cout<<" Hp:"<<0<<' ';
                porB=((double) hpB/ hpInicialB)*100;
                porB=porB/10;
                porB=porB*2;
                guiB=20-porB;      
                if(guiB>20){guiB=20;}
                cout.put('/');
                for(int i=1;i<=porB;i++){
                    cout.put('=');}
                for(int i=1;i<=guiB;i++){
                    cout.put('-');}
                cout.put('/');
            //sprite del pokemon aliado                  
                pintar1(0,20);
                cout<<endl;
                cout<<setw(10)<<" "<<setw(12)<<left<<TeamA[nA].name;
                cout<<" Hp:"<<hpA<<' ';
                porA=((double) hpA/ hpInicialA)*100;
                porA=porA/10;
                porA=porA*2;
                guiA=20-porA;
                cout.put('/');
                for(int i=1;i<=porA;i++){
                    cout.put('=');}
                for(int i=1;i<=guiA;i++){
                    cout.put('-');}
                cout.put('/');
                cout<<endl;cout<<endl;
                //

            gotoXY(3,38);cout<<TeamB[nB].name<<" no puede continuar"<<endl;
            gotoXY(3,39);cout<<TeamA[nA].name<<" es el ganador!"<<endl<<endl;
            reiniciarHPa=false;
            reiniciarHPb=true;
            pkResB--;
            nB++;
            bordes();
            box();
            if(nB<=5){
                gotoXY(3,40);
                cout<<Rival<<" saca a "<<TeamB[nB].name<<endl;
            }
            int time1=time(NULL);
            while(1){
                    int time2=time(NULL);
                    if(time2==(time1+2))break;
                } 
        }
        }    
        system("cls");  
        bordes();
        box();
        pintarBlue(68,1);
        pintarRed(4,17);
        gotoXY(3,38);
        if((pkResA<=-1 and pkResB<=-1) or (nA>=6 and nB>=6)){
            cout<<"Ni "<<Jugador<<" ni "<<Rival<<" cuentan con mas pokemon para usar, el resultado es un empate ";
            gotoXY(3,39);
            system("pause");
            break;
        }
        else{
            if(pkResA<=-1 or nA>=6){
                cout<<Jugador<<" no cuenta con mas pokemon para usar,";
                cout<<Rival<<" gana el combate ";
                gotoXY(3,39);
                system("pause");
                break;
            }
            if(pkResB<=-1 or nB>=6){
                cout<<Rival<<" no cuenta con mas pokemon para usar,";
                cout<<Jugador<<" gana el combate ";
                gotoXY(3,39);
                system("pause");
                break;
            }
        }
    }        
    system("cls");    
    bordes();
    box();   
    gotoXY(3,38);
    system("pause");
    gotoXY(3,39);
}

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

