#include <iostream>
#include<stdio.h>

#include <string>
#include <fstream>
#include<conio.h>
#include <cstring>

using namespace std;
enum Direction{LEFT=1,RIGHT,UP,DOWN};
enum ShipType{b=1,p=2,m=3,d=4};
class BattleShip{
public:
    char ch;
    std::pair<int,int> *pairs;
    int player;
    int direction;
    BattleShip(){pairs = NULL; };
    BattleShip(char l,  int p) : ch(l), player(p){ pairs = NULL; }
    BattleShip(char l,  int p, int dir) : ch(l),  player(p), direction(dir){ pairs = NULL;}
    ~BattleShip() {
        if (pairs != NULL)
            delete pairs;
    }
};
template <BattleShip> class BattleShipArray{
    size_t size;
    BattleShip *arr = nullptr;
    static int counter;

public:
    BattleShipArray(){
        memset(arr,0,sizeof(arr));
    }
    BattleShip& operator[](int index){ return arr[index]; }
    BattleShip& operator=(const BattleShip& vec);
    void print()const;
};

void BattleShipArray::print() const {
    for (int i = 0; i < 10; ++i) {
        cout << "arr[" << i << "]:" << arr[i].direction;
        for (int j = 0; j < 10; ++j) {
            cout << '(' << arr[i].pairs[j].first << ',' << arr[i].pairs[j].second << ") " ;
        }
        cout << endl;
    }
}
class BattleBoard
{
public:
    string* matrix;

    BattleBoard() : matrix(NULL) {}
    ~BattleBoard()
    {
        if (matrix != NULL)
        {
            delete[] matrix;
        }
    }
};

void input(BattleBoard& battleBoard)
{
    ifstream fin("boardexample1.txt");

    battleBoard.matrix = new string[10];
    for (int i =0; i < 10; ++i)
    {
        std::getline(fin, battleBoard.matrix[i]);
    }

    fin.close();
}

void output(const BattleBoard& battleBoard)
{

    for (int i = 0; i < 10; ++i)
    {
        for (int j =0; j < 10; ++j)
        {
            cout << battleBoard.matrix[i][j];
        }
        cout << endl;
    }
}

bool isValid(const BattleBoard& battleBoard){
    Direction dir;
    int player;
    BattleShipArray battleShipArray ;

    for (int i = 0; i < 10; ++i) { //horizontal walktrough
        for (int j = 0; j < 10; ++j) {
            char c = battleBoard.matrix[i][j];

            if(tolower(c) == 'b' || tolower(c) == 'm' || tolower(c) == 'p' || tolower(c) == 'd'){

                if(j+1<10 && battleBoard.matrix[i][j+1] == c)
                    dir = RIGHT;
                else if(i+1<10 && battleBoard.matrix[i+1][j] == c )
                    dir = DOWN;
                player = islower(c) ? 1 : 0;
                std::pair<int,int> point = make_pair(i,j);
                cout << '(' << i+1<< ',' << j+1 << ')' << dir << ' ' << c << endl;
                battleShipArray[i] = new BattleShip(c,point,player,dir);
            }
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    BattleBoard battleBoard;
    input(battleBoard);
    output(battleBoard);
    isValid(battleBoard);
    return 0;
}