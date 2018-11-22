// 匿名命名空间的作用域为当前程序文件 等价于namespace <unnamed>{} using namespace <unnamed>;
// 因此在匿名命名空间的定义前，这个匿名命名空间是不可见的
// 此外可以使用别名简化名字空间



namespace A{
    int y=1;
}
namespace B{
    namespace C{
        namespace D{
            int z=1;
        }
    }
}
namespace whatever = B::C::D;
using whatever::z;
int main(int argc, char const *argv[])
{
    y=1; 
    x=1;
    z=2;//正确
    // x 和 y 都会报错 - - use of undeclared identifier
    return 0;
}
namespace {
    int x=1;
}
using namespace A;