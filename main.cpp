#include <iostream>
#include <string>
#include <queue>
#include "BankAccount.h"

// Display people currently in the queue
void displayWaitlist(std::queue<std::string> waitlist)
{
	while (!waitlist.empty())
	{
		std::cout << waitlist.front() << '\n';
		waitlist.pop();
	};
};

// Remove elements from queue
void emptyWaitlist(std::queue<std::string>& waitlist)
{
	while (!waitlist.empty())
	{
		waitlist.pop();
	};
};

int main()
{
	// Use queue to store customers in arriving order
	std::queue<std::string> waitlist;

	// Populate queue with some test data
	waitlist.push("John");
	waitlist.push("Jane");
	waitlist.push("Mark");

	BankAccount john;
	BankAccount jane(4500.00, "Jane Doe");

	std::cout << "Welcome to the Banking Application. There are currently " << waitlist.size() << " people waiting to be served.\n";
	std::cout << "Name of customers in arriving order:\n";
	displayWaitlist(waitlist);
	std::cout << '\n';

	// Variables to hold input data
	std::string name;
	double balance;

	// Set data for john object
	std::cout << "Opening an account for John...\n";
	std::cout << "Enter customer name: ";
	std::getline(std::cin, name);
	john.setHolderName(name);

	std::cout << "Enter customer balance: ";
	std::cin >> balance;
	john.setBalance(balance);

	// Pop John from the queue
	waitlist.pop();
	std::cout << "\nSuccessfully completed John's request. Current queue length: " << waitlist.size() << '\n';

	// Modify data for jane object
	std::cout << "\nJane wants to check her balance and deposit some money to her account...\n";
	std::cout << "Current account balance: $" << jane.getBalance() << '\n';
	std::cout << "Enter amount to add: ";
	std::cin >> balance;
	jane.updateBalance(balance);
	std::cout << "Updated balance after transaction: $" << jane.getBalance() << '\n';

	// Pop Jane from queue
	waitlist.pop();
	std::cout << "\nSuccessfully completed Jane's request. Current queue length: " << waitlist.size() << '\n';
	std::cout << "Customers currently in the queue:\n";
	displayWaitlist(waitlist);

	// Add some more people to the queue
	waitlist.push("Mary");
	waitlist.push("Bob");

	std::cout << "\nMore customers arrived, adding them in arriving order:\n";
	displayWaitlist(waitlist);

	// Remove elements from queue
	emptyWaitlist(waitlist);
	std::cout << "\nBank is closing, customer service is finished for today...\n";
	std::cout << "Current queue length: " << waitlist.size() << '\n';

	return 0;
}