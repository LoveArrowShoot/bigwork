#include"LinkStack.h"
#include"LinkStack.cpp"

int main() {
	int n = 0;

	do {
		std::cout << "                  计算器      " << std::endl;
		std::cout << "		请输入选项选择对应的功能   " << std::endl;
		std::cout << "              1,计算      " << std::endl;
		std::cout << "              0,退出      " << std::endl;
		std::cin >> n;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入非法!请重新输入一个正确的数字" << std::endl;
			std::cin >> n;
		}
		switch (n) {
		case 1: {
			std::cout << "请输入你要计算的自然数四则运算表达式" << std::endl;
			std::string s;
			std::cin >> s;
			int len = s.length();
			LinkStack<int> temp;
			LinkStack<float> computer;
			std::vector<int> save;
			int b = 0;
			int priority = 0;
			int table[] = { 0,0,2,1,0,1,0,2 };//根据算术字符对应的ASCII码除10后的余数来代表对应的优先级
			//根据表得知分别对应左括号,右括号,乘号,加号,逗号,减号,句号,除号.

			/*简要思路:将字符串中的每个字符转化为ASCII码表,判断是否会有几个连续的数字字符,
			根据算术字符除10后的余数作为整数数组的下标从而获取算术字符对应的大小,
			建立一个整数栈和一个整数数组,数组用于储存处理完后的后缀表达式,栈作为中缀转换后缀的工具
			从而最终可以获得一个每一个空间储存数字或者储存算术字符所对应的ASCII码表的数组
			之后根据上述获得的可变数组进行遍历, 并通过浮点数栈作为辅助工具进行后缀表达式的计算*/
			//存在问题:	1,如果参与运算的数值与算术符对应的ASCII码相同,则会发生错误
			//			2,当前只能对自然数做运算
			for (int i = 0; i < len;)
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					b = 0;		//b用于储存大于9的数字赋给后缀栈

					while (s[i] >= '0' && s[i] <= '9')
					{
						b = b * 10 + (s[i] - '0');
						i++;
					}
					save.push_back(b);
				}

				//如果是右括号的话，将栈中在左括号以上的所有运算符弹出赋给后缀栈
				if (s[i] == ')')
				{
					while (temp.top->data != '(')
					{
						save.push_back(temp.getTopLStack());
						temp.popLStack();
					}
						temp.popLStack();
					//注意将左括号出栈后，须将新的栈顶元素的优先级记录下来
					priority = table[temp.getTopLStack() % 10];
					i++;
				}

				//如果是左括号的话，直接压栈
				if (s[i] == '(')
				{
					temp.pushLStack('(');
					//注意压栈后，须将新的栈顶元素的优先级记录下来
					priority = table[temp.getTopLStack() % 10];
					i++;
				}

				//如果只是普通的运算符，则压栈
				if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/')
				{
					//首先比较栈顶元素的优先级是否比入栈元素优先级要大
					//如果是大于的话，则先从栈顶将元素依次出栈后，然后把待入栈的元素压栈
					if (priority >= table[s[i] % 10])
					{
						while (priority >= table[s[i] % 10] && temp.getTopLStack() != '(')
						{
							save.push_back(temp.getTopLStack());
							temp.popLStack();
							//注意每次的出栈后，须将新的栈顶元素的优先级记录下来用作比较
							priority = table[temp.getTopLStack() % 10];
						}
						temp.pushLStack(s[i]) ;
						//注意压栈后，须将新的栈顶元素的优先级记录下来
						priority = table[temp.getTopLStack() % 10];
						i++;
					}
					else {
						temp.pushLStack(s[i]);
						//注意压栈后，须将新的栈顶元素的优先级记录下来
						priority = table[temp.getTopLStack() % 10];
						i++;
					}
				}
			}
			//把栈中还存在的元素进行弹出赋给后缀栈
			while (temp.top->next!= NULL)
			{
				save.push_back(temp.top->data);
				temp.popLStack();
			}
			float result = 0;
			for (auto i = save.begin(); i < save.end(); i++)
			{
				//循环遍历后缀表达式，数字就直接压栈，运算符就取栈顶两个元素出来计算，并将结果压栈
				switch (*i)
				{
				case 42:
					result = computer.top->next->data * computer.getTopLStack();
					computer.popLStack();
					computer.popLStack();
					computer.pushLStack(result);
					break;
				case 43:
					result = computer.top->next->data + computer.getTopLStack();
					computer.popLStack();
					computer.popLStack();
					computer.pushLStack(result);
					break;
				case 45:
					result = computer.top->next->data - computer.getTopLStack();
					computer.popLStack();
					computer.popLStack();
					computer.pushLStack(result);
					break;
				case 47:
					result = computer.top->next->data / computer.getTopLStack();
					computer.popLStack();
					computer.popLStack();
					computer.pushLStack(result);
					break;
				default:
					computer.pushLStack(*i);
					break;
				}
			}
			std::cout << "运算结果为:" << result << std::endl;
			break;
		}
		case 0:
			break;
		default:
			std::cout << "请输入一个正确的数字" << std::endl;
			break;
		}
	} while (n != 0);
	return 0;
}