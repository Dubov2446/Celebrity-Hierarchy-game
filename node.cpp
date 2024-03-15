// File: node.h
//
// Author: Josue Lopez
//
// Course/Class: CS302-002
//
// Date: 23rd October 2023
// 
// Program: cs302-002-program1
//
// NODE CLASS:
// 	Constructor(s):
// 		Node():
// 			precondition: A Node is being created.
// 			postcondition: A new Node is created with default value(s).
//
// 		Node(const string& apt, const string& name_, const string& phone, Node* ptr):
// 			precondition: A Node is being created.
// 			postcondition: A new Node is created with user input value(s).
//
// 	Destructor(s):
// 		~Node():
// 			precondition: A Node object exist.
// 			postcondition: Sets nodes values to their default when object is destroyed.
//
//	Date Member(s):
//		string appointment: stores appointment information.
//		string name: stores name information.
//		string phone_number: stores phone number information.
//		Node* next: store link to next Node
//
//	Member Function(s):
//		void set_appointment(const string& value):
//			precondition: Node object exist.
//			postcondition: sets appointment information.
//
//		void set_name(const string& name):
//			precondition: Node object exist.
//			postcondition: sets name information.
//
//		void set_phone_number(const string& value): 
//			precondition: Node object exist.
//			postcondition: sets phone number information.
//		
//		void set_next(Node* ptr):	
//			precondition: Node object exist.
//			postcondition: sets Node pointer information.
//
//		Node*& get_next(void):
//			precondition: Node object exist.
//			postcondition: return Node pointer information by reference.
//
//		Node* get_next_val(void):
//			precondition: Node object exist.
//			postcondition: returns Node pointer information.
//
//		string get_appointment(void) const;
//			precondition: Node object exist.
//			postcondition: returns appointment information.
//
//		string get_name(void) const:
//			precondition: Node object exist.
//			postcondition: returns name information.
//
//		string get_phone_number(void) const:
//			precondition: Node object exist.
//			postcondition: returns phone number information.

#include "node.h"

using std::string;

// default contructor
Node::Node() : appointment{""}, name{""}, phone_number{""}, next{nullptr} {}

Node::Node(const string& apt, const string& name_, const string& phone,
     Node* ptr) : appointment{apt}, name{name_}, phone_number{phone}, next{ptr} {}

Node::~Node()
{
	appointment = string();
	name = string();
	phone_number = string();
	next = nullptr;
}

void Node::set_appointment(const string& value)
{
	appointment = value;
	return;
}

void Node::set_name(const string& value)
{
	name = value;
	return;
}

void Node::set_phone_number(const string& value)
{
	phone_number = value;
	return;
}

void Node::set_next(Node* ptr)
{
	next = ptr;
	return;
}

Node* Node::get_next_val(void)
{
	return next;
}

Node*& Node::get_next(void) 
{
	return next;
}

string Node::get_appointment(void) const
{
	return appointment;
}

string Node::get_name(void) const
{
	return name;
}

string Node::get_phone_number(void) const 
{
	return phone_number;
}

