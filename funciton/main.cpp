#include <iostream>
#include <string>
int add(int, int);   // 声明普通函数
class Add_math {     // 定义类型，重写函数操作符，其对象可作为函数符使用
public:
	int opperator()(int a, int b){
		return a+b;
}
auto fun = [](Student &s){std::cout<<"name: "<<s.name<<" Score: " <<s.score<<std::endl;
class Student {
private:
	std::string name;
	float score;
public:
	Student(std::string n, float s) :name(n), score(s) {}
	void show() {
		std::cout << "name: " << name << " " << "score: " << score << std::endl;
	}
};
int main(int argc, char* argv[]) {
	int x;
	int y;
	x = 1;
	y = 2;
	Student s("John", 99.0);
	s.show();
	Add_math add_functor;  
	int sum = add_functor(x, y);
	return add(x, y);
}

int add(int a, int b) {
	return a + b;
}
