
//
//  main.cpp
//  fasta
//  Created by Abelard on 15/10/2.
//  Copyright (c) 2015年 Abelard. All rights reserved.
//
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


int main(int argc, const char * argv[]) {
    int sheet1[26][100],sheet2[26][100],count[26],countX[26],i,j;
    long len;
    string str1, str2;
    for (j = 0; j <26; j++){
        count[i] = 0;
    }
    ifstream data1 ("/Users/abelard/Desktop/fasta/fasta/proteinX.fasta");
    ifstream data2 ("/Users/abelard/Desktop/fasta/fasta/protein.fasta");
    if(!data2){
        cout << "Unable to open myfile";
        exit(1); // terminate with error
    }
    if(!data1){
        cout << "Unable to open myfile";
        exit(1); // terminate with error
    }
    char buffer[1000];
    data1.getline(buffer, 1000);
    while(!data1.eof()){
        data1.getline(buffer, 1000);
        str1+=buffer;
    }
  

    data2.getline(buffer, 1000);
    while(!data2.eof()){
        data2.getline(buffer, 1000);
        str2+=buffer;
    }
    len = str1.length();
    for (i = 0;i < len; i++){
        for (j = 0; j <26; j++){
            char ch = 'A' + j;
            if (str1[i] ==  ch){
                sheet1[j][count[j]] = i+1;
                count[j]++;
            }
        }
    }

    len = str2.length();
    for (i = 0;i < len; i++){
        for (j = 0; j <26; j++){
            char ch = 'A' + j;
            if (str2[i] ==  ch){
                sheet2[j][countX[j]] = i+1;
                countX[j]++;
            }
        }
    }
    cout << str1 << endl;
    cout << str2 << endl;
    for (i = 0;i < count[0]; i++){
        cout<<sheet1[0][i]<<' ' ;
    }
    cout <<endl;
    for (i = 0;i < countX[0]; i++){
        cout<<sheet2[0][i]<<' ';
    }
    cout <<endl;
    for (i = 0;i < count[0]; i++){
        for (j = 0;j < countX[0]; j++){
            cout<<sheet1[0][i] - sheet2[0][j]<<' ' ;
        }
    }
    return 0;
}

