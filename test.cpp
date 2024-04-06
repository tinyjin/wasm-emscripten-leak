#include <emscripten/bind.h>
#include <sanitizer/lsan_interface.h>

using namespace emscripten;
using namespace std;

class __attribute__((visibility("default"))) Test
{
public:
    ~Test()
    {
    }

    static unique_ptr<Test> create()
    {
        return unique_ptr<Test>(new Test());
    }

    void test1()
    {
    }

    void test2()
    {
    }

    void test3()
    {
    }

    void test4()
    {
    }

    Test()
    {
    }
};

EMSCRIPTEN_BINDINGS(test_bindings)
{
    class_<Test>("Test")
        .constructor(&Test ::create) // No Leak
        .function("test1", &Test::test1) // Leak 8 bytes
        .function("test2", &Test ::test2) // Leak 8 bytes
        .function("test3", &Test ::test3) // Leak 8 bytes
        .function("test4", &Test ::test4); // Leak 8 bytes

    emscripten::function("doLeakCheck", &__lsan_do_leak_check); // No Leak
}
