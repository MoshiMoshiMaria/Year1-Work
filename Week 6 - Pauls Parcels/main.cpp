//All seems to be working fully - and 3 week before schedule

#include <iostream>
#include <cmath>

using namespace std;

//Pseudocode in documents/school work/DMU/C++/ and on school onedrive
int main()
{
	int numberOfVans = 0;//Intialise the numberOfVans variable
	float heaviestLoad = 0;//Initialise the heaviestLoad variable
	float parcels[500];//Set up the array for the parcels
	int parcelIndex = 0;//Set up up variable to referencing array positions

	float currentParcelWeight;//Set up variable for parcel weight input
	do {
		currentParcelWeight = 0.0;//Set parcel Weight to 0
		cout << "Insert next parcel's weight or -1 to stop: ";//Prompt input from user
		cin >> currentParcelWeight;//Get input from user
		if (currentParcelWeight <= 120)  { //Make sure the weight is under 240kg
			parcels[parcelIndex] = currentParcelWeight;//Add the parcel weight to the end of the array
		parcelIndex++;//increment the end pointer
		}
		else {
			cout << endl << "Parcel is too heavy and has been dropped";
		}
		cout << endl;//Start on a new line
	} while (currentParcelWeight != -1);//END DO WHILE
	parcelIndex = 0;//Reset the index variable
	float currentVanWeight;//Set up varibale for the current van weight
	bool vanNotFull;//Set up loop condition variable
	while (parcels[parcelIndex] != -1) {
		currentVanWeight = 0; //Reset the current van weight variable
		vanNotFull = true; //Set up loop condition variable
		while (vanNotFull) {
			if (parcels[parcelIndex] == -1) {//If at the end of the parcel array...
				vanNotFull = false;
				break; //Break the while loop?
			}
			else {
				if (currentVanWeight + parcels[parcelIndex] < 750) {//Check if there is sapce in the van for the next parcel
					currentVanWeight += parcels[parcelIndex];//Add the parcel if there is space
					parcelIndex++;//Increment the array pointer
				}
				else {
					vanNotFull = false;//If there is no space, break the loop, start on the next van
				}//END IF
			}
		}//END WHILE
		numberOfVans += 1; //Once a van is full, 
		if (currentVanWeight > heaviestLoad) { //If the van is heavier than the heaviest recorded load...
			heaviestLoad = currentVanWeight; //Update the heaviest load variable
		}//END IF
	}//END WHILE

	//OUTPUT the results
	system("cls"); //Clear the console
	cout << endl;
	cout << "All parcels are loaded." << endl; //Print finish message
	cout << numberOfVans << " vans were used." << endl; //Display the number of vans used
	cout << "The heaviest load was " << heaviestLoad << "Kg." << endl; // Display the heaviest load
	system("pause"); //Pause the program
	return 0; //END PROGRAM
}