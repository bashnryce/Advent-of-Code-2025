/*
Psuedo code
given a range of numbers 
example: 11-22, 95-115, etc.
find all numbers that are symmetrical
example: 55 6464 123123
add all of these numbers that match the pattern together

we can ignore numbers with an odd number of digits 
as only numbers with even digits can meet the pattern

start
	get first range
	for i in that range
		i int to string
		get length of the string
		if string has even length
			divide the string in two
			if substrings are equal
				total += i 

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

string rangeStr;
string rangeStartStr;
string rangeEndStr;

ifstream File("puzzleInput2.txt");

long rangeStart;
long rangeEnd;

string currentNum;
string firstHalf;
string secondHalf;

int NumDigits;

long total = 0;

while(getline(File, rangeStr, ',')) {
	
	rangeStartStr = rangeStr.substr(0, rangeStr.find('-'));
	rangeEndStr = rangeStr.substr(rangeStr.find('-')+1);
	
	//cout << "Start: " << rangeStartStr << endl;
	//cout << "End: " << rangeEndStr << endl << endl;
	
	rangeStart = stol(rangeStartStr);
	rangeEnd = stol(rangeEndStr);
	
	for(long i = rangeStart; i <= rangeEnd; i++) {
		
		//cout << "I: " << i << endl;
		currentNum = to_string(i);
		NumDigits = currentNum.length();
		
		if((NumDigits % 2) == 0) { //if it has even digits
			firstHalf = currentNum.substr(0,NumDigits/2);
			secondHalf = currentNum.substr(NumDigits/2);
			//cout << "firstHalf: " << firstHalf << endl;
			//cout << "secondHalf: " << secondHalf << endl << endl;
			
			if(firstHalf == secondHalf) {
				total += i;
				cout << "Match found, total: " << total << endl << endl;
			}
			
		}
		
	}
	
}

cout << "Total: " << total << "     <---------------------------------------" << endl;

File.close();
return 0;

}