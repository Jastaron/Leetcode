/* 若遇到左括号，则压栈
 * 若遇到右括号，则取出栈顶元素，判断是否对应
 */

bool isValid(char* s){
	int len = strlen(s);
	char *stack = mallloc( sizeof(char) * 10000 );
	int top = -1;
	for(int i = 0; i < len; i++){
		if( s[i] == '[' || s[i] == '(' || s[i] == '{' )
			stack[++top] = s[i];
		else{
			if( top == - 1 )
				return false;         //栈已为空但是表达式还未处理完，返回假
			else if(
			( s[i] == ')' && stack[top] == '(') ||
			( s[i] == '}' && stack[top] == '{') ||
			( s[i] == ']' && stack[top] == ']' )
				top--;                //如果遇到匹配的左右括号，则弹出栈中的左括号

			else return false;            //遇到不匹配的左右括号，返回假
		}
	}
	if( top == -1 )
		return true;                          //栈为空，返回真
	else return false;                            //还有未匹配的左括号，返回假
