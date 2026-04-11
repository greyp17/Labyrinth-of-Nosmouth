#include "MyForm.h"
//Grey code starts here
#include <iostream>
#include "MAP.h"
#include "Maze.h"
int difficulty;
MAP Game;
Maze  Random_Gen;
Maze Print_Map;


using namespace System;
using namespace System::Windows::Forms;
[STAThread]

int main(array<String^>^ args)
{
	MAP Game;
	int difficulty;
	int Game_Run = 0;
	while (Game_Run == 0){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUILabyrinthProject::MyForm form;
	Application::Run(% form);
		std::cout << "Welcome to the Labyrinth of Nosmouth!" << "\n";
		std::cout << "Please select a difficulty level:" << "\n";
		std::cout << "Easy (1), Medium (2), Hard (3)" << "\n";
		std::cin >> difficulty;
		Game.difficulty = difficulty;
		Game.Game_Run = Game_Run;
		Game.RunGame();

	}
}