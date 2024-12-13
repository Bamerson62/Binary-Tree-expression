#include <iostream>
#include <stack>
#include <cstring>
#include "binaryTree.h"

using namespace std;

// struct for nodes in the binary expression tree
template <class Type>
struct node
{
    Type info;
    nodeType<class elemType> *lLink;
    nodeType<elemType>*rLink;
};

// binary expression tree class
class binaryExpressionTree : public binaryTree<nodeType<class elemType>&;

{
public:
    void buildExpressionTree(string postfix);
    double evaluateExpressionTree();

private:
void evaluateExpressionTree(nodeType<string> *p, stack<nodeType<string>*> &s);
};

void binaryExpressionTree::buildExpressionTree(string postfix)
{
    stack<nodeType<string>*> s;
    char *token;
    token = strtok(const_cast<char*>(postfix.c_str()), " ");

    while(token != NULL)
    {
        if(isdigit(token[0]))
        {
            nodeType<string> *temp = new nodeType<string>;
            temp->info = token;
            temp->lLink = NULL;
            temp->rLink = NULL;
            s.push(temp);
        }
        else if(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        {
          nodeType<string> *temp = new nodeType<string>;
                  temp->info = token;
                  temp->rLink = s.top();
                  s.pop();
                  temp->lLink = s.top();
                  s.pop();
                  s.push(temp);
              }
              else
              {
                  cerr << "Error: Unsupported token." << endl;
                  return;
              }
              token = strtok(NULL, " ");
          }

          if(s.size() != 1)
          {
              cerr << "Error: Stack is not empty." << endl;
              root = NULL;
          }
          else
          {
             root = s.top();
                    s.pop();
                }
            }

            double binaryExpressionTree::evaluateExpressionTree()
            {
                stack<nodeType<string>*> s;
                evaluateExpressionTree(root, s);
                nodeType<string> *temp = s.top();
                s.pop();
                double result = stod(temp->info);
                delete temp;
                return result;
            }

            void binaryExpressionTree::evaluateExpressionTree(nodeType<string> *p, stack<nodeType<string>*> &s)
            {
                if(p->lLink == NULL && p->rLink == NULL)
                {
                    s.push(p);
                }
              else if(p->info == "+")
                {
                    evaluateExpressionTree(p->lLink, s);
                    evaluateExpressionTree(p->rLink, s);
                    nodeType<string> *temp1 = s.top();
                    s.pop();
                    nodeType<string> *temp2 = s.top();
                    s.pop();
                    double x = stod(temp1->info);
                    double y = stod(temp2->info);
                    double result = y + x;
                    temp2->info = to_string(result);
                    s.push(temp2);
                    delete temp1;
                }
                else if(p->info == "-")
                {
                    evaluateExpressionTree(p->lLink, s);
                    evaluateExpressionTree(p->rLink, s);
                    nodeType<string> *temp1 = s.top();
                    s.pop();
                    nodeType<string> *temp2 = s.top();
                    s.pop();
                    double x = stod(temp1->info);
                    double y = stod(temp2->info);
                  double result = y - x;
                          temp2->info = to_string(result);
                          s.push(temp2);
                          delete temp1;
                      }
                     else if(p->info == "*")
                  {
                  evaluateExpressionTree(p->lLink, s);
                  evaluateExpressionTree(p->rLink, s);
                  nodeType<string> *temp1 = s.top();
                  s.pop();
                  nodeType<string> *temp2 = s.top();
                  s.pop();
                  double x = stod(temp1->info);
                  double y = stod(temp2->info);
                  double result = y * x;
                  temp2->info = to_string(result);
                  s.push(temp2);
                  delete temp1;
                  }
              else if(p->info == "/")
              {
              evaluateExpressionTree(p->lLink, s);
              evaluateExpressionTree(p->rLink, s);
              nodeType<string> *temp1 = s.top();
              s.pop();
              nodeType<string> *temp2 = s.top();
              s.pop();
              double x = stod(temp1->info);
              double y = stod(temp2->info);
              if(x == 0)
              {
              cerr << "Error: Division by zero." << endl;
              exit(1);
              }
              double result = y / x;
              temp2->info = to_string(result);
              s.push(temp2);
              delete temp1;
              }
              }
int main()
{
string postfix;
binaryExpressionTree tree;
cout << "Enter postfix expression: ";
getline(cin, postfix);

tree.buildExpressionTree(postfix);

cout << "The result of the expression is: " << tree.evaluateExpressionTree() << endl;

return 0;
}
