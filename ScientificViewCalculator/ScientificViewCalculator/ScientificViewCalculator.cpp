// ScientificViewCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Calculator.h"

using namespace std;


void main()
{
    Calculator Calc1;
    string form;
    char var;
    double value;
    
    while(true){
        cout<< "Please, enter your formula:"; cin>>form;
        cout<< "enter your variable:"; cin>>var;
        cout<<"Enter " <<var<<" value:"; cin >> value;
        cout<< "result = "<<c1.calc(form, var, value)<<endl;
        getche();
        system("cls");        
        
    }
}

