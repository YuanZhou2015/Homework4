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
#include <iomanip>

using namespace std;

void print_output(ofstream &outputfile, ofstream &errorfile,string str){
    string Fibornacci;
    if (str == Fibornacci){
       cout << str;
       outputfile << str;
    }
    else {
        cout << str;
        errorfile << str;
    }
}


ifstream &open_input(string inputfilename,ifstream &inputfile,int &flag, int &N){

    ofstream outputfile, errorfile;
    stringstream ss;
    string information;

    inputfile.open(inputfilename);

    errorfile.open("yuan.err");
    if (!inputfile.is_open()){
        ss << "Cannot open input file: "
                    << inputfilename
                    << endl;
        information = ss.str();
        print_output(outputfile,errorfile,information);
        flag = 1;
        return(inputfile);
    }

    // Check if the N is legal to create the Fibonacci sequence.

    inputfile >> N;
    if (N<1) {
        ss << "The input N is invalid. "
             << endl;
        information = ss.str();
        print_output(outputfile,errorfile,information);
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
    string inputfilename, outputfilename, errorfilename;
    int N,i,j,flag=0;

    // Open error file, output file, input file by calling functions

    open_error("yuan.err",errorfile);
    errorfile.close();
    open_output("yuan.out",outputfile);    
    open_input("yuan.in", inputfile, flag, N);  

    if (flag == 1)
    return 0;   

    unsigned long long temp=0,f1, f2;
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
    print_output(outputfile,errorfile, Fibonacci);
   
    inputfile.close();
    outputfile.close();
    errorfile.close();
    return 0;

}