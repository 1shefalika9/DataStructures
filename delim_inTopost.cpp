#include <iostream>
#include <iomanip>
#include "CharStack.h"
using namespace std;

bool isParenthesis(char a){
    char operators[6] = {'(', ')', '{', '}', '[', ']'};
    for (int i = 0; i < 6; ++i)
    {
        if(operators[i]==a)
            return true;
    }
    return false;
}

bool isOpening(char a){
    char openPar[3] = {'(', '{', '['};
    for (int i = 0; i < 3; ++i)
    {
        if(openPar[i]==a)
            return true;
    }
    return false;
}

int openingPar(char delim){
    int val_open;
    switch(delim){
        case '(':    val_open = 1;
                    break;
        case '{':    val_open = 2;
                    break;
        case '[':    val_open = 3;
                    break;
    }

    return val_open;
}

int closingPar(char delim){
    int val_close;
    switch(delim){
        case ')':    val_close = 1;
                    break;
        case '}':    val_close = 2;
                    break;
        case ']':    val_close = 3;
                    break;
    }

    return val_close;
}

bool isMatch(string exp){
	Stack stk;
	for (int i = 0; i < exp.length(); ++i)
	{
		if (isParenthesis(exp[i]))
		{
			if (isOpening(exp[i]))
				stk.push(exp[i]);
			else
			{	if(!stk.isEmpty())
					{ 
            			if (closingPar(exp[i]) == openingPar(stk.topEle()))
						  stk.pop();
            			else
              				return false;
					}
				else
					return false;
			}		
		}
	}
	if (stk.isEmpty())
		return true;
	else
		return false;
}

int precedence(char ch){
    int val;
    switch(ch){
        case '(' : val = 0;
                   break;
        case ')' : val = -1;
                   break;
        case '{' : val = 0;
                   break;
        case '}' : val = -1;
                   break;
        case '[' : val = 0;
                   break;
        case ']' : val = -1;
                   break;
        case '-' : val = 1;
                   break;
        case '+' : val = 2;
                   break;
        case '*' : val = 3;
                   break;
        case '/' : val = 4;
                   break;
        case '^' : val = 5;
                   break;
        default : val = -1;
    }
    return val;
}

char* in_to_post(string infix){
    char *postfix = new char[infix.length()];
    Stack st;
    int j = 0;
    for (int i = 0; i < infix.length(); ++i)
    {
        if (isalpha(infix[i]))    //when operand is an alphabet(ie. variable)
           { postfix[j] = infix[i]; j++;}

        else if(isdigit(infix[i]))    //when operand is a number
            {postfix[j] = infix[i]; j++;}

        else{
            if (st.topEle()== 'e')    //when operator stack is empty
                st.push(infix[i]);
            else{
                int exp_opd_prece = precedence(infix[i]);
                int stack_opd_prece = precedence(st.topEle());
                if(exp_opd_prece != 0 and exp_opd_prece != -1)    //when operator is not parenthesis
                {
                    if (stack_opd_prece > exp_opd_prece){
                        postfix[j] = st.topEle();
                        j++;
                        st.pop();
                        st.push(infix[i]);
                    }
                    else if(stack_opd_prece < exp_opd_prece)
                        st.push(infix[i]);
                }
                else    //when operator is parenthesis
                {
                    if (exp_opd_prece == 0)
                        st.push(infix[i]);
                    else{
                        while((st.topEle()!='(')and(st.topEle()!='{')and(st.topEle()!='['))
                        {
                            postfix[j] = st.topEle();
                            j++;
                            st.pop();
                        }
                        st.pop();
                    }
                }
            }
        }
    }
    while (st.topEle()!='e')
     { postfix[j] = st.topEle();
       st.pop();
       j++; }
    return postfix;
}

int main(int argc, char const *argv[])
{	char more= 'y';
  do{
		int choice;
		cout<<"\nChoose: \n1)Get the postfix expression to an infix expression.\n2)Check for matching parenthesis in an infix expression.";
		cin>>choice;
		switch(choice)
		{
			case 1:	string s;
    				cout<<"\nEnter the infix expression: ";
    				cin>>s;
    				char *post = in_to_post(s);
    				cout<<"\nThe postfix expression is: "<<post;
    				break;
			case 2:	string expression;
					cout<<"\nEnter the expression: ";
					cin>>expression;
  					bool result = isMatch(expression);
  					if (result == 1)
	  				cout<<"\nThe expression has matching parenthesis";
  					else
    				cout<<"\nThe expression does not have matching parenthesis";
		}
	cout<<"\nDo you wish to perform more operations?: (y/n): ";
  	cin>>more;
  	}while (more=='y');
	return 0;
}