//Santhosh Thundena
//sst0011
//hw1_sst0011.cpp
//The program calculates the fatal amount of diet coke.
//I observed the notes from the lectures and referred back to Project 1 for c syntax from Dr.Li.

#include <iostream>
#include <cmath>
using namespace std;


float fatalAmountHuman(float fatalMice, float weightFriend, float weightMouse);
const float SWEETENER = 0.001;

int main()
{
   float weightMouse, weightFriend, fatalMice, sweeten;
   
   cout << "Please input the weight of the mouse in kg" << endl;
   
   cin >> weightMouse;
   
   cout << "Please input fatal amount of sweetener for mouse in kg" << endl;
   
   cin >> fatalMice;
   
   cout << "Please input the weight of your dear friend in kg" << endl;
   
   cin >> weightFriend;
   
   cout << "The fatal amount of Coke for your friend is: " << fatalAmountHuman(fatalMice, weightFriend, weightMouse) << " kg";

   return 0;

}

float fatalAmountHuman(float fatalMice, float weightFriend, float weightMouse)
{  
   float fatalHuman = (fatalMice * weightFriend) / (weightMouse * SWEETENER);
   
   return fatalHuman;

}