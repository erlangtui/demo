class myClass
{
private:
    int data;

public:
    myClass(){};
    ~myClass(){};

    void set(int d) const
    {
        data = d; // 错误，常成员函数不能修改成员变量
    };
    int get() const
    {
        return data; // 正确，常成员函数进行只读操作
    }
    int get_data()
    {
        return data;
    };
};

int main(int argc, char **argv)
{
    const myClass m;
    int a = m.get();      // 正确，常对象调用常成员函数
    int b = m.get_data(); // 错误，常对象调用非常成员函数

    myClass n;
    int c = n.get();      // 正确，普通对象可以调用常成员函数
    int d = n.get_data(); // 正确，普通对象可以调用非常成员函数
}
