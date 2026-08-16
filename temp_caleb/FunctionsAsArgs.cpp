#include <iostream>

/*
    File contains a temporary example of how to pass functions as arguments.
    Will be removed later.
*/

using SpecialFunc = int (*)(int, int);

void execute(int x, int y, SpecialFunc funcArg)
{
    int result = funcArg(x, y);
    std::cout << "result: " << result << std::endl;
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    std::cout << "Hello, world!" << std::endl;
    execute(5, 2, add);
    execute(5, 2, [](int a, int b)
            { return a - b; });
    return 0;
}