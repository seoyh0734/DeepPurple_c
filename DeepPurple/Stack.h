#pragma once
class Snode {
private:
	char* str;
	Snode* backNode;
	Snode* nextNode;
public:
	Snode::Snode(char* tmp_str) ;
	Snode::Snode();
	char* Snode::get_str();
	Snode* Snode::get_next();
	Snode* Snode::get_back();
	void Snode::set_next(Snode* next);
	void Snode::set_back(Snode* back);
	void Snode::set_str(char* tmp_str);
};

class Stack {
private:
	int top;
	Snode* last;
public:
	Stack::Stack();
	void Stack::push(char* tmp);
	char* Stack::pop();
	bool Stack::is_empty();
};