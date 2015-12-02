//
//  BidDatabase.cpp
//  Bid Helper
//
//  Created by Patrick Harvey on 5/28/15.
//  Copyright (c) 2015 Patrick Harvey. All rights reserved.
//

#include "BidDatabase.h"
#include <fstream>
#include <iomanip>

using namespace std;


BidDatabase::BidDatabase()
{
    //job type menu items
    jobTypeItems.push_back("Addition");            //0
    jobTypeItems.push_back("Kitchen Remodel");     //1
    jobTypeItems.push_back("Bath Remodel");        //2
    jobTypeItems.push_back("Shower Only");         //3
    
    //addition menu items
    additionItems.push_back("Permits");
    additionItems.push_back("Demolition");
    additionItems.push_back("Footings");
    additionItems.push_back("Foundation");
    additionItems.push_back("Framing");
    additionItems.push_back("Roofing");
    additionItems.push_back("R.I. Electrical");
    additionItems.push_back("R.I. Plumbing");
    additionItems.push_back("Insulation");
    additionItems.push_back("Drywall");
    additionItems.push_back("Interior Trim");
    additionItems.push_back("Flooring");
    additionItems.push_back("Interior Painting");
    additionItems.push_back("Electrical Trimout");
    additionItems.push_back("Plumbing Trimout");
    additionItems.push_back("Hardware");
    additionItems.push_back("HVAC");
    additionItems.push_back("Interior Cleanup");
    additionItems.push_back("Windows & Exterior Doors");
    additionItems.push_back("Exterior Trim");
    additionItems.push_back("Siding");
    additionItems.push_back("Exterior Painting");
    additionItems.push_back("Decks");
    additionItems.push_back("Concrete");
    additionItems.push_back("Yardwork");
    additionItems.push_back("Landscaping");
    additionItems.push_back("Exterior Cleanup");
    
    //bath remodel menu items
    bathRemodelItems.push_back("Permit");
    bathRemodelItems.push_back("Demo");
    bathRemodelItems.push_back("Framing");
    bathRemodelItems.push_back("Rough In - Plumbing");
    bathRemodelItems.push_back("Rough In - Wiring");
    bathRemodelItems.push_back("Insulation");
    bathRemodelItems.push_back("Drywall");
    bathRemodelItems.push_back("Interior Trim");
    bathRemodelItems.push_back("Flooring");
    bathRemodelItems.push_back("Heated Floor");
    bathRemodelItems.push_back("Shower");
    bathRemodelItems.push_back("Shower Door");
    bathRemodelItems.push_back("Cabinetry");
    bathRemodelItems.push_back("Tops");
    bathRemodelItems.push_back("Painting");
    bathRemodelItems.push_back("Hardware");
    bathRemodelItems.push_back("Plumbing Trim Out");
    bathRemodelItems.push_back("Wiring Trim Out");
    bathRemodelItems.push_back("Misc");
    bathRemodelItems.push_back("Scrap & Cleanup");
    
    //kitchen remodel menu items
    kitchenRemodelItems.push_back("Permit");
    kitchenRemodelItems.push_back("Demo");
    kitchenRemodelItems.push_back("Framing");
    kitchenRemodelItems.push_back("Plumbing R.I.");
    kitchenRemodelItems.push_back("Electrical R.I.");
    kitchenRemodelItems.push_back("Insulation");
    kitchenRemodelItems.push_back("Drywall");
    kitchenRemodelItems.push_back("Trim");
    kitchenRemodelItems.push_back("Flooring");
    kitchenRemodelItems.push_back("Cabinetry");
    kitchenRemodelItems.push_back("Counter Tops");
    kitchenRemodelItems.push_back("Painting");
    kitchenRemodelItems.push_back("Appliances");
    kitchenRemodelItems.push_back("Range Hood");
    kitchenRemodelItems.push_back("Plumbing Trim");
    kitchenRemodelItems.push_back("Electrical Trim");
    kitchenRemodelItems.push_back("Undercounter Lighting");
    kitchenRemodelItems.push_back("Tile Work (backplash, etc)");
    kitchenRemodelItems.push_back("Misc");
    kitchenRemodelItems.push_back("Other Work");
    kitchenRemodelItems.push_back("Cleanup");
    kitchenRemodelItems.push_back("Scrap");
    
    //shower only menu items
    showerOnlyItems.push_back("Demo");
    showerOnlyItems.push_back("Plumbing R.I.");
    showerOnlyItems.push_back("Electrical R.I.");
    showerOnlyItems.push_back("Insulation");
    showerOnlyItems.push_back("Drywall");
    showerOnlyItems.push_back("Shower-Tile");
    showerOnlyItems.push_back("Shower-Build");
    showerOnlyItems.push_back("Trim Work");
    showerOnlyItems.push_back("Painting");
    showerOnlyItems.push_back("Electrical Trim");
    showerOnlyItems.push_back("Plumbing Trim");
    showerOnlyItems.push_back("Shower Door");
    showerOnlyItems.push_back("Misc");
    showerOnlyItems.push_back("Other Work");
    showerOnlyItems.push_back("Clean Up");
    showerOnlyItems.push_back("Scrap");
}

//still needs to add name to file
string BidDatabase::GetJobName()
{
    string name;
    
    cout << "Enter Job Name: ";
    cin >> name;
    
    _jobName = name;
    return name;
}


void BidDatabase::PrintJobTypeMenuAndGetJobType(ostream& outfile)
{
    int choice = 0;
    cout << "Choose Job Type: " << endl;
    
    for(int i = 0; i < jobTypeItems.size(); i++)
        cout << "(" << i+1 << ") " << jobTypeItems[i] << endl;
    
    cin >> choice;
    cout << endl;
    
    if (choice < 1 || choice > jobTypeItems.size())
    {
        cout << "Invalid Choice." << endl;
        cin >> choice;
    }
    choice-=1;
    
    jobTypeChoice = choice;         // not sure what this is for
    _jobType = jobTypeItems[choice];
    
    cout << string(20, '\n');      //clear screen
}




void BidDatabase::PrintMenuOfSpecifiedTypeAndAddToCostList(ostream& outfile)
{
    switch (jobTypeChoice)
    {
        case 0:
            PrintAdditionMenu(outfile);
            break;
        case 1:
            PrintKitchenRemodelMenu(outfile);
            break;
        case 2:
            PrintBathRemodelMenu(outfile);
            break;
        case 3:
            PrintShowerOnlyMenu(outfile);
            break;
    }
}



//not being used  d-
void BidDatabase::GetMaterialsAndLabor()
{
    int choice = 0;
    float amt = 0.00;
    
    cout << "1. Calculate Labor Cost." << endl;
    cout << "2. Enter Predetermined Labor Cost" << endl;
    cin >> choice;
    
    while(choice != 1 && choice != 2)
    {
        cout << "1. Calculate Labor Cost." << endl;
        cout << "2. Enter Predetermined Labor Cost" << endl;
    }
    switch (choice)
    {
        case 1:
            
            section.laborAmt = 0;
            break;
        case 2:
            
            cout << "Labor Amount: ";
            cin >> amt;
            section.laborAmt = amt;
            break;
    }
    
    choice = 0;
    cout << endl;
    cout << "1. Calculate Material Cost" << endl;
    cout << "2. Enter Predetermined Material Cost" << endl;
    
    while(choice != 1 && choice != 2)
    {
        cout << "1. Calculate Material Cost" << endl;
        cout << "2. Enter Predetermined Material Cost" << endl;
    }
    switch (choice)
    {
        case 1:
            section.materialsAmt = 0;
            break;
        case 2:
            cout << "Materials Amount: ";
            cin >> amt;
            section.materialsAmt = amt;
            break;
    }
    
}

void BidDatabase::PrintAdditionMenu(ostream& outfile)
{
    float laborAmt = 0;
    float materialsAmt = 0;
    int choice;
    
    //prints menu for addition job
    for(int i = 0; i < additionItems.size(); i++)
    {
        cout << "(" << i << ") " << additionItems[i] << endl;
    }
    
    cout << "(99) Exit Menu" << endl;
    cin >> choice;
    cout << endl;
    
    section.phaseName = additionItems[choice];
    
    while (choice != 99)
    {
        //get labor cost for choice by user
        cout << "Enter labor cost for " << additionItems[choice] << ": ";
        cin >> laborAmt;
        section.laborAmt = laborAmt;
        
        //get material cost for choice by user
        cout << "Enter material cost for " << additionItems[choice] << ": ";
        cin >> materialsAmt;
        section.materialsAmt = materialsAmt;
        
        costList.push_back(section);
        
        AddToTotalCost(laborAmt, materialsAmt);     //add to totals
        
        for (int i = 0; i < 10; i++)    //clears screen
            cout << endl;
        
        //prints menu for addition job again
        for(int i = 0; i < additionItems.size(); i++)
        {
            cout << "(" << i << ") " << additionItems[i] << endl;
        }
        cout << "(99) Exit Menu" << endl;
        cin >> choice;
        cout << endl;
        section.phaseName = additionItems[choice];
    }
}


void BidDatabase::PrintKitchenRemodelMenu(ostream& outfile)
{
    float laborAmt = 0;
    float materialsAmt = 0;
    int choice = -1;
    
    
    //prints menu for kitchenRemodel job
    for(int i = 0; i < kitchenRemodelItems.size(); i++)
    {
        cout << "(" << i << ") " << kitchenRemodelItems[i] << endl;
    }
    cout << "(99) Exit Menu" << endl;
    cin >> choice;
    cout << endl;
    
    section.phaseName = kitchenRemodelItems[choice];
    
    while (choice != 99)
    {
        //get labor cost for choice by user
        cout << "Enter labor cost for " << kitchenRemodelItems[choice] << ": ";
        cin >> laborAmt;
        section.laborAmt = laborAmt;
        
        //get material cost for choice by user
        cout << "Enter material cost for " << kitchenRemodelItems[choice] << ": ";
        cin >> materialsAmt;
        section.materialsAmt = materialsAmt;
        
        costList.push_back(section);
        
        AddToTotalCost(laborAmt, materialsAmt);     //add to totals
        
        for (int i = 0; i < 10; i++)    //clears screen
            cout << endl;
        
        //prints menu for kitchenRemodel job again
        for(int i = 0; i < kitchenRemodelItems.size(); i++)
        {
            cout << "(" << i << ") " << kitchenRemodelItems[i] << endl;
        }
        cout << "(99) Exit Menu" << endl;
        cin >> choice;
        cout << endl;
        section.phaseName = kitchenRemodelItems[choice];
    }
    
    
}

//not done. copy from addition
void BidDatabase::PrintBathRemodelMenu(ostream& outfile)
{
    float laborAmt = 0;
    float materialsAmt = 0;
    int choice = -1;
    
    
    //prints menu for bathRemodel job
    for(int i = 0; i < bathRemodelItems.size(); i++)
    {
        cout << "(" << i << ") " << bathRemodelItems[i] << endl;
    }
    cout << "(99) Exit Menu" << endl;
    cin >> choice;
    cout << endl;
    
    section.phaseName = bathRemodelItems[choice];
    
    while (choice != 99)
    {
        //get labor cost for choice by user
        cout << "Enter labor cost for " << bathRemodelItems[choice] << ": ";
        cin >> laborAmt;
        section.laborAmt = laborAmt;
        
        //get material cost for choice by user
        cout << "Enter material cost for " << bathRemodelItems[choice] << ": ";
        cin >> materialsAmt;
        section.materialsAmt = materialsAmt;
        
        costList.push_back(section);
        
        AddToTotalCost(laborAmt, materialsAmt);     //add to totals
        
        for (int i = 0; i < 10; i++)    //clears screen
            cout << endl;
        
        //prints menu for bathRemodel job again
        for(int i = 0; i < bathRemodelItems.size(); i++)
        {
            cout << "(" << i << ") " << bathRemodelItems[i] << endl;
        }
        cout << "(99) Exit Menu" << endl;
        cin >> choice;
        cout << endl;
        section.phaseName = bathRemodelItems[choice];
    }
    
}

//not done. copy from addition
void BidDatabase::PrintShowerOnlyMenu(ostream& outfile)
{
    float laborAmt = 0;
    float materialsAmt = 0;
    int choice = -1;
    
    
    //prints menu for shower only job
    for(int i = 0; i < showerOnlyItems.size(); i++)
    {
        cout << "(" << i << ") " << showerOnlyItems[i] << endl;
    }
    cout << "(99) Exit Menu" << endl;
    cin >> choice;
    cout << endl;
    
    section.phaseName = showerOnlyItems[choice];
    
    while (choice != 99)
    {
        //get labor cost for choice by user
        cout << "Enter labor cost for " << showerOnlyItems[choice] << ": ";
        cin >> laborAmt;
        section.laborAmt = laborAmt;
        
        //get material cost for choice by user
        cout << "Enter material cost for " << showerOnlyItems[choice] << ": ";
        cin >> materialsAmt;
        section.materialsAmt = materialsAmt;
        
        costList.push_back(section);
        
        AddToTotalCost(laborAmt, materialsAmt);     //add to totals
        
        for (int i = 0; i < 10; i++)    //clears screen
            cout << endl;
        
        //prints menu for showerOnly job again
        for(int i = 0; i < showerOnlyItems.size(); i++)
        {
            cout << "(" << i << ") " << showerOnlyItems[i] << endl;
        }
        cout << "(99) Exit Menu" << endl;
        cin >> choice;
        cout << endl;
        section.phaseName = showerOnlyItems[choice];
    }
    


}

//takes labor and materials costs and adds to totals
void BidDatabase::AddToTotalCost(float labor, float materials)
{
    _totalCost = _totalCost + labor + materials;
}

void BidDatabase::AddInsurance()
{
    float size = costList.size();
    float laborTotal = 0;
    for (int i = 0; i < size; i++)
    {
        laborTotal += costList[i].laborAmt;
    }
    
    cout << "Labor total is $" << laborTotal << endl;
    cout << "Enter insurance amount: $";
    cin >> _insuranceCost;
    //should add this to bottom of outfile
    
    laborTotal += _insuranceCost;
}


float BidDatabase::GetTotalLaborCost()
{
    float size = costList.size();
    _laborTotal = 0;
    for (int i = 0; i < size; i++)
    {
        _laborTotal += costList[i].laborAmt;
    }
    
    _laborTotal += _insuranceCost;
    
    return _laborTotal;
    //add labor total to outfile.
}

float BidDatabase::GetTotalMaterialsCost()
{
    float size = costList.size();
    _materialsTotal = 0;
    for (int i = 0; i < size; i++)
    {
        _materialsTotal += costList[i].materialsAmt;
    }
    
    return _materialsTotal;
    //add labor total to outfile.
}

void BidDatabase::AddProfit()
{
    cout << "Enter Profit Amount: $";
    cin >> _profitAmount;
    cout << endl << endl;
}

//prints total amount of bid
void BidDatabase::GetTotal()
{
    cout << "Total Estimate Cost: $" << _totalCost << endl;
}

// sends all information to output file and adds in correct format
void BidDatabase::PrintEverything(string jobName, ofstream& outfile)
{
    float size = costList.size();
    float ttlBeforeProfit = 0;
    float totalBidAmt;
    
    outfile << "Job Name: " << jobName << endl << endl;
    outfile << setw(35) << left << "Section";
    outfile << setw(15) << left << "Labor";
    outfile << setw(15) << left << "Materials" << endl << endl;
    
    for (int i = 0; i < size; i++)
    {
        outfile << setw(35) << left << costList[i].phaseName;
        outfile << setw(15) << left << costList[i].laborAmt;
        outfile << setw(15) << left << costList[i].materialsAmt << endl;
    }
    
    outfile << setw(35) << left << "Insurance";
    outfile << setw(15) << left << _insuranceCost << endl << endl;
    
    outfile << "____________________________________________________" << endl;
    
    
    
    outfile << setw(35) << left << "Labor & Materials Totals: ";
    outfile << setw(15) << left << GetTotalLaborCost();
    outfile << setw(15) << left << GetTotalMaterialsCost() << endl;
    ttlBeforeProfit = GetTotalLaborCost() + GetTotalMaterialsCost();
    
    
    outfile << setw(35) << "Total Before Profit:";
    outfile << setw(9) << right << ttlBeforeProfit << endl;
    
    
    outfile << setw(35) << left << "Profit";
    outfile << setw(9) << right << _profitAmount << endl;
    totalBidAmt = ttlBeforeProfit + _profitAmount;
    
    outfile << endl;
    outfile << setw(35) << left << "Total Bid Amount";
    outfile << setw(9) << right << totalBidAmt;
}

