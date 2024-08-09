#include <iostream>
#include <cmath>
#include <ctime>
#include "Track.h"
using namespace std;

#ifndef GAME_RACER_H
#define GAME_RACER_H

class Racer{
public:
    struct Cell{
        int x;
        int y;
    };

    Cell cell;
    int litres;
    int meters;
    Track* track;

    Racer (Track* track){
        this->track=track;
        litres = 10;
        meters = 0;
        cell.x = 0;
        cell.y = track->size/2;
        track->tiles[0][track->size/2]='H';
        printXY();
        cout << "Litres: " << litres << endl;
        cout << "Meters: " << meters << endl;
    }

    void printXY(){
        cout<<"x: "<<cell.x<<" y: "<<cell.y<<endl;
    }

    char symbol(int c_x,int c_y){
        char sym;
        sym = track->tiles[cell.x+c_x][cell.y+c_y];
        return sym;
    }

    char changeCell(int c_x,int c_y){
        cell.x=cell.x+c_x;
        cell.y=cell.y+c_y;
        track->tiles[cell.x][cell.y] = 'H';
        return 0;
    }

    void return_all(){
        track->tiles[cell.x][cell.y] = random(track->tiles[cell.x][cell.y]);
        litres = 10;
        meters = 0;
        cell.x = 0;
        cell.y = track->size/2;
        track->tiles[0][track->size/2] = 'H';
    }

    virtual void changeRecord(){
        meters+=3;
    }

    virtual void changeLitres(char s){
        if (s=='x' || litres<1) {
            cout<<"\n"
                  "XXXXXXXXXX\n"
                  "GAME OVER.\n"
                  "XXXXXXXXXX"
                  "\n"<<endl;
            cout << "RECORD: " << meters << " meters" << endl; //TUUUUUUT POSMOTRIIIIIIIIII
            cout<<endl;
            cout<<"NEW GAME: "<<endl;
            cout<<endl;
            return_all();
        }
        if (s=='+') litres+=1;
        if (s=='*') litres+=5;
        if (s=='$') litres+=10;
        if (s=='-') litres-=1;
    }

    virtual void changeTrack(){
        for (int i=0;i+1<track->size;i++){
            for(int j=0;j<track->size;j++) track->tiles[i][j] = track->tiles[i+1][j];
        }
        for (int i=track->size-1;i<track->size;i++){
            for (int j=0;j<track->size;j++) track->tiles[i][j] = random(track->tiles[i][j]);
        }
    }

    virtual void Perform(int c_x,int c_y){
        char s;
//levelUp(s);
        if (((cell.y+c_y) < track->size) && ((cell.y+c_y)>=0)){
            changeTrack();
            s = symbol(c_x,c_y);
            changeCell(c_x,c_y);
            changeLitres(s);
            changeRecord();
            printXY();
            cout << "Litres: " << litres << endl;
            cout<< "Meters: " << meters << endl;
            track->printTrack();
        }
        else cout<<"You got out of the track. Try again."<<endl;
    }

    virtual void move(){
        char command = '0';
        game_rules();
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

class Overrunner: public Racer{
public:
    Track* track;

    Overrunner(Track *track1, Track *track) : Racer(track1) {
        this->track=track;
        litres = 10;
        meters = 0;
        cell.x = 0;
        cell.y = track->size/2;
        track->tiles[0][track->size/2]='H';
    }
    void move() override{
        char command = '0';
        game_rules();
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
            if (((cell.y+c_y) < track->size) && ((cell.y+c_y)>=0)){
                changeTrack();
                s = symbol(c_x,c_y);
                changeCell(c_x,c_y);
                changeLitres(s);
                changeRecord();
                track->printTrack();
                printXY();
                cout << "Litres : " << litres << endl;
                cout<< "Meters: " << meters << " meters" << endl;
            }
            else cout<<"You got out of the track. Try again."<<endl;
        }
        else {
            if (((cell.y+c_y) < track->size) && ((cell.y+c_y)>=0)){
                changeTrack2();
                s = symbol(c_x,c_y);
                changeCell(c_x,c_y);
                changeLitres2(s);
                changeRecord2();
                track->printTrack();
                printXY();
                cout << "Litres: " << litres << endl;
                cout<< "Meters: " << meters << " meters" << endl;
            }
            else cout<<"You got out of the track. Try again."<<endl;
        }
    }

    void changeTrack() override{
        for (int i=0;i+2<track->size;i++){
            for(int j=0;j<track->size;j++) track->tiles[i][j]=track->tiles[i+2][j];
        }
        for (int i=track->size-2;i<track->size;i++){
            for (int j=0;j<track->size;j++) track->tiles[i][j] = random(track->tiles[i][j]);
        }
    }

    void changeTrack2(){
        for (int i=0;i+1<track->size;i++){
            for(int j=0;j<track->size;j++) track->tiles[i][j]=track->tiles[i+1][j];
        }
        for (int i=track->size-1;i<track->size;i++){
            for (int j=0;j<track->size;j++) track->tiles[i][j] = random(track->tiles[i][j]);
        }
    }
    void changeRecord2(){
        meters+=5;
    }
    void changeLitres(char s) override{
        if (s=='x' || litres<1) {
            cout<<"\n"
                  "XXXXXXXXXX\n"
                  "GAME OVER.\n"
                  "XXXXXXXXXX"
                  "\n"<<endl;
            cout << "RECORD: " << meters << " meters" << endl;
            cout<<endl;
            cout<<"NEW GAME: "<<endl;
            cout<<endl;
            return_all();
        }
        if (s=='+') litres+=2;
        if (s=='*') litres+=7;
        if (s=='$') litres+=12;
        if (s=='-') litres-=1;
    }

    void changeLitres2(char s){
        if (s=='x' || litres<1) {
            cout<<"\n"
                  "XXXXXXXXXX\n"
                  "GAME OVER.\n"
                  "XXXXXXXXXX"
                  "\n"<<endl;
            cout << "RECORD: " << meters << " meters"<< endl;
            cout<<endl;
            cout<<"NEW GAME: "<<endl;
            cout<<endl;
            return_all();
        }
        if (s=='+') litres+=1;
        if (s=='*') litres+=5;
        if (s=='$') litres+=10;
        if (s=='-') litres-=1;
    }
};


#endif //GAME_RACER_H
