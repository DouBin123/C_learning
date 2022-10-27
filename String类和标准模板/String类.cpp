//************************string类***************
/*
1、构造字符串
	7个构造函数，ctor标识
	string(const char*);
	string(size_type n,char c);//n个c
	string(const string &str);//复制
	string();
	string(const char*s,size_type n);
	string(const string &str,string size_type pos=0,size_typr=npos);//初始化为str中pos到尾，或pos开始的n个字符
	string(string &&str)noexcept;//移动
	string(initializer_list<char>il)
	template<class Iter>string(Iter begin,Iter end);
注意：string可以像字符数组一样访问字符，但是对象名不能像数组名一样做地址。
2、string输入
	(1)C风格
		cin>>cstr;
		cin.getline(cstr,100);
		cin.get(cstr,100);
	(2)string对象,可以自动适应长度
		cin>>str;
		getline(cin,str)
注意getline都有一个可选参数，指定字符确定输入边界
getline(str,':');
cin.getline(cstr,100,':');
	cin.opertor>>(fname);
	operator>>(cin,fname);
在getline()限制string对象的长度：string::npos
	(1)到达文件尾，输入的eofbit将被设置，fail()和eof()都将返回true.
	(2)遇到分界字符(默认\n)，将分界字符从出入流中删除，但不存储。
	(3)读取的字符数达到最大允许值（string::nops和可分配内存字节数中的较小值），设置输入流的failbit,fail()返回true.
string版本的operator>>()函数与此类似，只是它不断读取，直到遇到空白字符并将其留在队列中，直到遇到分界字符并将其丢弃。
空白字符指空格，回车，制表符，调用isspace()。
3、使用字符串
	(1)重载比较运算符，从第一个字母开始按照机器排列序列（ASCII:数<大写<小写）
	(2)确定字符串长度，返回字符串中的字符数：size(),length().
	(3)搜索子字符或字符串：find()
		size_type find(const string &str,size_type pos=0)const;//从字符串的pos位置开始，查找子字符串str，若有，返回首次出现索引，否则，返回string::npos.
		size_type find(const char *s,size_type pos=0)const;//                                子字符串s，
		size_type find(const char *s,size_type pos=0,sizetype n);//查找s的前n个字符组成的字符串
		size_type find(char ch,type_size pos=0)const;//查找字符ch
	find()函数的拓展：
		rfind():查找最后一次出现的位置
		find_first_of():查找参数中任何一个字符首次出现的位置
		find_last_of():查找参数中任何一个字符最后一次出现的位置
		find_first_not_of():查找参数中第一个不包含参数中的字符首次出现的位置
4、自动调整大小
	在定义时会预分配一个内存大小（15），当字符串不断增大时，程序将分配一个大小
	为原来两倍的新内存块，以提供足够大的空间。
	capcity()返回当前分配给字符串的内存块的大小
	reserve()方法能够请求内存块的最小长度。
如果想要用c风格字符串作为参数，而只有string对象时，可以调用c_str()返回一个c风格字符串。
5、字符串种类
	一般默认string基于char类型，事实上string库基于模版。
	template <class charT,class traits=char _traits<charT>,class Allocator=allocator<charT>>
	basic_string{……};
	模版basic_string有4个实例化，每个实例化具有一个typedef名称：
		typedef basic_string<char> string;	
		typedef basic_string<wchar_t> string;
		typedef basic_string<char16_t> string;//c++11
		typedef basic_string<char32_t> string;//c++11
	traits类描述关于选定字符类型的特定情况，如如何对值比较。
	Allocator类是一个管理内存分配的类。对于各种字符类型，都有预定义的allocator模版具体化，使用new和delete。
6、智能指针模版类
	auto_ptr,shared_ptr,unique_ptr
	对于普通的指针变量，如果使用new申请 了内存，必须显式使用delete来释放，如果在定义异常时会跳过delete，也会导致
	内存泄漏，因此考虑参考类的析构函数，希望在指针变量过期时，自动释放内存。
	头文件：
	# include<memory>
	创建指针模版类实例，分配内存：
	auto_ptr<double> pd(new double);
	所有智能指针类都有一个explicit构造函数，该构造函数将指针作为参数 (double *p=new double;)
注意：不能在参数列表中使用&。
为什么要定义三种智能指针？
多个指针指向同一个内存，这是不允许的，因为变量过期时会释放多次内存
	1、定义赋值运算符，深度复制，建立副本
	2、建立所有权概念，只能有一个智能指针可以拥有它，让赋值操作转让所有权(operator=),转让的指针指向空地址会报错，auto_ptr和unique_ptr(更严格)
	3、创建智能更高的指针，跟踪引用特定对象的智能指针，即引用计数。shared_ptr
unique_ptr不允许在程序中使用非临时智能指针变量的所有权转移（赋值），但运行临时智能指针变量的赋值（函数返回值为智能指针，模版实例化函数等）
这避免了非临时智能指针变量所有权转移之后的悬挂问题。
shared_ptr和auto_ptr使用new分配内存，不能使用new[]
unique_ptr使用new和new[]
	选择智能指针：
	shared_ptr：多个指针指向同一个对象。
	unique_ptr:不是多个指针指向一个对象，且函数使用new并返回指向该内存的指针
*/
//************************标准模板库（STL）:泛型编程************************
/*
容器（同质）：存储值的类型相同
算法：完成特定任务(数组排序，链表查值)的处方
迭代器：用来遍历容器的对象，是广义指针。可以是指针，也可以是一个可执行类似指针操作的对象（解除引用，递增等等）
函数对象：类似于函数的对象，可以是类对象或函数指针。
*/
/*
模版类：vector
1、对应数组，区别于数组 
	定义： int array[n];
	vector<int> a(n);
	vector<int> b;
	访问： array[i];a[i]
	分配存储空间，自定义方法

2、头文件：
# include <vector>
template <class T,class Allocator=allocator<T>>
class vector{……};
3、可对矢量执行的操作
	size():返回容器中元素的数目；
	swap():交换两个容器的内容；
	begin():返回指向容器中第一个元素的迭代器
	end():返回一个表示超过容器尾的迭代器。
	声明迭代器:
		vector<double> ::iterator pd;
	push_back():将元素添加到矢量末尾；
	erase():删除矢量中给定区间的元素，参数为迭代器；
	insert():将另一容器指定区间元素插入指定区间
		old_v.insert(old_v.begin(),new_v.begin()+1,new_v.end());
4、对矢量可执行的其他操作（STL函数）
	for_each(iterator1,iterator2,*fun):将被指向的函数应用于容器区间中的各个元素，不可修改容器元素的值
	random_shuffle(iterator1,iterator2):随机排列两个区间的元素
	sort(iterator1,iterator2，*fun):排序，如果元素是用户自定义对象，需要重载<()
*/
/*
基于范围的for循环：
double prices[5]={4.499,10.399,45.872,45.345,78.987};
for(double x:prices)
cout<<x<<endl;
基于容器：
for (auto x : books)ShowReview1(x);
不同于for_each(),基于范围的for循环可以修改容器的内容。
诀窍是指定一个引用参数：
void InflatReview(Review &r){r.rating++;}
for(auto &x:books)InflateReview(x);
*/
//**************************泛型编程**********
//迭代器
/*
模板使算法独立于存储的数据类型，而迭代器使算法独立于使用的容器类型。
vector<double>class:
vector<double>::iterator pr;
//声明vector<double>类的迭代器
1、迭代器类型
	输入迭代器（只读）：输入是相对于程序的角度说的，来自容器的信息被视为输入：单向，可递增，读值
	输出迭代器（只写）：将信息从程序传给容器
	正向迭代器（读写）：支持++，多次通行算法，拥有输入输出迭代器所有特性。固定可重复排序
	双向迭代器（读写）：支持前缀和后缀，拥有正向迭代器所有特性。a++,a--;
	随机访问迭代器（读写）：支持随机操作，拥有双向迭代器所有特性。a[],a--,a+n;
2、迭代器层次结构
	迭代器的类型是一种概念性描述
3、概念，改进，模型
	概念可以具有类似继承的关系，但不是类的派生，是一种改进。
	概念的具体实现被称为模型。
	(1)指针是迭代器
	sort(s.begin(),s.end());
	sort(ARRY,ARRY+SIZE);
	//使istream输入用作迭代器接口
	//ostream_iterator也有两个模版参数，第一个参数为要读取的数据类型，第二个参数指出输入流使用的字符类型。
	第二个参数可以是C-Sty1e字符串，也可以是字符串常量。它用来表示各个元素被输出时的分隔符，默认情形下输出的各个元素并无任何分隔符
	copy(dice.begin(),dice.end(),ostream_iterator<int,char>(cout,""));
	copy(istream_iterator<int,char>(cin),istream_iterator<int,char>(),dice.begin());
	(2)其他有用的迭代器类型
		reverse_iterator:反向迭代器，执行递增操作会导致它被递减
			vector类有一个名为rbegin()的成员函数和rend()的成员函数，前者返回指向超尾的反向迭代器，后者返回指向第一个元素的反向迭代器
			rend()和begin()返回相同的值，但类型不同。
			copy(c.rbegin(),c.rend(),out_iter);
			若rp指向6，则*rp是5的位置
		back_insert_iterator:用于允许在尾部快速插入的容器，vector满足
			back_insert_iterator<vector<int>> back_iter (dice);
		front_insert_iterator:用于在起始位置做时间固定的插入的容器，queue满足，vector不满足	
		insert_iterator：没有限制的任意位置插入元素
			insert_iterator<vector<int>> insert_iter(dice,dice.begin());
*/
//容器
/*
1、种类
deque,list,queue,priority_queue,stack,vector,map,multimap,set,multiset,bitset,
forward_list,unordered_map,unordered_multimap,unordered_set,unordered_multiset
2、概念
容器是存储其他对象的对象。被存储的对象必须是同一种类型的，它们可以是OOP意义上的对象，也可以是内置数据类型
不能将任何类型的对象存储在在容器中，具体地说，类型必须是可以复制构造和可赋值的。
3、复杂度
从快到慢依次为：编译时间，固定时间，线性时间
	编译时间：操作在编译时执行，执行时间为0；
	固定复杂度意味着操作在发生运行阶段，但独立于对象中元素的数目
	线性复杂度意味着时间与元素数目成正比。
4、序列
要求其元素按严格的线性顺序排列。
数组和链表都是系列，但分支结构不是。
5、类型
一般容器/非关联容器
	(1)vector
	头文件：<vector>
	是数组的一种类表示，提供了自动内存管理功能，可以动态改变vector对象的长度
	提供了对元素的随机访问，在尾部添加和删除元素的时间是固定的，但在头部或中间插入和删除元素的复杂度为线性时间
	除序列外，vector还是可反转容器(reversible container)概念的模型，这增加了两个类方法：rbegin(),rend().
	vector是最简单的序列类型。
	(2)list
	头文件：<list>
	list模版类表示双向链表，可以双向遍历链表。
	在链表中任意位置插入和删除的时间都是固定的。
	除序列和可反转容器的函数外，链表还具有以下成员函数：
		void merge(list<T,Alloc>,&x):将链表x与调用链表合并,线性时间
		void remove(const T&val):删除val元素，线性时间
		void sort()：排序,N个元素为NlogN
		void splice(iterator pos,list<T ,Alloc>x):将x链表插入pos前面，固定时间,将原始区间移到目标地址，合并后，被合并列表为空，insert是插入副本
		void unique():将连续相同的元素压缩为单个元素，线性时间。
		remove_if():访问区间所有元素，接收一个bool参数，如果为true则删除元素
	(3)forward_list
	单链表，每个节点都只链接到下一个节点，而没有链接到前一个节点，因此只需要正向迭代器。
	不同于vector和list，forward_list是不可反转的容器。
	(4)queue
	头文件<queue>适配器类
	不允许随机访问元素，不允许遍历元素，可以将元素添加到队尾，从队首删除，查看元素的值，可以在队首队尾检查元素数目以及测试队列是否为空。
	方法：
		bool empty()const;
		size_type size()const;返回元素数目
		T & front();返回指向队首元素的引用
		T & back();返回指向队尾元素的引用
		void push(const T & x);在队尾插入x
		void pop();删除队首元素
	(5)priority_queue
	头文件<queue>适配器类
	与queue不同的是，最大的元素被移到队首，内部区别在于，默认的底层类是vector.
	可以修改用于确定哪个元素放到队首的方法，提供在一个可选的构造函数参数：
		priority_queue<int> pq2(greater<int>);//use greater<int>to order
	(6)stack
	头文件<stack>适配器类
	不允许随机访问栈元素，不允许遍历栈。只允许栈顶访问，方法：
		bool empty()const;
		size_type size()const;返回栈中元素数目
		T & top();返回指向栈顶元素的引用
		void push(const T & x);在栈顶插入x
		void pop();删除栈顶元素
	(7)array
	头文件<array>并非STL容器
	长度固定，无调整容器大小的操作。方法：
	operator[]()，at()
	STL方法：copy()for_each().
关联容器：键值对
	可以插入新元素，但不能指定位置，使用某种树来实现
	(8)set
	可反转，可排序，键是唯一的。
	set<string> A;
	set<string,less<string>> A;//第二个参数是可选的，可用来指示对键进行排序的比较函数或对象。
	集合取并操作：
	set_union(A.begin(),A.end(),B.begin(),B.end(),ostream_iterator<string,char>out(cout," "));
	set_union(A.begin(),A.end(),B.begin(),B.end(),insert_iterator<set<string>>(C,C.begin()));
	set_intersection():交集
	set_differece():差集
	lower_bound():将键作为参数返回一个迭代器，该迭代器指向集合中第一个不小于键参数的成员。
	upper_bound():将键作为参数返回一个迭代器，该迭代器指向集合中第一个不大于键参数的成员。
	(9)multimap
	可反转，经过排序的容器，但是键和值的类型不同，同一个键可能与多个值关联
	multimap<int,string> codes;//键的类型为int,值的类型为string
	为了将信息结合在一起，实际的值类型将键类型和数据类型结合为一对，在STL中使用模版类
	pair<class T,class U>将两种值存储到一个对象中。
	pair<const int,string>item (213,"Los Angeles");
	codes.insert(item);
	或
	codes.insert(pair<const int,string>item (213,"Los Angeles"));
	获取multimap的信息(成员函数)：
	count()接收键作为参数，返回具有该键的元素数目
	lower_bound(),upper_bound()，确定上下限
	equal_range()用键作为参数，且返回两个迭代器，它们表示的区间与该键匹配，将两个迭代器封装在一个pair对象中。
	pair<multimap<KeyType,string>::iterator,multimap<KeyType,string>::iterator> range=codes.equal_range(718);
	range.first,range.second可以访问两个迭代器；
无序关联容器：
	unordered_set,unordered_multimap,unordered_multiset,unodered_map
*/

//**********************函数对象(仿函数)****************
/*
函数符是可以以函数方式与( )结合使用的任意对象。这包括函数名，指向函数的指针，重载了( )的运算符的类对象
	生成器是不用参数就可以调用的函数符
	一元函数是用一个参数可以调用的函数符
	二元函数是用两个参数就可以调用的函数符
	返回bool值的一元函数是谓词
	返回bool值的二元函数是二元谓词
预定义的函数符
	支持将函数作为参数，以transform为例：
	版本一：
	transform(a.begin(),a.end(),out,sqrt);//计算容器中每个元素的平方根
	版本二：
	double add(double x,double y){return x+y;};
	……
	transform(a.begin(),a.end(),b.begin(),out,add);//a容器与b容器相加，需要为不同容器定义函数，所以创建模版

	# include <functional>
	plus<double>add;
	double y=add(2.2,3.4);
自适应函数符和函数适配器：
	函数符自适应的意义在于：函数适配器对象可以使用函数对象，并认为存在这些typedef成员
	multiplies()函数可以执行乘法操作，但它是二元函数，因此需要一个函数适配器，将接受2个参数的函数符转换
	为接受1个参数的函数符：
		binder1st(f2,val)f1;//f1()：单参数,将常数赋给f1()的第一个参数
		binder2nd(f2,val)f3;//将常数赋给f1()的第二个参数
*/
//*************************************算法***************************************
/*
对于算法函数设计，有两个主要的通用部分。
首先，用模版提供泛型，其次，使用迭代器访问容器中的数据通用表示。
1、算法组
	头文件：<algorithm>
	非修改式序列操作：不得修改容器内容，如:find(),for_each()
	修改式序列操作：可以修改容器内容和序列，transform(),random_shuffle(),copy()
	排序和相关操作:sort()和其他集合操作
	头文件:<numeric>
	通用数字运算：区间的内容操作，vector是最有可能使用这些操作的容器
2、算法的通用特征：使用迭代器和迭代器区间--------调用数组的函数
	就地版本：结果被存放在原始数据的位置上，sort()
	复制版本_copy：接受一个额外的输出迭代器参数，将结果发送到另一个位置，copy()
	_if版本：将函数应用与容器元素得到的结果来执行操作
有些算法有两个版本：
	template <class ForwadIterator,class T>
	void replace(ForwardIterator first,InputIterator last,
				const T&old_value,const T&new_value);
	所有的old_value替换为new_value,就地发生的。
	template <class InputIterator,class OutputIterator, class T >
	OutputIterator replace_copy(InputIterator first,InputIterator last
						OutputIterator result,
						const T&old_value,const T& new_value);
3、函数与容器方法
有时可以选用STL方法和STL函数，通常方法是更好的选择。首先，它适用于特定的容器，其次作为成员函数，它可以使用模版的
内存管理工具，从而在需要时调整容器的长度。
*/
/*
其他库：
vector模板类是一个容器类和算法系统的一部分，它支持面向容器的操作，如排序，插入排序，重新排序，搜索，转移数据等
valarray模板是面向数值计算的，为很多数学运算提供了一个简单、直观的接口
	valarray<bool>vbool=number>9;//创建数组，vbool[i]=number[i]>9
	valarray[slice(1,4,3)]=10;//slice对象作为索引表示一组，（开始索引，索引数目，跨距）
array为代替内置数组而设计的，让数组结构更紧凑，效率更高。
*/
/*
模板initializer_list:(c++11)
	头文件：<initializer_list>
	使用列表初始化语法将STL容器初始化为一系列值
	std::vector<double> payments{45.99,56.78,67.8,89.01};
	注意不能进行隐式的窄化转换
initializer_list的迭代器类型为const


*/