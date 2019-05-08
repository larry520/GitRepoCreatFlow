// use for c++ learning

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "SerialPort.h"
#include<windows.h>
#include"Stock.h"
#include"Sales_data.h"

using namespace std;
void struct_use();
void pt_use();
void quote();
void string_test();
void vetcor_type();
int serail_test(int argc);
void exception_test();
long long fact();
long long fact_sub();
void class_t();
void class_t2();
void def_acpra(int a = 10, string b = "very good!", string::size_type c = 66);
void sale_book();



int main()
{
    std::cout << "Hello World!\n"; 
	using namespace std;
	
	//pt_use();
	//struct_use();
	//string_test();
	//vetcor_type();
	//serail_test(1);
	//exception_test();
	//fact();
	//class_t2();
	//sale_book();

	return 0;
}
//对象指针 
// Coordinate *p = new Coordinate();
// p->m_iX = 10; // (*p).m_iX = 10;    指针使用时采用（*p）为一个指针对象，可直接访问成员。
// p->m_iY = 20; // (*p).m_iY = 20;
// delete p;
// p = NULL;
// ------------this 指针------------------------
// this 指针为对本身对象的引用  指针与引用实质上都是指向地址





// 类操作2
void sale_book()
{
	Sales_data S1, S2, S3; 
	S1.read();
	S1.print();
	S2.read();
	S2.print();
	// S1.combine(S2);
	S3 = add(S1, S2);
	S3.print();
}

// 默认实参  如果没有显示的使用实参进行赋值，则会采用默认实参。局部变量不会影响默认实验值
void def_acpra(int a/*= 10*/, string b/*="very good!"*/, string::size_type c/*=66*/)
{
	std::cout << "a: " << a << "\n b: " << b << "\n c: " << c << "\n";
}

// 类操作1
void class_t()
{
	Stock stock1("Larry Tec", 100, 60);
	stock1.show();
	stock1.buy(10, 50);
	stock1.update(100);
	Stock stock2("Google Page", 1000, 3);
	stock1.sell(20, 80);
}
void class_t2()
{
	int a = 100;
	def_acpra(a);
	def_acpra();
}

// 阶乘计算
long long fact_sub() {
	int num;
	long long count=1;
	std::cout << "plsease input a positive integer: " << std::endl;
	std::cin >> num;
	std::cout << "num number:"<< num<< std::endl;
	cin.clear();
	cin.ignore(1024, '\n');
	if (num <= 0 || int(num)!=num) 
		throw "you input a wrong number!";
	
	while (num>0)
	{
		count = count * num;
		std::cout << count << " num: " << num << std::endl;
		if (count < 0)
			throw " Attention, numerical calculation overflow!";
		Sleep(5);
		num--;
	}
	return(count);
}
long long fact() {
	long long count = -1;
	while (true) {
		try {
			count = fact_sub();
		}
		catch (const char* msg) {
			cerr << msg << endl;
			cout << "input Y for continue,  any other key for quit. " << endl;
			char tag;
			cin >> tag;
			if (toupper(tag) != 'Y') {
				break;
			}
			else
				continue;
			cin.clear();
			cin.ignore(1024,'\n');
		}
	}
	return(count);
}

// 异常处理
void exception_test()
{	
	int num1, num2;
	for (int i = 1; i < 5;i++) {
		std::cin >> num1 >> num2;
		std::cout << endl;
		try {
			if (num2 == 0) 
				throw "Oh dear, we can't divide num1 by zero~ ";
			std::cout << num1 / num2 << endl;
		// 
		}catch (const char* msg) {   
			cerr << msg << endl;
		}
		
	}
}

// 串口操作
int serail_test(int argc)
{

	CSerialPort mySerialPort;
	//初始化串口 COM2
	if (!mySerialPort.InitPort(argc))   
	{
		std::cout << "initPort fail !" << std::endl;
	}
	else
	{
		std::cout << "initPort success !" << std::endl;
	}
	//开启监听线程 
	if (!mySerialPort.OpenListenThread())
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}


	int temp;
	std::cin >> temp;
	std::cout << "You just input: " << temp << endl;
	return 0;
}

//vector 类型的使用
void vetcor_type()
{
	using std::vector;
	vector<int> ivec1{ 666 };						// 创建1个元素，初始值为666
	vector<int> ivec2(10, 1);						//创建10个元素，初始值为1
	cout << ivec2[3] << endl << ivec1[0] << endl;
	
	vector<unsigned> scores(11, 0);
	unsigned grade;
	while (cin>>grade)
	{
		if (grade <= 100) 
		{  
			// 统计各分数段的数量，并存在scores里面。
			++scores[grade / 10];
			cout << grade / 10 << endl;
		}	
	}
	// 输出各分数段的数量
	cout << "The scores destribution are:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout <<i*10<<" ~ "<<(i+1)*10<<": "<< scores[i] << endl;
	}
	cout << " 100 ： " << scores[10] << endl;
}

void vector_type2()
{
	vector<int> svea = { 1 };
	vector<int> sveb(svea);
	vector<int> svec = svea;
	vector<int> sved{ 0,1,2,3,4 };
	vector<int> svef(5);
	vector<int> svef(5);  // 5个元素，默认初始化为0 
	vector<int>::iterator p = svef.begin();  // 容器指针的使用 auto 定义元素比较方便，统一
	auto n = svef.end();
	auto m = *svef.begin(); // 指向第一个元素
	cout << "value of m = " << m << endl;
	// 容器遍历元素
	while (p != n )  
	{
		cout << "value of svef = " << *p << endl;
		p++;
	}
	int a, b, c, d;
	a=svec.front();
	b = *svec.begin();
	c = svec.at(0);
	d = svec[0];
	cout << "a: " << a << " b: " << b << " c: "<<c << " d: " << d;
}

// String option   使用string需要#include<string> 头文件，以及 using std::string两行代码。
void string_test()
{
	
	using std::string;
	string s1= "hey ha! ";
	string s2 = "good";
	string s3("job!");
	string	&s4 = s1;
	string	s5(6, '6');
	cout << s4 << " " << s2 << " " << s3 <<endl<< s5 << endl;
}

// 指针的使用
void pt_use()
{
	using namespace std;
	int qq = 100;
	int *p = &qq;
	int *pp = new int;
	cout << pp << endl << *pp << endl << &pp << endl;
	*pp = *pp + qq;
	cout << pp << endl << *pp << endl << &pp;
}

// 结构体使用及结构体指针
void struct_use()
{
	struct fruit   // 结构体定义
	{
		int apple;
		int orange;
		int cherry;
	};

	fruit fruitNo = { 6,5,2 };
	fruit *pt = &fruitNo;
	using namespace std;
	cout << "fruitNo member: " << endl
		<< "apple: " << fruitNo.apple << endl
		<< "orange: " << pt->orange << endl
		<< "cherry: " << pt->cherry << endl;

	struct years
	{
		int year;
	};
	years s01, s02;
	s01.year = 1990;
	years *pa = &s02;
	pa->year = 1999;
	cout << "I Love C++, that's a prefect program language! \n";
}

//引用，即和引用变量指向同一地址。两个变量同时作用于该地址存储值
void quote()
{
	int j0 = 1;
	int i = j0;
	int &k = i;
	j0 = 2;
	std::cout << k << std::endl;
}












// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件