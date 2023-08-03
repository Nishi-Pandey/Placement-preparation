//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Function which returns the root of the flattened linked list. */
Node* merge(Node* list1, Node* list2) {
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    Node* result;

    if (list1->data < list2->data) {
        result = list1;
        result->bottom = merge(list1->bottom, list2);
    } else {
        result = list2;
        result->bottom = merge(list1, list2->bottom);
    }

    result->next = nullptr; // Important to set the next pointer of merged nodes to NULL.
    return result;
}

Node* flatten(Node* root) {
    // Base case: If the root is NULL or the next node is NULL, return the root.
    if (!root || !root->next)
        return root;

    // Recursively flatten the next linked list.
    root->next = flatten(root->next);

    // Merge the flattened root with the current bottom linked list.
    root = merge(root, root->next);

    return root;
}





