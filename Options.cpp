//Import Libraries
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//Global Variables
std::string stock;

//Options variables
float strikePrice, optionPremium, stockPrice, payoff, profit;

int menuChoice, functionRun = 1;

//Declaring Core Functions
void callOption();
void putOption();
void assetInfo();

//Declaring Aesthetic and UI functions
void shutDown();
void greetings();

//main function
int main () {
    //set text and bg color
    system("COLOR 02");

//Intro
greetings();

do {    //Menu Selection
    cout << "\nMenu Select\n"
    << "=================\n"
    << "1. Call Options \n"
    << "2. Put Options \n"
    << "3. Shutdown \n"
    << "=================\n";

    //Choice if want to do more
    cin >> menuChoice;

    //case
    switch (menuChoice) {
case 1:
    callOption();
    break;
case 2:
    putOption();
    break;
case 3:
    menuChoice = 3;
    break;
default:
    cout << "Please select a valid option\n";

    }

    }

 while (menuChoice != 3);
shutDown();

return 0;

}



//Declared core-function exposition
//Call Option
void callOption() {

//Function Variables
int buysellCall;

//Prompt user for core asset info
assetInfo();

do {
//Prompt user asking what they want to do.
cout << "Would you like to exercise a buy or sell call option? | Buy = 1 | Sell = 0  |  Return to Menu = 2\n";
cin >> buysellCall;


//Switch for option buy
switch (buysellCall) {
    case 1:
    //Call Option Payoff and Profit
    cout << "What is the price of " << stock << " stock currently?\n";
    cin >> stockPrice; //Maybe make this a global function

    //Calculation
    payoff = std::max(stockPrice - strikePrice, 0.0f);
    profit = payoff - optionPremium;
    cout << "Your payoff is: " << payoff << " and your profit is: " << profit << std::endl;

break;

    case 0:
    //Selling (Writing) Call Options
    cout << "What is the price of " << stock << " stock currently?\n";
    cin >> stockPrice; //Maybe make this a global function

    //Calculation
    payoff = -std::max(stockPrice - strikePrice, 0.0f);
    profit = payoff + optionPremium;
    cout << "Your payoff is: " << payoff << " and your profit is: " << profit << std::endl;

    break;

    case 2:
    functionRun = 0;
    break;

    default:
       cout << "Not a valid action!\n";
    break;}

} while (functionRun != 0);

} //Call Option Function End

void putOption() {

//Local variables
int buysellPut;

assetInfo(); //Set up core asset information

//Do Loop
do {
    cout << "Would you like to exercise a buy or sell put option? | Buy = 1 | Sell = 0  |  Return to Menu = 2\n";
    cin >> buysellPut;

    switch (buysellPut) {
    //Case if buy
    case 1:
    //Call Option Payoff and Profit
    cout << "What is the price of " << stock << " stock currently?\n";
    cin >> stockPrice; //Maybe make this a global function

    //Calculation
    payoff = std::max(strikePrice - stockPrice, 0.0f);
    profit = payoff - optionPremium;
    cout << "Your payoff is: " << payoff << " and your profit is: " << profit << std::endl;

break;

    case 0:
    //Selling (Writing) Call Options
    cout << "What is the price of " << stock << " stock currently?\n";
    cin >> stockPrice; //Maybe make this a global function

    //Calculation!!!!
    payoff = std::max(strikePrice - stockPrice, 0.0f);
    profit = -payoff + optionPremium;
    cout << "Your payoff is: " << payoff << " and your profit is: " << profit << std::endl;

    break;

    case 2:
    functionRun = 0;
    break;

    default:
       cout << "Not a valid action!\n";
    break;}

} while (functionRun != 0);

}

void assetInfo() {
cout << "Please enter in the name of the underlying asset, the strike price, and the option premium\n";
cin >> stock;
cin >> strikePrice;
cin >> optionPremium;
}


//Declared aesthetic and UI function expositions
void shutDown (){
std::string shutdownText = R"(
 .d8888b.                         888        888888b.                     888
d88P  Y88b                        888        888  "88b                    888
888    888                        888        888  .88P                    888
888         .d88b.   .d88b.   .d88888        8888888K.  888  888  .d88b.  888
888  88888 d88""88b d88""88b d88" 888        888  "Y88b 888  888 d8P  Y8b 888
888    888 888  888 888  888 888  888 888888 888    888 888  888 88888888 Y8P
Y88b  d88P Y88..88P Y88..88P Y88b 888        888   d88P Y88b 888 Y8b.      "
 "Y8888P88  "Y88P"   "Y88P"   "Y88888        8888888P"   "Y88888  "Y8888  888
                                                             888
                                                        Y8b d88P
                                                         "Y88P"
)";

cout << shutdownText << std::endl;
}

void greetings(){
std::string titleMessage = R"(
---------------------------------------------------------------------------------
   ____        __  _                   __               _____ ____  ____  ____
  / __ \____  / /_(_)___  ____  ____ _/ /____  _____   |__  // __ \/ __ \/ __ \
 / / / / __ \/ __/ / __ \/ __ \/ __ `/ __/ _ \/ ___/    /_ </ / / / / / / / / /
/ /_/ / /_/ / /_/ / /_/ / / / / /_/ / /_/  __/ /      ___/ / /_/ / /_/ / /_/ /
\____/ .___/\__/_/\____/_/ /_/\__,_/\__/\___/_/      /____/\____/\____/\____/
    /_/
                                                            c. 1987
---------------------------------------------------------------------------------
)";

cout << titleMessage << std::endl;
}
