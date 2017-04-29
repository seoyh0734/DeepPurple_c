#include "Node.h"

Node::Node() {
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
	//cout << "노드 제거" << endl;
	//if (children != nullptr) {
	//for (int i = 0; i < child_len; i++) {
	//	delete children[i];
	//	cout << i << endl;
	//}
	//delete children;
	//}
	//cout << this << endl;
	
};

void Node::destroy() {

};

void Node::setting(Node* Parent, bool Color,string Command, float Policy_Score) {
	parent = Parent;
	color = Color;
	command = Command;
	policy_Score = Policy_Score;
};
void Node::set_Children(int Len,Node** Children) {
	children = Children;
	child_len = Len;
};
void Node::make_Children(int Len) {
	children = new Node*[Len];
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
string Node::get_command() {
	return command;
};
Node* Node::get_bestChild() {
	float tmp_max = 0;
	int index = 0;
	for (int i = 0; i < child_len; i++) {
		if (children[i]->calc_selectingScore() > tmp_max) {
			index = i;
			tmp_max = children[i]->calc_selectingScore();
		}
	}

	return children[index];
};

Node* Node::get_Parent() {
	return parent;
};
Node** Node::get_Children() {
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

int Node::get_Visit() {
	return visit;
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
	if (parent != nullptr) {
		int visit_sum = parent->sum_childrenVisit();
		return visit_sum - visit;
	}
	else {
		printf("부모노드가 없습니다.");
		return 0;
	}
};

float Node::calc_selectingScore() {
	//cout << win / (1 + win + lose + draw) + Cpuct * policy_Score * 1 << endl;
	return  get_Qscore()+ get_Uscore() ;
};

float Node::get_Qscore() {
	return (win + 0.1 * draw )/ (1 + win + lose + draw);
};
float Node::get_Uscore() {
	return Cpuct * policy_Score * 1 * sqrt(sum_otherVisit() + 1) / (1 + visit);
};

void Node::visited(){
	visit += 1;
};
float Node::sumChildPolicyScore() {
	float tmp_sum = 0;
	for (int i; i < child_len; i++) {
		tmp_sum += children[0]->policy_Score;
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
void Node::renew_result(string Result) {};

string Node::For_root_choice() {
	float tmp_max = 0;
	int index = 0;

	for (int i = 0; i < child_len; i++) {
		if (children[i]->get_Visit() > tmp_max) {
			index = i;
			tmp_max = children[i]->get_Visit();
		}
	}

	return children[index]->get_command();
};
bool Node::is_root() {
	if (!parent) {
		return true;
	}
	else
		return false;
};

// 출력해보고 싶은 노드정보
void Node::print_childInfo() {
	cout << "win : " << win;
	cout << " lose : " << lose;
	cout << " Draw : " << draw;

};


int Node::sum_childrenVisit() {
	int sum = 0;
	for (int i = 0; i < child_len; i++)
		sum += children[i]->get_Visit();
	return sum;
};