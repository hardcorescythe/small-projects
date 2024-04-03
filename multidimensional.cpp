#include <iostream>
#include <string>

int repn,row,column,reps = 0;
std::string inf;

std::string storage[10][10];

//fill 2d array with dummy text

void fillArray() {
    for(int i = 0; i<=9;i++) {
        for(int j = 0; j<=9;j++) {
            storage[i][j] = "null";
        }
    }
}

//insert data to storage

void insert(int r, int c, std::string info) {
    storage[r][c] = info;
    std::cout << "successfully inserted " << info << " at row " << r << ", column " << c << std::endl;
}

//get data out of storage

std::string extract(int r, int c) {
    return(storage[r][c]);
}

int main() {

    fillArray();

    std::cout << "succesfully started" << std::endl;
    std::cout << "please insert how many times you want to use this thingy >";
    std::cin >> repn;

    while(true) {
        std::cout << "please insert a string into the matrix (row / column / info)" << std::endl;

        std::cin >> row >> column >> inf;

        insert(row, column, inf);

        std::cout << "\nnow, search the matrix for your info in the matrix (row / column)" << std::endl;

        std::cin >> row >> column;

        std::cout << extract(row, column) << " found at " << row << ", " << column << std::endl;

        reps++;
        if(reps == repn) {break;}
    }
}