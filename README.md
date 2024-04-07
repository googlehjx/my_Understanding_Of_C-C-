# 我对C/C++的理解
> 我已建立数据类型的概念，包括基础数据类型、复合数据类型（指针）
> 也知道函数定义和函数调用的概念，编译器在编译源码时，会自动加上startup
> 代码，由启动代码调用main函数，每次函数调用都会建立**栈帧**，在栈帧上
> 保存了必要的局部变量。有些局部变量会被优化到寄存器中，以加速程序
> 执行，但如果要通过&取地址符号取址某变量，那么编译器必须在当前栈帧中分配
> 相应的空间，并把该地址赋给指向它的指针。

## 指针
> 指针是变量，也占有空间，它的大小是由系统决定的，一般因32位/64位机器
> 而分得4字节/8字节空间。同时，指针是复合数据类型，指向整型和指向浮点型的
> 指针不是同一个类型，因为在译码过程中读取的位数是不同的，对它们的解释也不同。

## 内存模型
> 通过编译得到的可执行文件是一种镜像，它描述了执行代码和操作数据如何
> 映射到内存中，操作系统执行某个程序，首先利用加载器去读取该文件，然后按照
> 编译器和操作系统之间的约定，将不同部分的数据分配到内存的不同位置上，
> 这就是**加载**过程。

> 内存主要分为如下几个区域：静态数据区、只读数据区、栈段、堆段，还有一部分
> 是内核映射区，那部分是所有进程共享的。它是操作系统代码常驻的区域。上面提
> 到的每次函数调用都会分配一个栈帧就是分配在栈段中，通过bp和sp寄存器指定。
> 该区域负责函数调用过程中实参传递和返回值传递，调用函数（caller function）
> 和被调函数（callee function)的寄存器保存（叫**压栈**），以及保存函数返回
> 后下一个要继续执行的代码的地址(叫**保护现场**)。

> 可以认为局部变量就保存在栈区，通过malloc或new分配的空间在堆段，全局变量保
> 存在静态数据区，代码保存在只读数据区域。这不难理解，全局变量的作用域不属于
> 任何函数，在main函数开始执行前，全局变量的空间就已经存在了。所以在程序进入
> main函数前其实就以及做了很多准备工作了。

> 从程序执行的角度看，就这些东西。但是现代编程语言是相当复杂的工程，从源程序到
> 可执行程序，再经过程序加载过程，形成**进程**，要经历很多阶段。面对越来越复杂的现实
> 问题，程序也变得越发庞大，编程语言也加入了更多特性，让程序员更轻松的驾驭编程
> 过程。总结起来就是**编程思想**或者**编程范式**，从早期的**结构化编程**到**面向
> 对象编程**，再到**泛型编程**，目的都是为了让程序员更好的写出可靠性高、易维护
> 和可重用的代码。

## 万变不离其宗
> 面对这样复杂如摩天大楼似的软件工程，一定要有这样的信念。找到合适的路径，付出足够的
> 努力和耐心，一定可以“登顶”

## 去掉那些不重要的细枝末节

> 程序涵盖了成千上万的概念和知识点，但它们并不是都那么重要，有些概念和知识点值得
> 你反复琢磨，而有些重要了解就够了，或者说是用到时查看一下就行了。而且，概念之间也
> 是分层次的，就像是摩天大楼，一层一层盖上去，从地基到框架，从硬装到软装，建造起来
> 是按步骤进行的。要抓住那些核心的支柱概念，才能最终成功“登顶”。

### 下面是我认为不重要的

1. 输入输出格式不重要，对用户体验来说比较重要，但是在后期专门花点时间修饰它就好，
初学者不需要花太多时间在这上面。
2. 操作符的优先级不重要，因为它们不是编程必须要了解的知识。如果可能多加括号，或者总
是另起一行就行了。
3. 二进制表示，它是比较复杂的，有反码、补码，浮点数表示、ASCII、Unicode编码等，在
某个时候看一下大概的原理，抓住核心就OK。

### 下面是我认为的非常非常核心的概念
> 掌握它们就能读、能写高质量的程序，切换到其他任何一门编程语言都轻而易举。也能够
> 在面对现实中千变万化、纷繁复杂的建模领域时得心应手。

函数  
- 定义
- 调用
- 返回值
- 作用域  
- 算法

对象  
- 数据对象
- 操作对象
- OOP对象
- 模板对象（泛型） 
- 作用域
- 对象与类型的关系

类型  
- 类型分类与表示
- 类型系统
- 类型推导
- 类型转换
- 类型与语义的关系
- 抽象数据类型（ADT）

访问权限
- 对象的作用域
- 数据和操作相互指向
- 类型空间  

内存模型
- 对象生命周期
- 存储位置
- 占用空间

### 什么是函数

> 函数是一组操作的组合，依赖C/C++预先定义的一些基本操作或者程序员自定义的其他操作(函数)。
> 它的名字可以认为是这些组合的代表。任何一门语言必须提供一种方式，让程序员
> 能够**定义**函数，在某个程序的可用空间中，包含了有名的操作组合，在需要使用
> 对应操作功能时，可以**调用**它。所以与函数概念紧密相连的两个概念是**函数定义**
> 和**函数调用**。

> **定义**是发明、创造，而**调用**是基于前面的创造出的函数，而使用它。既然函数
> 是操作组合，那么必然得知道操作的对象，以及操作的结果，它们分别叫**函数参数**
> 和**函数返回值**。

> 函数三要素： 
- 函数名
- 参数
- 返回值  
无一例外。有些情况下，看到函数没有参数列表，或者在函数定义的内部没看到返回值语句
是因为编译器添加了默认的返回语句。如果程序员严谨些，因为显示的给出它们。下面是
符合C99标准的最简单程序，它只包含一个main函数，且不接受传入参数，返回0.
```c
int main(void){
	return 0;
}
```
有些编译器还接受更加简洁的main函数。
```c
int main(){
}
```
main函数体内，没有return语句，是因为编译器指定了一条特别规则，main函数
如果没有给出return语句，那么就默认返回整数0，而函数头后面的空括号，表面
main函数不接受传入任何值。
在这个程序中，只有main定义，那么，谁来调用它呢？
这涉及C/C++语言及其编译器之间的默认协议。编译器在编译程序时，首先会查找main
函数。对可执行程序而言，main函数是程序的用户定义入口，编译器添加起始代码和
做一些环境初始化后，会调用main函数,语义上，在操作系统内部有`main()`调用语句。
可以理解为main函数是操作系统隐式调用的，而其他自定义函数或者库函数，必须由
程序员显示在main函数中，或者其他函数中调用，且符合程序上下文，比如
传入的参数和返回值符合当前的语义，也即类型兼容。
这点对初学者容易来说比较难理解，因为它还需要其他背景知识。
比如，对两个整数求和，那么可以定义add函数：
```c
int add(int a, int b){
	return a+b;
}
```
它的作用就是对传入的两个整数进行求和，并返回结果。有了这个定义后，就可以调用它，
传入相应的参数，预期得到相应的结果。
```c
int main(void){
	int x;
	int y;
	x = 1;
	y = 2;
	return add(x, y);
}
```
这个程序的预期返回值应该是3，因为在main函数中调用了add并且传入了两个整型，分别
是x和y，它们相应的值分别是1和2，相加得到3，并且被main函数返回。
C和C++还要求函数调用前，因为先**声明**，也就是给出说明，这个函数的名称、返回值
和传入参数，也叫**函数原型**。这样编译器就能识别出调用是否合法。
所以，上面正确的写法是：
```c
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
```
同样的方法可以定义其他函数，比如减法、乘法或者更加复杂的处理函数。
说到函数，还有一个概念就是**函数重载**，本质就是函数名相同，但是传入的
参数个数或者类型不同，在函数调用时，能够编译器准确识别到对应的函数定义。既然
函数名相同，那么它们之间肯定有非常密切的关联，否则另起一个函数不是更
明确？比如又想将两个float型的数相加，就可以定义`float add(float, float)`
它与`int add(int, int)`都是求两个数的和，但是传入的参数类型不同，这涉及
变量的类型的概念。其实在计算机内部整型和浮点型可以认为是两种完全不同的参数类型
只是它们在咱们日常认知中都是数的概念，而且有时候可以互相转换，才让问题变得
复杂了。编译器将add(int, int)这样的函数经过**名字修饰 (Name mangling)**后
变成了两个函数，避免了名称冲突。猜测将add(int, int)修饰为add_i_i，而add(float, flaot)
修饰为add_f_f，这样当调用传入float类型的函数时，将调用add_f_f函数而不是
add_i_i，如果不嫌麻烦完全可以给它们起这样的名字，而不需要函数重载概念。这是
编译器为程序员提供的一种方便，减少记忆太多的函数名。

### 什么是对象
> 其实函数也一种对象，它在内存中占有一定空间，并且表示某种语义——计算并返回结果
> 除了函数对象，还有数据对象，广义上的，一个简单类型变量，如`int a`,定义变量a，它
> 在内存中占有4个字节，它的语义代表**常规整型**，一种整数，可以加、减、乘、除和比较相等
> 操作。

C++在C的基础上对类型进行了扩展，也就是通过关键字`class`定义类型，它实例化后产生
狭义上的**对象**。class内包含成员变量和成员函数，在一个对象内，既包含了数据也
包含了数据的操作。极大的方便了程序员管理数据和操作。
```C++
class Student{
private:
	string name;
	float score;
public:
	Student(std::string n, float s):name(n), score(s){}
	void show(){
		std::cout<<"name: "<<name<<" "<<"score: "<<score<<std::endl;
	}
```
暂时忽略构造函数、析构函数等等概念。上面的代码片段定义了一个新的类型Student
它依赖预先提供的基础类型，float和库类型string，并且定义了show函数。
通过Student类型实例化一个对象，那么该对象中包含的数据就有学生的姓名和分数。
并且通过对象可以调用show函数，打印学生的信息。比较如下代码：
```c

std::string name;
float score;
void show(std::string, float);

```
当要输入某个学生的信息时，通过给name和score赋值，然后打印信息时调用`show(name, score)`
完成这样的功能。而C++面向对象编程，则：
```C++
Student s(name, score);
s.show();
```
函数模板和类模板也是一种对象，它将类型也参数化，也即类型的类型作为参数，编译器
在编译程序期间，根据传入的类型实参，对模板进行**实例化**。就是根据上下文产生相应
的函数/类定义，之后的编译步骤，与非模板程序编译相同。所以模板编程，比经典的面向对象
编程又多了一轮代码扫描，多了一层需要关注的语义层面。在可执行文件中，其实跟最上面描述
的函数调用、传递参数、返回结果没有区别。

### 什么是类型
> 在介绍函数、对象时，都绕不开**类型**这个概念。int是整型，float是浮点型，Student
是自定义的Student class类型，甚至在介绍函数时，它也是函数类型，具体为“能够执行
加法操作，对输入参数进行求和，并返回计算结果的一组操作组合”类型。每个不同的函数都是
函数类型的具体实例。模板是类型，模板函数或模板类型就是它的实例。

类型，是一个抽象概念，描述了一类具有共性的对象集合，它的具体化就是**对象**。每个
对象都属于特定的类型。类型抽象了这一类对象的语义，可以对它们**求值**。根据对象是数据类型还是
函数类型，编译器对它们求值方式不同。数据对象的求值过程，就是根据类型定义，读取对象指向的
地址的内容，并解释它；函数对象的求值过程是，读取函数名代表的内存地址内容，按照
代码格式解释或执行相应的操作，并返回结果或抛出异常。  
每个具体的类型也是一种对象，它是**类型对象**，该**类型对象**的类型是**Meta type**，它是
所有对象的祖先。
```c
int a;
float b;
"This is a Text"
class Student{
public:
	string name;
	float score;
	void show_info(){std::cout<<"name: "<<name<<" score: "<<score<<endl;}
}
Student s;
s.name = "Jim Green";
s.score = 89.0;
s.show_info();        // 通过对象调用其对应class的成员函数
class Add_functor{
public:
	int operator()(int a, int b){reture a+b;}   // 函数符重载
}
Add_functor af;
af(2, 3);     // 函数符调用， 求值过程
```
上述代码片段中int、float、string、Student、Add_functor都是类型，对应的对象也如代码所示，
函数调用过程就是函数类型的求值过程，变量参与运行、显示变量等过程中涉及数据对象的求值。


