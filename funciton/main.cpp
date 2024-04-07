#include <iostream>
#include <string>
int add(int, int);
class Add_math {
public:
	int opperator()(int a, int b){
		return a+b;
}

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
	Add_math add;
	int sum = add(x, y);
	return add(x, y);
}

int add(int a, int b) {
	return a + b;
}
