#include <iostream>
#include <string>
int add(int, int);   // 声明普通函数

template<typename T>  // 函数模板
T add_temp(T a, T b) {
	return a + b;
}

template<>   // 函数模板特化
double add_temp<double>(double a, double b) {
	std::cout << "specialization template function" << std::endl;
	return a + 1.0;
}

class Add_math {     // 定义类型，重写函数操作符，其对象可作为函数符使用
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

class Student {
public:
	std::string name;
	float score;
};

// lambda表达式
auto fun = [](Student& s) {std::cout << "name: " << s.name << " Score: " << s.score << std::endl; };
int main(int argc, char* argv[]) {
	int x;
	int y;
	x = 1;
	y = 2;
	Student s{ "John", 99.0 };
	Add_math add_functor;  
	int sum = add_functor(x, y);
	fun(s);    // lambda函数调用
	add_temp<int>(x, y); // 函数模板显示实例化
	add_temp<double>(1.0, 3.0);
	return add(x, y);
}

// 函数定义
int add(int a, int b) {
	return a + b;
}
