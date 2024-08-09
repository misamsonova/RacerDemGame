#include <iostream>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

#ifndef GAME_TRACK_H
#define GAME_TRACK_H

char random(char a) {
    if (rand() % 100 < 20) a = 'x';
    else {
        if (rand() % 100 < 40) a = '+';
        else {
            if (rand() % 100 < 60) a = '-';
            else {
                if (rand() % 100 < 80) a = '*';
                else a = '~';
                }
            }
        }
        return a;
    }

    void game_rules(){
        cout<<"'-' - none bonus.\n"
             "'x' - death or game over.\n"
             "'+' - plus 1 litre.\n"
             "'*' - plus 5 litres.\n"
             "'$' - plus 10 litres"<<endl;
    }


    class Track{
    public:
        int size;
        char** tiles;

        Track(int size){
            int m_size;
            this->size=size;
            m_size = size/2;
            tiles = new char* [size];
            for (int i=0; i<size;i++){
                tiles[i] = new char[size];
                for (int j=0; j<size;j++) tiles[i][j] = random(tiles[i][j]);
            }
            tiles[0][m_size] = 'H';
        }

        void printTrack() {
            for (int i=0; i<size;i++){
                for (int j=0; j<size;j++) cout<<tiles[i][j]<<" ";
                cout<<endl;
            }
        }

    };

#endif //GAME_TRACK_H
