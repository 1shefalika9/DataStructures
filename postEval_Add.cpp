#include <iostream>
#include <iomanip>
#include "IntStack.h"
using namespace std;

Stack add(Stack st1, Stack st2){
  int num1, num2, carry=0, sum=0, result=0;
  Stack s3;
	cout<<"\nEnter first number (Enter -1 to finish): ";
	while (1){
		cin>>num1;
    if(num1!= -1)
		  st1.push(num1);
    else
      break;
	}
	cout<<"\nEnter second number (Enter -1 to finish): ";
	while (1){
		cin>>num2;
    if(num2!= -1)
		  st2.push(num2);
    else
      break;
	}
  while(!st1.isEmpty() and !st2.isEmpty()){
    	int a = st1.topEle();
    	int b = st2.topEle();
        sum = a + b + carry;

        if(sum / 10 >= 1){
            carry = sum / 10;
            result = sum % 10;
        }
        else{
            carry = 0;
            result = sum;
        }
        
        s3.push(result);
        st1.pop();
        st2.pop();        
    }
    if (st1.isEmpty())
    {	int b = st2.topEle();
        while(!st2.isEmpty()){
            sum = b + carry;

            if(sum / 10 >= 1){
                carry = sum / 10;
                result = sum % 10;
            }
            else{
                carry = 0;
                result = sum;
            }

            s3.push(result);
            st2.pop();
        }
    }
    else{
    	int a = st1.topEle();
        while(!st1.isEmpty()){
            sum = a + carry;

            if(sum / 10 >= 1){
                carry = sum / 10;
                result = sum % 10;
            }
            else{
                carry = 0;
                result = sum;
            }

            s3.push(result);
            st1.pop();
        }
    }
    if(carry>0)
        s3.push(carry);
    return s3;
}

bool isOperator(char a){
    char operators[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; ++i)
    {
        if(operators[i]==a)
            return true;
    }
    return false;
}

int operation(char opr, int opd1, int opd2){
    int res;
    switch(opr){
        case '+':    res = opd1+opd2;
                    break;
        case '-':    res = opd1-opd2;
                    break;
        case '*':    res = opd1*opd2;
                    break;
        case '/':    res = opd1/opd2;
                    break;
    }

    return res;
}

int evaluate(string exp){
    Stack stk;
    for (int i = 0; i < exp.length(); ++i)
    {
        if (isdigit(exp[i]))
            stk.push((int)exp[i]-48);
        else if (isOperator(exp[i]))
        {    
            int opd2, opd1, result;
            opd2 = stk.topEle();
            stk.pop();
            opd1 = stk.topEle();
            stk.pop();
            result = operation(exp[i], opd1, opd2);
            stk.push(result);
        }
    }
    return stk.topEle();
}

int main(int argc, char const *argv[])
{
	char more= 'y';
  do{
		int choice;
		cout<<"\nChoose: \n1)Evaluate a postfix expression.\n2)Add two large numbers.";
		cin>>choice;
		switch(choice)
		{
			case 1:	string postfix;
    				cout<<"\nEnter the postfix expression to be evaluated: ";
    				cin>>postfix;
    				int answer;
    				answer = evaluate(postfix);
    				cout<<"\nEvaluating the expression we get: "<<answer;
			case 2:	Stack stack1, stack2;
					Stack stack3 = add(stack1, stack2);
  					cout<<"Sum is: ";
					int r;
  					r=stack3.disp();
  					if(r==-1)
    					cout<<"error";
		}
	cout<<"\nDo you wish to perform more operations?: (y/n): ";
  	cin>>more;
  	}while (more=='y');
	return 0;
}
