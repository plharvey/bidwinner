//
//  BidDatabase.h
//  Bid Helper
//
//  Created by Patrick Harvey on 5/28/15.
//  Copyright (c) 2015 Patrick Harvey. All rights reserved.
//

#ifndef __Bid_Helper__BidDatabase__
#define __Bid_Helper__BidDatabase__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class BidDatabase
{
public:
    BidDatabase();
    string GetJobName();
    void GetJobType();
    void PrintJobTypeMenuAndGetJobType(ostream& outfile);
    void PrintMenuOfSpecifiedTypeAndAddToCostList(ostream& outfile);
    void GetMaterialsAndLabor();
    
    void PrintAdditionMenu(ostream& outfile);
    void PrintKitchenRemodelMenu(ostream& outfile);
    void PrintBathRemodelMenu(ostream& outfile);
    void PrintShowerOnlyMenu(ostream& outfile);
    
    
    void AddToTotalCost(float labor, float materials);    //adds each entry to cost
    void AddInsurance();
    float GetTotalLaborCost();
    float GetTotalMaterialsCost();
    void AddProfit();
    void GetTotal();
    void PrintEverything(string jobName, ofstream& outfile);
    
    int jobTypeChoice;      //number of choice of type of job
    
    
protected:
    
    struct JobPhase
    {
        string phaseName;
        float laborAmt;
        float materialsAmt;
    };
    
    
    vector< JobPhase > costList;
    vector< JobPhase >::iterator it;
    
    JobPhase section;
    string _jobName;
    string _jobType;
    
    float _totalCost;
    float _laborTotal;
    float _materialsTotal;
    float _insuranceCost;
    float _profitAmount;

    

    
public:
    
    vector<string> jobTypeItems;        //vector to hold types of jobs for menu
    vector<string> additionItems;       //vector to hold addition menu items
    vector<string> bathRemodelItems;    //vector of bath remodel items for menu
    vector<string> kitchenRemodelItems; //vector of kitchen remodel items for menu
    vector<string> showerOnlyItems;     //vector of shower only items for menu
    
};



#endif /* defined(__Bid_Helper__BidDatabase__) */
