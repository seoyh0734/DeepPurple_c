#include "Node.h"

Node::Node() {
	command = NULL;
	color = NULL;
	policy_Score = 0;
	win = 0;
	draw = 0;
	lose = 0;
	visit = 0;
	children = NULL;
	child_len = 0;
	parent = NULL;
	bear_flag = false;
};
Node::~Node() {
	
}

void Node::setting(Node* Parent, bool Color, char* Command, float Policy_Score) {
	parent = Parent;
	color = Color;
	command = Command;
	policy_Score = Policy_Score;
};
void Node::set_Children(int Len,Node* Children) {
	children = Children;
	child_len = Len;
};
void Node::make_Children(int Len) {
	children = new Node[Len];
	child_len = Len;
};
void Node::set_Color(bool Color) {
	color = Color;
};
bool Node::should_expand(int Visit) {
	if (visit == Visit)
		return true;
	else
		return false;
};
float Node::get_policy_Score() {
	return policy_Score;
};
char* Node::get_command() {
	return command;
};
Node* Node::get_bestChild() {
	float tmp_max = 0;
	int index = 0;
	for (int i = 0; i < child_len; i++) {
		if (children[i].get_policy_Score() > tmp_max) {
			index = i;
			tmp_max = children[i].get_policy_Score();
		}
	}
	return &children[index];
};

Node* Node::get_Parent() {
	return parent;
};
Node* Node::get_Children() {
	return children;
};

bool Node::get_Color() {
	return color;
};
int Node::get_Win() {
	return win;
};
int Node::get_Draw() {
	return draw;
};
int Node::get_Lose() {
	return lose;
};
bool Node::get_Flag() {
	return bear_flag;
};
void Node::on_Flag(){
	bear_flag = true;
};
void Node::add_Win() {
	win++;
};
void Node::add_Draw() {
	draw++;
	};
void Node::add_Lose() {
	lose++;
	};
void Node::add_Lose(int Lose) {
	lose += Lose;
};
int Node::sum_otherVisit() {
	if (parent) {
		int visit_sum = parent->sum_otherVisit();
		return visit_sum - visit;
	}
	else {
		printf("ë¶€ëª¨ë…¸?œê? ?†ìŠµ?ˆë‹¤.\n");
		return 0;
	}
};

float Node::calc_selectingScore() {
	return win / (1 + win + lose + draw) + Cpuct * policy_Score * sqrt(sum_otherVisit() + 1) / (1 + visit);
};
void Node::visited(){
	visit += 1;
};
float Node::sumChildPolicyScore() {
	int len = sizeof(children) / sizeof(Node);
	float tmp_sum = 0;
	for (int i; i < len; i++) {
		tmp_sum += children[0].policy_Score;
	}
	return tmp_sum;
};
float* Node::get_policyDistribution() {
	float tmp_sum = sumChildPolicyScore();
	return &tmp_sum;
};
int Node::get_bestPolicyScoreChildIndex() {
	return 1;
};
void Node::renew_result(bool Result) {};
char* Node::For_root_choice() {
	int best_child_index = get_bestPolicyScoreChildIndex();
	return 	children[best_child_index].get_command();
};
bool Node::is_root() {
	if (!parent) {
		return true;
	}
	else
		return false;
};

// Ãâ·ÂÇØº¸°í ½ÍÀº ³ëµåÁ¤º¸
void Node::print_childInfo() {
	cout << win << endl;
	cout << lose << endl;
};
