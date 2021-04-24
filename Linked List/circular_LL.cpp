#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

// split a circular linked list into two halves

class Node{
    public:
        int data;
        Node* next;
};

void splitList(Node *head,Node **head1,Node **head2){
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if(head==NULL){
        return;
    }

    while(slow_ptr->next!=head && fast_ptr->next->next!=head){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    if(fast_ptr->next->next ==head){
        fast_ptr = fast_ptr->next;
    }

    *head1 = head;
    if(head->next!=head){
        *head2 = slow_ptr->next;
    }

    fast_ptr = slow_ptr;
    slow_ptr->next = head;

}
void push(Node **head, int data){
    Node *node = new Node();
    Node *temp = *head;
    node->data = data;
    node->next = *head;
    if(*head==NULL){
        node->next = node;
    }else{
        while(temp->next!=*head){
            temp = temp->next;
        }
        temp->next = node; 
    }
    *head = node;
}

void printList(Node *head)  
{  
    Node *temp = head;  
    if(head != NULL)  
    {  
        cout << endl;  
        do {  
        cout << temp->data << " ";  
        temp = temp->next;  
        } while(temp != head);  
    }  
} 


int main(){
  int list_size, i;  
          
    /* Initialize lists as empty */
    Node *head = NULL;  
    Node *head1 = NULL;  
    Node *head2 = NULL;  
      
    /* Created linked list will be 12->56->2->11 */
    push(&head, 12);  
    push(&head, 56);  
    push(&head, 2);  
    push(&head, 11);  
      
    cout << "Original Circular Linked List";  
    printList(head);      
      
    /* Split the list */
    splitList(head, &head1, &head2);  
      
    cout << "\nFirst Circular Linked List";  
    printList(head1);  
      
    cout << "\nSecond Circular Linked List";  
    printList(head2);  
    return 0;  
   return 0;
}