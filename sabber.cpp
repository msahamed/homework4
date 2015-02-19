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

using namespace std;

void FibonacciNumber(int number);
int open_input(string inputFileName);

//Main program

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
    

    string inputFileName = "sabber.in" ;

    // open the inputfile :
    int length = open_input(inputFileName);

    // calling FibonacciNumber function to computer the series
    FibonacciNumber(length);
}


 
int open_input(string inputFileName){
   
   ifstream inputFile;
   inputFile.open(inputFileName.c_str());


   if (inputFile.fail()) {
      cout << "Error reading the file  " << inputFileName << endl;
      exit(EXIT_FAILURE);
   }

    string line;
    int length;
    getline(inputFile, line);
    istringstream number (line);
    number >> length;
    
    return length; 
}


void FibonacciNumber(int N){

    int number = 10 * N;
    int fibonacciArray[number];
    int first = 0;
    int second = 1;
    fibonacciArray[0] = first ;
    fibonacciArray[1] = second ;

    int i = 2;
    while(i <= number){
       
      int fnumber = first + second;
      fibonacciArray[i] = fnumber ;
      first  = second;
      second = fnumber;
      i++ ;
    }


}
