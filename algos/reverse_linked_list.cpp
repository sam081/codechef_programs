#include<iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

//print linked list
void print_list(ListNode *head){
	ListNode *curr = head;
	while(curr != NULL){
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}

//reverse a LL
ListNode* reverse(ListNode * head){
	ListNode *curr, *prev, *temp;

	if(head->next == NULL) return head;

	curr = head;
	prev = NULL;
	while(curr != NULL){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
	return head;
}

//reverse between given range
ListNode * reverse_range(ListNode* head, int n, int m){
	//find the start and end of the LL to be reversed
	ListNode *start=NULL, *end=NULL;
	ListNode *curr=head, *prev=NULL;
	int i=0;
	cout<<"start while\n";
	while(i<m){
		prev = curr;
		cout << i;
		curr = curr->next;

		if(i==n-1) start = prev;
		i++;
	}
	end = curr;
	cout << end->val;
	//call reverse on the sublist
	ListNode *temp_head = reverse(prev->next);

	start->next = temp_head;
	
	i=0;
	while(i<m){
		prev = curr;
		curr = curr->next;
		i++;
	}

	prev->next = end;
	return head;
}
int main(){
	while(1){
		int t,n,m;
		cin >> t >> n >>m ;
		ListNode *head = NULL, *curr = NULL, *prev = NULL;// *next = NULL;

		//create linked list
		for(int i=0; i<t; i++){
			int x;
			cin >> x;
			ListNode * newNode = new ListNode(x);

			if(i==0){
				curr = newNode;
				prev = curr;
				head = curr;
			}
			else{
				curr->next = newNode;
				prev = curr;
				curr = curr->next;
			}
		}
		cout << "LL: "; print_list(head);
//		head = reverse(head);
//		cout << "Rev LL: "; print_list(head);
		head = reverse_range(head, n, m);
		cout << "Rev sublist LL: "; print_list(head);
	}
}
