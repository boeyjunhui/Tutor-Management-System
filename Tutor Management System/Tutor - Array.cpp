#include <iostream>

#include <string>
#include <iomanip>
#include "Validation.h"

using namespace std;
string TutorArray[100][13] = { { "1", "John", "20/1/2018", "30/6/2019", "15.00", "john@gmail.com", "0123456789", "6, Jalan Cheras, Taman Cheras, 56100 Chearas, Kuala Lumpur.", "CRS1001", "eXcel Tuition Center (Cheras)", "PHY1234", "Physics", "4.5"},
	{"2", "May", "6/3/2018", "NA", "18.00", "may@gmail.com", "0184628592", "6, Jalan Cheras, Taman Cheras, 57000 Chearas, Kuala Lumpur.", "CRS1001", "eXcel Tuition Center (Cheras)", "AM2280", "Additional Mathematics", "4.8"},
	{"3", "Brian", "3/8/2019", "NA", "17.00", "brian@gmail.com", "0118427585", "23-A, Jalan Jalil, 57000 Bukit Jalil, Kuala Lumpur.", "BKJ1001", "eXcel Tuition Center (Bukit Jalil)", "MAT3125", "Mathematics", "4.6"}

};

int getRow()
{
	//calculate size
	int arraySize = sizeof(TutorArray) / sizeof(TutorArray[0]);
	int row = 0;
	while (row < arraySize && TutorArray[row][0] != "") { row++; }
	return row;
}

void displayTutor() {

	cout << string(40, '-') << " TUTOR RECORD LIST " << string(40, '-') << endl << endl;

	int row = 0;
	while (row < getRow())
	{
		cout << string(40, '-') << " [" << "Position: " << row + 1 << "] " << string(40, '-') << endl;
		cout << "Tutor ID\t\t: " << stoi(TutorArray[row][0]) << "\n" <<
			"Name\t\t\t: " << TutorArray[row][1] << "\n" <<
			"Date Joined\t\t: " << TutorArray[row][2] << "\n"
			"Date Terminated\t\t: " << TutorArray[row][3] << "\n" <<
			"Hourly Pay Rate\t\t: RM " << fixed << setprecision(2) << stod(TutorArray[row][4]) << "\n" <<
			"Email\t\t\t: " << TutorArray[row][5] << "\n" <<
			"Phone Number\t\t: " << TutorArray[row][6] << "\n" <<
			"Address\t\t\t: " << TutorArray[row][7] << "\n" <<
			"Tuition Center Code\t: " << TutorArray[row][8] << "\n" <<
			"Tution Center Name\t: " << TutorArray[row][9] << "\n" <<
			"Subject Code\t\t: " << TutorArray[row][10] << "\n" <<
			"Subject Name\t\t: " << TutorArray[row][11] << "\n" <<
			"Rating\t\t\t: " << fixed << setprecision(1) << stod(TutorArray[row][12]) << endl << endl;
		cout << endl;

		row++;
	}
}


void addTutor() {

	// variables to read from user input
	int userInput = 1;
	int tutorID = 4;
	string name;
	int day = 1;
	int month = 1;
	int year = 2000;
	string dateJoined;
	string dateTerminated;
	double hourlyPayRate = 0.0;
	string email;
	string phoneNumber;
	string address;
	string tuitionCenterCode;
	string tuitionCenterName;
	string subjectCode;
	string subjectName;
	double rating = 0;


	displayTutor();

	// ask user if they want to start adding tutor list
	cout << "Enter: 1- Start Adding Tutor, Others- Exit Add Tutor: ";
	cin >> userInput;
	cout << endl;

	if (userInput == 1)
	{
		while (userInput == 1)
		{
			// name
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Name: ";
				getline(cin, name);
			} while (cin.fail() || !nameValidation(name));

			// date joined
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Date Joined:-\nEnter Day: ";
				cin >> day;
				cout << "Enter Month: ";
				cin >> month;
				cout << "Enter Year: ";
				cin >> year;

				dateJoined = to_string(day) + '/' + to_string(month) + '/' + to_string(year);
			} while (cin.fail() || !dateValidation(day, month, year));

			// date terminated
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Is this tutor terminated? 1- Yes, Others- No: ";
			cin >> userInput;

			do
			{
				if (userInput == 1)
				{
					cout << "Enter Date Terminated:-\nEnter Day: ";
					cin >> day;
					cout << "Enter Month: ";
					cin >> month;
					cout << "Enter Year: ";
					cin >> year;

					dateTerminated = to_string(day) + '/' + to_string(month) + '/' + to_string(year);
				}
				else
				{
					dateTerminated = "NA";
				}
			} while (cin.fail() || !dateValidation(day, month, year));

			// hourly pay rate
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Hourly Pay Rate: ";
				cin >> hourlyPayRate;
			} while (cin.fail());

			// email
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Email: ";
				cin >> email;
			} while (cin.fail() || !emailValidation(email));

			// phone number
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Phone Number: ";
				cin >> phoneNumber;
			} while (cin.fail() || !phoneNumberValidation(phoneNumber) || phoneNumber.length() < 10 || phoneNumber.length() > 11);

			// address
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Address: ";
			getline(cin, address);

			// tuition center code
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Tuition Center Code: ";
				cin >> tuitionCenterCode;
			} while (cin.fail() || !tuitionCenterCodeValidation(tuitionCenterCode));

			// tuition center name
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Tuition Center Name: ";
			getline(cin, tuitionCenterName);

			// subject code
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Subject Code: ";
				cin >> subjectCode;
			} while (cin.fail() || !subjectCodeValidation(subjectCode));

			// subject name
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Subject Name: ";
			getline(cin, subjectName);;

			// rating
			do
			{
				cin.clear(); // remove the input operation
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Rating: ";
				cin >> rating;
			} while (cin.fail() || rating < 0 || rating > 5);

			// add to array

			//get row size
			int row = getRow();

			TutorArray[row][0] = to_string(tutorID);
			TutorArray[row][1] = name;
			TutorArray[row][2] = dateJoined;
			TutorArray[row][3] = dateTerminated;
			TutorArray[row][4] = to_string(hourlyPayRate);
			TutorArray[row][5] = email;
			TutorArray[row][6] = phoneNumber;
			TutorArray[row][7] = address;
			TutorArray[row][8] = tuitionCenterCode;
			TutorArray[row][9] = tuitionCenterName;
			TutorArray[row][10] = subjectCode;
			TutorArray[row][11] = subjectName;
			TutorArray[row][12] = to_string(rating);


			tutorID++;

			// ask user if they want to add additional tutor list
			cout << endl << "Do you want to add additional tutor record? 1- Yes, Others- No: ";
			cin >> userInput;
			cout << endl;
		}
	}

	displayTutor();
}

void editTutor();
void deleteTutor();

//		quick sort code
int partition(string TutorArray[][13], int start, int end, int sortField)
{

	if (sortField == 1) 
	{
		//tutor Id
		int pivot = stoi(TutorArray[start][0]);

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (stoi(TutorArray[i][0]) <= pivot)
				count++;
		}

		// Giving pivot element  correct position
		int pivotIndex = start + count;
		swap(TutorArray[pivotIndex], TutorArray[start]);

		// Sorting left and right pivot elements
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (stoi(TutorArray[i][0]) <= pivot) {
				i++;
			}

			while (stoi(TutorArray[j][0]) > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(TutorArray[i++], TutorArray[j--]);
			}
		}
		return pivotIndex;


	}
	else if (sortField == 2)
	{
		//hourly pay rate
		double pivot = stod(TutorArray[start][4]);

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (stod(TutorArray[i][4]) <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(TutorArray[pivotIndex], TutorArray[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (stod(TutorArray[i][4]) <= pivot) {
				i++;
			}

			while (stod(TutorArray[j][4]) > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(TutorArray[i++], TutorArray[j--]);
			}
		}

		return pivotIndex;

	}
	else if (sortField == 3)
	{
		//rating
		double pivot = stod(TutorArray[start][12]);

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (stod(TutorArray[i][12]) <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(TutorArray[pivotIndex], TutorArray[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (stod(TutorArray[i][12]) <= pivot) {
				i++;
			}

			while (stod(TutorArray[j][12]) > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(TutorArray[i++], TutorArray[j--]);
			}
		}

		return pivotIndex;

	}
}
void quickSort(string  TutorArray[][13], int start, int end, int sortField)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(TutorArray, start, end, sortField);

	// Sorting the left part
	quickSort(TutorArray, start, p - 1,  sortField);

	// Sorting the right part
	quickSort(TutorArray, p + 1, end, sortField);
}
//		quick sort code end here


//		linear search code
bool linearSearch()
{
	// store position 
	int position = 0;
	// if search term exist
	bool found = false;

	// todo complete this add the loop and error thing when input is incorrect
	int searchType = 0;
	int searchId = 0;
	double searchRating = 0;

	// ask user to select field to search from
	cout << "Please Select search type: " << endl << "1-Tutor ID, 2-Rating: ";
	cin >> searchType;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	if (searchType == 1)
	{
		cout << "Please enter Id: ";
		cin >> searchId;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//go throgh the array (for id)
		while (stoi(TutorArray[position][0]) != searchId && position < getRow()) {
			// Update position
			position++;
		}
		// print print out the index
		if (stoi(TutorArray[position][0]) == searchId) {

			// todo add printing the details
			cout << "Found id at :" << position + 1 << endl;

			//item found
			found = true;
		}
	}

	else if (searchType == 2)
	{
		cout << "Please enter rating: ";
		cin >> searchRating;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// go throgh the whole array (for rating)
		while (position < getRow()) {

			// print print out the index
			if (stod(TutorArray[position][2]) == searchRating) {

				// todo add printing the details
				cout << "Found at :" << position + 1 << endl;

				//item found
				found = true;
			}
			// Update position
			position++;
		}

	}
	else
	{
		cout << "Invalid input ";

	}


	// return T = found element, F = element not found
	return found;
}
//		linear search code end here


int main() {
	addTutor();

	// searching
	cout << linearSearch() << endl;
	//will show T or F success or F



	// todo menu for sort add the loop and error thing here the invalid input
	int sortField = 0;
	// ask user to select field to sort with MUST PUT HERE BECASUE THE FUNCTION ABOVE ALL ARE RECURSUE
	cout << "sort" << endl;
	cout << "Please Select Field to sort: " << endl << "1-Tutor ID, 2-Hourly Pay Rate, 3-Rating: ";
	cin >> sortField;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	quickSort(TutorArray, 0, getRow() - 1, sortField);




	displayTutor();


	return 0;
}