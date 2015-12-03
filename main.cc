
// David Zubal
// Shelby Stately 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

//Size of the board
const int MAX_SIZE = 5;
const char EMPTY = '.';
const char AI = '*'; //The appearance of the AI on the board

//Extra credit: Print out the row and column numbers and/or make it look pretty
void print_array(char arr[][MAX_SIZE]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cout << arr[i][j]; 	//YOU: Print out the array values here
		}
		cout << endl;
	}
}

//Initializes the array to make it ready for a new game
void clear_array(char arr[][MAX_SIZE]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			arr[i][j] = EMPTY;
		}
	}
}

//Will examine a board to see if there's a winning position
//A winning position is a horizontal row or vertical column all with the same letter
// in it. Letter '.' means an empty space, so don't win if we have five .'s in a row.
//Return true if there's a winner, false otherwise.
//Write the winning character into the winner parameter
//If the board is invalid (two+ winners, etc.) set error to true, otherwise false
bool check_winner(char arr[][MAX_SIZE], char &winner, bool &error) {
	int count=0;// Sets count to 0
	char temp;//  Constant variable holding character 
	for (int i= 0; i < MAX_SIZE; i++){  // Check diagonal decreasing slope 
		if (arr[i][i]=='.') { break; }
		else if (i==0) {
			temp=arr[i][i];
			count++;
		}
		else if (i!=0&&temp==arr[i][i]) {
			count++;
		}
		else break;
		if (count==MAX_SIZE) {
			winner=temp;
			return true;
		}
		
	}
		count = 0; //resets intput
		for (int i=0; i < MAX_SIZE; i++){  //Check diagonal incresing slope
		if (arr[i][MAX_SIZE -1 -i]=='.') { break; }
		else if (i==0) {
			temp=arr[i][MAX_SIZE -1 -i]; // 
			count++;
		}
		else if (i!=0&&temp==arr[i][MAX_SIZE -1- i]) {
			count++;
		}
		else break;
		if (count==MAX_SIZE) {
			winner=temp;
			return true;
		}
		
	}
	count = 0 ;
	for  (int i = 0; i < MAX_SIZE; i++ ){ // Check horizontal
		for (int j= 0; j < MAX_SIZE; j++){
			if (arr[i][j]=='.'){break;}
			else if (j== 0){
			temp= arr[i][j]; 
			count++; 
			}
			else if (j!=0&&temp==arr[i][j]){
			count++;
			}
			else  break;
			if (count==MAX_SIZE){
				winner =temp;
				return true; 
			}
		}
		count = 0; 
	}
	count = 0;
	for  (int j = 0; j < MAX_SIZE; j++ ){ // Check vertical 
		for (int i= 0; i <MAX_SIZE; i++){
			if (arr[i][j]=='.'){break;}
			else if (i== 0){
			temp= arr[i][j]; 
			count++; 
			}
			else if (i!=0&&temp==arr[i][j]){
			count++;
			}
			else  break;
			if (count==MAX_SIZE){
				winner =temp;
				return true; 
			}
		}
	    count = 0;  
	}
    count =  0; 
    //YOU: Write all this
	return false;
}

void waiter(string error = "") {
	cout << error << "Press any key to continue.\n";
	string nothing;
	cin >> nothing;
}

int main() {
	char my_array[MAX_SIZE][MAX_SIZE] = {}; //= {} means initialize to zero
	srand(time(NULL)); //Initialize the random number generator

	//Start with empty board 
	clear_array(my_array);

	while (true) {
		system("clear"); //Clear the screen
		print_array(my_array);

		//Handle input and check for errors
		cout << "Input x and y coordinates followed by a letter (letter 'Q' to quit): ";
		int x,y;
		char input;
		cin >> x;
		if (!cin) exit(EXIT_FAILURE);
		cin >> y;
		if (!cin) exit(EXIT_FAILURE);
		cin >> input;
		if (!cin) exit(EXIT_FAILURE);
		if (input == 'Q')exit(EXIT_SUCCESS);
		if (!isalpha(input))exit(EXIT_FAILURE);

		//YOU: Check to see if the coordinate is out of bounds
		if (x>=MAX_SIZE || x<0 || y>=MAX_SIZE || y<0 ) {
			waiter("That coordinate is out of bounds. "); //Pause
			continue; //Let them reenter the move
		}

		//YOU: Check for the spot being filled already
		if (my_array[x][y] != '.' ) {
			waiter("That spot is already taken. "); //Pause
			continue; //Let them reenter the move
		}
		else {
			my_array[x][y]	= input;
				//YOU: Enter the move onto the board here
		}

		//Extra Credit: Write an AI to play against you

		char winner;
		bool error;
		if (check_winner(my_array, winner, error)) {
			//Print win message and/or error message here
			system("clear"); //Clear the screen
			print_array(my_array);
			if (error) cout << "Error: Multiple winners!\n";
			else {
				if (winner == AI) 
					cout << "Failure! The AI has beaten you!\n";
				else
					cout << "Congrats! Player " << winner << " has won!\n";
				exit(EXIT_SUCCESS);
			}
			waiter(); //Pause
		}
	}
}
