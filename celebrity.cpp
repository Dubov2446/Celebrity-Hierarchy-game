// File: celebrity.cpp
//
// Author: Josue Lopez
//
// Course/Class: CS302-002
//
// Date: 23rd October 2023
// 
// Program: cs302-002-program1
//
// CELEBRITY CLASS
// 	Constructor(s):
// 		Celebrity(): default constructor, no need to do anything as this will be called
// 			     automatically when object is made.
// 		
//
//		Celebrity(const string& name_, const int& age_, const int& fans, const string& main_event_,
//			  const string& main_event_d): Fill in data for Celebrity by entering information
//			  			       into the paramaterized constructor.
//
//		
//		Celebrity(const Celebrity& to_copy): copy constructor to make a copy of the object that's
//						     on the right hand side of the assigment operator.
//						     example call: Actor new_actor(your_actor);
//
//	Destructor(s):
//		~Celebrity(): This is called automatically, you do not need to do anything with this.
//
//	Operator(s):
//		Celebrity& operator = (const Celebrity& to_copy): Copy assignmen operator, that will make
//								  a copy of whatever is on the right hand
//								  side of the equal sign after clearing
//								  all the data on the object on the left
//								  hand side. Example call: my_actor = your_actor;
//
//	Member Function(s):
//		void display(void) const: displays the information on your current Celebrity.
//
//		void show_main_event(void) const: displays main event information.
//
//		bool set_main_event(const string& value): Allows you to set a new main event that is different 
//							  from the one you've originally set.
//
//		bool set_main_event_day(const string& value): Allows you to set a new main event day.
//
// ACTOR CLASS:
// 	Constructor(s):
// 		Actor(): If you create a Actor object with no arguments, it will get set to default
// 			 values.
//
// 		Actor(const string& name_, const int& age_, const int& fans, const string& main_event_,
// 		      const string& main_event_d, const string& gen): If you want to pass in information
// 		      						      when creating this object, it will get
// 		      						      those values and not default ones.
//
// 		Actor(const Actor& to_copy): Allows you to make a copy from what's on the right hand side.
// 					     Example call: Actor my_actor(your_actor):
// 	Destructor(s):
// 		~Actor(): No need to do anything with this, will get called automatically and clear data.
//
// 	Operator(s):
// 		Actor& operator = (const Actor& to_copy): Allows you to make a copy of whatever is on the
// 							  right hand side. Example call: my_actor = your_actor;
//
// 	Member Function(s):
// 		Public:
// 			void display(void) const: Outputs information on the Actor.
//
// 			bool autograph_sign_up(const string& number): Allows user to sign up for a autograph
// 								      appointment. Returns true if they can,
// 								      if they have already signed up, they 
// 								      cannot sign up again, false is returned.
//
// 			bool raffle_ticket(const int& number) const: User can guess a number is order for a
// 								     chance to win a prize, bool is returned.
//
// 			bool cancel_autograph(const string& number): Allows user to cancel autograph appointment
// 								     if they have already made one.
//
// 		Private:
// 			bool insert(Node*& head, Node*& tail, const string& name, const string& number): Allows
// 				    user to insert a new appointment if they haven't already made one. This is called
// 				    from within the autograph sign up function.
//
// 			void copy(Node*& dest_head, Node*& tail, Node*& source_head, Node*& source_tail): Allows user to
// 				    copy a linked list when called from within the copy constructor/assignmen operator.
//
//			bool cancel_autograph(Node*& head, Node*& tail, const string& number): When the user tries to cancel
//				    an appointment, this will be called recursively and if found will delete their
//				    appointment.
//
//			void assign_tail(Node*& head, Node* cursor, Node*& tail): Allows for the tail of the linked list
//				    to get back to it's rightful place if it is ever not clear.
//
//			void remove_all(Node*& head, Node*& tail): This is called from within the Destructor and
//				    will clear all nodes to avoid memory leaks. You don't call this.
//
//			void remove(void): Does the same thing except, this is the wrapper function for the
//				   recursive one with the same name.
//
// MONSTER CLASS:
// 	Constructor(s):
// 		Monster(): Default constructor that will set all values to default if you don't pass
// 		           anything into it.
//
// 		Monster(const string& name_, const int& age_, const int& fans, const string& main_event_,
// 			const string& main_event_day_d, const string& monster_type): Constructor with arguments
// 				so you can set values for data fields at the start if you want.
//
//	Destructor(s):
//		~Monster(): Deletes all nodes in destructor, you do not have to call this.
//
//	Operator(s):
//		Monster& operator = (const Monster& to_copy): Allows you to make a copy of whateven is on
//							      the right hand side when creating a new object.
//							      Example call: Monster my_monster(your_monster);
//
//	Memeber Function(s):
//		Public:
//			void display(void) const: Outputs Monster information.
//
//			bool wear_costume_sign_up(const string& name): Allows the user to sign up for a costume
//								       wearing appoitment.
//
//			bool cancel_costume_sign_up(const string& number): Allows user to cancel their appointment
//									   if they have one.
//
//			bool guess_costume_price(const int& value) const: Allows the user to guess how much a costume
//									  cost in order to maybe win a prize.
//
//		private:
//			bool search_vector(const string& number, int start_idx, const int& end_idx) const: This is called
//				from within the costume sign up function to see if they already have an appointemnt. If
//				they do not, one will be scheduled for them.
//
//			bool delete_appointment(const string& number, int start_idx, conts int& end_idx): This is called
//				from within the cancel costume sign up function, if their appointment is found, this
//				will delete it.

#include "celebrity.h"
#include "node.h"
#include <cstring> // strlen, strcpy 
#include <utility> // pair
#include <algorithm> // copy
#include <iostream> // cout, endl
using std::cout;
using std::endl;
using std::copy;
using std::string;
using std::cin;
using std::pair;
using std::make_pair;

// BASE CLASS FUNCTIONS BELOW

Celebrity::Celebrity() : name{nullptr}, age{0}, num_of_fans{0} {}

Celebrity::Celebrity(const string& name_, const int& age_, const int& fans,
		     const string& main_event_, const string& main_event_d) :
	name{new char[name_.size() + 1]}, age{age_}, num_of_fans{fans},
	main_event{main_event_}, main_event_day{main_event_d}
{
	copy(name_.begin(), name_.end(), name);
}

Celebrity::~Celebrity()
{
	if(name)
		delete [] name;
	age = 0;
	num_of_fans = 0;
	main_event = "";
	main_event_day = "";
}

Celebrity::Celebrity(const Celebrity& to_copy)
{
	name = new char[strlen(to_copy.name) + 1];
	strcpy(name, to_copy.name);

	age = to_copy.age;
	num_of_fans = to_copy.num_of_fans;
	main_event = to_copy.main_event;
	main_event_day = to_copy.main_event_day;
}

Celebrity& Celebrity::operator = (const Celebrity& to_copy)
{
	if(this != &to_copy)
	{
		if(name)
			delete [] name;
		string len = to_copy.name;
		name = new char[len.size() +  1];
		strcpy(name, to_copy.name);
		age = to_copy.age;
		num_of_fans = to_copy.num_of_fans;
		main_event = to_copy.main_event;
		main_event_day = to_copy.main_event_day;
	}
	return *this;
}

void Celebrity::show_main_event(void) const 
{
	cout << main_event << endl;
	return;
}

bool Celebrity::set_main_event(const string& value) 
{
	main_event = value;
	return true;
}

bool Celebrity::set_main_event_day(const string& value)
{
	main_event_day = value;
	return true;
}

void Celebrity::display(void) const 
{
	if(name)
	{
		cout << endl << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "# of fans: " << num_of_fans << endl;
		cout << "Main Event: " << main_event << endl;
		cout << "Main Event Day: " << main_event_day << endl; 
	}
	else
		cout << "No info was entered...." << endl;
	return;
}

// ACTOR CLASS BELOW


Actor::Actor() : genre{nullptr}, head{nullptr} {}

Actor::Actor(const string& name_, const int& age_, const int& fans,
	     const string& main_event_, const string& main_event_d, const string& gen) : 
	     Celebrity(name_, age_, fans, main_event_, main_event_d), genre(gen), head(nullptr), tail(nullptr) {}

Actor::Actor(const Actor& to_copy) : Celebrity(to_copy), genre{to_copy.genre}, head{nullptr}, tail{nullptr}
{
	/*
	if(to_copy.head && to_copy.tail)
	{
		copy(head, tail, to_copy.head, to_copy.tail);
		tail->set_next(head);
	}
	*/
}

void Actor::copy(Node*& dest_head, Node*& dest_tail, Node*& source_head, Node*& source_tail)
{
	return; // work on later, smd
}

Actor::~Actor()
{
	genre = "";
	if(head)
	{
		remove_all();
	}
	head = nullptr;
	tail = nullptr;
}

void Actor::display(void) const
{
	Celebrity::display();
	cout << "Genre: " << genre << endl << endl;
	return;
}

bool Actor::raffle_ticket(const int& number) const
{
	if(number == rand() % 51)
		return true;
	return false;
}

bool Actor::autograph_sign_up(const string& number)
{
	string name_temp{""};

	
	cout << "Enter name: ";
	getline(cin, name_temp);

	if(!head && !tail)
	{
		head = new Node("Autograph", name_temp, number, head);
		tail = head;
		return true;
	}

	if(head == tail) // both pointing to same node (only one)
	{
		if(head->get_phone_number() == number)
			return false; // their appointment is alread entered
				      
		tail = new Node("Autograph", name_temp, number, head);
		head->set_next(tail);
		return true;
	}

	// there are more than one nodes, so we need to check if apt already exist
	return insert(head, tail, name_temp, number);
}

bool Actor::cancel_autograph(const string& number)
{
	if(!head && !tail)
		return false;

	if(head == tail)
	{
		if(head->get_phone_number() == number)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}
		return false;
	}

	if(head->get_phone_number() == number && head != tail)
	{
		Node* temp = head;
		head = head->get_next();
		delete temp;
		tail->set_next(head);
		return true;
	}

	bool result = cancel_autograph(head, tail, number);
	if(result)
	{
		assign_tail(head, head, tail);
	}
	return result;
}

void Actor::assign_tail(Node*& head, Node* cursor, Node*& tail)
{
	if(cursor->get_next() == head)
	{
		tail = cursor;
		return;
	}
	return assign_tail(head, cursor->get_next_val(), tail);
}

bool Actor::cancel_autograph(Node*& head, Node*& tail, const string& number)
{
	if(head == tail)
	{
		if(head->get_phone_number() == number)
		{
			Node* temp = tail;
			head = head->get_next();
			delete temp;
			tail = nullptr;
			return true;
		}
		return false;
	}

	if(head->get_phone_number() == number)
	{
		Node* temp = head;
		head = head->get_next();
		delete temp;
		return true;
	}

	return cancel_autograph(head->get_next(), tail, number);
}

bool Actor::insert(Node*& head, Node*& tail, const string& name, const string& number)
{
	if(head == tail)
	{
		if(head->get_phone_number() == number)
			return false;
		Node * temp = new Node("Autograph", name, number, nullptr);
		temp->set_next(tail->get_next());
		tail->set_next(temp);
		tail = temp;
		return true;
	}

	if(head->get_phone_number() == number)
		return false;

	return insert(head->get_next(), tail, name, number);
}


void Actor::remove_all()
{
	if(!head && !tail)
		return;

	if(head == tail)
	{
		delete head;
		return;
	}

	// for more than 1 node, recursively delete all nodes
	tail->set_next(nullptr);
	remove_all(head, tail);
	head = nullptr;
	tail = nullptr;

	return;
}

void Actor::remove_all(Node*& head, Node*& tail)
{
	if(head == tail)
	{
		delete head;
		return;
	}

	remove_all(head->get_next(), tail);

	delete head;
	return;
}


/*********************************** ARTIST CLASS STARTS HERE ********************************/

Artist::Artist() : head{nullptr}, genre{""} {
	head = new Node*[0];
}

Artist::Artist(const string& name_, const int& age_, const int& fans,
       const string& main_event_, const string& main_event_d, const string& gen) :
       Celebrity(name_, age_, fans, main_event_, main_event_d), genre{gen}, head{nullptr} 
{
	head = new Node*[0];
}

Artist::~Artist()
{
	remove_all(head[0]);
	genre = "";
}

Artist::Artist(const Artist& to_copy)
{
	genre = to_copy.genre;
	copy(head[0], to_copy.head[0]);
}

Artist& Artist::operator = (const Artist& to_copy) 
{
	if(this != &to_copy)
	{
		remove_all(head[0]);
		if(to_copy.head[0])
			copy(head[0], to_copy.head[0]);
		genre = to_copy.genre;
	}
	return *this;
}

void Artist::copy(Node*& dest_head, Node*& source_head)
{
	if(!source_head)
		return;
	dest_head = new Node("Karaoke", source_head->get_name(), source_head->get_phone_number(), nullptr);
	return copy(dest_head->get_next(), source_head->get_next());
}

void Artist::remove_all(Node*& head)
{
	if(!head)
		return;
	remove_all(head->get_next());

	delete head;
	return;
}

bool Artist::karaoke_sign_up(Node*& head, const string& name, const string& number)
{
	if(head == nullptr)
	{
		head = new Node("Karaoke", name, number, nullptr);
		return true;
	}
	
	if(head->get_phone_number() == number)
		return false;
	return karaoke_sign_up(head->get_next(), name, number);
}

bool Artist::karaoke_sign_up(const string& number)
{
	string name{""};
	cout << "Enter name: ";
	getline(cin, name);
	if(head[0] == nullptr){
		head[0] = new Node("Karaoke", name, number, nullptr);
		return true;
	}

	return karaoke_sign_up(head[0], name, number);
}

bool Artist::cancel_karaoke(const string& number)
{
	if(head[0] == nullptr)
		return false;
	return cancel_karaoke(head[0], number);
}

bool Artist::cancel_karaoke(Node*& head, const string& number)
{
	if(!head)
		return false;
	
	if(head->get_phone_number() == number)
	{
		Node* temp = head;
		head = head->get_next();
		delete temp;
		return true;
	}

	return cancel_karaoke(head->get_next(), number);
}

void Artist::buy_vinyl(void) const
{
	int amount{0};
	cout << "Price per vinly 20$, how many would you like: ";
	cin >> amount;
	cin.ignore(100, '\n');
	if(amount > 0)
		cout << "Congrats on your order of " << amount << "vinyls!";
	else
		cout << "Invalid number, try again...";
	return;
}

void Artist::display(void) const 
{
	Celebrity::display();
	cout << "Genre: " << genre << endl;
	return;
}


/*********************************** MONSTER CLASS STARTS HERE ********************************/

Monster::Monster() : monster_type{""} {} 

Monster::Monster(const string& name_, const int& age_, const int& fans, 
		 const string& main_event_, const string& main_event_d,
		 const string& monster_type) : Celebrity(name_, age_, fans, main_event_, main_event_d),
					     monster_type{monster_type} {}


Monster& Monster::operator = (const Monster& to_copy) 
{
	if(this != &to_copy)
	{
		monster_type = to_copy.monster_type;
		my_vector.clear();
		my_vector.reserve(to_copy.my_vector.size());
		my_vector = to_copy.my_vector;
	}
	return *this;
}

Monster::~Monster()
{
	my_vector.clear();
	monster_type = "";
}

void Monster::display(void) const
{
	Celebrity::display();
	cout << "Monster type: " << monster_type << endl;
	return;
}

bool Monster::search_vector(const string& number, int start_idx, const int& end_idx) const 
{
	if(start_idx >= end_idx)
		return false;
	
	if(my_vector[start_idx].first == number)
		return true;
	
	return search_vector(number, start_idx + 1, end_idx);
}

bool Monster::wear_costume_sign_up(const string& number)
{
	if(!search_vector(number, 0, my_vector.size()))
	{
		string name{""};
		cout << "Enter name: ";
		getline(cin, name);
		my_vector.push_back(make_pair(number, Node("Costume", name, number, nullptr)));
		return true;
	}
	return false;
}

bool Monster::delete_appointment(const string& number, int start_idx, const int& end_idx)
{
	if(start_idx >= end_idx)
		return false;
	
	if(my_vector[start_idx].first == number)
	{
		my_vector.erase(my_vector.begin() + start_idx, my_vector.begin() + start_idx + 1);
		return true;
	}
	return delete_appointment(number, start_idx + 1, end_idx);
}

bool Monster::cancel_costume_sign_up(const string& number)
{
	return delete_appointment(number, 0, my_vector.size());
}

bool Monster::guess_costume_price(const int& value) const
{
	return (rand() % 101 == value);
}
