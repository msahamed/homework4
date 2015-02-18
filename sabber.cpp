 /* 
 * Sabber Ahamed
 * Homework -3
 * Programming tools for Eanginners and scientists
 * Spring 2015
 * Github link : https://github.com/msahamed/ProgrammingTools/tree/master/homeWork3
 */


#include <iostream>
using namespace std;

void FibonacciNumber(int number);

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
    
    int length = 20;
    FibonacciNumber(length);
}



void FibonacciNumber(int number){

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
