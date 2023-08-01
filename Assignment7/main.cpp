/*********************
Name: Kaden Misenheimer
Assignment 7: Hash Tables
Purpose: This file builds test data and thoroughly tests the Hash Table ADT in every case possible.
**********************/


#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    HashTable hashTable;
    int randomData = (rand() % testdatasize);

    // show it is empty by calling getCount and printTable
    cout << "PRINTING EMPTY TABLE" << endl;
    cout << "Count: " << hashTable.getCount() << endl;
    hashTable.printTable();

    //EMPTY TESTS
    cout << "\nEMPTY TABLE TESTS" << endl;
    //remove
    randomData = (rand() % testdatasize);
    cout << "Removing " << ids[randomData] << ": ";
    if (hashTable.removeEntry(ids[randomData])) {
        cout << "Success" << endl;
    } else
    {
        cout << "Failed" << endl;
    }
    //get
    randomData = (rand() % testdatasize);
    cout << "Getting " << ids[randomData] << ": " << hashTable.getData(ids[randomData]) << endl;
    //add
    randomData = (rand() % testdatasize);
    cout << "Adding " << ids[randomData] << " : " << strs[randomData] << ": ";
    if (hashTable.insertEntry(ids[randomData], &strs[randomData])) {
        cout << "Success" << endl;
    } else {
        cout << "Failed" << endl;
    }


    // try and put ALL the test data into the table and show what happens
    cout << "\nADDING ALL TEST DATA" << endl;
    for (int i = 0; i<testdatasize; i++) {
        cout << "Adding " << ids[i] << " : " << strs[i] << ": ";
        if (hashTable.insertEntry(ids[i], &strs[i])) {
            cout << "Success" << endl;
        } else
        {
            cout << "Failed" << endl;
        }
    }

    cout << "\nPRINTING FULL TABLE" << endl;
    cout << "Count: " << hashTable.getCount() << endl;
    hashTable.printTable();

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    //TESTING THE TABLE WITH ALL THE TEST DATA
    cout << "\nTESTS WITH ALL DATA" << endl;
    //add
    randomData = (rand() % testdatasize);
    cout << "Adding " << ids[randomData] << " : " << strs[randomData] << ": ";
    if (hashTable.insertEntry(ids[randomData], &strs[randomData])) {
        cout << "Success" << endl;
    } else {
        cout << "Failed" << endl;
    }
    //get
    randomData = (rand() % testdatasize);
    cout << "Getting " << ids[randomData] << ": " << hashTable.getData(ids[randomData]) << endl;
    //remove
    randomData = (rand() % testdatasize);
    cout << "Removing " << ids[randomData] << ": ";
    if (hashTable.removeEntry(ids[randomData])) {
        cout << "Success" << endl;
    } else
    {
        cout << "Failed" << endl;
    }

    //REMOVE HALF THE TEST DATA
    cout << "\nREMOVING HALF THE TEST DATA" << endl;
    for (int i = 0; i<testdatasize/2; i++) {
        cout << "Removing " << ids[i] << ": ";
        if (hashTable.removeEntry(ids[i])) {
            cout << "Success" << endl;
        } else
        {
            cout << "Failed" << endl;
        }
    }


    cout << "\nPRINTING HALF FULL TABLE" << endl;
    cout << "Count: " << hashTable.getCount() << endl;
    hashTable.printTable();

    //TESTING THE TABLE WITH HALF THE TEST DATA
    cout << "\nTESTS WITH HALF THE DATA" << endl;
    //add
    randomData = (rand() % testdatasize);
    cout << "Adding " << ids[randomData] << " : " << strs[randomData] << ": ";
    if (hashTable.insertEntry(ids[randomData], &strs[randomData])) {
        cout << "Success" << endl;
    } else {
        cout << "Failed" << endl;
    }
    //remove
    randomData = (rand() % testdatasize);
    cout << "Removing " << ids[randomData] << ": ";
    if (hashTable.removeEntry(ids[randomData])) {
        cout << "Success" << endl;
    } else
    {
        cout << "Failed" << endl;
    }
    //get
    randomData = (rand() % testdatasize);
    cout << "Getting " << ids[randomData] << ": " << hashTable.getData(ids[randomData]) << endl;


    //RANDOM TEST CASES
    cout << "\nRANDOM TEST CASES" << endl;

    for (int i =0; i<HASHTABLESIZE*HASHTABLESIZE*TESTDATAMULTIPLIER; i++) {
        //picks which test case to do
        int testCase = (rand() % 4) + 1;

        //picks which piece of the test data to interact with in the test
        int randomData = (rand() % testdatasize);

        switch (testCase) {
            case 1:
                //add case
                cout << "Adding " << ids[randomData] << " : " << strs[randomData] << ": ";
                if (hashTable.insertEntry(ids[randomData], &strs[randomData])) {
                    cout << "Success" << endl;
                } else
                {
                    cout << "Failed" << endl;
                }
                break;
            case 2:
                //remove case
                cout << "Removing " << ids[randomData] << ": ";
                if (hashTable.removeEntry(ids[randomData])) {
                    cout << "Success" << endl;
                } else
                {
                    cout << "Failed" << endl;
                }
                break;
            case 3:
                //get count case
                cout << "Count: " << hashTable.getCount() << endl;
                break;
            case 4:
                //get case
                cout << "Getting " << ids[randomData] << ": " << hashTable.getData(ids[randomData]) << endl;
                break;
        }
    }

    //FINAL TABLE PRINT
    cout << "\nPRINTING TABLE" << endl;
    cout << "Count: " << hashTable.getCount() << endl;
    hashTable.printTable();

    return 0;
}
