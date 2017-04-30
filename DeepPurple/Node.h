#pragma once
#include <iostream>
#include <math.h>


using namespace std;
class Node {
private:
	static const int Cpuct = 3;
	char command[10] = "";
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
	void Node::destroy();
	void Node::setting(Node* Parent, bool Color, char* Command, float Policy_Score);
	void Node::set_Children(int Len, Node** Children);
	void Node::make_Children(int Len);
	Node* Node::make_Child(int I);
	void Node::set_Color(bool Color);
	bool Node::should_expand(int Visit);
	Node* Node::get_bestChild();
	float Node::get_policy_Score();
	char* Node::get_command();
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
	float Node::get_Qscore();
	float Node::get_Uscore();
	void Node::visited();
	float Node::sumChildPolicyScore();
	float* Node::get_policyDistribution();
	int Node::get_bestPolicyScoreChildIndex();
	void Node::renew_result(char* Result);
	char* Node::For_root_choice();
	bool Node::is_root();
	void Node::print_childInfo();
	void Node::print_nodeInfo();
	int Node::sum_childrenVisit();

};