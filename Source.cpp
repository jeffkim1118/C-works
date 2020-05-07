#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX_NAMES = 6000;

int openFile(string namesList[], string filename) {

	int numofNames = 0;

	ifstream inputFile;
	inputFile.open(filename);
	// If the file can't be opened, display a warning sign
	// Otherwise, proceed to the next step
	if (!inputFile) {
		cout << "Error: not able to open the file" << filename << endl;
	}
	else {
		string name;
		int i = 0;
		while (inputFile >> name && (numofNames < MAX_NAMES)){
			namesList[i] = name;
			i++;
			numofNames++;
		}
		inputFile.close();
	}
	return numofNames;
}


int printNamesWithK(string names[], int nameCount) {
	// Keep the count of the number of names that has the first letter of my last name.
	int countMatchingNamesWithK = 0;

	// Used a for loop to set a range for names
	for (int x = 0; x < nameCount; x++) {
		string stringEle = names[x];
		int stringLength = stringEle.length();
		// This for loop is to set a range within individual string(name)
		// this loop will test each index values if there are any 'K' in it
		for (int i = 0; i < stringLength; i++) {
			//My last name is KIM
			//The first letter from my last name is 'K'
			if (stringEle[i] == 'K') {
				//if the condition is true, then increment the counter.
				countMatchingNamesWithK++;
				i++;
			}
		}
	}
	return countMatchingNamesWithK;
}


int main() {
	string namesArray[MAX_NAMES];
	// I have a window computer.
	//This is my path to the text file that I used.
	//Please check the text file location before grading it
	string filename = "C:\\Users\\Jeffrey\\Desktop\\names.txt";
	
	//Function 1 : Counting the total number of the names in the file.
	int nameCount = openFile(namesArray, filename);
	//Function 2 : Searching for names that has 'K' in it.
	int nameCountOfK = printNamesWithK(namesArray, nameCount);

	cout << nameCountOfK << endl;

	return 0;
}
