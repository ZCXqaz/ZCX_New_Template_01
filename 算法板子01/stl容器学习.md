[TOC]

# string

### string.substr( )   求子串

```c++
    string s = "hello, world!";
    //从位置2开始，直到最后
    string s1 = s.substr(2);		//llo, world!
    //从位置2开始，len = 3
    string s2 = s.substr(2, 3);		//llo

```

### string.erase( )   删除对应字串

```c++
	string s = "hello,world!";
	string s1 = s.erase(6);	//删除下标为6开始的所有字符,  hello,
	s = "hello,world!";
	string s2 = s.erase(1, 2);	//删除下标为1开始的2个字符，即删除el 
	s = "hello,world!";
	string s3 = s.erase(s.find("ll"), 3);// he,world!

```



### string.insert()

```c++
int main(){
    string str = "012345";
    string s = "Hahah";
    str.insert(1, s);//在原串下标为1的字符前插入字符串s
    cout << str << endl;    //0Hahah12345
    
    string str = "012345";
    string s = "Hahah";
    if(str.find("12")!=str.npos){//在原串找不到“12”字串，不执行，否则会报错
    	str.insert(str.find("12"), s);//在原串找到“12”字串，在前插入字符串s
    }
    cout << str << endl;    //0Hahah12345

    string str1 = "012345";
    char c = 'w';
    str1.insert(4, 5, c);//在原串下标为4的字符前插入5个字符c
    cout << str1 << endl;   //0123wwwww45

    string str2 = "012345";
    string s2 = "weakhaha";
    str2.insert(0, s2, 1, 3);
    //将字符串s2从下标为1的e开始数3个字符，分别是eak，插入原串的下标为0的字符前
    cout << str2 << endl;   //eak012345
    
    return 0;
}
```

### string.replace()

```c++
int main(){
	string line = "this@ is@ a test string!";

	/*用法一： 
     *用str替换指定字符串从起始位置pos开始长度为len的字符 
     *string& replace (size_t pos, size_t len, const string& str); 
     */ 
	line.replace(line.find("@"), 1, ""); 	//从第一个@位置替换第一个@为空  
	cout << line << endl;   		//this is@ a test string!

    /*用法二： 
 	*用str替换 迭代器起始位置 和 结束位置 的字符 
*string& replace (const_iterator i1, const_iterator i2, const string& str); 
 	*/
    line.replace(line.begin(), line.begin() + 6, "");  
                //用str替换从begin位置开始的6个字符  
    cout << line << endl;   //is@ a test string!
    
    /*用法三： 
 	*用substr的指定子串（给定起始位置和长度）替换从指定位置上的字符串 
*string& replace (size_t pos, size_t len, const string& str, size_t subpos, size_t sublen); 
	*/
    string substr = "012345";
    line.replace(2, 5, substr, substr.find("1"), 3); 
            //用substr的指定子串（从1位置数共3个字符）替换从2位置len=5的line  
    cout << line << endl;       //th123s@ a test string!
    
    /*用法四：
     *用s的从开始位置pos2长度为len2的字符串替换从开始位置pos1长度为len1的字符串
     *string& replace(size_t pos1, size_t len1, const char* s, size_t pos2, size_t len2,);
     */
    string str = "12345";
    line.replace(0, 5, str, 1, 4);  //用str从1位置开始的4个字符替换从0位置开始长度为5的字符串  
    cout << line << endl;       //2345 is@ a test string!
    
    /*用法五：
     *用str替换从指定位置0开始长度为5的字符串
     *string& replace(size_t pos, size_t len, const char* s);
     */
    string str = "12345";
    line.replace(0, 5, str); //用str替换从指定位置0开始长度为5的字符串  
    cout << line << endl;       //12345 is@ a test string!
    
    /*用法六：
     *用str替换从指定迭代器位置的字符串
     *string& replace (const_iterator i1, const_iterator i2, const char* s);
     */
    string str = "12345";
    line.replace(line.begin(), line.begin() + 4, str); 
            //用str替换从指定迭代器位置的字符串  *区间左闭右开（因为line.end)*
    cout << line << endl;       //12345@ is@ a test string!
    
    /*用法七：
     *用重复n次的c字符替换从指定位置pos长度为len的内容
     *string& replace (size_t pos, size_t len, size_t n, char c);
     */
    char c = '1';
    line.replace(0, 5, 3, c); //用重复3次的c字符替换从指定位置0长度为5的内容 
    cout << line << endl;       //111 is@ a test string!
    
    /*用法八：
    *用重复n次的c字符替换从指定迭代器位置（从i1开始到结束）的内容
    *string& replace (const_iterator i1, const_iterator i2, size_t n, char c);
    */
    char c = '1';
    line = line.replace(line.begin(), line.begin() + 5, 3, c);   
    					//用重复3次的c字符替换从指定迭代器位置的内容  
    cout << line << endl;   //111 is@ a test string!
}
```

### string s = to_string( )    (int,double,ll  转字符串)

```c++
    int n = 123456;
    string s1 = to_string(n);
    cout << s1 << endl;     //123456

    //double 默认保留6位小数，不够的用 0 补齐
    string s2 = to_string(123.456);
    cout << s2 << endl;     //123.456000

```

### 字符串转 int / double

```c++
    string s = "123456";
    int n = stoi(s);    //123456

    string s1 = "123.456";
    double n1 = stod(s1);//123.456

```



# bitset

### 1、初始化

```c++
    bitset<4>a1;        //长度为4，默认以0填充
    bitset<8>a2(12);        //长度为8，将12以二进制保存，前面用0补充

    string s = "100101";
    bitset<10>a3(s);    //长度为10，前面用０补充

    cout << a1 << endl;//0000
    cout << a2 << endl;//00001100
    cout << a3 << endl;//0000100101

```

```c++
//位数不足时，截取的位置不同
	bitset<3>b1(12);//12的二进制为1100（长度为４），但b1的size=3，只取后面部分，即100

    string s = "100101";
    bitset<4> b2(s);		//s的size=6，而b2的size=4，只取前面部分，即1001

    cout << b1 << endl;    //100
    cout << b2 << endl;    //1001
```

### 2、位运算操作

```c++
    bitset<4> a(string("1001"));//这种赋值方式就可以直接用，没有限制
    bitset<4> b(string("0011"));
    cout << (a ^= b) << endl;   // 1010   (a对b按位异或后赋值给a)
    cout << (a &= b) << endl;   // 0010   (按位与后赋值给a)
    cout << (a |= b) << endl;   // 0011   (按位或后赋值给a)
    cout << (a <<= 2) << endl;  // 1100   (左移２位，低位补０，有自身赋值)
    cout << (a >>= 1) << endl;  // 0110   (右移１位，高位补０，有自身赋值)
    cout << (~b) << endl;       // 1100   (按位取反) 
    cout << (b >> 1) << endl;   // 0001   (右移，不赋值)
    cout << (a == b) << endl;   // （0）  false (0110==0011为false)
    cout << (a != b) << endl;   // （1）  true  (0110!=0011为true)
    cout << (a & b) << endl;    // 0010   (按位与，不赋值)
    cout << (a | b) << endl;    // 0111   (按位或，不赋值)
    cout << (a ^ b) << endl;	// 0101   (按位异或，不赋值)
```

### 3、单一元素访问和修改

```c++
    //bitset<4>a1("1011");//这个赋值方法只能在c++11里用，noip八行
    bitset<4>a1(string("1011"));

    cout << a1[0] << endl;	//1
    cout << a1[1] << endl;	//1
    cout << a1[2] << endl;	//0
    cout << a1[3] << endl;	//1
    //注意！这两种赋值方式都是反序赋值的，所以输出值为1101；
    //但可以直接输出a1来输出正序

    //bitset支持单点修改
    a1[0] = 0;
    cout << a1[0] << endl;	//0
    cout << a1 << endl;		//1010

```

### 4、花里胡哨的函数

```c++
// 取反、置1、置0
	bitset<8> foo("10011011");

    cout << foo.flip(2) << endl;//10011111　　
//（flip函数传参数时，用于将参数位取反，本行代码将foo下标２处"反转"，即０变１，１变０
    cout << foo.flip() << endl;//01100000　　
//（flip函数不指定参数时，将bitset每一位全部取反

    cout << foo.set() << endl;//11111111　　
//（set函数不指定参数时，将bitset的每一位全部置为１
    cout << foo.set(3, 0) << endl;//11110111　　
//（set函数指定两位参数时，将第一参数位的元素置为第二参数的值，本行相当于foo[3]=0
    cout << foo.set(3) << endl;//11111111　　
//（set函数只有一个参数时，将参数下标处置为１

    cout << foo.reset(4) << endl;//11101111　　
//（reset函数传一个参数时将参数下标处置为０
    cout << foo.reset() << endl;//00000000　　
//（reset函数不传参数时将bitset的每一位全部置为０

```

```c++
    bitset<8>a(string("10011011"));

    cout << a.count() << endl;//5　（count函数：求bitset中1的个数，foo中共有５个１
    cout << a.size() << endl; //8　（size函数：求bitset的大小，一共有８位

    cout << a.test(0) << endl;//1　（test函数：查询下标处的元素是０还是１
    cout << a.test(2) << endl;//0　（同理，foo[2]为０，返回 0

    cout << a.any() << endl;  //1　（any函数：检查bitset中是否有１
    cout << a.none() << endl; //0　（none函数：检查bitset中是否没有１
    cout << a.all() << endl;  //0　（all函数：检查bitset中是全部为１

```

```c++
//再从bitset转化回来
	bitset<8> foo("10011011");

    string s = foo.to_string();//将bitset转换成string类型
    unsigned long a = foo.to_ulong();//将bitset转换成unsigned long类型
    unsigned long long b = foo.to_ullong();//将bitset转换成unsigned long long类型
    //不能转化为有符号数，因为不确定符号位
    cout << s << endl;//10011011
    cout << a << endl;//155
    cout << b << endl;//155

```

```c++
    string s = "ababababab";

    //从字符串的子串构造bitset。使用第1个字符开始的5位。将'a'转换0，将'b'转换为1。
    bitset<7>b(s, 1, 5, 'a', 'b'); 	//不足位数补0
    cout << b << endl;  	//0010101

```


