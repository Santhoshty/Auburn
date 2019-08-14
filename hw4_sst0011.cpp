//Santhosh Thundena
//sst0011
//hw4_sst0011.cpp
//The program finds which strategy is best for Aaron in a duel between his friend.
//I observed the notes from the lectures and referred back to previous projects from Professor Li.
//Used the hints given in the pdf file for homework 3.
//https://www.geeksforgeeks.org/sort-c-stl/ used sorting function
//https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.html used tutorial
// to gain better understanding of pointer



//packages
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <algorithm> 

using namespace std;

//functions
int readfile(int inputArray[], ifstream& instream);   
int sort(int inputArray1[], int inputArray1_size,
         int  inputArray2[], int inputArray2_size,
         int outputArray[]);
void writefile(int outputArray[], int outputArray_size, ofstream& outstream);
 
//constants
const int MAX_SIZE = 100;

int main() {
   
   //variables
   //reads the file
   ifstream inStream1;
   ifstream inStream2;
   ofstream outStream;
   
   int data;
   
   string filename1;
   string filename2;
   string outputfile = "output.txt";
   
   int arraySize1 = 0;
   int arraySize2 = 0;
   
   int iArray1 [MAX_SIZE];
   int iArray2 [MAX_SIZE];
   
   int outputSize;
   int oArray [MAX_SIZE];
   
   
   //output
   cout << "*** Welcome to Santhosh Thundena's sorting program ***\n";
   
   //FIRST TEXT FILE
   cout << "Enter the first input file name: ";
   cin >> filename1;
   
   //opens file
   inStream1.open((char*)filename1.c_str());
   
   //if fails close
   if(inStream1.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   
      
   //sets size of array 1
   arraySize1 = readfile(iArray1,inStream1);
   //copies array to the correct size array
   int realArray1 [arraySize1];
   
   cout << "The list of " << arraySize1 + 1 << " numbers in file " << filename1 << " is:\n";
  
   inStream1 >> data;
      
   for(int i = 0; i <= arraySize1; i++) {
      cout << iArray1[i] << endl;   
   }
   
   inStream1.close();
   
   cout << endl;
   
   //SECOND TEXT FILE
   cout << "Enter the second input file name: ";
   cin >> filename2;
   
   inStream2.open((char*)filename2.c_str());
   
   //if fails close
   if(inStream2.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
       
   //sets size of array 1
   arraySize2 = readfile(iArray2,inStream2);
   //copies array to the correct size array
   int realArray2 [arraySize2];
   
   cout << "The list of " << arraySize2 + 1 << " numbers in file " << filename2 << " is:\n";
   
   for(int i = 0; i <= arraySize2; i++) {
      cout << iArray2[i] << endl;   
   }
      
   inStream2.close();
   
   cout << endl;
   
   //OUTPUT ARRAY
   
   outputSize = sort(iArray1, arraySize1,
         iArray2, arraySize2,
         oArray);
         
   cout << "The sorted list of " << outputSize << " numbers is: ";
         
   for(int i = 0; i <= outputSize; i++) {
      cout << oArray[i] << " ";
   }
   
   //OUTPUT TEXT FILE
   outStream.open((char*)outputfile.c_str());
   writefile(oArray, outputSize, outStream);
   outStream.close();
   
        
   outStream.close();
   
   return 0;
}


//function that returns the input of the size of the array

int readfile(int inputArray[], ifstream& inStream) {
   //initialize index to 0
   int index = 0;
   //take whatevers in the textfile into array
   inStream >> inputArray[index];
   //read and input till the file is over
   while (! inStream.eof()) {
      index++;
      inStream >> inputArray[index];
   }

   return index;
} 

//function that returns the size of the output array

int sort(int inputArray1[], int inputArray1_size,
         int  inputArray2[], int inputArray2_size,
         int outputArray[]) {

   int outputArray_size = inputArray1_size + inputArray2_size + 1;
           
   for (int i = 0; i <= inputArray1_size; i++) {
         outputArray[i] = inputArray1[i];
      }
      
   for (int j = inputArray1_size; j <= outputArray_size; j++) {  
         outputArray[j + 1] = inputArray2[j - inputArray1_size];
      }   
   
   //sort function
   sort(outputArray, outputArray + outputArray_size + 1);
   
   return outputArray_size;
}

//function that creates output.txt

void writefile(int outputArray[], int outputArray_size, ofstream& outstream) {
//take each part of array line by line till no data left
  for(int i = 0; i < outputArray_size; i++) {
    outstream << outputArray[i] << endl;            
  }
} 