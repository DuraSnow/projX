
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
    int sheet2[200][100],countX[800],n[800],dis[100],num[200][200],i,j,k=0,max;
    long len1,len2;
    string str1, str2;
    for (j = 0; j <800; j++){
        countX[j] = 0;
        n[j]=0;
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
    len1 = str1.length();

    data2.getline(buffer, 1000);
    while(!data2.eof()){
        data2.getline(buffer, 1000);
        str2+=buffer;
    }
    len2 = str2.length();
    for (i = 0;i < len2; i++){
                sheet2[str2[i]][countX[str2[i]]] = i;
                countX[str2[i]]++;
    }
    cout << str1 << endl;
    cout << str2 << endl;

    
    for (i = 0; i < len1; i++){
        for (j = 0;j < countX[str1[i]]; j++){
            num[i][j] = i - sheet2[str1[i]][j];
            n[i - sheet2[str1[i]][j]+400]++;
            cout<<i - sheet2[str1[i]][j]<<"  ";
        }
    }
    cout<<endl;
    max = 0;
    for(i = 0; i <800; i++){
        if (n[i]>max){
            max =n[i];
        }
    }
    cout<<max<<endl;
    for(i = 0; i <800; i++){
        if (n[i]==max){
            dis[k] = i -400;
            k++;
        }
    }
    for (;k>0;k--) {
        cout<<dis[k-1]<<endl;
        for (i = 0; i < len1; i++){
            for (j = 0;j < countX[str1[i]]; j++){
                if(num[i][j] == dis[k-1]){
                    cout<<str1[i];
                }
            }
        }
        cout<<endl;
    }

    return 0;
}

