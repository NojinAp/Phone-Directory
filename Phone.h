/*
    ==================================================
    Phone Directory
    ==================================================
*/

#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

#define NUM_OF_RECORDS 37

namespace sdds 
{
	const int MAX_NAME_LEN = 51;
	const int AREA_LEN = 4;
	const int PREFIX_LEN = 4;
	const int NUMBER_LEN = 5;

	struct Record
	{
		char name[MAX_NAME_LEN];
		char area[AREA_LEN];
		char prefix[PREFIX_LEN];
		char number[NUMBER_LEN];
	};

	void programtitle(const char* title);
	void searchRecord(const Record* record);
	void phoneDir(const char* programTitle, const char* fileName);
}

#endif
