#include <simplecpp>
#include <string>
#include <fstream>
#include <sstream>

struct Node{
  Node *L, *R;
  char op;
  string value;
  Node(string v);
  Node(char op1, Node* L1, Node* R1=NULL);
  Node(istream& infile);
  string print(){
    if(op == 'P') return value;
    else{
      string res =  string("(") + L->print() + op;
      if(R != NULL) res += R->print();
      res += ")";
      return res;
    }
  }

  Node *deriv(){
    if(op == 'P') return new Node(value == "x" ? "1" : "0");
    if(op == '+' || op == '-')
      return new Node(op, L->deriv(), R->deriv());

    if(op == 's') return new Node('*', new Node('c',L),
				  L->deriv());
    if(op == 'c')
      return new Node('-', new Node("0"), new Node('*', new Node('s',L),
					   L->deriv()));
    if(op == '*')
      return new Node('+', new Node('*', L->deriv(), R),
		      new Node('*',L, R->deriv()));
		    
    if(op == '/')
      return new Node('/',
		      new Node('-',
			       new Node('*', R, L->deriv()),
			       new Node('*', L, R->deriv())),
		      new Node('*', R, R));				    
    else return NULL;
  }
};

Node::Node(string v){                        // primitive constructor
  value = v;
  op = 'P';   // convention: 'P' in op denotes primitive formula.
  L = NULL;
  R = NULL;
}

Node::Node(char op1, Node* L1, Node* R1){  // recursive constructor
  value = "";
  op    = op1;
  L   = L1;
  R   = R1;
}

Node::Node(istream &infile){
  char c=infile.get();
  if((c >= '0' && c <= '9') ||     // is it a primitive formula?
     (c >= 'a' && c <= 'z') ||
     (c >= 'A' && c <= 'Z')){
    L=R=NULL; op='P'; value = c;
  }
  else if(c == '('){              // does it start a non-primitive formula?
    L = new Node(infile);            // recursively get the L formula
    op = infile.get();                 // get the operator
    if(op != 's' && op != 'c')
      R = new Node(infile);            // recursively get the R formula
    if(infile.get() != ')') 
      cout << "No matching parenthesis.\n";
  }
  else cout << "Error in input.\n";
}


int main(){
  Node z(cin);
  cout << z.deriv()->print() << endl;
}
