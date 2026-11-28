#include <iostream>
#include < conio.h >
#include < iomanip >
#include <windows.h>
using namespace std;
struct players {
	int x;
	int y;
	int lives;
	int score;
	char symbol;
};
struct Bullet {
	int x;
	int y;
	char symbol;
	bool active = false;
};
const int rows = 28;
const int col = 60;
char screenarray[rows][col] = { };
void moveplayer(players &player,Bullet &bulllet);

void gototop();
void bulletfire();
int main() {
	players player1;
	player1.lives = 3;
	player1.score = 0;
	player1.symbol='P';
	player1.x = rows - 2;
	player1.y = col / 2;
	Bullet bullet1;
	bullet1.symbol = '|';
	cout << "\033[?25l";//this coomand remove the bliking cursor hat appaear beacuse of printing blank spaces" " ;
	while (true) {
		moveplayer(player1,bullet1);
		gototop();
		for (int i = 0;i < rows;i++) {
			for (int j = 0;j < col;j++) {
				if (i == 0 || i == rows - 1 || j == 0 || j == col - 1) {
					screenarray[i][j] = '#';


				}
				else if (i== player1.x&&j==player1.y) {
					screenarray[i][j] = player1.symbol;
				}
				else if (i == bullet1.x && j == bullet1.y) {
					screenarray[i][j] = bullet1.symbol;
					bullet1.x--;
				}
				else {
					screenarray[i][j] = ' ';

				}
				cout<<screenarray[i][j] << " ";

			}
			cout << endl;
		}
		
	}
	return 0;
}
void moveplayer(players &player ,Bullet &bullet1) {
	if (_kbhit()) {
		char key = _getch();
		if ((key == 'A' || key == 'a')&&player.y>1) {
			player.y = player.y - 1;
		}
		else if ((key == 'D' || key == 'd')&&player.y<col-2) {
			player.y = player.y + 1;
		}
		else if (key == ' ') {
			if (!bullet1.active) {
				bullet1.x=player.x-1;
				bullet1.y = player.y; 
				bullet1.active = true;
			}
			if (bullet1.active >= 0) {
				bullet1.active = false;
			}
		}

	}
}
void gototop() {
	COORD pos;//create the coardinate struct variable named pos in the memory with slots X and Y
	pos.X = 0;//create coardinate struct varible named pos in memory with two slots
	pos.Y=0;//sets the vertical column position inside to 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	//gets your active console and moves the active console window dirtectly to zero


}
