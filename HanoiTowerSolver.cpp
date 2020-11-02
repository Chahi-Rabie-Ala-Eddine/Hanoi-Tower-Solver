/*
  CHAHI Rabie Ala Eddine
  C++ Hanoi tour Solver
*/

#include <string>

/*Positions*/
#define FirstTower "Start "
#define SecondTower "Middle"
#define ThirdTower "Goal  "

/*Maximum level supported (we can obviously increase it)*/
#define MaxLevel 18

using namespace std; 

/*Global steps counter*/
int moves = 0;

/*Check if argv is a positive number and that number is less than 18*/
bool isNumber(string number){
    return ((number.find_first_not_of("0123456789") == string::npos) && atoi(number.c_str()) < MaxLevel);
}

/*The function that print the step*/
void printCase(int ring, string initialPosition, string nextPosition){
    (ring == 1) ? printf("🔸 Take 🕳️  [%d] from %s ➡️  %s\n", 1, initialPosition.c_str(), nextPosition.c_str()) : printf("🔸 Take 🕳️  [%d] from %s ➡️  %s\n", ring, initialPosition.c_str(), nextPosition.c_str());
}

/*The recursive function that solves the hanoi tower game*/
void recursiveHTS(string initialPosition, string nextPosition, string tempPosition, unsigned int ring){  
    
    ++moves;

    if(ring < 0) return;

    else if (ring == 1){  
        printCase(ring, initialPosition, nextPosition);

        return;  
    }  
    
    recursiveHTS(initialPosition.c_str(), tempPosition.c_str(), nextPosition.c_str(), ring - 1);  

    printCase(ring, initialPosition, nextPosition);

    recursiveHTS(tempPosition.c_str(), nextPosition.c_str(), initialPosition.c_str(), ring - 1);  
}    

/*General program fonction*/
void HanoiTowerSolver(char* level){

    if(!isNumber(level)){
        puts("Your level number seems wrong ! Please execute solver as ./a.out [NUMBER]");
        exit(0);
    }

    printf("##########################################################\n##########################################################\n###########                                     ##########\n###########  WELCOME IN THE HANOI TOWER SOLVER  ##########\n###########                                     ##########\n##########################################################\n##########################################################\n\n\n\nAn example of a starting position for a level 3 game :\n\n    _|_             |              |\n   __|__            |              |\n  ___|___           |              |\n===========    ===========    ===========\n   START          MIDDLE          GOAL\n\nLet's solve a level %d game !\n\n",atoi(level));
    
    recursiveHTS(FirstTower, ThirdTower, SecondTower, atoi(level)); 

    printf("\n\nWe solved it using %d moves ✔️\n\nBY CHAHI RABIE ALA EDDINE - 2020\n\n", moves);
}
 
int main(int argc, char** argv)  
{  
    HanoiTowerSolver(argv[1]);

    return 0;  
}  