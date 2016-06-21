#include <bits/stdc++.h>

using namespace std;


char stack1[100];//for infix to postfix
char stack2[100];//for evalution 
int top=-1;//for infix to postfix
int top1=-1;//for postfix evalution

int Isoperand(char x)
{
	if((x >= 'a' && x<='z' )|| (x>='A'&& x<='Z')||(x>='0' && x<='9')){
		return 1;
	}
	else{
		return 0;
	}
}
int Isoperator(char x)
{
	if(x == '^' || x=='*' || x == '/' || x=='+' ||x =='-'){
		return 1;
	}
	else {
		return 0;
	}
}
int prec(char x)
{
	if(x=='^'){
		return  3;
	}
	if(x=='*'||x =='/'){
		return 2;
	}
	if(x=='+' || x=='-'){
		return 1;
	}
	return -1;
}
//for infix to postfix
void push(char x)
{
	top = top+1;
	stack1[top]=x;
}
//for  postfix evalution
void push1(char w)
{
	top1 = top1+1;
	stack2[top1]=w;
}
//for postfix evalution
char pop1()
{
	char a = stack2[top1];
	top1 = top1-1;
	return a;
}	
//for infix to postfix
void pop()
{
	top = top-1;
}
char postfixevalution(string d)
{
	int n = d.length();
	for(int k=0;k<n;k++){
		if(Isoperand(d[k])==1){
			push1(d[k]);
		}
		if(Isoperator(d[k])==1){
			char val1 = (int)pop1();
			char  val2 = (int)pop1();
			int q = val1 - 48;
			int q1 = val2 -48;
			if(d[k] == '+'){
				push1((q+q1)+'0');
			}
			else if(d[k] =='-'){
				push1((q1-q)+'0');
			}
			else if(d[k] =='*'){
				push1((q1*q)+'0');
			}
			else if(d[k]=='/'){
			push1((q1/q)+'0');
			}
			else if(d[k]=='^'){
			push1((pow(q1,q))+'0');
			}
		}
	}
	//cout<<stack1[top1]<<endl;
	return stack2[top1];
}

string infixToPostfix(string s)
{
	int n = s.length();
	int k=0;
	char ff[n+1];
	int flag=0;
	for(int i=0;i<n;i++){
		if(Isoperand(s[i])==1){
			ff[k]=s[i];
			k++;		
		}
		else if(s[i]=='('){
			push(s[i]);
		}
		else if(s[i]==')'){
			if(top==-1 && stack1[top]!='('){
				cout<<"Invalid expression ";
				flag =1;
			}
			while(top!=-1 && (stack1[top])!='('){
				ff[k] = stack1[top];
				k++;
				pop();
			}
			if(stack1[top]=='('){
				pop();
			}
		}
		else if(Isoperator(s[i])==1){
			while(top!=-1 && (prec(stack1[top])>=prec(s[i])))
			{
				ff[k]=stack1[top];
				k++;
				pop();
			}
			push(s[i]);
		}
	}
	while(top!=-1){
		ff[k] = stack1[top];
		pop();
		k++;
	}
	if(flag!=1){
		for(int g=0;g<n;g++){
			cout<<ff[g];
		}
	}
	cout<<"\n";
	return ff;
}


int main()
{

	string s;
	cin>>s;
	string g = infixToPostfix(s);
	char f =postfixevalution(g);
	cout<<f<<endl;
	return 0;
}
