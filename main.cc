#include <iostream>
#include <fstream>
#include <random>

struct wordGenerator
{
  std::vector<std::string> storeStrings; std::string randomlySelectedWord; std::string underscorePlacement; std::string tempHolder; int length; 
  
	int readFile()
	{
		std::string list; std::ifstream readWordList{ "words.txt" };
		if(!readWordList){ return 1; } else { while(std::getline(readWordList, list)) { storeStrings.push_back(list); } }
		return 0;
	}

  void random()
  {
  	std::random_device seed; std::mt19937 generator(seed()); std::uniform_int_distribution<> selector(0 , storeStrings.size() -1);
  	randomlySelectedWord = storeStrings[selector(generator)];
  }

	void getLengthOfCurrentString(){ length = randomlySelectedWord.length(); underscorePlacement = std::string(length, '_'); tempHolder = underscorePlacement; }

}init;

struct display
{
	std::string display0[7][5] = 
	{
		{"_","_","_"," "," "},
		{"|"," "," "," "," ",},
		{"|"," "," "," "," ",},
		{"|"," "," "," "," ",},
		{"|"," "," "," ","",},
		{"|"," "," "," "," ",},
		{"-","-","-","-","-",},
	};
	std::string display1[7][5] = 
	{
		{"_","_","_"," "," "},
		{"|"," ","|"," "," ",},
		{"|"," "," "," "," ",},
		{"|"," "," "," "," ",},
		{"|"," "," "," ","",},
		{"|"," "," "," "," ",},
		{"-","-","-","-","-",},
	};
	std::string display2[7][5] = 
	{
		{"_","_","_"," "," "},
		{"|"," ","|"," "," ",},
		{"|"," ","o"," "," ",},
		{"|"," "," "," "," ",},
		{"|"," "," "," ","",},
		{"|"," "," "," "," ",},
		{"-","-","-","-","-",},
	};
	std::string display3[7][5] = 
	{
		{"_","_","_"," "," "},
		{"|"," ","|"," "," ",},
		{"|"," ","o"," "," ",},
		{"|"," ","|"," "," ",},
		{"|"," "," "," ","",},
		{"|"," "," "," "," ",},
		{"-","-","-","-","-",},
	};
	std::string display4[7][5] = 
	{
		{"_","_","_"," "," "},
		{"|"," ","|"," "," ",},
		{"|"," ","o"," "," ",},
		{"|","-","|"," "," ",},
		{"|"," "," "," ","",},
		{"|"," "," "," "," ",},
		{"-","-","-","-","-",},
	};
	std::string display5[7][5] = 
	{
		{"_","_","_"," "," "},
		{"|"," ","|"," "," ",},
		{"|"," ","o"," "," ",},
		{"|","-","|","-"," ",},
		{"|"," "," "," ","",},
		{"|"," "," "," "," ",},
		{"-","-","-","-","-",},
	};
	std::string display6[7][5] = 
	{
		{"_","_","_"," "," "},
		{"|"," ","|"," "," ",},
		{"|"," ","o"," "," ",},
		{"|","-","|","-"," ",},
		{"|","/"," "," ","",},
		{"|"," "," "," "," ",},
		{"-","-","-","-","-",},
	};
	std::string display7[7][5] = 
	{
		{"_","_","_"," "," "},
		{"|"," ","|"," "," ",},
		{"|"," ","o"," "," ",},
		{"|","-","|","-"," ",},
		{"|","/"," ","\\","",},
		{"|"," "," "," "," ",},
		{"-","-","-","-","-",},
	};
}updateGraphics;

char userInput(){ std::string x; std::getline(std::cin >> std::ws, x); return x[0]; } // make not case sensitive

int main()
{
  std::vector<char> usedKeys; int numberOfGuesses {7}; bool bypass {true};
  if(init.readFile()){ std::cerr << "File name does not exist\n"; return 1; } else { init.random(); init.getLengthOfCurrentString(); std::cout << init.underscorePlacement << "\n\n";}

  for(int i {0}; i < numberOfGuesses + 1;)
  { 

     /**/ if(i == 0){ for (uint j {0}; j < 7; ++j ){ for (uint k {0}; k < 5; ++k){ std::cout << updateGraphics.display0[j][k]; } std::cout << std::endl; } }
     else if(i == 1){ for (uint j {0}; j < 7; ++j ){ for (uint k {0}; k < 5; ++k){ std::cout << updateGraphics.display1[j][k]; } std::cout << std::endl; } }
     else if(i == 2){ for (uint j {0}; j < 7; ++j ){ for (uint k {0}; k < 5; ++k){ std::cout << updateGraphics.display2[j][k]; } std::cout << std::endl; } }
     else if(i == 3){ for (uint j {0}; j < 7; ++j ){ for (uint k {0}; k < 5; ++k){ std::cout << updateGraphics.display3[j][k]; } std::cout << std::endl; } }
     else if(i == 4){ for (uint j {0}; j < 7; ++j ){ for (uint k {0}; k < 5; ++k){ std::cout << updateGraphics.display4[j][k]; } std::cout << std::endl; } }
     else if(i == 5){ for (uint j {0}; j < 7; ++j ){ for (uint k {0}; k < 5; ++k){ std::cout << updateGraphics.display5[j][k]; } std::cout << std::endl; } }
     else if(i == 6){ for (uint j {0}; j < 7; ++j ){ for (uint k {0}; k < 5; ++k){ std::cout << updateGraphics.display6[j][k]; } std::cout << std::endl; } }
  	 else if(i == 7){ for (uint j {0}; j < 7; ++j ){ for (uint k {0}; k < 5; ++k){ std::cout << updateGraphics.display7[j][k]; } std::cout << std::endl; } 
  	 std::cout << "\nthe word was: " << init.randomlySelectedWord << std::endl; break; }
          
  	char guess { userInput() };

    if(!usedKeys.empty()){for(uint j {0}; j < usedKeys.size(); ++j){if(guess == usedKeys[j]){std::cout << '\n' << "you already entered this key" << std::endl; bypass = false; break;}}}

    if(bypass){ for(int k {0}; k < init.length; ++k){if(guess == init.randomlySelectedWord[k]){ init.tempHolder[k] = guess; } }
	    if(init.tempHolder != init.underscorePlacement){ init.underscorePlacement = init.tempHolder; } else { std::cout << "\nnu uh" << std::endl; ++i; }
    }

    if(init.underscorePlacement == init.randomlySelectedWord) { std::cout << "\nYou won! the word was: " << init.randomlySelectedWord << std::endl; break; }
    std::cout << "\n" << init.underscorePlacement << "\n\n";
    usedKeys.push_back(guess);
    bypass = true;
  	
  }
  
	return 0;
}
