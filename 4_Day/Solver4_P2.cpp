/*Pseudo Code and Description

given a grid of @ and . chars find all the @ chars that have less than 4 @ surrounding them
total the amount of @'s that meet the criteria
Part2: now remove all of the @ symbols and continue until no more can be removed

modifications:
	- flag to track how many @ have been found in one iteration over the whole grid
		- this will be used as a flag for a while loop 
	- when < 4 condition is met change that 1 to a 0

*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	ifstream File("puzzleInput4.txt");
	string lineStr;
	
	int length;
	int rowCount = 1;
	
	vector<vector<int>> grid;
	
	//convert the file to a 2D vector of 1's and 0's
	grid.push_back(vector<int>());
	
	while(getline(File, lineStr)) {
		
		grid.push_back(vector<int>()); //add a new row
		
		//if(rowCount != 0) {
			
			length = lineStr.length();
		
			grid[rowCount].push_back(0);
			
			for(int i = 0; i < length; i++) {
			
				if(lineStr[i] == '@') {
					grid[rowCount].push_back(1);
				}
				else if(lineStr[i] == '.') {
					grid[rowCount].push_back(0);
				}
			
			}
		
			grid[rowCount].push_back(0);
			
		//}
		
		rowCount++;	
		
	}
	
	//pad top and bottom with zeros
	
	grid.push_back(vector<int>());
	
	int rowSize = grid.size();
	int colSize = grid[1].size();
	
	for(int i = 0; i < colSize; i++) { //for each column
		
		grid[0].push_back(0);          //pad zeros on first row
		grid[rowSize-1].push_back(0);  //pad zeros on last row
		
	}
	
	
	//print the grid of numbers
	
	for(int j = 0; j < rowSize; j++) {
		
		for(int k = 0; k < colSize; k++) {
			
			cout << grid[j][k];
			
		}
		cout << endl;
		
	}
	
	
	//working loop to find all spots that match the condition
	int surrounding = 0;
	int total = 0;
	int removedCount = 1; //inital value != 0 so we get at least one interation
	
	while(removedCount != 0) {
	
		removedCount = 0; //clear the value after each interation over the grid
		
		for(int j = 1; j < rowSize-1; j++) {
			for(int k = 1; k < colSize-1; k++) {
				
				//for each char in grid
				
				if(grid[j][k] == 1) { //if we are at an @ char
					
					//loop over each char surrounding the current one and add them together in surrounding
					for(int x = -1; x <= 1; x++) { 
						for(int y = -1; y <= 1; y++) {
						
								surrounding += grid[j+x][k+y];		

						}
					}
					surrounding--;		// -1 to exclude the current position (we only want the surrounding)
					if(surrounding < 4) {
						total++;
						grid[j][k] = 0; //remove the item (@)
						removedCount++;
					}
					
				}
				
				surrounding = 0; //reset value after each element
				
			}		
		}
		
	}
	
	cout << "Total: " << total << endl << endl;

	File.close();
	return 0;
	
}
