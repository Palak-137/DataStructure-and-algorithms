#include<bits/stdc++.h>           //------------------Kumari Palak---------
using namespace std;             //-----------------3222----------------

struct  node {
   char data;
   int f;
   node *lf, *rt;
   node(char c = '-', int cn = 0, node* a = NULL, node* b = NULL) {
      data = c;
      f = cn;
      lf = a;
      rt = b;
   }
};
class compare {
public:
   bool operator() (node *a, node *b) {
      return (a->f > b->f);
   }
};
priority_queue<node*, vector<node *>, compare> q;
map<char, int> m;
string s;
map<char, string> ck;
void solve() {

   while (q.size() > 1) {
      node *lft = q.top();
      q.pop();
      node *rtt = q.top();
      q.pop();
      q.push(new node('@', lft->f + rtt->f, lft, rtt));
   }

}
void encode(node *t = q.top(), string s = "") {
   if (t == NULL)
      return ;
   if (t->data != '@')
      ck[t->data] = s;
   else {
      encode(t->lf, s + '0');
      encode(t->rt, s + '1');
   }
}
void decode(string code) {
   string ans = "";
   node *t = q.top();
   for (char c : code) {
      if (c == '0')
         t = t->lf;
      else
         t = t->rt;
      if (t->data != '$') {
         ans += t->data;
         t = q.top();
      }
   }
}

int  main() {
   while(1){
            cout<<"Enter string: ";
            cin >> s;
    for (char c : s)
      m[c]++;
   for (auto it : m)
      q.push(new node(it.first, it.second));
   solve();
   encode();
   for (auto it : ck) {
      cout << it.first << " " << it.second << endl;
   }
   string code = "";
   for (char c : s) {
      code+="-";
      code += ck[c];
   }
   cout << code << endl;
   decode(code);

    }
   return 0;
}
