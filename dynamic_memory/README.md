主要学习C++ Primer中的第12章：动态内存

# 动态内存提出的原因
所有编写的程序均有严格的生存期。
- 全局对象在程序启动时自动分配，在程序结束时销毁。
- 局部对象在我们进入其定义的程序块时被创建，在离开块时销毁。
- 局部static对象在第一次使用前分配，在程序结束时销毁。

除了自动和static对象外，C++还支持动态分配对象。动态分配的对象的身存其与它们在哪里创建无关，
只有当显示的被释放时，对象才会被销毁。但动态对象的释放是极其容易出错的地方。因此，为了更安全的
使用动态对象，标准库中定义了两个智能指针类型来管理动态分配的的对象。当动态对象应当被释放时，
指向他的智能指针可以确保自动释放他。

# 静态内存、栈内存和堆
- 静态内存：保存局部static对象、类static数据成员以及定义在任何函数之外的变量。
- 栈内存：保存定义在函数内的非static对象。栈中的对象只有定义的程序块在运行时存在。
- 堆内存：存储动态分配的对象。在堆上分配的内存是无名的，因此new无法为其分配的对象命名，而是
  返回一个指向该对象的指针。默认情况下，动态分配的对象时默认初始化的，这意味着内置类型或组合
  类型的对象的值是未定义的，而类类型对象将使用默认构造函数进行初始化。

``` cpp 
int *pi = new int; // pi指向一个动态分配的、未初始化的无名对象。

// 直接初始化方式来初始化一个动态分配的对象
string *ps = new string(10, '9');
vector<int> *ps = new vector<int>{0,1,2,3};

// 使用auto从初始化器来推断想分配的对象的类型
auto p1 = new auto(obj); // 正确
auto p2 = new auto{a, b, c} //错误：括号中只能有单个初始化器

// 释放动态内存
delete p; // p必须指向一个动态分配的对象或是一个空指针
```

# 动态内存与共享指针
动态内存管理的运算符： `new`  &  `delete`
- new：在动态内存（堆）中为对象分配空间并返回一个指向该对象的指针。
- delete：接受一个动态对象的指针，销毁该对象，并释放与之相关联的内存。

# 动态内存容易产生的问题：内存泄漏与悬空指针
- 内存泄漏：忘记释放动态内存
- 空悬指针：有指针引用内存的情况下释放，是指向一块曾经保存数据对象但现在已经无效的内存的指针

所以要使用智能指针，可以避免上述问题，对于一块动态内存，只要在没有任何智能指针指向它的情况下，
智能指针彩绘自动释放它

# 两种智能指针(smart pointer)
- shared_ptr：允许多个指针指向同一对象；
- unique_ptr：独占所指向的对象；
- week_ptr：是若引用，指向shared_ptr所管理的对象。

上述三种类型都定义在memory头文件中

## shared_ptr类
类似vector，智能指针也是模板。
shared_ptr有一个关联的计数器，通常称为引用计数。
只要我们拷贝一个shared_ptr，计数器都会递增。
而给shared_ptr赋予一个新值或者shared_ptr被销毁时，计数器会递减。shared_ptr的销毁是通过析构函数实现。
一旦一个shared_ptr的计数器变为0，它就会自动释放自己所管理的对象。

``` c++
// make_shared函数
shared_ptr<int> p3 = make_shared<int>(42);
shared_ptr<int> p4 = make_shared<int>();
// 更常见的方法
auto p5 = make_shared<vector<string>>();

// shared_ptr的拷贝和赋值
auto p = make_shared<int>(42); // 此时p指向的对象只有一个引用者
auto q(p) //p和q指向相同的对象，此对象有两个引用者

auto r = make_shared<int>(42);
r = q; // r被赋值，指向另外一个地址，会递减r所指向对象的引用计数，递增q所指向对象的引用计数，
      // 此时r所指向对象的引用为0，会自动释放。


void use_factory(T arg) {
    shared_ptr<Foo> p = factory(arg)
    return p;
}
```

## unique_ptr类
一个unique_ptr “拥有”它所指向的对象,所以它不支持普通的拷贝或赋值操作。与shared_ptr不同的是，
某个时刻只能有一个unique_ptr指向一个给定的对象。当unique_ptr被销毁时，它所指向的对象也被销毁。
当我们定义一个unique_prt时，需要将其绑定到一个new返回的指针上。

``` cpp
unique_ptr<double> p1; // 空 unique_ptr
unique_ptr<int> p2(new int(42));
unique_ptr<string> p1(new string("aaaa"));
unique_ptr<string> p2(p1) //错误，unique_ptr不支持拷贝
unique_ptr<string> p3;
p3 = p2; // 错误，unique_ptr不支持赋值
```

虽然我们无法拷贝或赋值unique_ptr，但可以通过调用release或reset将指针的所有权从一个unique_ptr
转移给另外一个unique_ptr。

``` cpp
unique_ptr<int> p2(p1.release()); // 
p2.release(); // 错误：p2不会释放内存，并且丢失了指针
auto p = p2.release() // 正确，但要即的delete p

// 可以拷贝或赋值一个将要被销毁的unique_ptr
unique_ptr<int> clone (int p) {
    return unique_ptr<int> (new int(p));
}
// 返回局部对象的拷贝
unique_ptr<int> clone (int p) {
    unique_ptr<int> ret(new int(p))
    return ret;
}
```

向unique_ptr中传递删除器

``` cpp
// 使用一个类型名为delT的对象来释放objT,它会调用名为fcn的delT对象
unique_ptr<objT, delT> p (new objT, fcn);
```

