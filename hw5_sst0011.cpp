//Santhosh Thundena
//sst0011
//hw5_sst0011.cpp
//for production version comment out #define UNIT_TESTING for debug decomment
//The program has a user input questions till satsified. Then asks questions and gives points to user base on correctness.
//I observed the notes from the lectures and referred back to previous projects from Professor Li.
//Getting access to data in a node https://stackoverflow.com/questions/26536979/getting-data-value-from-node-pointer-confusion
//Inserting a node at the end of a linked list https://stackoverflow.com/questions/20125477/linked-list-insert-at-the-end-c

#include <iostream>
#define UNIT_TESTING

using namespace std;

//keeps track of number of questions in the list.
int num_Trivia = 0;
//keep track of points
int total_Points = 0;

//Trivia Node Structure 
struct TriviaNode {

//INFO ABOUT A SINGLE TRIVIA NODE QUESTION
   string question;
   string answer;
   int points;

//POINTER TO OTHER TRIVIA NODE
   TriviaNode *next;
};


//Linked List class

class LinkedList {
   public:
   TriviaNode *firstNode, *lastNode;
   LinkedList() {
      firstNode = NULL; //first node in the list important to keep track of
      lastNode = NULL; //last node of the list important to keep track of
   }
};

//data in list that shows up in all instances used for testing.
void initialList(LinkedList &list) {
	
   TriviaNode *t1 = new TriviaNode;
   TriviaNode *t2 = new TriviaNode;
   TriviaNode *t3 = new TriviaNode;
   
   //trivia 1
   t1 -> question = "How long was the shortest war on record? (Hint: how many minutes)";
   t1 -> answer = "38";
   t1 -> points = 100;
   t1 -> next = t2;
   num_Trivia++;
   
   //trivia 2
   t2 -> question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   t2 -> answer = "Bank of Italy"; 
   t2 -> points = 50;
   t2 -> next = t3;
   num_Trivia++;
   
   //trivia 3
   t3 -> question = "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)";
   t3 -> answer = "Tetris";
   t3 -> points = 20;
   t3 -> next = NULL;
   num_Trivia++;
   
   list.firstNode = t1;
   list.lastNode = t3;
}

//function adds node to the LinkedList
void addTrivia(LinkedList &list, string input_question, string input_answer, int input_points) {

   //new node for trivia
	TriviaNode *newNode = new TriviaNode;
   //setting up the last node
	TriviaNode *endNode = list.firstNode;
   
   // move the end Node to the end   
   while (endNode -> next != NULL) {
		endNode = endNode -> next;
   }
   
   //put data into the node
   newNode -> question = input_question;
   newNode -> answer = input_answer;
	newNode -> points = input_points;
  
   //if the list is empty
	if (endNode == NULL) {
   //the new node is the first node
		list.firstNode = newNode;
	}
   
   //otherwise after the current end is now the new node
	else {
		endNode -> next = newNode;
	}
   
   //increment number of trivia
	num_Trivia++;

}

//checks if questions are right and gives points based on correctness
int checkQuestions(LinkedList list, TriviaNode *currentNode, int totalPoints) {
	string user_input;
		cout << "\nQuestion: " << currentNode -> question << endl;
      cout << "Answer: ";
      getline(cin,user_input);

		if (currentNode -> answer == user_input) {
	    cout << "Your answer is correct. You receive " << currentNode -> points << " points.\n";
		       total_Points = total_Points + currentNode -> points;	
		}
      
		else {
		 cout << "Your answer is wrong. The correct answer is:\t" << currentNode -> answer << endl;
		}
      
		cout << "Your total points: " << total_Points << endl;
	
	return 0;

}

//tester for debug version
void tester() {
   cout << "*** This is a debug version ***\n";

   //Test Case 1
   cout << "Unit Test Case 1: Ask no questions. The program should give a warning message.\n";
   if (num_Trivia == 0) {
    cout << "Warning - The number of trivia to be asked must equal to or larger than 1.\n\n";
   }
   else {
    cout << "Case 1: failed...\n\n";
   }
   
   //Test Case 2.1
   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.\n";
   
   LinkedList list;
   string user_answer;
   initialList (list);
   TriviaNode *currentQuestion = list.firstNode;
   
	cout << "Question: " << currentQuestion -> question;
   
   cout << "\nAnswer: ";
   getline(cin,user_answer);
   
   if(currentQuestion -> answer == user_answer) {
    cout << "Case 2.1 failed...\n\n";
   }
   
   else {
   cout << "Case 2.1 passed...\n\n";
   }
   
   //Test Case 2.2
   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.\n";
   //move to a different question
   currentQuestion = currentQuestion -> next;
   
   cout << "Question: " << currentQuestion -> question;
   
   cout << "\nAnswer: ";
   getline(cin,user_answer);
   
   if(currentQuestion -> answer == user_answer) {
    cout << "Case 2.2 passsed...\n\n";
   }
   
   else {
   cout << "Case 2.2 failed...\n\n";
   }
   
   //Test Case 3
   cout << "Unit Test Case 3: Ask the last trivia in the linked list.\n";
   
   // move to end of the list
   while (currentQuestion -> next != NULL) {
		currentQuestion = currentQuestion -> next;
   }
   cout << "Question: " << currentQuestion -> question;
   cout << "\nAnswer: ";
   cin >> user_answer;
   
   //Test Case 4
   cout << "\nUnit Test Case 4: Ask five questions in the linked list.\n";
   
   if(num_Trivia == 5) {
    cout << "Case 4 failed..." ;
   }
   
   else {
   cout << "Warning - There are only three trivia in the list.\n\n";
   }
   
   cout << "*** End of the Debug Version ***"; 
}

int main() {
   //DEBUG
   #ifdef UNIT_TESTING
   tester();
   
   //PRODUCTION
   #else
   
   //declaration of LinkedList
   LinkedList list;
   int totalPoints = 0;
   
   //data taken in to LinkedList when adding node
   string input_question;
   string input_answer;
   int input_points;
   
   //asking user if more data needs to be inputted
   string yes_or_no;
   bool loopback = false;
   
	cout << "*** Welcome to Santhosh's trivia quiz game ***\n";
   
   //initial hardcoded three questions
   initialList(list);
   
   //create more than one trivia quiz from a keyboard
   //do - while has to be done once
   do {
   cout << "Enter a question:\t";
   cin >> input_question;
   
   cout << "Enter an answer:\t";
   cin >> input_answer;
   
   cout << "Enter award points:\t";
   cin >> input_points;
   
   addTrivia(list, input_question, input_answer, input_points);
   
   //Continue?
   cout << "Continue? (Yes/No):\t";
   cin >> yes_or_no;
   //error if not ignored
   cin.ignore();
   //if user enters yes loop back
    if (yes_or_no == "Yes") {
     loopback = true;
    }
   //if user enters no stop
    if (yes_or_no == "No") {
     loopback = false;
    }
   }
   while (loopback == true);
   
	TriviaNode *currentNode = list.firstNode;
   
   //iterate and check all questions
	for (int i = 0; i < num_Trivia; i++) {
       checkQuestions(list, currentNode, totalPoints);
       currentNode = currentNode -> next;
   }   

	cout <<"\n*** Thank you for playing the trivia quiz game.  Goodbye! ***\n";
   
   #endif
   return 0;
}