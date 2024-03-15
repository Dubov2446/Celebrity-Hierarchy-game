// File: celebrity.h
//
// Author: Josue Lopez
//
// Course/Class: CS302-002
//
// Date: 23rd October 2023
// 
// Program: cs302-002-program1
//
// Funciton(s):
// 	void monster_choice(void): If the user chooses to interact with a monster, this will 
// 			  allow them to do so via a menu.
// 	void monster_menu(void): Prints out the menu for them to interact with.
//
// 	void actor_choice(void): If the user chooses to interact with a actor, this will 
// 			  allow them to do so via a menu.
// 	void actor_menu(void): Prints out the menu for them to interact with.
//
// 	void artist_choice(void): If the user chooses to interact with a artist, this will 
// 			  allow them to do so via a menu.
// 	void artist_menu(void): Prints out the menu for them to interact with.
//
// 	void ending_message(void): prints out a general goodbye message when user quits program

#include "celebrity.h"
#include "node.h"
#include <iostream> // output
#include <cstdlib> // NULL, rand, srand
using std::cout;
using std::endl;
using std::cin;

void monster_choice(void);
void monster_menu(void);

void actor_choice(void);
void actor_menu(void);

void artist_choice(void);
void artist_menu(void);

void ending_message(void);

int main()
{
	int choice{0};
	cout << "Choose which celebrity you want to interact with: " << endl;
	cout << "1 - Actor" << endl;
	cout << "2 - Artist" << endl;
	cout << "3 - Monster" << endl;
	cin >> choice;

	cin.ignore(100, '\n');

	if(choice == 1)
		actor_choice();
	else if(choice == 2)
		artist_choice();
	else if(choice == 3)
		monster_choice();
	else
		cout << "Invalid entry, program ending...." << endl;
	return 0;
}

void ending_message(void)
{
	cout << endl << "Thank you, come again! Goodbye now..." << endl;
	return;
}

void actor_menu(void)  
{
	cout << "PLEASE SELECT FROM THIS MENU!" << endl;
	cout << "1 - show main event" << endl;
	cout << "2 - set new main event" << endl;
	cout << "3 - set new main event day" << endl;
	cout << "4 - display" << endl;
	cout << "5 - autograph sign up" << endl;
	cout << "6 - raffle ticket" << endl;
	cout << "7 - cancel autograph sign up" << endl;
	cout << "0 - to quit/exit" << endl;
	return;
}

void actor_choice(void)
{
	string name{""};
	string main_event{""};
	string main_event_day{""};
	string genre{""};
	int age{0};
	int num_of_fans{0};
	int user_input{0};
	string user_number{""};
	int raffle_ticket_number_guess{0};

	cout << "Enter Actor name: ";
	getline(cin, name);
	cout << "Enter Actor main event: ";
	getline(cin, main_event);
	cout << "Enter Actor main event day: ";
	getline(cin, main_event_day);
	cout << "Enter genre of Actor: ";
	getline(cin, genre);

	cout << "Enter Actor age: ";
	cin >> age;
	cout << "Enter number of fans Actor has: ";
	cin >> num_of_fans;

	cin.ignore(100, '\n');

	Actor my_actor(name, age, num_of_fans, main_event, main_event_day, genre);

	do
	{
		cout << endl;
		actor_menu();
		cin >> user_input;
		cout << endl;
		cin.ignore(100,'\n');

		switch(user_input)
		{
			case 0: break;

			case 1: my_actor.show_main_event();
				break;

			case 2: cout << "Enter new main event: ";
				getline(cin, main_event);
				if(my_actor.set_main_event(main_event))
					cout << "New main event: " << main_event;
				else
					cout << "Error setting new main event, try again";
				break;

			case 3: cout << "Enter new main event day: ";
				getline(cin, main_event_day);
				if(my_actor.set_main_event_day(main_event_day))
					cout << "New main event day: " << main_event_day;
				else
					cout << "Error setting main event day...try again";
				break;

			case 4: my_actor.display();
				break;

			case 5: cout << "Enter your number: " << endl;
				getline(cin, user_number);
				if(my_actor.autograph_sign_up(user_number))
					cout << "Appointment entered successfully!";
				else
					cout << "Number has already been entered, cannot sign up twice...";
				break;

			case 6: cout << "Enter raffle ticket number from 0 - 50: ";
				cin >> raffle_ticket_number_guess;
				if(my_actor.raffle_ticket(raffle_ticket_number_guess))
					cout << "YOU WIN! COME PICK UP YOUR PRIZE!!!";
				cout << "Wrong guess, better luck next time...";
				cin.ignore(100, '\n');
				break;
			
			case 7: cout << "Enter appointment number to cancel: ";
				getline(cin, user_number);
				if(my_actor.cancel_autograph(user_number))
				{
					cout << "Cancelled successfully!";
				}
				else
				{
					cout << "No appointment found with number " << user_number;
				}
				break;

			default: cout << "Invalid input, try again...";
				 user_input = 1;
				 break;
		}
		cout << endl;
	}
	while(user_input != 0);

	ending_message();
	
	return;
}

void artist_menu(void)
{
	cout << "PLEASE SELECT FROM THIS MENU!" << endl;
	cout << "1 - show main event" << endl;
	cout << "2 - set new main event" << endl;
	cout << "3 - set new main event day" << endl;
	cout << "4 - display" << endl;
	cout << "5 - karaoke sign up" << endl;
	cout << "6 - buy vinyl" << endl;
	cout << "7 - cancel karaoke sign up" << endl;
	cout << "0 - to quit/exit" << endl;
	return;
}

void artist_choice(void)
{
	string name{""};
	string main_event{""};
	string main_event_day{""};
	string genre{""};
	int age{0};
	int num_of_fans{0};
	int user_input{0};
	string user_number{""};

	cout << "Enter Artist name: ";
	getline(cin, name);
	cout << "Enter Artist main event: ";
	getline(cin, main_event);
	cout << "Enter Artist main event day: ";
	getline(cin, main_event_day);
	cout << "Enter Artist genre: ";
	getline(cin, genre);

	cout << "Enter Artist age: ";
	cin >> age;
	cout << "Enter number of fans Artist has: ";
	cin >> num_of_fans;

	cin.ignore(100, '\n');

	Artist my_artist(name, age, num_of_fans, main_event, main_event_day, genre);

	do
	{
		cout << endl;
		artist_menu();
		cin >> user_input;
		cout << endl;
		cin.ignore(100,'\n');

		switch(user_input)
		{
			case 0: break;

			case 1: my_artist.show_main_event();
				break;

			case 2: cout << "Enter new main event: ";
				getline(cin, main_event);
				if(my_artist.set_main_event(main_event))
					cout << "New main event: " << main_event;
				else
					cout << "Error setting new main event, try again";
				break;

			case 3: cout << "Enter new main event day: ";
				getline(cin, main_event_day);
				if(my_artist.set_main_event_day(main_event_day))
					cout << "New main event day: " << main_event_day;
				else
					cout << "Error setting main event day...try again";
				break;

			case 4: my_artist.display();
				break;
			
			case 5: 
				cout << "Enter number: ";
				getline(cin, user_number);
				if(my_artist.karaoke_sign_up(user_number))
					cout << "Sign up sucessful!";
				else
					cout << "cannot sign up twice...";
				break;

			case 6: my_artist.buy_vinyl();
				break;

			case 7: cout << "Enter number ";
				getline(cin, user_number);
				if(my_artist.cancel_karaoke(user_number))
					cout << "Cancelled successfully!";
				else
					cout << "No appointment found for " << user_number;
				break;

			default: cout << "Invalid menu choice, try again....";
				 user_input = 1;
		}
		cout << endl;
	}
	while(user_input != 0);

	ending_message();

	return;
}

void monster_menu(void)
{
	cout << "PLEASE SELECT FROM THIS MENU!" << endl;
	cout << "1 - show main event" << endl;
	cout << "2 - set new main event" << endl;
	cout << "3 - set new main event day" << endl;
	cout << "4 - display" << endl;
	cout << "5 - wear costume sign up" << endl;
	cout << "6 - cancel costume sign up" << endl;
	cout << "7 - guess costume price " << endl;
	cout << "0 - to quit/exit" << endl;
}

void monster_choice(void)
{

	string name{""};
	string main_event{""};
	string main_event_day{""};
	string monster_type{""};
	int age{0};
	int num_of_fans{0};
	int user_input{0};
	string user_number{""};
	int costume_price_guess{0};

	cout << "Enter Monster name: ";
	getline(cin, name);
	cout << "Enter Monster main event: ";
	getline(cin, main_event);
	cout << "Enter Monster main event day: ";
	getline(cin, main_event_day);
	cout << "Enter Monster Type: ";
	getline(cin, monster_type);

	cout << "Enter Monster age: ";
	cin >> age;
	cout << "Enter number of fans Monster has: ";
	cin >> num_of_fans;

	cin.ignore(100, '\n');

	Monster my_monster(name, age, num_of_fans, main_event, main_event_day, monster_type);


	do
	{
		cout << endl;
		monster_menu();
		cin >> user_input;
		cout << endl;
		cin.ignore(100,'\n');

		switch(user_input)
		{
			case 0: break;

			case 1: my_monster.show_main_event();
				break;

			case 2: cout << "Enter new main event: ";
				getline(cin, main_event);
				if(my_monster.set_main_event(main_event))
					cout << "New main event: " << main_event;
				else
					cout << "Error setting new main event, try again";
				break;

			case 3: cout << "Enter new main event day: ";
				getline(cin, main_event_day);
				if(my_monster.set_main_event_day(main_event_day))
					cout << "New main event day: " << main_event_day;
				else
					cout << "Error setting main event day...try again";
				break;

			case 4: my_monster.display();
				break;
			
			case 5: cout << "Enter number: ";
				getline(cin, user_number);
				if(my_monster.wear_costume_sign_up(user_number))
					cout << "Sign up successful!";
				else
					cout << "Cannot sign up twice....";
				break;

			case 6: cout << "Enter number: ";
				getline(cin, user_number);
				if(my_monster.cancel_costume_sign_up(user_number))
					cout << "Cancelled successfully!";
				else
					cout << "No appointment found for: " << user_number;
				break;

			case 7: cout << "Enter number ";
				cin >> costume_price_guess;
				cin.ignore(100, '\n');
				if(my_monster.guess_costume_price(costume_price_guess))
					cout << "WINNER! Come pick up your free costume";
				else
					cout << "Wrong guess, try again...";
				break;

			default: cout << "Invalid menu choice, try again....";
				 user_input = 1;
		}
		cout << endl;
	}
	while(user_input != 0);

	ending_message();

	return;
}
