//Santhosh Thundena
//sst0011
//hw3_sst0011.cpp
//The program finds which strategy is best for Aaron in a duel between his friend.
//I observed the notes from the lectures and referred back to previous projects from Professor Li.
//Used the hints given in the pdf file for homework 3.

#include <iostream>
#include <ctime>
#include <assert.h>
#include <stdlib.h>
using namespace std;

//declaring functions
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool&C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
//declaring test functions
void at_least_two_alive_Test();
void Aaron_shoots1_Test();

//declaring constants
const double ACCURACY_AARON = 1.0/3.0;
const double ACCURACY_BOB = 0.5;
const double ACCURACY_CHARLIE = 1.0;
const int NUM_OF_TRIALS = 10000;

int main()
{

   //random number generator
   srand(time(0));

   //constants for main
   bool aaron_Alive, bob_Alive, charlie_Alive;
   int A_Wins1, A_Wins2, b_Wins, c_Wins = 0;
   double a_success, b_success, c_success = 0.0;
   
   cout << "***Welcome to the Duel Simulator***\n";
   
   //test case 1 unit testing
   at_least_two_alive_Test();
   
   cout << "Press Enter to continue...";
   cin.get();
   
   //*** STRATEGY1 ***
   
   for(int i = 0; i < NUM_OF_TRIALS; i++) {
   
   aaron_Alive = true;
   bob_Alive = true;
   charlie_Alive = true;
   
      do {
         if(aaron_Alive) 
            Aaron_shoots1(bob_Alive, charlie_Alive);
         if(bob_Alive)
            Bob_shoots(aaron_Alive, charlie_Alive);
         if(charlie_Alive)
            Charlie_shoots(aaron_Alive, bob_Alive);
      }
      while (at_least_two_alive(aaron_Alive, bob_Alive, charlie_Alive));
      
      if(aaron_Alive == true)
         A_Wins1 ++;
      if(bob_Alive == true)
         b_Wins ++;
      if(charlie_Alive == true)
         c_Wins ++;
      
      
   }
   
   a_success = (A_Wins1/(double)NUM_OF_TRIALS) * 100;
   b_success = (b_Wins/(double)NUM_OF_TRIALS) * 100;
   c_success = (c_Wins/(double)NUM_OF_TRIALS) * 100;
   
   cout << "Ready to test strategy 1 (run 10000 times)\n";
   
   cout << "Press Enter to continue...";
   cin.get();
   
   cout << "Aaron won " << A_Wins1 << "/" << NUM_OF_TRIALS <<" duels or " << a_success << "%\n";
   cout << "Bob won " << b_Wins << "/" << NUM_OF_TRIALS << " duels or " << b_success << "%\n";   
   cout << "Charlie won " << c_Wins << "/" << NUM_OF_TRIALS << " duels or " << c_success << "%\n\n";
   
   
   //*** STRATEGY 2 ***
   b_Wins = 0;
   c_Wins = 0;
   
   for(int i = 0; i < NUM_OF_TRIALS; i++) {
   
   aaron_Alive = true;
   bob_Alive = true;
   charlie_Alive = true;
   
      do {
         if(aaron_Alive)
            Aaron_shoots2(bob_Alive, charlie_Alive);
         if(bob_Alive)
            Bob_shoots(aaron_Alive, charlie_Alive);
         if(charlie_Alive)
            Charlie_shoots(aaron_Alive, bob_Alive);
      }
      while (at_least_two_alive(aaron_Alive, bob_Alive, charlie_Alive));
      
      if(aaron_Alive == true)
         A_Wins2 ++;
      if(bob_Alive == true)
         b_Wins ++;
      if(charlie_Alive == true)
         c_Wins ++;
         
      
   }
   
   a_success = (A_Wins2/(double)NUM_OF_TRIALS) * 100;
   b_success = (b_Wins/(double)NUM_OF_TRIALS) * 100;
   c_success = (c_Wins/(double)NUM_OF_TRIALS) * 100;
   
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   cout << "Press Enter to continue...";
   cin.get();
   cout << "Aaron won " << A_Wins2 << "/" << NUM_OF_TRIALS <<" duels or " << a_success << "%\n";
   cout << "Bob won " << b_Wins << "/" << NUM_OF_TRIALS << " duels or " << b_success << "%\n";   
   cout << "Charlie won " << c_Wins << "/" << NUM_OF_TRIALS << " duels or " << c_success << "%\n\n";   
   
  //*** STRATEGY COMPARISION***
  
  if(A_Wins2 >= A_Wins1) {
   cout << "Strategy 2 is better than strategy 1.";
  }
  
  else {
   cout << "Strategy 1 is better than strategy 2.";
  }
   
   return 0;
}
//***FUNCTIONS***

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
/* Input: A_alive indicates whether Aaron is alive */
/* B_alive indicates whether Bob is alive */
/* C_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */
/* otherwise return false */
    if (A_alive && B_alive) 
    {
        return true;
    }

    if (A_alive && C_alive) 
    {
        return true;
    }

    if (B_alive && C_alive) 
    {
        return true;
    }

    return false;
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
/* Strategy 1: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/

//Aaron will attempt to shoot Charlie. If Charlie is dead he will shoot Bob
   //represents the 1 in 3 chanch Aaron will have to hit
   int shoot_target_result = rand() % 3;
   
   if(shoot_target_result == 1) {
      if(C_alive == true) {
         C_alive = false;
      }
      
      else {
         B_alive = false;    
      }
   }

}

void Bob_shoots(bool& A_alive, bool& C_alive) {
/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change C_alive into false if Charlie is killed.
*/

//Bob will attempt to shoot Charlie. If Bob is dead he will shoot Aaron
   //reprensents the 1 in 2 chance Bob have to hit
   int shoot_target_result = rand() % 2;
   
   if(shoot_target_result == 1) {
   
      if(C_alive == true) {
         C_alive = false;
      }
      
      else {
         A_alive = false;
      }
   }
   
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* B_alive indicates whether Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change B_alive into false if Bob is killed.
*/

//Charlie will shoot Bob if alive if not alive he will shoot Aaron
//Charlie will not miss
 
   int shoot_target_result = rand() % 1;
   //Charlie will always hit his target shoot_target_result is unneccessary
   if(shoot_target_result <= ACCURACY_CHARLIE && B_alive == true) {
      B_alive = false;
   }

   else {
      A_alive = false;
   }
   
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
/* Strategy 2: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/

//Aaron will miss when Bob and Charlie are alive
        
   int shoot_target_result = rand() % 3;
   
   if(shoot_target_result == 1) {
   
      if(!(B_alive && C_alive)) {
      
      if(C_alive == true) {
         C_alive = false;
      }
      
      else {
         B_alive = false;    
      }
   }
   }
       
}  
//***TEST FUNCTIONS***

void at_least_two_alive_Test(void) {

cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   
   //all alive
   cout << "\tCase1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true,true,true));
   cout << "\tCase passed ...\n";
   
   
   //two alive
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";
   
   //one alive alive
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed...\n";
   
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed...\n";
   
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed...\n";
   
   //all dead
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed...\n";   
   
}

void Aaron_shoots1_Test(void) {
   
bool Aaron_alive, Bob_alive, Charlie_alive = true;

cout << "Unit Testing 2: Function - Aaron_shoots1(Bob_alive, Charlie_alive)\n";

   cout << "\tCase 1: Bob alive, Charlie alive\n";
   Aaron_shoots1(Bob_alive,Charlie_alive);
   
   cout << "\tCase 2: Bob alive, Charlie dead\n";
   Charlie_alive = false;
   Aaron_shoots1(Bob_alive,Charlie_alive);
   
   cout << "\tCase 3: Bob dead, Charlie alive\n";
   Charlie_alive = true;
   Bob_alive = false;
   Aaron_shoots1(Bob_alive,Charlie_alive);
}

void Bob_shoots_Test(void) {
   
bool Aaron_alive, Bob_alive, Charlie_alive = true;

cout << "Unit Testing 3: Function - Bob_shoots(Aaron_alive, Charlie_alive)\n";

   cout << "\tCase 1: Aaron alive, Charlie alive\n";
   Bob_shoots(Aaron_alive,Charlie_alive);
   
   cout << "\tCase 2: Aaron alive, Charlie dead\n";
   Charlie_alive = false;
   Bob_shoots(Aaron_alive,Charlie_alive);
   
   cout << "\tCase 3: Aaron dead, Charlie alive\n";
   Charlie_alive = true;
   Aaron_alive = false;
   Bob_shoots(Aaron_alive,Charlie_alive);
}

void Charlie_shoots_Test(void) {
   
bool Aaron_alive, Bob_alive, Charlie_alive = true;

cout << "Unit Testing 4: Function - Charlie_shoots(Aaron_alive, Bob_alive)\n";

   cout << "\tCase 1: Aaron alive, Bob alive\n";
   Bob_shoots(Aaron_alive,Bob_alive);
   
   cout << "\tCase 2: Aaron dead, Bob alive\n";
   Aaron_alive = false;
   Bob_shoots(Aaron_alive,Bob_alive);
   
   cout << "\tCase 3: Aaron alive, Bob dead\n";
   Bob_alive = false;
   Aaron_alive = true;
   Bob_shoots(Aaron_alive,Bob_alive);
}

void Aaron_shoots2_Test(void) {
   
bool Aaron_alive, Bob_alive, Charlie_alive = true;

cout << "Unit Testing 5: Function - Aaron_shoots2(Bob_alive, Charlie_alive)\n";

   cout << "\tCase 1: Bob alive, Charlie alive\n";
   Aaron_shoots2(Bob_alive,Charlie_alive);
   
   cout << "\tCase 2: Bob alive, Charlie dead\n";
   Charlie_alive = false;
   Aaron_shoots2(Bob_alive,Charlie_alive);
   
   cout << "\tCase 3: Bob dead, Charlie alive\n";
   Charlie_alive = true;
   Bob_alive = false;
   Aaron_shoots2(Bob_alive,Charlie_alive);
}