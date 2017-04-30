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

void Node::destroy() {
	if (children != nullptr) {
		for (int i = 0; i < child_len; i++) {
			children[i]->destroy();
		}
	}
	delete children;
	delete this;
};

void Node::setting(Node* Parent, bool Color,char* Command, float Policy_Score) {
	parent = Parent;
	color = Color;
	int i = 0;
	for (i; Command[i] != '\0'; i++) {
		command[i] = Command[i];
	}
	command[i] = Command[i];
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
Node* Node::make_Child(int I) {
	return children[I] = new Node();
}

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
void Node::renew_result(char* Result) {

	char Wwin = '0';
	char Bwin = '1';
	char Draw = '2';

	if (!color) { // 흰색이면
		if (Result[2] == Wwin) {
			add_Win();
		}
		else if (Result[2] == Bwin) {
			add_Lose();
		}
		else if (Result[2] == Draw) {
			add_Draw();
		}
	}
	else {
		if (Result[2] == Wwin) {
			add_Lose();
		}
		else if (Result[2] == Bwin) {
			add_Win();
		}
		else if (Result[2] == Draw) {
			add_Draw();
		}
	}
};
/*
중요!!! 수정해야함

랜덤 모델로 부터 받은 점수이기 때문에 

VISIT 선별 이후, Q 점수로 선별, 

정상 모델이라면 Selectiong Score 로 선별!


*/
char* Node::For_root_choice() {
	int tmp_max = 0;
	float tmp_max2 = 0;
	int index = 0;
	int num = 0;
	for (int i = 0; i < child_len; i++) {
		if (children[i]->get_Visit() > tmp_max) {
			index = i;
			tmp_max = children[i]->get_Visit();
			num = 1;
		}
		else if (children[i]->get_Visit() == tmp_max) {
			num++;
		}
	}
	if (num > 1){	
		index = 0;
		for (int i = tmp_max; i < child_len; i++) {
			if (children[i]->get_Visit() == tmp_max) {
				if (children[i]->get_Qscore() > tmp_max2) {
					index = i;
					tmp_max2 = children[i]->get_Qscore();
					cout << tmp_max2 << children[i]->get_Qscore();
				}
			}

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
void Node::print_childInfo() {
	for (int i = 0; i < child_len; i++) {
		cout << i << " : ";
		children[i]->print_nodeInfo();
	}
		
};


// 출력해보고 싶은 노드정보
void Node::print_nodeInfo() {
		cout << command;
		cout << "	win : " << win;
		cout << "	lose : " << lose;
		cout << "	Draw : " << draw; 
		cout << "	SCORE : " << calc_selectingScore();
		cout << "	Q : " << get_Qscore();
		cout << "	u : " << get_Uscore();
		cout << "	Visit : " << get_Visit() << endl;
};




int Node::sum_childrenVisit() {
	int sum = 0;
	for (int i = 0; i < child_len; i++)
		sum += children[i]->get_Visit();
	return sum;
};