
/***********************************************************************************************************************

 Name: Limbana Garcia      Z#: 23315062
 Course: Foundations of Computer Science (COP3014)
 Professor: Dr. Lofton Bullard
 Due Date: May 29. 2019     Due Time: 11:59pm
 Total Points: 20
 Assignment #2: amazon_orders.cpp

 Description:

 **********************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*********************************************************
 //Following is the declaration of a order record
 **********************************************************/
class order_record
{
public:
    string cell_number;
    string item_number;
    double quantity;
    double price;
    int processing_plant;
    double tax_rate;
    double order_tax;
    double net_cost;
    double total_cost;
};


//Prototypes for your functions: input, output, and process will go here

void input(ifstream &, order_record &);
void output(const order_record &);
void process(order_record &);

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:
// Example:Get input (values of cell_number, item_number, quantity, price, processing_plant )
//from data file order record (p_record).

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream & in, order_record & p_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
    in >> p_record.cell_number;
    in >> p_record.item_number;
    in >> p_record.quantity;
    in >> p_record.price;
    in >> p_record.processing_plant;

    //add more code to read the rest of the fields (item_number, quantity, price and processing_plant) into the
    //order record, p_record.
}

///*************************************************************************************
//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

void output(const order_record & p_record)
{
    //Use thee following statement to help you format you our output. These statements are called the magic formula.
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);
    /********************************************/

    cout << p_record.cell_number << "\t";
    cout << p_record.item_number << "\t";
    cout << p_record.quantity << "\t";
    cout << p_record.price << "\t";
    cout << p_record.processing_plant << "/t";
    cout << p_record.tax_rate << "\t";
    cout << p_record.order_tax << "\t";
    cout << p_record.net_cost << "\t";
    cout << p_record.total_cost << "\t";

    //cout << p_record.cell_number << "\t";
    //add more code to print all the fields in the order record


}

///*************************************************************************************
//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

//Note: there is one 1 input/output parameter
void process(order_record & p_record)
{

    if (0 <= p_record.processing_plant && p_record.processing_plant <= 50){
        p_record.tax_rate = 0.06;
    }

        else if (51 <= p_record.processing_plant && p_record.processing_plant <= 110){
            p_record.tax_rate = 0.07;
        }

            else if (111 <= p_record.processing_plant && p_record.processing_plant <= 200){
                p_record.tax_rate = 0.08;
            }

                else if (201 <= p_record.processing_plant && p_record.processing_plant <= 500){
                    p_record.tax_rate = 0.09;
                }

                else{
                    p_record.tax_rate = 0.11;
                }

    p_record.order_tax = p_record.quantity * p_record.price * p_record.tax_rate;

    p_record.net_cost = p_record.quantity * p_record.price;

    p_record.total_cost = p_record.net_cost + p_record.order_tax;



}


int main()
{

    order_record customer_record;

    ifstream in;    //declaring an input file stream
    in.open("purchase_data.txt");

    if (in.fail())
    {
        cout << "Input file did not open correctly" << endl;
    }
    else
    {
        while (!in.eof())
        {
            input(in, customer_record);
            process(customer_record);
            output(customer_record);
        }
    }

    in.close();

    return 0;
}
