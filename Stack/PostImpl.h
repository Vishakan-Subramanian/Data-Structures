/* FUNCTION IMPLEMENTATIONS FOR POSTFIX CONVERSION AND EVALUATION USING STACK */

int Precedence(char op1){			//To check precedence between 2 operators
	int o1;
	switch(op1){
		case '+':
		case '-':
				o1=1;
				break;
		case '*':
		case '/':
				o1=2;
				break;
		case '^':
				o1=3;
				break;
	}

	return o1;
}

char *infixtoPostfix(char *str, Stack *s){		//  To convert the given infix expression 
														//(without involving parenthesis) into its 
	char *temp;													//postfix form using the stack
	int len=strlen(str);
	temp=(char *)malloc(sizeof(char)*len);
	int i=0,tc=0;

	while(i<len){
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^'){

			if(isEmpty(s))
				push(s,str[i]);
			
			else{
				while((Precedence(s->arr[s->top])>=Precedence(str[i]))&&(!isEmpty(s))){
					temp[tc]=pop(s);
					tc++;
				}
				push(s,str[i]);	
			}
			
		}

		else
			temp[tc++]=str[i];

		i++;
	}

	while(!isEmpty(s)){
		temp[tc]=pop(s);
		tc++;
	}

	return temp;
}

int evaluateExp(char *postfix, Stack *s){		//To evaluate the expression considering its postfix form
	int i=0,x,y,res;
	int len=strlen(postfix);
	while(i<len){
		if(isdigit(postfix[i]))
			push(s,postfix[i]-'0');				//char to int conversion
		else{
			x=pop(s);
			y=pop(s);
			switch(postfix[i]){
				case '+':
					res=y+x;
					break;
				case '-':
					res=y-x;
					break;
				case '*':
					res=y*x;
					break;
				case '/':
					res=y/x;
					break;
				case '^':
					res=pow(y,x);
					break;
			}

			push(s,res);
		}
		i++;
	}
	return pop(s);
}