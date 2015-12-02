//
//  main.cpp
//  Bid Helper
//
//  Created by Patrick Harvey on 5/22/15.
//  Copyright (c) 2015 Patrick Harvey. All rights reserved.
//

/*
    1)  output file name is determined (from the name of the job given by user)
    2)  job "type" is determined.. (room addition, remodel, etc)
    3)  a menu loops to allow user to select different specifics of the job,
        then the labor and material costs for each part are added.
            -the menu loops until user selects "exit" option from menu
    4)  adds insurance based on total cost up to this point
    5)  adds profit based on user input
    6)  print the output file with information on it
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "BidDatabase.h"

using namespace std;

int main(int argc, const char * argv[])
{
    BidDatabase entries;        //not sure "database" is the correct term..
    ofstream bidOutput;
    
    string jobName = entries.GetJobName();     //prompt user for job name
    string outputFileName = jobName + ".txt";  //saves name for the job
    cout << string(50, '\n');     //"clears" screen
    bidOutput.open(outputFileName);
    
    entries.PrintJobTypeMenuAndGetJobType(bidOutput);               //menu for types of job
    entries.PrintMenuOfSpecifiedTypeAndAddToCostList(bidOutput);    //loops for items to add to cost list
    entries.AddInsurance();                                         //user add insurance
    entries.AddProfit();                                            //user add profit
    entries.GetTotal();                                             //prints total cost to standard output
    entries.PrintEverything(jobName, bidOutput);                    //prints the output file
    bidOutput.close();                                              //clost output file
    
    cout << endl << "the end, eh. Your food is ready." << endl;
    return 0;
}



