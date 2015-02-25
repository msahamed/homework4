 /* 
 * Sabber Ahamed
 * Homework -4
 * Programming tools for Eanginners and scientists
 * Spring 2015
 * Github link : https://github.com/msahamed/ProgrammingTools/tree/master/homeWork3
 */


#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> 
#include <fstream>
#include <iomanip>

using namespace std;


void open_output(ofstream& outputFile, string fileName){

     outputFile.open("fileName", ofstream::out | ofstream::app);
}


void print_output(ofstream& outputFile, int number, long double* fibonacciArray, int length){

   int colNumber;
   switch (number){
     case 1 :
         colNumber = 1;
     for (int i = 0; i < length; i++){

       if ((colNumber%10) == 0) {
          outputFile << fibonacciArray[i] <<left<< setw(13) <<endl;
          colNumber++;

       }else{
          outputFile << fibonacciArray[i] <<left<< setw(13);
          colNumber++;
       }
     }
     break;
   case 2 : 
       colNumber = 1;
       for (int i = 0; i < length; i++){
          if ((colNumber%10) == 0) {
             cout << fibonacciArray[i] <<left<< setw(13) <<endl;
             colNumber++;
          }
          else {
             cout << fibonacciArray[i] <<left<< setw(13);
             colNumber++;
          }
       } 
    break;
    }
}


void generateError(int errorNumber, string name){

    ofstream outputErrorFile;
    outputErrorFile.open("sabber.err", ofstream::out | ofstream::app);
    switch (errorNumber) {
      case 1 : 
          outputErrorFile << "Error # 1"    << "Error reading the file  ' " << name << " '" << endl; 
          break;
      case 2 :
          outputErrorFile << "Error # 2 : Invalied input (" << name << "). Number must be greater" 
                          << " than or equal to 1. please correct the input file" << endl; 
          break;
    }
}


void open_input(ifstream& inputFile, string inputFileName){

   inputFile.open(inputFileName.c_str());

   if (inputFile.fail()) {
      cout << "Error reading the file  " << inputFileName << endl;
      generateError(1 , inputFileName);
      exit(EXIT_FAILURE);
   }
}


int getNumber(ifstream& inputFile ){
    
    string line;
    int length;
    getline(inputFile, line);
    istringstream number (line);
    number >> length;    
    return length; 
}


// Main program 

int main () {

    cout << "\n";
    cout << " I was able to compile this code using the HPC at the University of Memphis."
         << " When I compiled it there, it did not produce any warning message."
         << " The HPC uses a GNU C++ compiler that can be considered a good up-to-date standard."
         << " I also version-controlled this code using git, and use a remote repository hosted by github."
         << " If I can do this, so can you!!!"
         << " \n ";
    cout << " \n ";
    cout << " I am so cool, that I was also able to write a code that produces the first N numbers "
         << " of the Fibonacci sequence. Here they are:"
         << " \n ";
    cout << " \n ";

    // open the input file 
    string inputFileName = "sabber.in" ;
    ifstream inputFile;
    open_input(inputFile, inputFileName);

    // get the number from the file
    int length = getNumber(inputFile);
    inputFile.close();

    if (length < 1){
       string name = " ";

       cout << "Error # 2 : Invalied input number. Number must be greater than or equal to 1"
            << "please correct the input file" << endl;
       generateError(2,name);
       exit(EXIT_FAILURE);

    }
//    inputFile.close();
   
    // calculating Fibonacci series
     int arrayLength = 10*length;
     long double fibonacciArray[arrayLength];

     long double first = 0;
     long double  second = 1;
     fibonacciArray[0] = first ;
     fibonacciArray[1] = second ;
     
     int i = 2;
     while(i <= arrayLength){
     
       long double fnumber = first + second;
       fibonacciArray[i] = fnumber ;
       first  = second;
       second = fnumber;
       i++ ;
     }
    
    // open output file
    ofstream outputFile;
    string outputFileName = "sabber.out";
    open_output(outputFile, outputFileName);

    // printing on terminal and to output file
    int file = 1; int  terminal = 2;
    print_output(outputFile, file, fibonacciArray, arrayLength);
    print_output(outputFile, terminal, fibonacciArray, arrayLength);



}
    
	    
