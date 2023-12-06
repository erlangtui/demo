#include <iostream>

class MyClass
{
public:
    // 默认构造函数
    MyClass() : size(0)
    {
        std::cout << "default" << std::endl;
    }

    // 带参构造函数
    MyClass(int newSize) : size(newSize)
    {
        std::cout << "para" << std::endl;
    }

    // 拷贝构造函数
    MyClass(const MyClass &other) : size(other.size)
    {
        std::cout << "copy" << std::endl;
    }

    // 移动构造函数
    MyClass(MyClass &&other) noexcept : size(other.size)
    {
        other.size = 0;
        std::cout << "move construct" << std::endl;
    }

    // 拷贝赋值函数
    MyClass &operator=(const MyClass &other)
    {
        if (this != &other)
        {
            size = other.size;
        }
        std::cout << "copy assign" << std::endl;
        return *this;
    }

    // 移动赋值函数
    MyClass &operator=(MyClass &&other) noexcept
    {
        if (this != &other)
        {
            size = other.size;
            other.size = 0;
        }
        std::cout << "move assign" << std::endl;
        return *this;
    }

    ~MyClass()
    {
        std::cout << "~MyClass: " << size << std::endl;
    }

private:
    int size;
};

int main(int argc, char **argv)
{
    MyClass c = 2; // important
    
    return 0;
}
