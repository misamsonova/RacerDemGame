#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include "Field.h"
using namespace std;

#ifndef FIELD_H
#define FIELD_H

    class Unit{
    public:
        struct Cell{
            int x;
            int y;
        };

        Cell cell;
        int score;
        Field* field;

        Unit (Field* field){
            this->field=field;
            score = 0;
            cell.x = 0;
            cell.y = field->size/2;
            field->tiles[0][field->size/2]='H';
            printXY();
            cout<<"Current score: "<<score<<endl;
        }

        void printXY(){
            cout<<"x: "<<cell.x<<" y: "<<cell.y<<endl;
        }

        char symbol(int c_x,int c_y){
            char sym;
            sym = field->tiles[cell.x+c_x][cell.y+c_y];
            return sym;
        }

        char changeCell(int c_x,int c_y){
            cell.x=cell.x+c_x;
            cell.y=cell.y+c_y;
            field->tiles[cell.x][cell.y] = 'H';
            return 0;
        }

        void return_coord(){
            field->tiles[cell.x][cell.y] = random(field->tiles[cell.x][cell.y]);
            score = 0;
            cell.x = 0;
            cell.y = field->size/2;
            field->tiles[0][field->size/2] = 'H';
        }

        virtual void changeRecord(char s){
            if (s=='x') {
                cout<<"\n"
                     "XXXXXXXXXX\n"
                     "GAME OVER.\n"
                     "XXXXXXXXXX"
                     "\n"<<endl;
                cout<<"FINAL SCORE: "<<score<<endl;
                cout<<endl;
                cout<<"NEW GAME: "<<endl;
                cout<<endl;
                return_coord();
            }
            else score+=1;
        }

        virtual void changeField(){
            for (int i=0;i+1<field->size;i++){
                for(int j=0;j<field->size;j++) field->tiles[i][j]=field->tiles[i+1][j];
            }
            for (int i=field->size-1;i<field->size;i++){
                for (int j=0;j<field->size;j++) field->tiles[i][j] = random(field->tiles[i][j]);
            }
        }

        virtual void Perform(int c_x,int c_y){
            char s;
//levelUp(s);
            if (((cell.y+c_y) < field->size) && ((cell.y+c_y)>=0)){
                changeField();
                s = symbol(c_x,c_y);
                changeCell(c_x,c_y);
                changeRecord(s);
                printXY();
                cout << "Current score = " << score << endl;
                field->printField();
            }
            else cout<<"You got out of the field. Try again."<<endl;
        }

        virtual void move(){
            char command = '0';
            instruction();
            while (command!='F') {
                cout<<"Enter the command or end the game by entering 'F'"<<endl;
                cin>>command;
                switch(command){
                    int c_x, c_y;
                    case 's':{
                        c_x=0; c_y=0;
                        Perform(c_x,c_y);
                        break;
                    }
                    case 'a':{
                        c_x=0; c_y=-1;
                        Perform(c_x,c_y);
                        break;
                    }
                    case 'd':{
                        c_x=0; c_y=1;
                        Perform(c_x,c_y);
                        break;
                    }
                    case 'F': break;
                    default: {
                        cout<<"Wrong command. Enter again."<<endl;
                        break;}
                }

            }

        }


    };

    class Overrunner: public Unit{
    public:
        Field* field;

        Overrunner(Field *field1, Field *field) : Unit(field1) {
            this->field=field;
            score = 0;
            cell.x = 0;
            cell.y = field->size/2;
            field->tiles[0][field->size/2]='H';
        }
        void move() override{
            char command = '0';
            instruction();
            while (command!='F') {
                cout<<"Enter the command or end the game by entering 'F'"<<endl;
                cin>>command;
                switch(command){
                    int c_x, c_y;
                    case 's':{
                        c_x=0; c_y=0;
                        Perform(c_x,c_y);
                        break;
                    }
                    case 'a':{
                        c_x=0; c_y=-2;
                        Perform(c_x,c_y);
                        break;
                    }
                    case 'd':{
                        c_x=0; c_y=2;
                        Perform(c_x,c_y);
                        break;
                    }
                    case 'F': break;
                    default: {
                        cout<<"Wrong command. Enter again."<<endl;
                        break;}
                }

            }
        }

        void Perform(int c_x,int c_y) override{
            char s;
//levelUp(s);
            if(c_y==0){
                if (((cell.y+c_y) < field->size) && ((cell.y+c_y)>=0)){
                    changeField();
                    s = symbol(c_x,c_y);
                    changeCell(c_x,c_y);
                    changeRecord(s);
                    field->printField();
                    printXY();
                    cout << "Current score : " << score << endl;
                }
                else cout<<"You got out of the field. Try again."<<endl;
            }
            else {
                if (((cell.y+c_y) < field->size) && ((cell.y+c_y)>=0)){
                    changeField2();
                    s = symbol(c_x,c_y);
                    changeCell(c_x,c_y);
                    changeRecord2(s);
                    field->printField();
                    printXY();
                    cout << "Current score : " << score << endl;
                }
                else cout<<"You got out of the field. Try again."<<endl;
            }
        }

        void changeField() override{
            for (int i=0;i+2<field->size;i++){
                for(int j=0;j<field->size;j++) field->tiles[i][j]=field->tiles[i+2][j];
            }
            for (int i=field->size-2;i<field->size;i++){
                for (int j=0;j<field->size;j++) field->tiles[i][j] = random(field->tiles[i][j]);
            }
        }

        void changeField2(){
            for (int i=0;i+1<field->size;i++){
                for(int j=0;j<field->size;j++) field->tiles[i][j]=field->tiles[i+1][j];
            }
            for (int i=field->size-1;i<field->size;i++){
                for (int j=0;j<field->size;j++) field->tiles[i][j] = random(field->tiles[i][j]);
            }
        }

        void changeLitres(char s) override{
            if (s=='x') {
                cout<<"\n"
                     "XXXXXXXXXX\n"
                     "GAME OVER.\n"
                     "XXXXXXXXXX"
                     "\n"<<endl;
                cout<<"FINAL SCORE: "<<score<<endl;
                cout<<endl;
                cout<<"NEW GAME: "<<endl;
                cout<<endl;
                return_coord();
            }
            else score+=2;
        }

        void changeLitres2(char s){
            if (s=='x') {
                cout<<"\n"
                     "XXXXXXXXXX\n"
                     "GAME OVER.\n"
                     "XXXXXXXXXX"
                     "\n"<<endl;
                cout<<"FINAL SCORE: "<<score<<endl;
                cout<<endl;
                cout<<"NEW GAME: "<<endl;
                cout<<endl;
                return_coord();
            }
            else score+=1;
        }
    };

#endif /*FIELD_H*/