/*Homework 4 
 *GitHub address for this homework: https://github.com/YuanZhou2015/Homework4
 *Fibonacci sequenc
 *Learning to use functions
 *by Yuan Zhou
 *Feburary 22, 2015
 */

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void print_output(ofstream &outputfile, int f){
    cout << setw(9) << left << f;
    outputfile << setw(9) << left <<f;
}

void print_error(ofstream &errorfile, string error){
    cout << error <<endl;
    errorfile << error <<endl;
}

ifstream &open_input(string inputfilename,ifstream &inputfile,int &flag, int &N){

    ofstream errorfile;
    inputfile.open(inputfilename);
    errorfile.open("yuan.err");
    if (!inputfile.is_open()){
        cout << "Cannot open input file: "
             << inputfilename
             << endl;
        errorfile <<"Cannot open input file: "
                  << inputfilename
                  << endl;
        flag = 1;
        return(inputfile);
    }

    // Check if the N is legal to create the Fibonacci sequence.

    inputfile >> N;
    if (N<1) {
        cout << "The input N is illegal. "
             << endl;
        errorfile << "The input N is illegal. "
                  << endl;
        flag = 1;
        return(inputfile);
    }
 
    return(inputfile);
}

ofstream &open_error( string errorfilename, ofstream &errorfile){
    errorfile.open(errorfilename);
    if (!errorfile.is_open() ){
        cout << "Cannot open error file: "
             << errorfilename
             << endl;
        return (errorfile);
    }
}

ofstream &open_output( string outputfilename, ofstream &outputfile){
    ofstream errorfile;
    outputfile.open(outputfilename);
    errorfile.open("yuan.err");
    if (!outputfile.is_open() ){
        cout << "Cannot open output file: "
             << outputfilename
             << endl;
        errorfile <<"Cannot open output file: "
                  << outputfilename
                  << endl;
        return (outputfile);
    }
}


int main() {

    // Message want to print out on terminal

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
         << "Here they are:"<< "\n"
         << endl;
    
    // The first 10*N numbers of the Fibonacci sequence.

    ifstream inputfile;
    ofstream outputfile, errorfile;
    string inputfilename, outputfilename, errorfilename, Fibonacci;
    int N,i,j,flag=0;

    // Open error file, output file, input file by calling functions

    open_error("yuan.err",errorfile);
    errorfile.close();
    open_output("yuan.out",outputfile);
    
    open_input("yuan.in", inputfile, flag, N);  

    if (flag == 1)
    return 0;
       
    int temp=0,f1, f2;
    f1=1;
    f2=1;
    print_output(outputfile,f1);
    print_output(outputfile,f2);

    for (i=2;i<10*N;i++){
        temp=f1+f2;
        f1=f2;
        f2=temp;
        print_output(outputfile,temp);
        if ((i+1)%10==0 && i>2){
            cout <<"\n";
            outputfile << "\n";
        }
    } 
       
    inputfile.close();
    outputfile.close();
    errorfile.close();
    return 0;

}