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

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void push(struct Node **head , int data){
    struct Node * new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = data;

    new_node->next = *head;
    new_node->prev = NULL;

    if(*head!=NULL)
        (*head)->prev = new_node;
    
    *head = new_node;
}

void insertBefore(struct Node **head,struct Node*next_node , int ndata){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = ndata;

    new_node->prev = next_node->prev;
    new_node->next = next_node;

    if(next_node->prev!=NULL){
        next_node->prev->next = new_node;
    }
    else{
        (*head) = new_node;
    }

}

void append(struct Node**head,int ndata ){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = ndata;
    new_node->next = NULL;
    if(*head==NULL){
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    new_node->prev = temp;
    return;
}

void insertAfter(struct Node *pev_node, int ndata){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = ndata;

    new_node->next = pev_node->next;

    pev_node->next = new_node;

    new_node->prev = pev_node;

    if(pev_node->next!=NULL){
        new_node->next->prev = new_node;
    }

}

void deleteNode(struct Node *head){
    head->prev->next = head->next;
    if()
}

void printList(struct Node *head){
    struct Node*last;
    cout<<"In forward direction\n";
    while(head!=NULL){
      cout<<head->data<<" ";
      last = head;
      head=head->next;
    }
    cout<<endl;
    cout<<"In backward direction\n";
    while(last!=NULL){
        cout<<last->data<<" ";
        last = last->prev;
    }
}
 
int main(){
 Node* head = NULL; 
 
    // Insert 6. So linked list becomes 6->NULL 
    append(&head, 6); 
 
    // Insert 7 at the beginning. So 
    // linked list becomes 7->6->NULL 
    push(&head, 7); 
 
    // Insert 1 at the beginning. So 
    // linked list becomes 1->7->6->NULL 
    push(&head, 1); 
 
    // Insert 4 at the end. So linked 
    // list becomes 1->7->6->4->NULL 
    append(&head, 4); 
 
    // Insert 8, after 7. So linked 
    // list becomes 1->7->8->6->4->NULL 
    insertAfter(head->next, 8); 
 
    cout << "Created DLL is: "; 
    printList(head); 
 
    return 0; 
}