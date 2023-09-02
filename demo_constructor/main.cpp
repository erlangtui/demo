#include <iostream>

class MyClass
{
public:
    // 默认构造函数
    MyClass() : data(nullptr), size(0)
    {
        name = "default construct";
        std::cout << name << std::endl;
    }

    // 带参构造函数
    MyClass(int *newData, int newSize, std::string newName) : size(newSize)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = newData[i];
        }
        name = "paras construct";
        std::cout << name << std::endl;
    }

    // 拷贝构造函数
    MyClass(const MyClass &other) : size(other.size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
        name = "copy construct";
        std::cout << name << std::endl;
    }

    // 移动构造函数
    MyClass(MyClass &&other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
        name = "move construct";
        std::cout << "move construct" << std::endl;
    }

    // 拷贝赋值函数
    MyClass &operator=(const MyClass &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        name = "copy assign";
        std::cout << "copy assign" << std::endl;
        return *this;
    }

    // 移动赋值函数
    MyClass &operator=(MyClass &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        name = "move assign";
        std::cout << "move assign" << std::endl;
        return *this;
    }

    ~MyClass()
    {
        std::cout << std::boolalpha;
        std::cout << "~MyClass: " << name << "  data is null: " << (data == nullptr) << std::endl;
        delete[] data;
    }

private:
    int *data;
    int size;

    std::string name;
};

int main(int argc, char **argv)
{
    int data[3] = {1, 2, 3};
    // 执行默认构造函数
    MyClass x, y, z, a;
    // 执行带参构造函数
    MyClass b(data, 3, "b");
    // 执行拷贝构造函数
    MyClass c = a; // important
    // 执行拷贝构造函数
    MyClass d(a);
    // 执行移动构造函数
    MyClass e = std::move(x);

    std::cout << "-----------------" << std::endl;

    // 执行拷贝赋值函数
    y = b;
    // 执行移动赋值函数
    z = std::move(c);

    std::cout << "-----------------" << std::endl;

    const int iii = 9;
    const int &j = iii;
    int const &m = iii;
    std::cout << j << std::endl;
    std::cout << m << std::endl;
    const int *p;
    p = &iii;

    int const *p1;
    p1 = &iii;

    int i = 5;
    int *const p2 = &i;
    return 0;
}