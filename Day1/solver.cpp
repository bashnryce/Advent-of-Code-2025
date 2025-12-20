//pseudo code
/*

left is lower
right is higher

rolls over when left from zero and right from 99
starts pointing at 50
count the times that the dial is zero after a turn

dial = 50;
zeros = 0;

while not end of file
	get line from file
	get turn value
	if L 
		if turn value > dial  //it will roll over to 99
			turn value = turn value % 99;
			turn value = turnvalue - dial - 1;
			dial = 99;
			dial = dial - turn value; 
		else
			dial = dial - turnvalue;
		
	if R
		if dial + turnvalue > 99  //roll over to 0
			turn value %= 99;
			turnvalue = turnvalue+dial
			dial = 0
			dial = dial + turnvalue 
		else
			dial =+ turnvalue
			
	if dial == 0 
		zeros++;
	

print zeros

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	
	int dial = 50;
	int zeros = 0;
	
	string Line;
	string strTurnVal;
	int turnval; 
	int turnCount;
	int previousDial;
	
	ifstream File("puzzleInput.txt");
	
	while(getline(File, Line)) {
		
		cout << "Command: " << Line << endl;
		strTurnVal = Line.substr(1);
		turnval = stoi(strTurnVal);
		
		cout << "Dial: " << dial << endl;
		cout << "TurnVal: " << turnval << endl; 
		
		previousDial = dial;
		
		if(Line[0] == 'L') {
			if(turnval > dial) { //roll over from low to 99 and continue
				turnCount = turnval / 100;
				zeros += turnCount;
				cout << "Turns: " << turnCount << endl;
				
				turnval %= 100; 		//cut off extra rotations
				
				if(turnval > dial) {
					turnval = turnval - (dial + 1);
					dial = 99;
					dial -= turnval;
					if((dial != 0)&&(previousDial != 0)){
						zeros++;
					}			
				}
				else {
					dial -= turnval;
				}
			}
			else {
				dial -= turnval;
			}		 
			
		}
		if(Line[0] == 'R') {
			if((dial+turnval) > 99) { //if the value will roll past 99 
				turnCount = turnval / 100;
				zeros += turnCount;
				cout << "Turns: " << turnCount << endl;
				
				turnval %= 100; 		//cut off extra rotations
				
				if((dial+turnval) > 99) { //still need to roll over
					turnval = turnval - (99 - dial + 1); 
					dial = 0;
					dial += turnval;
					if((dial != 0)&&(previousDial != 0)){
						zeros++;
					}
				}
				
				else {					//cutting out extra rotations fixed it
					dial += turnval;
				}
			}
			else {
				dial += turnval;
			}

		}			
		if(dial == 0) {
			zeros++;
		}
		
		cout << "New Dial Value: " << dial << endl;
		cout << "Zeros: " << zeros << endl << endl;
		
	}
	
	File.close();
	cout << endl << "Zeros landed on: " << zeros << endl;

	return 0;
	
	
}