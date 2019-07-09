/***********************************************************
 Limbana Garcia            Total Points:  10
 Due Date:  2/4/2013
 Course:  C0P3014
 Assignment:  Assignment 1
 Professor: Dr. Lofton Bullard
 
 Description: This is a program called "call_cost_calculator.cpp" that calculates the net cost of a call (net_cost), the tax on a call (call_tax) and the total cost of the call (total_cost).
 
 
 *************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string user_response = "y";
    long cell_num;
    int relays;
    int call_length;
    double tax_rate = 0.0;
    double net_cost;
    double call_tax;
    double total_cost;
    
    while (user_response == "y" || user_response == "Y")
    {
        
        // phone number
        cout<<"Enter a phone number: ";
        cin>>cell_num;
        
        // # of relays
        cout<<"\nEnter the number of relay stations: ";
        cin>>relays;
        
        // length of the call
        cout<<"\nEnter the length of the call in minutes: ";
        cin>>call_length;
        
        // tax rate
        if (0<= relays && relays <=5){
            tax_rate = 0.01;
        }
        else if(6<= relays && relays <=11){
            tax_rate = 0.03;
        }
        else if (12<= relays && relays <=20){
            tax_rate = 0.05;
        }
        else if (21<= relays && relays <=50){
            tax_rate = 0.08;
        }
        else if (relays >50){
            tax_rate = 0.12;
        }
        
        // calculations
        net_cost = ( relays / 50.0 * 0.40 * call_length);
        call_tax = net_cost * tax_rate;
        total_cost = net_cost + call_tax;
        
        // output
        cout<<"\n  Field              Format           "<<endl;
        cout<<"======================================"<<endl;
        cout<<"Cellphone              "<<cell_num<<endl;
        cout<<"# of relay stations    "<<relays<<endl;
        cout<<"Minutes used           "<<call_length<<endl;
        cout<<"Net cost               "<<net_cost<<endl;
        cout<<"Tax rate               "<<tax_rate<<endl;
        cout<<"Call tax               "<<call_tax<<endl;
        cout<<"Total cost of call     "<<total_cost<<endl;
        
        // continue ?
        cout<<"Would you like to do another calculation (Y or N): "<<endl;
        cin>>user_response;
       
    }
    
    
    return  0;
}



