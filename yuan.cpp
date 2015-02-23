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

void print_output(ofstream outputfile, int a[]) {
    int n,i,j;
    for (i=0; i<n;i++){
        for (j=i*10;j<=i*10+9;j++){
            cout << setw(8) << left << a[j];
            outputfile << setw(8) << left << a[j];
        }
        cout <<"\n";
        outputfile << "\n";
    }
} 

/*ifstream open_input(string inputfilename){
    ifstream inputfile;
    ofstream errorfile;
    inputfile.open(inputfilename.c_str());
    if (!inputfile.is_open() ){
        cout << "Cannot open input file: "
             << inputfilename
             << endl;
        errorfile <<"Cannot open input file: "
                  << "yuan.out"
                  << endl;
        return inputfile;
    }
    
}

ofstream open_output(string outputfilename){
    ofstream outputfile, errorfile;
    outputfile.open("yuan.out");
    if ( !outputfile.is_open() ){
        cout << "Cannot open output file: "
             << "yuan.out"
             << endl;
        errorfile <<"Cannot open output file: "
                  << "yuan.out"
                  << endl;
        return outputfile;
    }

}

ofstream open_error( string errorfilename){
    ofstream  errorfile;
    errorfile.open("yuan.err");
    if (!errorfile.is_open() ){
        cout << "Cannot open error file: "
             << "yuan.err"
             << endl;
        return errorfile;
    }

}*/


int main() {
    ifstream inputfile;
    ofstream outputfile, errorfile;
    string inputfilename, outputfilename, errorfilename;

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
  
 
    inputfile.open("yuan.in");
    if (!inputfile.is_open() ){
        cout << "Cannot open input file: "
             << inputfilename
             << endl;
        errorfile <<"Cannot open input file: "
                  << "yuan.out"
                  << endl;
        return 10;
    }
    
    outputfile.open("yuan.out");
    if ( !outputfile.is_open() ){
        cout << "Cannot open output file: "
             << "yuan.out"
             << endl;
        errorfile <<"Cannot open output file: "
                  << "yuan.out"
                  << endl;
        return 20;
    }


    errorfile.open("yuan.err");
    if (!errorfile.is_open() ){
        cout << "Cannot open error file: "
             << "yuan.err"
             << endl;
        return 30;
    }
    

    int N,i,j;

    inputfile >> N;
   
    int a[1000];
    a[0]=1;
    a[1]=1;
    for (i=2;i<=10*N;i++){
        a[i]=a[i-1]+a[i-2];
    }
    
  
    for (i=0; i<N;i++){
        for (j=i*10;j<=i*10+9;j++){
            cout << setw(8) << left << a[j];
            outputfile << setw(8) << left << a[j];
        }
        cout <<"\n";
        outputfile << "\n";
    }
    
    inputfile.close();
    outputfile.close();
    errorfile.close();
    return 0;

}