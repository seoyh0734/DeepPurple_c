#pragma once
#include <iostream>
#include <math.h>
#include <string>

using namespace std;
class Node {
private:
	static const int Cpuct = 3;
	string command;
	bool color;
	float policy_Score;
	int win;
	int draw;
	int lose;
	int visit;
	Node** children;
	int child_len;
	Node* parent;
	bool bear_flag;
public:
	Node::Node();
	virtual Node::~Node();
	void Node::setting(Node* Parent, bool Color, string Command, float Policy_Score);
	void Node::set_Children(int Len, Node** Children);
	void Node::make_Children(int Len);
	void Node::set_Color(bool Color);
	bool Node::should_expand(int Visit);
	Node* Node::get_bestChild();
	float Node::get_policy_Score();
	string Node::get_command();
	Node* Node::get_Parent();
	Node** Node::get_Children();
	bool Node::get_Color();
	int Node::get_Win();
	int Node::get_Draw();
	int Node::get_Lose();
	int Node::get_Visit();
	bool Node::get_Flag();
	void Node::on_Flag();
	void Node::add_Win();
	void Node::add_Draw();
	void Node::add_Lose();
	void Node::add_Lose(int Lose);
	int Node::sum_otherVisit();
	float Node::calc_selectingScore();
	void Node::visited();
	float Node::sumChildPolicyScore();
	float* Node::get_policyDistribution();
	int Node::get_bestPolicyScoreChildIndex();
	void Node::renew_result(string Result);
	string Node::For_root_choice();
	bool Node::is_root();
	void Node::print_childInfo();

};