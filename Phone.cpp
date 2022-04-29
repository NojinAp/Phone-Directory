/*
    ==================================================
    Phone Directory
    ==================================================
    Name   : Nozhin Azarpanah
    Date   : January 23, 2022
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

#include "Phone.h"
#include "cStrTools.h"

using namespace std;

namespace sdds 
{
    //shows the title of the program
    void programtitle(const char* title) 
    {
        cout << title << " phone direcotry search\n-------------------------------------------------------\n";
    }

    //searches for the record
    void searchRecord(const Record* record) 
    {
        char searchName[MAX_NAME_LEN];
        char lowerCaseSearchName[MAX_NAME_LEN];
        char lowerCaseRecordName[MAX_NAME_LEN];

        do
        {
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl << "> ";
            cin >> searchName;
            toLowerCaseAndCopy(lowerCaseSearchName, searchName);
            for (int i = 0; i < NUM_OF_RECORDS; i++)
            {
                toLowerCaseAndCopy(lowerCaseRecordName, record[i].name);
                if (strStr(lowerCaseRecordName, lowerCaseSearchName) == nullptr) 
                {

                }
                else 
                {
                    cout << record[i].name << ": (" << record[i].area << ") " << record[i].prefix << "-" << record[i].number << endl;
                }
            }

        } while (strCmp(searchName, "!") != 0);
    }

    //runs the phone directory appication
    void phoneDir(const char* programTitle, const char* fileName) 
    {
        programtitle(programTitle);
        FILE* fptr = fopen(fileName, "r");
        Record records[NUM_OF_RECORDS] = { };
        if (fptr == NULL) 
        {
            cout << fileName << " file not found!" << endl;
        }
        else
        {
            for (int i = 0; i < NUM_OF_RECORDS && !feof(fptr); i++)
            {
                fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", records[i].name, records[i].area, records[i].prefix, records[i].number);
            }
            fclose(fptr);
            searchRecord(records);
        }
        cout << "Thank you for using " << programTitle << " directory." << endl;
    }
}

