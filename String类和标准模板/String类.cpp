//************************string��***************
/*
1�������ַ���
	7�����캯����ctor��ʶ
	string(const char*);
	string(size_type n,char c);//n��c
	string(const string &str);//����
	string();
	string(const char*s,size_type n);
	string(const string &str,string size_type pos=0,size_typr=npos);//��ʼ��Ϊstr��pos��β����pos��ʼ��n���ַ�
	string(string &&str)noexcept;//�ƶ�
	string(initializer_list<char>il)
	template<class Iter>string(Iter begin,Iter end);
ע�⣺string�������ַ�����һ�������ַ������Ƕ�����������������һ������ַ��
2��string����
	(1)C���
		cin>>cstr;
		cin.getline(cstr,100);
		cin.get(cstr,100);
	(2)string����,�����Զ���Ӧ����
		cin>>str;
		getline(cin,str)
ע��getline����һ����ѡ������ָ���ַ�ȷ������߽�
getline(str,':');
cin.getline(cstr,100,':');
	cin.opertor>>(fname);
	operator>>(cin,fname);
��getline()����string����ĳ��ȣ�string::npos
	(1)�����ļ�β�������eofbit�������ã�fail()��eof()��������true.
	(2)�����ֽ��ַ�(Ĭ��\n)�����ֽ��ַ��ӳ�������ɾ���������洢��
	(3)��ȡ���ַ����ﵽ�������ֵ��string::nops�Ϳɷ����ڴ��ֽ����еĽ�Сֵ����������������failbit,fail()����true.
string�汾��operator>>()����������ƣ�ֻ�������϶�ȡ��ֱ�������հ��ַ����������ڶ����У�ֱ�������ֽ��ַ������䶪����
�հ��ַ�ָ�ո񣬻س����Ʊ��������isspace()��
3��ʹ���ַ���
	(1)���رȽ���������ӵ�һ����ĸ��ʼ���ջ����������У�ASCII:��<��д<Сд��
	(2)ȷ���ַ������ȣ������ַ����е��ַ�����size(),length().
	(3)�������ַ����ַ�����find()
		size_type find(const string &str,size_type pos=0)const;//���ַ�����posλ�ÿ�ʼ���������ַ���str�����У������״γ������������򣬷���string::npos.
		size_type find(const char *s,size_type pos=0)const;//                                ���ַ���s��
		size_type find(const char *s,size_type pos=0,sizetype n);//����s��ǰn���ַ���ɵ��ַ���
		size_type find(char ch,type_size pos=0)const;//�����ַ�ch
	find()��������չ��
		rfind():�������һ�γ��ֵ�λ��
		find_first_of():���Ҳ������κ�һ���ַ��״γ��ֵ�λ��
		find_last_of():���Ҳ������κ�һ���ַ����һ�γ��ֵ�λ��
		find_first_not_of():���Ҳ����е�һ�������������е��ַ��״γ��ֵ�λ��
4���Զ�������С
	�ڶ���ʱ��Ԥ����һ���ڴ��С��15�������ַ�����������ʱ�����򽫷���һ����С
	Ϊԭ�����������ڴ�飬���ṩ�㹻��Ŀռ䡣
	capcity()���ص�ǰ������ַ������ڴ��Ĵ�С
	reserve()�����ܹ������ڴ�����С���ȡ�
�����Ҫ��c����ַ�����Ϊ��������ֻ��string����ʱ�����Ե���c_str()����һ��c����ַ�����
5���ַ�������
	һ��Ĭ��string����char���ͣ���ʵ��string�����ģ�档
	template <class charT,class traits=char _traits<charT>,class Allocator=allocator<charT>>
	basic_string{����};
	ģ��basic_string��4��ʵ������ÿ��ʵ��������һ��typedef���ƣ�
		typedef basic_string<char> string;	
		typedef basic_string<wchar_t> string;
		typedef basic_string<char16_t> string;//c++11
		typedef basic_string<char32_t> string;//c++11
	traits����������ѡ���ַ����͵��ض����������ζ�ֵ�Ƚϡ�
	Allocator����һ�������ڴ������ࡣ���ڸ����ַ����ͣ�����Ԥ�����allocatorģ����廯��ʹ��new��delete��
6������ָ��ģ����
	auto_ptr,shared_ptr,unique_ptr
	������ͨ��ָ����������ʹ��new���� ���ڴ棬������ʽʹ��delete���ͷţ�����ڶ����쳣ʱ������delete��Ҳ�ᵼ��
	�ڴ�й©����˿��ǲο��������������ϣ����ָ���������ʱ���Զ��ͷ��ڴ档
	ͷ�ļ���
	# include<memory>
	����ָ��ģ����ʵ���������ڴ棺
	auto_ptr<double> pd(new double);
	��������ָ���඼��һ��explicit���캯�����ù��캯����ָ����Ϊ���� (double *p=new double;)
ע�⣺�����ڲ����б���ʹ��&��
ΪʲôҪ������������ָ�룿
���ָ��ָ��ͬһ���ڴ棬���ǲ�����ģ���Ϊ��������ʱ���ͷŶ���ڴ�
	1�����帳ֵ���������ȸ��ƣ���������
	2����������Ȩ���ֻ����һ������ָ�����ӵ�������ø�ֵ����ת������Ȩ(operator=),ת�õ�ָ��ָ��յ�ַ�ᱨ��auto_ptr��unique_ptr(���ϸ�)
	3���������ܸ��ߵ�ָ�룬���������ض����������ָ�룬�����ü�����shared_ptr
unique_ptr�������ڳ�����ʹ�÷���ʱ����ָ�����������Ȩת�ƣ���ֵ������������ʱ����ָ������ĸ�ֵ����������ֵΪ����ָ�룬ģ��ʵ���������ȣ�
������˷���ʱ����ָ���������Ȩת��֮����������⡣
shared_ptr��auto_ptrʹ��new�����ڴ棬����ʹ��new[]
unique_ptrʹ��new��new[]
	ѡ������ָ�룺
	shared_ptr�����ָ��ָ��ͬһ������
	unique_ptr:���Ƕ��ָ��ָ��һ�������Һ���ʹ��new������ָ����ڴ��ָ��
*/
//************************��׼ģ��⣨STL��:���ͱ��************************
/*
������ͬ�ʣ����洢ֵ��������ͬ
�㷨������ض�����(�������������ֵ)�Ĵ���
���������������������Ķ����ǹ���ָ�롣������ָ�룬Ҳ������һ����ִ������ָ������Ķ��󣨽�����ã������ȵȣ�
�������������ں����Ķ��󣬿�������������ָ�롣
*/
/*
ģ���ࣺvector
1����Ӧ���飬���������� 
	���壺 int array[n];
	vector<int> a(n);
	vector<int> b;
	���ʣ� array[i];a[i]
	����洢�ռ䣬�Զ��巽��

2��ͷ�ļ���
# include <vector>
template <class T,class Allocator=allocator<T>>
class vector{����};
3���ɶ�ʸ��ִ�еĲ���
	size():����������Ԫ�ص���Ŀ��
	swap():�����������������ݣ�
	begin():����ָ�������е�һ��Ԫ�صĵ�����
	end():����һ����ʾ��������β�ĵ�������
	����������:
		vector<double> ::iterator pd;
	push_back():��Ԫ����ӵ�ʸ��ĩβ��
	erase():ɾ��ʸ���и��������Ԫ�أ�����Ϊ��������
	insert():����һ����ָ������Ԫ�ز���ָ������
		old_v.insert(old_v.begin(),new_v.begin()+1,new_v.end());
4����ʸ����ִ�е�����������STL������
	for_each(iterator1,iterator2,*fun):����ָ��ĺ���Ӧ�������������еĸ���Ԫ�أ������޸�����Ԫ�ص�ֵ
	random_shuffle(iterator1,iterator2):����������������Ԫ��
	sort(iterator1,iterator2��*fun):�������Ԫ�����û��Զ��������Ҫ����<()
*/
/*
���ڷ�Χ��forѭ����
double prices[5]={4.499,10.399,45.872,45.345,78.987};
for(double x:prices)
cout<<x<<endl;
����������
for (auto x : books)ShowReview1(x);
��ͬ��for_each(),���ڷ�Χ��forѭ�������޸����������ݡ�
������ָ��һ�����ò�����
void InflatReview(Review &r){r.rating++;}
for(auto &x:books)InflateReview(x);
*/
//**************************���ͱ��**********
//������
/*
ģ��ʹ�㷨�����ڴ洢���������ͣ���������ʹ�㷨������ʹ�õ��������͡�
vector<double>class:
vector<double>::iterator pr;
//����vector<double>��ĵ�����
1������������
	�����������ֻ����������������ڳ���ĽǶ�˵�ģ�������������Ϣ����Ϊ���룺���򣬿ɵ�������ֵ
	�����������ֻд��������Ϣ�ӳ��򴫸�����
	�������������д����֧��++�����ͨ���㷨��ӵ����������������������ԡ��̶����ظ�����
	˫�����������д����֧��ǰ׺�ͺ�׺��ӵ������������������ԡ�a++,a--;
	������ʵ���������д����֧�����������ӵ��˫��������������ԡ�a[],a--,a+n;
2����������νṹ
	��������������һ�ָ���������
3������Ľ���ģ��
	������Ծ������Ƽ̳еĹ�ϵ�������������������һ�ָĽ���
	����ľ���ʵ�ֱ���Ϊģ�͡�
	(1)ָ���ǵ�����
	sort(s.begin(),s.end());
	sort(ARRY,ARRY+SIZE);
	//ʹistream���������������ӿ�
	//ostream_iteratorҲ������ģ���������һ������ΪҪ��ȡ���������ͣ��ڶ�������ָ��������ʹ�õ��ַ����͡�
	�ڶ�������������C-Sty1e�ַ�����Ҳ�������ַ�����������������ʾ����Ԫ�ر����ʱ�ķָ�����Ĭ������������ĸ���Ԫ�ز����κηָ���
	copy(dice.begin(),dice.end(),ostream_iterator<int,char>(cout,""));
	copy(istream_iterator<int,char>(cin),istream_iterator<int,char>(),dice.begin());
	(2)�������õĵ���������
		reverse_iterator:�����������ִ�е��������ᵼ�������ݼ�
			vector����һ����Ϊrbegin()�ĳ�Ա������rend()�ĳ�Ա������ǰ�߷���ָ��β�ķ�������������߷���ָ���һ��Ԫ�صķ��������
			rend()��begin()������ͬ��ֵ�������Ͳ�ͬ��
			copy(c.rbegin(),c.rend(),out_iter);
			��rpָ��6����*rp��5��λ��
		back_insert_iterator:����������β�����ٲ����������vector����
			back_insert_iterator<vector<int>> back_iter (dice);
		front_insert_iterator:��������ʼλ����ʱ��̶��Ĳ����������queue���㣬vector������	
		insert_iterator��û�����Ƶ�����λ�ò���Ԫ��
			insert_iterator<vector<int>> insert_iter(dice,dice.begin());
*/
//����
/*
1������
deque,list,queue,priority_queue,stack,vector,map,multimap,set,multiset,bitset,
forward_list,unordered_map,unordered_multimap,unordered_set,unordered_multiset
2������
�����Ǵ洢��������Ķ��󡣱��洢�Ķ��������ͬһ�����͵ģ����ǿ�����OOP�����ϵĶ���Ҳ������������������
���ܽ��κ����͵Ķ���洢���������У������˵�����ͱ����ǿ��Ը��ƹ���Ϳɸ�ֵ�ġ�
3�����Ӷ�
�ӿ쵽������Ϊ������ʱ�䣬�̶�ʱ�䣬����ʱ��
	����ʱ�䣺�����ڱ���ʱִ�У�ִ��ʱ��Ϊ0��
	�̶����Ӷ���ζ�Ų����ڷ������н׶Σ��������ڶ�����Ԫ�ص���Ŀ
	���Ը��Ӷ���ζ��ʱ����Ԫ����Ŀ�����ȡ�
4������
Ҫ����Ԫ�ذ��ϸ������˳�����С�
�����������ϵ�У�����֧�ṹ���ǡ�
5������
һ������/�ǹ�������
	(1)vector
	ͷ�ļ���<vector>
	�������һ�����ʾ���ṩ���Զ��ڴ�����ܣ����Զ�̬�ı�vector����ĳ���
	�ṩ�˶�Ԫ�ص�������ʣ���β����Ӻ�ɾ��Ԫ�ص�ʱ���ǹ̶��ģ�����ͷ�����м�����ɾ��Ԫ�صĸ��Ӷ�Ϊ����ʱ��
	�������⣬vector���ǿɷ�ת����(reversible container)�����ģ�ͣ��������������෽����rbegin(),rend().
	vector����򵥵��������͡�
	(2)list
	ͷ�ļ���<list>
	listģ�����ʾ˫����������˫���������
	������������λ�ò����ɾ����ʱ�䶼�ǹ̶��ġ�
	�����кͿɷ�ת�����ĺ����⣬�����������³�Ա������
		void merge(list<T,Alloc>,&x):������x���������ϲ�,����ʱ��
		void remove(const T&val):ɾ��valԪ�أ�����ʱ��
		void sort()������,N��Ԫ��ΪNlogN
		void splice(iterator pos,list<T ,Alloc>x):��x�������posǰ�棬�̶�ʱ��,��ԭʼ�����Ƶ�Ŀ���ַ���ϲ��󣬱��ϲ��б�Ϊ�գ�insert�ǲ��븱��
		void unique():��������ͬ��Ԫ��ѹ��Ϊ����Ԫ�أ�����ʱ�䡣
		remove_if():������������Ԫ�أ�����һ��bool���������Ϊtrue��ɾ��Ԫ��
	(3)forward_list
	������ÿ���ڵ㶼ֻ���ӵ���һ���ڵ㣬��û�����ӵ�ǰһ���ڵ㣬���ֻ��Ҫ�����������
	��ͬ��vector��list��forward_list�ǲ��ɷ�ת��������
	(4)queue
	ͷ�ļ�<queue>��������
	�������������Ԫ�أ����������Ԫ�أ����Խ�Ԫ����ӵ���β���Ӷ���ɾ�����鿴Ԫ�ص�ֵ�������ڶ��׶�β���Ԫ����Ŀ�Լ����Զ����Ƿ�Ϊ�ա�
	������
		bool empty()const;
		size_type size()const;����Ԫ����Ŀ
		T & front();����ָ�����Ԫ�ص�����
		T & back();����ָ���βԪ�ص�����
		void push(const T & x);�ڶ�β����x
		void pop();ɾ������Ԫ��
	(5)priority_queue
	ͷ�ļ�<queue>��������
	��queue��ͬ���ǣ�����Ԫ�ر��Ƶ����ף��ڲ��������ڣ�Ĭ�ϵĵײ�����vector.
	�����޸�����ȷ���ĸ�Ԫ�طŵ����׵ķ������ṩ��һ����ѡ�Ĺ��캯��������
		priority_queue<int> pq2(greater<int>);//use greater<int>to order
	(6)stack
	ͷ�ļ�<stack>��������
	�������������ջԪ�أ����������ջ��ֻ����ջ�����ʣ�������
		bool empty()const;
		size_type size()const;����ջ��Ԫ����Ŀ
		T & top();����ָ��ջ��Ԫ�ص�����
		void push(const T & x);��ջ������x
		void pop();ɾ��ջ��Ԫ��
	(7)array
	ͷ�ļ�<array>����STL����
	���ȹ̶����޵���������С�Ĳ�����������
	operator[]()��at()
	STL������copy()for_each().
������������ֵ��
	���Բ�����Ԫ�أ�������ָ��λ�ã�ʹ��ĳ������ʵ��
	(8)set
	�ɷ�ת�������򣬼���Ψһ�ġ�
	set<string> A;
	set<string,less<string>> A;//�ڶ��������ǿ�ѡ�ģ�������ָʾ�Լ���������ıȽϺ��������
	����ȡ��������
	set_union(A.begin(),A.end(),B.begin(),B.end(),ostream_iterator<string,char>out(cout," "));
	set_union(A.begin(),A.end(),B.begin(),B.end(),insert_iterator<set<string>>(C,C.begin()));
	set_intersection():����
	set_differece():�
	lower_bound():������Ϊ��������һ�����������õ�����ָ�򼯺��е�һ����С�ڼ������ĳ�Ա��
	upper_bound():������Ϊ��������һ�����������õ�����ָ�򼯺��е�һ�������ڼ������ĳ�Ա��
	(9)multimap
	�ɷ�ת��������������������Ǽ���ֵ�����Ͳ�ͬ��ͬһ������������ֵ����
	multimap<int,string> codes;//��������Ϊint,ֵ������Ϊstring
	Ϊ�˽���Ϣ�����һ��ʵ�ʵ�ֵ���ͽ������ͺ��������ͽ��Ϊһ�ԣ���STL��ʹ��ģ����
	pair<class T,class U>������ֵ�洢��һ�������С�
	pair<const int,string>item (213,"Los Angeles");
	codes.insert(item);
	��
	codes.insert(pair<const int,string>item (213,"Los Angeles"));
	��ȡmultimap����Ϣ(��Ա����)��
	count()���ռ���Ϊ���������ؾ��иü���Ԫ����Ŀ
	lower_bound(),upper_bound()��ȷ��������
	equal_range()�ü���Ϊ�������ҷ������������������Ǳ�ʾ��������ü�ƥ�䣬��������������װ��һ��pair�����С�
	pair<multimap<KeyType,string>::iterator,multimap<KeyType,string>::iterator> range=codes.equal_range(718);
	range.first,range.second���Է���������������
�������������
	unordered_set,unordered_multimap,unordered_multiset,unodered_map
*/

//**********************��������(�º���)****************
/*
�������ǿ����Ժ�����ʽ��( )���ʹ�õ���������������������ָ������ָ�룬������( )��������������
	�������ǲ��ò����Ϳ��Ե��õĺ�����
	һԪ��������һ���������Ե��õĺ�����
	��Ԫ�����������������Ϳ��Ե��õĺ�����
	����boolֵ��һԪ������ν��
	����boolֵ�Ķ�Ԫ�����Ƕ�Ԫν��
Ԥ����ĺ�����
	֧�ֽ�������Ϊ��������transformΪ����
	�汾һ��
	transform(a.begin(),a.end(),out,sqrt);//����������ÿ��Ԫ�ص�ƽ����
	�汾����
	double add(double x,double y){return x+y;};
	����
	transform(a.begin(),a.end(),b.begin(),out,add);//a������b������ӣ���ҪΪ��ͬ�������庯�������Դ���ģ��

	# include <functional>
	plus<double>add;
	double y=add(2.2,3.4);
����Ӧ�������ͺ�����������
	����������Ӧ���������ڣ������������������ʹ�ú������󣬲���Ϊ������Щtypedef��Ա
	multiplies()��������ִ�г˷������������Ƕ�Ԫ�����������Ҫһ��������������������2�������ĺ�����ת��
	Ϊ����1�������ĺ�������
		binder1st(f2,val)f1;//f1()��������,����������f1()�ĵ�һ������
		binder2nd(f2,val)f3;//����������f1()�ĵڶ�������
*/
//*************************************�㷨***************************************
/*
�����㷨������ƣ���������Ҫ��ͨ�ò��֡�
���ȣ���ģ���ṩ���ͣ���Σ�ʹ�õ��������������е�����ͨ�ñ�ʾ��
1���㷨��
	ͷ�ļ���<algorithm>
	���޸�ʽ���в����������޸��������ݣ���:find(),for_each()
	�޸�ʽ���в����������޸��������ݺ����У�transform(),random_shuffle(),copy()
	�������ز���:sort()���������ϲ���
	ͷ�ļ�:<numeric>
	ͨ���������㣺��������ݲ�����vector�����п���ʹ����Щ����������
2���㷨��ͨ��������ʹ�õ������͵���������--------��������ĺ���
	�͵ذ汾������������ԭʼ���ݵ�λ���ϣ�sort()
	���ư汾_copy������һ������������������������������͵���һ��λ�ã�copy()
	_if�汾��������Ӧ��������Ԫ�صõ��Ľ����ִ�в���
��Щ�㷨�������汾��
	template <class ForwadIterator,class T>
	void replace(ForwardIterator first,InputIterator last,
				const T&old_value,const T&new_value);
	���е�old_value�滻Ϊnew_value,�͵ط����ġ�
	template <class InputIterator,class OutputIterator, class T >
	OutputIterator replace_copy(InputIterator first,InputIterator last
						OutputIterator result,
						const T&old_value,const T& new_value);
3����������������
��ʱ����ѡ��STL������STL������ͨ�������Ǹ��õ�ѡ�����ȣ����������ض��������������Ϊ��Ա������������ʹ��ģ���
�ڴ�����ߣ��Ӷ�����Ҫʱ���������ĳ��ȡ�
*/
/*
�����⣺
vectorģ������һ����������㷨ϵͳ��һ���֣���֧�����������Ĳ����������򣬲���������������������ת�����ݵ�
valarrayģ����������ֵ����ģ�Ϊ�ܶ���ѧ�����ṩ��һ���򵥡�ֱ�۵Ľӿ�
	valarray<bool>vbool=number>9;//�������飬vbool[i]=number[i]>9
	valarray[slice(1,4,3)]=10;//slice������Ϊ������ʾһ�飬����ʼ������������Ŀ����ࣩ
arrayΪ���������������Ƶģ�������ṹ�����գ�Ч�ʸ��ߡ�
*/
/*
ģ��initializer_list:(c++11)
	ͷ�ļ���<initializer_list>
	ʹ���б��ʼ���﷨��STL������ʼ��Ϊһϵ��ֵ
	std::vector<double> payments{45.99,56.78,67.8,89.01};
	ע�ⲻ�ܽ�����ʽ��խ��ת��
initializer_list�ĵ���������Ϊconst


*/