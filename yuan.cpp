/*Homework 4 
 *GitHub address for this homework: https://github.com/YuanZhou2015/Homework4
 *by Yuan Zhou
 *Feburary 22, 2015
 */

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
/*
void print_output(ofstream, ofstream,string) {
} */

ifstream open_input(string inputfilename){
    ifstream inputfile;
    inputfile.open(inputfilename.c_str());
    if (!inputfile.is_open() ){
        cout << "Cannot open input file: "
             << inputfilename
             << endl;
        return inputfile;
    }
    
}

ofstream open_output(string outputfilename, string errorfilename){
    ofstream outputfile, errorfile;
    outputfile.open("yuan.out");
    if ( !outputfile.is_open() ){
        cout << "Cannot open output file: "
             << "yuan.out"
             << endl;
        return outputfile;
    }

    errorfile.open("yuan.err");
    if (!errorfile.is_open() ){
        cout << "Cannot open error file: "
             << "yuan.err"
             << endl;
        return errorfile;
    }

}

int main() {
    ifstream inputfile;
    ofstream outputfile, errorfile;
    cout << "I was able to compile this code using the HPC at the University of Memphis."<< "\n"
         << "When I compiled it there, it did not produce any warning message."<< "\n"
         << "The HPC uses a GNU C++ compiler that can be considered "<< "\n"
         << "a good up-to-date standard."<< "\n"
         << "I also version-controlled this code using git,"<< "\n" 
         << "and use a remote repository hosted by github. "<< "\n" 
         << "If I can do this, so can you!!!" << "\n"
         << endl;
    cout << "I am so cool, that I was also able to write a code " << "\n"
         << "that produces the first N numbers of the Fibonacci sequence." << "\n"
         << "Here they are:"<< "\n";
   /* 
    open_input ("yuan.in") ;
    //ifstream inputfile;
   // inputfile >> N;
   
   // cout << N;
    open_output("yuan.out", "yuan.err");
    
    inputfile.close();
    outputfile.close();
    errorfile.close();*/

    int n=2;
    int a[10000];
    a[0]=1;
    a[1]=1;
    for (int i=2;i<=10*n;i++){
        a[i]=a[i-1]+a[i-2];
        cout << a [i] <<"\n";
    }
    
    return 0;

}