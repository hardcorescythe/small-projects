#include <iostream>
#include <cstdlib>
#include <time.h>

int currentSum, checkedNum, checkingNum, duplicates,reps;

int table[4][13] = {{},{},{},{}},choice,sum,sumTemp;

void checkSame() {
    duplicates=0;
    for(int i=0; i<4;i++) {
        currentSum=0;
        for(int s=0;s<=12;s++){
            currentSum+=table[i][s];
        }
        for(int j=0;j<=12;j++){
            std::cout<<"comparing #"<<j<<std::endl;
            checkedNum = table[i][j];
            for(int k=0;k<=12;k++){
                if(j!=k) {
                    checkingNum=table[i][k];
                    if(checkedNum == checkingNum) {
                        std::cout<<"found duplicate #" << i*j << std::endl;
                        duplicates++;
                        if(currentSum < 104) {
                            checkingNum += 104-currentSum;
                            std::cout<<"fixed? \n";
                        } else {
                            checkingNum -= currentSum-104;
                            std::cout<<"fixed? \n";
                        }
                    }
                    
                }
            }
        }
    }
}

void order() {
    for(int i=0; i<4;i++) {
        for(int j=0; j<=12; j++) {
            table[i][j] = j+2;
        }
    }
    std::cout<<"ordered deck \n";
}

//below shows cards, for some reason
//SOLVED:outputs 2 instead of the 4th '13'

void show() {
    std::cout<<"cards in deck are: \n";
    for(int i=0; i<4;i++) {
        for(int j=0; j<=12; j++) {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//below shuffles the deck

void shuffle() {
    reps=0;

    order();

    srand(time(NULL));

    for(int i = 0; i<=20; i++) {
        int temp1,temp2;
        int r = rand() % 4;
        int j1 = rand() % 13 + 1;
        int j2 = rand() % 13 + 1;
        if( j1 != j2 and table[r][j1] != table[r][j2]) {
            temp1 = table[r][j1];
            temp2 = table[r][j2];
            table[r][j1] = temp2;
            table[r][j2] = temp1;

            show();
            std::cout<<std::endl;
        }
    }

    checkSame();
    while(duplicates>=1){
        if(reps>=5) {
            shuffle();
            break;
        }
        std::cout<<"found "<<duplicates<<" duplicates \n";
        reps++;
        checkSame();
    }

}

int main() {
    std::cout<<"type 1 to put cards in order, 2 to show the deck, and 3 to shuffle the cards(wait until it completely stops) \n";
    order();    //makes sure the deck is in order
    show();     //shows deck's order
    while(true){
        try{
            std::cin>>choice;
            if(choice <=3 and choice >= 0 ) {
                if(choice == 1) {order();} else if(choice == 2) {show();} else {shuffle();}
            } else {throw 4;}
        }
        catch(...) {
            std::cout << "choice does not exist, please try again \n";
        }
    }
}