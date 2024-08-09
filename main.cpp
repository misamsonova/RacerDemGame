#include <iostream>
#include <cmath>
#include <ctime>
#include "Track.h"
#include "Racer.h"
using namespace std;

int main() {
    srand(time(nullptr));
    int size; char racer;
    cout << "Enter the size of the track (must be an odd number and greater than 1):" << endl;
    cin >> size;
    while(size<2 || size%2==0){
        cout<<"Wrong size.Enter again."<<endl;
        cin>>size;
    }
    Track tr(size);
    tr.printTrack();
    cout<<"Who will you choose? Night racer or Overrunner? Enter 1 or 2."<<endl;
    cin>>racer;
    switch(racer){
        case '1':{
            Racer car(&tr);
            car.move();
            break;
        }
        case '2':{
            Overrunner car(&tr, &tr);
            car.move();
            break;
        }
    }


}