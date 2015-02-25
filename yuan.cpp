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
#include <sstream>

using namespace std;

//Print out function for print out different information and Fibonacci sequence.

void print_output(ofstream &outputfile, ofstream &errorfile,string str,int &F){
    
    if (F==1){
        outputfile.open("yuan.out");
        cout << str;
        outputfile << str;
        outputfile.close();
    }

    if (F==2){
        errorfile.open("yuan.err");
        cout << str;
        errorfile << str;
        errorfile.close();
    }    
     
}

// The funcitons to open and check the files.

void open_input(string inputfilename,ifstream &inputfile,int &flag, int &N){

    ofstream outputfile, errorfile;
    stringstream ss;
    string information;

    inputfile.open(inputfilename.c_str());

    if (!inputfile.is_open()){
        ss << "Cannot open input file: "
           << inputfilename
           << endl;
        information = ss.str();
        int F = 1;
        print_output(outputfile,errorfile,information,F);
        flag = 1;
        return;
    }

    // Check if the N is legal to create the Fibonacci sequence.

    inputfile >> N;
    if (N<1) {
        ss << "The input N is invalid. \n";
        information = ss.str();
        int F=2;
        print_output(outputfile,errorfile,information,F);
        flag = 1;
        return;
    }
 
    return;
}

void open_error( string errorfilename, ofstream &errorfile){
    stringstream ss;
    string information;
    errorfile.open(errorfilename.c_str());
    if (!errorfile.is_open() ){
        ss << "Cannot open error file: "
             << errorfilename
             << endl;
        information = ss.str();
        int F=2;
        print_output(errorfile,errorfile,information,F);
        int flag = 1;
        return;
    }
}

void open_output( string outputfilename, ofstream &outputfile){
    ofstream errorfile;
    stringstream ss;
    string information;

    outputfile.open(outputfilename.c_str());
    errorfile.open("yuan.err");
    if (!outputfile.is_open() ){
        ss << "Cannot open output file: "
             << outputfilename
             << endl;
        information = ss.str();
        int F=2;
        print_output(outputfile,errorfile,information,F);
        int flag = 1;
        return;
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
    string inputfilename, outputfilename, errorfilename;
    int N,i,flag=0;

    // Open error file, output file, input file by calling functions

    open_error("yuan.err",errorfile);
    errorfile.close();
    open_output("yuan.out",outputfile); 
    outputfile.close();
    open_input("yuan.in", inputfile, flag, N);  

    // If any of these files fail to be opened or has other error, exit the program.
    if (flag == 1)
    return 0;   

    unsigned long long temp=0, f1, f2;
    string  Fibonacci;
    stringstream ss;
    ss << "The first " << N*10 <<" numbers of Fibonacci sequence are:" << "\n";
    f1=0;
    ss << f1 <<" ";
    Fibonacci = ss.str();
    f2=1;
    ss << f2<<" ";;
    Fibonacci = ss.str(); 

    for (i=2;i<10*N;i++){
        temp=f1+f2;
        f1=f2;
        f2=temp;
        if ((i+1)%10==0 && i>2)
            ss << temp <<"\n";
        else
            ss << temp<<"  ";
        Fibonacci = ss.str();      
    } 
    int F=1;
    print_output(outputfile,errorfile, Fibonacci,F);

    inputfile.close();
    outputfile.close();
    errorfile.close();
    
    return 0;
}