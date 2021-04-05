#include"SqStack.h"
#include"SqStack.cpp"


int main() {
	int n = 0;
	
	do {
		std::cout << "                  ������      " << std::endl;
		std::cout << "		������ѡ��ѡ���Ӧ�Ĺ���   " << std::endl;
		std::cout << "              1,����      " << std::endl;
		std::cout << "              0,�˳�      " << std::endl;
		std::cin >> n;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "����Ƿ�!����������һ����ȷ������" << std::endl;
			std::cin >> n;
		}
		switch (n) {
		case 1:{
			std::cout << "��������Ҫ�������Ȼ������������ʽ" << std::endl;
			std::string s;
			std::cin >> s;
			int len = s.length();
			SqStack<int> temp(len);
			SqStack<float> computer(len);
			std::vector<int> save;
			int b = 0;
			int priority = 0;
			int table[] = { 0,0,2,1,0,1,0,2 };//���������ַ���Ӧ��ASCII���10��������������Ӧ�����ȼ�
			//���ݱ��֪�ֱ��Ӧ������,������,�˺�,�Ӻ�,����,����,���,����.
			
			/*��Ҫ˼·:���ַ����е�ÿ���ַ�ת��ΪASCII���,�ж��Ƿ���м��������������ַ�,
			���������ַ���10���������Ϊ����������±�Ӷ���ȡ�����ַ���Ӧ�����ȼ���С,
			����һ������ջ��һ����������,�������ڴ��洦�����ĺ�׺���ʽ,ջ��Ϊ��׺ת����׺�Ĺ���
			�Ӷ����տ��Ի��һ��ÿһ���ռ䴢�����ֻ��ߴ��������ַ�����Ӧ��ASCII��������
			֮�����������õĿɱ�������б���,��ͨ��������ջ��Ϊ�������߽��к�׺���ʽ�ļ���*/
			
			//��������:	1,��������������ֵ����������Ӧ��ASCII����ͬ,��ᷢ������
			//			2,��ǰ�������������ֻ������Ȼ��
			for (int i = 0; i < len;)
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					b = 0;		//b���ڴ������9�����ֲ�������׺ջ

					while (s[i] >= '0' && s[i] <= '9')
					{
						b = b * 10 + (s[i] - '0');
						i++;
					}
					save.push_back(b);
				}

				//����������ŵĻ�����ջ�������������ϵ��������������������׺ջ
				if (s[i] == ')')
				{
					while (temp.getTopStack() != '(')
					{
						save.push_back(temp.getTopStack());
						temp.popStack();
					}
					temp.popStack();
					//ע���ջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����
					priority = table[temp.getTopStack() % 10];
					i++;
				}

				//����������ŵĻ���ֱ��ѹջ
				if (s[i] == '(')
				{
					temp.pushStack(s[i]);
					//ע��ѹջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����
					priority = table[temp.getTopStack() % 10];
					i++;
				}

				//���ֻ����ͨ�����������ѹջ
				if (s[i]=='*'|| s[i] == '+'||s[i] == '-'||s[i] == '/')
				{
					//���ȱȽ�ջ��Ԫ�ص����ȼ��Ƿ����ջԪ�����ȼ�Ҫ��
					//����Ǵ��ڵĻ������ȴ�ջ����Ԫ�����γ�ջ��Ȼ��Ѵ���ջ��Ԫ��ѹջ
					if (priority >= table[s[i]%10])
					{
						while (priority >= table[s[i] % 10] && temp.getTopStack() != '(')
						{
							save.push_back(temp.getTopStack());
							temp.popStack();
							//ע��ÿ�εĳ�ջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼���������Ƚ�
							priority = table[temp.getTopStack() % 10];
						}
						temp.pushStack(s[i]);
						//ע��ѹջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����
						priority = table[temp.getTopStack() % 10];
						i++;
					}
					else {
						temp.pushStack(s[i]);
						//ע��ѹջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����
						priority = table[temp.getTopStack() % 10];
						i++;
					}

				}
			}
			//��ջ�л����ڵ�Ԫ�ؽ��е���������׺ջ
			while (temp.top != -1)
			{
				save.push_back(temp.getTopStack());
				temp.popStack();
			}

			float result = 0;
			for (auto i = save.begin(); i < save.end(); i++)
			{
				//ѭ��������׺���ʽ�����־�ֱ��ѹջ���������ȡջ������Ԫ�س������㣬�������ѹջ
				switch (*i)
				{
				case 42:
					result = computer.data[computer.top-1] * computer.getTopStack();
					computer.popStack();
					computer.popStack();
					computer.pushStack(result);
					break;
				case 43:
					result = computer.data[computer.top - 1] + computer.getTopStack();
					computer.popStack();
					computer.popStack();
					computer.pushStack(result);
					break;
				case 45:
					result = computer.data[computer.top - 1] - computer.getTopStack();
					computer.popStack();
					computer.popStack();
					computer.pushStack(result);
					break;
				case 47:
					result = computer.data[computer.top - 1] / computer.getTopStack();
					computer.popStack();
					computer.popStack();
					computer.pushStack(result);
					break;
				default:
					computer.pushStack(*i);
					break;
				}
			}
			std::cout<<"������Ϊ:"<<result<<std::endl;
			break;
		}
		case 0:
			break;
		default:
			std::cout << "������һ����ȷ������" << std::endl;
			break;
		}
	} while (n != 0);
	return 0;
}