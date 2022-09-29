/*逆波兰表达式用栈求值即可
 */

bool isNumber(char* s){                               //判断字符串是否是数字
	return strlen(s) > 1 || ( s[0] <='9' && s[0] >= '0' );
}

int evalRPN(char** tokens, int tokensSize){
	int stack = malloc( sizeof(int) * 10000 );
	int top =  -1;                                //记录栈顶的位置
	for(int i = 0; i < tokensSize; i++){
		if( isNumber(tokens[i] )
			stack[++top] = atof(tokens[i]);  //是数字则入栈
		else{                                 //运算符则弹出两个数字运算后将结果入栈
			int n2 = stack[top--];
			int n1 = stack[top--];
			int ans;
			if( tokens[i][0] == '+')
				ans = n1 + n2;
			if( tokens[i][0] == '-' )
				ans = n1 - n2;
			if( tokens[i][0] = '*' )
				ans = n1 * n2;
			if( tokens[i][0] == '/' )
				ans = n1 / n2;
			stack[++top] = ans;
			}
	}
	return stack[top];
}
