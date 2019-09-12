# include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

void CreateList(ListNode *L, int n) {
	ListNode *tmp = NULL;
	ListNode *represent;
	L->next = NULL;
	represent = L;
	cout << "请输入" << n << "个数据来生成单链表" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> tmp->val;
		represent->next = tmp;
		represent = represent->next;
	}
	tmp->next = NULL;
}

void print(ListNode *L) {
	ListNode *p;
	p = L->next;
	cout << endl << "start";
	while (p) {
		cout << "->" << p->val;
		p = p->next;
	}
	cout << endl;
}

ListNode *mergeTwoLists(ListNode *l1,ListNode *l2) {
	if (l1 == NULL & l2 == NULL) return NULL;
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	//Final Output ListNode
	
	ListNode *pre = new ListNode(NULL);
	ListNode *head = pre;
	while (l1 != NULL && l2 != NULL) {
		if (l1->val > l2->val) {
			head = l2;
			l2 = l2->next;
		}
		else {
			head->next = l1;
			l1 = l1->next;
		}
		head = head->next;
		if (l1)
			head->next = l1;
		if (l2)
			head->next = l2;
			
	}
	return pre->next;
}

int main() {
	ListNode *list1 = new ListNode(NULL);
	ListNode *list2 = new ListNode(NULL);
	ListNode *result;
	int length_l1, length_l2;
	cout << "请依次输入两个单链表的长度用于创建单链表：" << endl;
	cin >> length_l1 >> length_l2;
	CreateList(list1, length_l1);
	CreateList(list2, length_l2);
	cout << "合并结果如下" << endl;
	result = mergeTwoLists(list1, list2);
	print(result);
}