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
// Descrition: Header file to define the base class and all the derived classes.
// 	       There are three derived classes that are all catagorized as celebrities.
// 	       All the function prototypes are below, their implementations are in the
// 	       file listed as "celebrity.cpp". 
//
// CELEBRITY CLASS
// 	Constructor(s):
// 		Celebrity():
// 			precondition: User has created a Celebrity object.
// 			postcondition: A new Celebrity object has been created and has
// 				       default values for member variables.
//
//		Celebrity(const string& name_, const int& age_, const int& fans, const string& main_event_,
//			  const string& main_event_d):
//			precondition: User has created a Celebrity object.
//			postcondition: A new Celebrity object has been created and the private member
//				       have been initialized with the information that has been placed
//				       in by the user.
//		
//		Celebrity(const Celebrity& to_copy):
//			precondition: A previous Celebrity object exist.
//			postcondition: A new Celebrity object is created as a copy of an exist Celebrity object.
//
//	Destructor(s):
//		~Celebrity():
//			precondition: A Celebrity object exist.
//			postcondition: All data is cleared and is reverted to their default vaule(s).
//
//	Operator(s):
//		Celebrity& operator = (const Celebrity& to_copy):
//			preconditon: At least two Celebrity objects exist.
//			postcondition: One Celebrity object becomes a copy of another preexisting 
//				       Celebrity object.
//
//	Data member(s):
//		chair* name: stores Celebrity name.
//		int age: stores Celebrity age.
//		int num_of_fans: stores number of fans the Celebrity has.
//		string main_event: stores main event for the Celebrity.
//		string main_event_day: stores main event day for the Celebrity.
//
//	Member Function(s):
//		void display(void) const:
//			precondition: A Celebrity object exist.
//			postcondition: Outputs information about the Celebrity.
//
//		void show_main_event(void) const:
//			precondition: A Celebrity object exist.
//			postcondition: Outputs the main event.
//
//		bool set_main_event(const string& value):
//			precondition: A Celebrity object exist.
//			postcondition: User sets a new main event for the Celebrity.
//
//		bool set_main_event_day(const string& value):
//			precondition: A Celebrity object exist.
//			postcondition: User sets a new main event day for the Celebrity.
//
//
// ACTOR CLASS:
//
// 	Constructor(s):
// 		Actor():
// 			precondition: A new Actor object is being created.
// 			postcondition: A new Actor object has been created with default value(s).
//
// 		Actor(const string& name_, const int& age_, const int& fans, const string& main_event_,
// 		      const string& main_event_d, const string& gen):
// 			precondition: A new Actor object is being created.
// 			postcondition: A new Actor object has been created with values passed in by client.
//
// 		Actor(const Actor& to_copy):
// 			precondition: At least one Actor objects exist.
// 			postcondition: A newly created Actor object becomes a copy of a preexisng Actor object.
//
// 	Destructor(s):
// 		~Actor():
// 			precondition: A Actor object exist.
// 			postcondition: All data is cleared and reset to their default vaule(s).
//
// 	Operator(s):
// 		Actor& operator = (const Actor& to_copy):
// 			precondition: At least two Actor objects exist.
// 			postcondition: A preexisting Actor object has now become a copy of another
// 				       preexisting Actor object.
//
// 	Date Member(s):
// 		string genre: stores genre of the Actor.
// 		Node* head: stores the head of the circular linked list.
// 		Node* tail: stores the tail of the circular linked list.
//
// 	Member Function(s):
// 		Public:
// 			void display(void) const:
// 				precondition: An Actor object exist.
// 				postcondition: Outputs information about the Actor.
//
// 			bool autograph_sign_up(const string& number):
// 				precondition: An Actor object exist.
// 				postcondition: User signs up for an appointment with the Actor.
//
// 			bool raffle_ticket(const int& number) const:
// 				precondition: An Actor object exist.
// 				postcondition: User inputs a number for chance to win a prize.
//
// 			bool cancel_autograph(const string& number):
// 				precondition: An Actor object exist.
// 				postcondition: User cancels their appointment with the Actor.
//
// 		Private:
// 			bool insert(Node*& head, Node*& tail, const string& name, const string& number):
// 				precondition: Actor object exist and user is attempting to make an
// 					      appointment with the Actor.
// 				postcondition: If no previous appointment is found, one is made.
//
// 			void copy(Node*& dest_head, Node*& tail, Node*& source_head, Node*& source_tail):
// 				precondition: At least two Actor objects exist and either the copy constructor
// 					      or copy assignment has been invoked. 
//				postcondition: An Actor object has a copy of another preexisting Actor's
//					       circular linked list.
//
//			bool cancel_autograph(Node*& head, Node*& tail, const string& number):
//				precondition: An Actor object exist and user is attempting to cancel
//					      an appointment with an Actor.
//				postcondition: If an appointment is found, it is deleted.
//
//			void assign_tail(Node*& head, Node* cursor, Node*& tail):
//				precondition: An Actor object exist.
//				postcondition: tail of the Actors circular linked list is updated.
//
//			void remove_all(Node*& head, Node*& tail):
//				precondition: An Actor object exist.
//				postcondition: All the information in the linked list is erased.
//
//			void remove(void):
//				precondition: An Actor object exist.
//				postcondition: All the information in the linked list is erased.
//
// MONSTER CLASS:
// 	Constructor(s):
// 		Monster():
// 			precondition: A Monster is being created.
// 			postcondition: A new Monster object is created with default value(s).
//
// 		Monster(const string& name_, const int& age_, const int& fans, const string& main_event_,
// 			const string& main_event_day_d, const string& monster_type):
// 			precondition: A Monster object is being created.
// 			postcondition: A Monster object is created with the values the user has entered.
//
//	Destructor(s):
//		~Monster():
//			precondition: A Monster object exist.
//			postcondition: A Monsters data memebers are deleted and reset to deafault vaule(s).
//
//	Operator(s):
//		Monster& operator = (const Monster& to_copy):
//			precondition: At least two Monster objects exist.
//			postcondition: A Monster object is copied from another preexisting Monster object.
//
//	Data Member(s):
//		vector<pair<string, Node>> my_vector: stores Node information from user input.
//		string monster_type: stores type of Monster.
//
//	Memeber Function(s):
//		Public:
//			void display(void) const:
//				precondition: Monster object exist.
//				postcondition: Ouputs information about the Monster.
//
//			bool wear_costume_sign_up(const string& name):
//				precondition: Monster object exist.
//				postcondition: New appointment is created for user.
//
//			bool cancel_costume_sign_up(const string& number):
//				precondition: Monster object exist.
//				postcondition: Appointment is cancelled if it exist.
//
//			bool guess_costume_price(const int& value) const:
//				precondition: Monster object exist.
//				postcondition: User is able to guess the price and win a prize.
//
//		private:
//			bool search_vector(const string& number, int start_idx, const int& end_idx) const:
//				precondition: Monster object exist and user wants to cancel appointment
//				postcondition: Appointment is cancelled based on user choice.
//
//			bool delete_appointment(const string& number, int start_idx, conts int& end_idx):
//				precondition: Monster object exist and user wants to delete appointemnt.
//				postcondition: Appointment is deleted if found.
//
// 	
#ifndef CELEBRITY_H
#define CELEBRITY_H

#include "node.h"
#include <utility> // pair
#include <string> // string
#include <vector> // vector
using std::string;
using std::pair;

class Celebrity
{
	public:
		Celebrity(); // default constructor
		~Celebrity(); // destructor
		Celebrity(const string& name_, const int& age_, const int& fans, const string& main_event_, 
			  const string& main_event_d);

		// copy constructor and copy assignment operator
		Celebrity(const Celebrity& to_copy); 
		Celebrity& operator = (const Celebrity& to_copy);

		void display(void) const;
		
		// additional function(s)
		void show_main_event(void) const;
		bool set_main_event(const string& value);
		bool set_main_event_day(const string& value);
	private:
		char* name;
		int age;
		int num_of_fans;
		string main_event;
		string main_event_day;
};


class Actor : public Celebrity
{
	public:
		Actor(); // default constructor
		~Actor(); // destructor - NEED 
		Actor(const string& name_, const int& age_, const int& fans, const string& main_event_,
		      const string& main_event_d, const string& gen);
		      
	
		// copy constructor and copy assignment operator - NEED BOTH
		Actor(const Actor& to_copy);
		Actor& operator = (const Actor& to_copy);

		// additional functions
		void display(void) const;
		bool autograph_sign_up(const string& number);  
		bool raffle_ticket(const int& number) const;
		bool cancel_autograph(const string& number); 

	private:
		// private member function(s) to help, client should not use these
		bool insert(Node*& head, Node*& tail, const string& name, const string& number);
		void copy(Node*& dest_head, Node*& dest_tail, Node*& source_head, Node*& source_tail);
		bool cancel_autograph(Node*& head, Node*& tail, const string& number);
		void assign_tail(Node*& head, Node* cursor, Node*& tail);
		void remove_all(Node*& head, Node*& tail);
		void remove_all(void);

		// private data memebers below
		string genre;
		Node* head;
		Node* tail;
};


class Artist : public Celebrity
{
	public:
		Artist(); // default constructor
		~Artist(); // destructor
		Artist(const string& name_, const int& age_, const int& fans,
		       const string& main_event_, const string& main_event_d, 
		       const string& gen);
		
		// copy constructor and copy assignment operator
		Artist(const Artist& to_copy);
		Artist& operator = (const Artist& to_copy);

		// additional funcitons
		void display(void) const;
		bool karaoke_sign_up(const string& number);
		void buy_vinyl(void) const;
		bool cancel_karaoke(const string& number);
		void print() const;

	private:
		bool cancel_karaoke(Node*& head, const string& number);
		void print(Node*& head) const;
		void copy(Node*& dest_head, Node*& source_head);
		bool karaoke_sign_up(Node*& head, const string& name, const string& number);
		void remove_all(Node* & head);
		Node** head;
		string genre;
};


class Monster : public Celebrity
{
	public:
		Monster(); // default constructor
		~Monster(); // destructor
		Monster(const string& name_, const int& age_, const int& fans,
		        const string& main_event_, const string& main_event_day_d, 
			const string& monster_type);
		
		// copy constructor and copy assignment operator
		Monster& operator = (const Monster& to_copy);

		// additional funcitons
		void display(void) const;
		bool wear_costume_sign_up(const string& number);
		bool cancel_costume_sign_up(const string& number);
		bool guess_costume_price(const int& value) const;

	private:
		bool search_vector(const string& number, int start_idx, const int& end_idx) const;
		bool delete_appointment(const string& number, int start_idx, const int& end_idx);
		std::vector<pair<string,Node>> my_vector;
		string monster_type;
};

#endif // CELEBRITY_H
