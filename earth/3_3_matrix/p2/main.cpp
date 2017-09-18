#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

int main(){
	int playground[3][3] = {0};  // 3 by 3 array to store the numbers

	//used for solver
	int PG_solver[3][3] = {0};


	int rx, ry;
	srand (time(NULL));
	

	//store 1,2,3 randomly into the matrix
	for (int TEMP=0; TEMP<3;  TEMP++){
		do{
			rx = rand() % 3 ;
			ry = rand() % 3 ;	
		}
		while(playground[rx][0] != 0 || playground[rx][1] != 0 || playground[rx][2] != 0 
			|| playground[0][ry] != 0 || playground[1][ry] != 0 || playground[2][ry] != 0);

		playground[rx][ry] = TEMP + 1;


		//saved into solver for future use
		PG_solver[rx][ry] = TEMP + 1;
		//check TEMP loop times
		cout << TEMP << "\n";
	}

	//printf
	for (int x=0; x<3; x++){
		for(int y=0; y<3; y++){
			cout << playground[x][y] << " ";
		}
		cout << "\n";
	}

	string k;
	cout << "Lets solve it!\n";
	cin  >> k;
	cout << k << " <- that's what i typed\n";

	//sloving alogrithem
	for (int x_check=0; x_check <3; x_check++){
		for(int y_check=0; y_check<3; y_check++){
			if(playground[x_check][y_check] == 0){
				PG_solver[x_check][y_check] = 6 - playground[x_check][0] - playground[x_check][1] - playground[x_check][2]
												- playground[0][y_check] - playground[1][y_check] - playground[2][y_check];
			}
		}
	}

	//print the solved puzzle
	for (int x=0; x<3; x++){
		for(int y=0; y<3; y++){
			cout << PG_solver[x][y] << " ";
		}
		cout << "\n";
	}


	//end main return
	return 0;
}