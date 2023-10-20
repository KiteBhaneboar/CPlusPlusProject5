#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


using namespace std;

bool running = true;

struct ReadAccountResult { //creates struct for keeping track of account number and number of accounts. I am trying out functional programming.
	int accountNum;
	int acctCount;
};



ReadAccountResult readAccountNo(int prevAcctCount) { //asks for customer account number
	
	int accountNum = 0;
	int acctCount = prevAcctCount + 1;
	
	while (running) {
		
		cout << "Please enter account number " << acctCount << ":" << endl;
		cin >> accountNum;
		
		if ((accountNum > 10000) || (accountNum < 0) || (accountNum % 2 != 0)) {
			cout << "No account under that number has been found. Try to enter the account number again." << endl;
		}
		else if ((accountNum < 10000) || (accountNum > 0) || (accountNum % 2 == 0)) {
			accountNum;
			break;
			
		}
	
	}
	
	return ReadAccountResult{ accountNum, acctCount };
}



float readBalanceAmount(int acctCount){ //reads opening balance amount
	
	float balance = 0;
	
	while (running) {
		cout << "Please enter the opening balance amount for account " << acctCount <<": " << endl;
		cin >> balance;
		if (balance > 200000)
			cout << "Account balance too high. Please try again" << endl;
		else if (balance <= 0)
			cout << "Account balance too low. Please try again." << endl;
		else  {
			balance;
			break;
		}
	}
	return balance;
}


float  calculateBalance(int accountNum, int acctCount, float balance) { //asks for deposit and calculates balance amount after deposit

	float deposit = 0;

	while (running) {
		cout << "Please enter the deposit amount for account number " << acctCount << ": " << endl;
		cin >> deposit;
		if (deposit < 0)
			cout << "Amount too low, please try again." << endl;
		else {
			balance = balance + deposit;
			break;
		}
	}
	return balance;
}

struct AddReturnBalanceResult { //creates struct to keep track of final balance, orignal balance and account number
	int accountNum;
	int acctCount;
	float balance;
};


AddReturnBalanceResult addReturnBalance(int accountNum, int acctCount, float balance) { //calculates balance amount after bank's perfecntage matching

	if ((balance >= 1) || (balance <= 100))
		balance = (balance * .02) + balance;
	else if ((balance >= 101) || (balance <= 500))
		balance = (balance * .03) + balance;
	else if ((balance >= 501) || (balance <= 1000))
		balance = (balance * .04) + balance;
	else
		balance = (balance * .05) + balance;

	return AddReturnBalanceResult {accountNum, acctCount, balance};
 }


float printAllInfo(int acctOne, int acctTwo, int acctThree, int acctFour, float balOne, float balTwo, float balThree, float balFour) { //formats and prints all info from previous functions
	cout << fixed;
	cout << setw(40) << setfill('=') << " Account Balances " << setw(31) << setfill('=') << "" << endl << endl;
	cout << setw(71) << setfill('=') << "" << endl << endl;
	cout << "The account balance for acount number " << acctOne << " is " << setw(15)  << setfill('.') << setprecision(2)  << balOne << endl;
	cout << "The account balance for acount number " << acctTwo << " is " << setw(15) << setfill('.') << setprecision(2) << balTwo << endl;
	cout << "The account balance for acount number " << acctThree << " is " << setw(15)  << setfill('.') << setprecision(2) << balThree << endl;
	cout << "The account balance for acount number " << acctFour << " is " << setw(15) << setfill('.') << setprecision(2) << balFour << endl << endl;
	cout << setw(71) << setfill('=') << "" << endl;

	return(acctOne, acctTwo, acctThree, acctFour, balOne, balTwo, balThree, balFour);
}


int main() { //call previous funcations and prints developer info. Initializes variable for calculating bank's percentage. Also gives user menu option to do various things within progam

		ReadAccountResult firstAcct = readAccountNo(0);
		ReadAccountResult secondAcct = readAccountNo(firstAcct.acctCount);
		ReadAccountResult thirdAcct = readAccountNo(secondAcct.acctCount);
		ReadAccountResult fourthAcct = readAccountNo(thirdAcct.acctCount);
		float firstOriginal = readBalanceAmount(firstAcct.acctCount);
		float secondOriginal = readBalanceAmount(secondAcct.acctCount);
		float thirdOriginal = readBalanceAmount(thirdAcct.acctCount);
		float fourthOriginal = readBalanceAmount(fourthAcct.acctCount);
		AddReturnBalanceResult firstFinalBal = { firstAcct.accountNum, firstAcct.acctCount, firstOriginal };
		AddReturnBalanceResult secondFinalBal = { secondAcct.accountNum, secondAcct.acctCount, secondOriginal };
		AddReturnBalanceResult thirdFinalBal = { thirdAcct.accountNum, thirdAcct.acctCount, thirdOriginal };
		AddReturnBalanceResult fourthFinalBal = { fourthAcct.accountNum, fourthAcct.acctCount, fourthOriginal };
		cout << setw(71) << setfill('*')<< "" << endl << endl;
		cout << setw(71) << setfill('*') << "" << endl << endl;
		cout << "Name: Casey Hillstrom " << setw(10) << setfill(' ') << " Section: CPS 171 section DT1 " << setw(10) << setfill(' ') << " Due Date: 06/08/23 " << endl << endl;
		cout << setw(71) << setfill('*') << "" << endl << endl;
		printAllInfo(firstFinalBal.accountNum, secondFinalBal.accountNum, thirdFinalBal.accountNum, fourthFinalBal.accountNum, firstFinalBal.balance, secondFinalBal.balance, thirdFinalBal.balance, fourthFinalBal.balance);
	while (running) { //dispalys menu options
		char choice;
		int acctCount = 0;
		cout << "Please choose from the following menu. Hit enter when you've typed the corresponding letter." << endl;
		cout << "A- Make Deposit" << endl;
		cout << "B- View Accounts" << endl;
		cout << "C- Exit Program" << endl;
		cin >> choice;
		switch (tolower(choice)) {
		case 'a': //allow user to make deposits
			while (acctCount < 1 || acctCount > 4) {
				cout << "Which account (1, 2, 3 or 4) would you like to add a deposit to? " << endl;
				cin >> acctCount;
			}
			if (acctCount == 1) {
				firstOriginal = calculateBalance(firstFinalBal.accountNum, firstFinalBal.acctCount, firstFinalBal.balance);
				firstFinalBal = addReturnBalance(firstFinalBal.accountNum, firstFinalBal.acctCount, firstOriginal);
				cout << "The final balance is " << firstFinalBal.balance << endl;
			}
			else if (acctCount == 2) {
				secondOriginal = calculateBalance(secondFinalBal.accountNum, secondFinalBal.acctCount, secondFinalBal.balance);
				secondFinalBal = addReturnBalance(secondFinalBal.accountNum, secondFinalBal.acctCount, secondOriginal);
				cout << "The final balance is " << secondFinalBal.balance << endl;
			}
			else if (acctCount == 3) {
				thirdOriginal = calculateBalance(thirdFinalBal.accountNum, thirdFinalBal.acctCount, thirdFinalBal.balance);
				thirdFinalBal = addReturnBalance(thirdFinalBal.accountNum, thirdFinalBal.acctCount, thirdOriginal);
				cout << "The final balance is " << thirdFinalBal.balance << endl;
			}
			else if (acctCount == 4) {
				fourthOriginal = calculateBalance(fourthFinalBal.accountNum, fourthFinalBal.acctCount, fourthFinalBal.balance);
				fourthFinalBal = addReturnBalance(fourthFinalBal.accountNum, fourthFinalBal.acctCount, fourthOriginal);
				cout << "The final balance is " << fourthFinalBal.balance << endl;
			}
			break;
		case 'b': //allows user to view current account info
			while (acctCount < 1 || acctCount > 4) {
				cout << "Which account (1, 2, 3 or 4) would you like to view?" << endl;
				cin >> acctCount;
			}
			if (acctCount == 1) {
				cout << "Account number " << setw(20) << setfill('.') << firstFinalBal.accountNum << "   Balance" << setw(20) << setfill('.') << firstFinalBal.balance << endl;
			}
			else if (acctCount == 2) {
				cout << "Account number " << setw(20) << setfill('.') << secondFinalBal.accountNum << "   Balance" << setw(20) << setfill('.') << secondFinalBal.balance << endl;
			}
			else if (acctCount == 3) {
				cout << "Account number " << setw(20) << setfill('.') << thirdFinalBal.accountNum << "   Balance" << setw(20) << setfill('.') << thirdFinalBal.balance << endl;
			}
			else if (acctCount == 4) {
				cout << "Account number " << setw(20) << setfill('.') << fourthFinalBal.accountNum << "   Balance" << setw(20) << setfill('.') << fourthFinalBal.balance << endl;
			}
			break;
		case 'c': //exits program
			running = false;
		};

	}
	return 0;
}