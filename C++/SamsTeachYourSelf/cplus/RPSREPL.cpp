#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

string opponentPick(void){
	srand(time(NULL));
	int random = rand() % 100;
	int thresholdP =random % 2;
	int thresholdR =random % 3;
	int thresholdS =random % 5;
	string results;
	if(thresholdP == 0){
	results = "p";
	}
	if (thresholdR == 0){
	results = "r";
	}
	if (thresholdS == 0){
	results = "s";
	}
	return results;
}
int compare(string cpu, string user){
	cout << "CPU chose: " << cpu << endl;
	map<string, string> winMap;
	map<string, string> tieMap;
	winMap[string("r")] = string("s");
        winMap[string("s")] = string("p");
	winMap[string("p")] = string("r");
	tieMap[string("r")] = string("r");
	tieMap[string("s")] = string("s");
	tieMap[string("p")] = string("p");
	string outComeWin = winMap[user];
	string outComeTie = tieMap[user];
	int results = outComeWin.compare(cpu);
	int resultedTie = outComeTie.compare(cpu);
	if (results == 0){
		return 0;
	}else if ( resultedTie == 0){
		return 1;
	}
	else {
		return -1;	
	}
	
}

int main(void){
	cout << "\nWelcome to Rocks Paper Scizzors \n\nKey Controls: \n r: rock \n p: paper \n s: scissors \n q: quit \n" << endl;
	while(bool continuous = true){
		string userInput;
		cin >> userInput;
		string q ("q");
		map<string, int> acceptedInputs;
		acceptedInputs[string("r")] = 1;
		acceptedInputs[string("p")] = 1;
		acceptedInputs[string("s")] = 1;
		if (userInput.compare(q) == 0){
			return 0;
		}else if (acceptedInputs[userInput]!=1){
			cout << "Pick valid command" << endl;
		}
		else{
			string results = opponentPick();
			int winLossResults = compare(results, userInput);
			if (winLossResults == -1){
				cout << "You lose" << endl;
			}else if(winLossResults ==1){
				cout << "Tie" << endl;
			}else{
				cout << "You win" << endl;
			}
		}
	}
}
