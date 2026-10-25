/* struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
}; */

Node* intersectPoint(Node* head1, Node* head2) {
    
	// slow and fast pointer solve karta hu

	Node* slow = head1 , *fast = head1, *curr = head1;

	while(curr->next){
		curr = curr->next;
	}


	curr->next = head2;

	while(fast&&fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			break;
		}
	}

	if(slow!=fast) return NULL; // handel when both are not connected with a common node in that case we return the NULL
	slow = head1;
   
//    common point pe meet karenge
	while(slow!=fast){
      slow = slow->next;
	  fast = fast->next;
	}    


	return fast;
	

}
