#include <functional>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <cstddef>
#include <iostream>

class new_circulation
{
private:
    // 通用 for 循环实现
    template <typename Func, typename UpdateFunc = std::nullptr_t>
    void for_loop(size_t cycle_index, Func &&executive_function, UpdateFunc &&update_function = nullptr)
    {
        try
        {
            if (cycle_index == 0)
            {
                return; // 如果循环次数为 0，直接返回
            }

            size_t i = 1; // 循环变量从 1 开始
            for (size_t count = 0; count < cycle_index; ++count)
            {
                // 调用用户提供的执行函数，传入 i 的地址
                std::invoke(std::forward<Func>(executive_function), &i);

                // 如果提供了更新函数，用它来更新 i
                if (update_function)
                {
                    std::invoke(std::forward<UpdateFunc>(update_function), i);
                }
                else
                {
                    // 默认行为：i 每次增加 1
                    ++i;
                }
            }
        }
        catch (const std::exception &e)
        {
            // 捕获标准异常并打印错误信息
            std::cerr << "Exception caught in for_loop: " << e.what() << std::endl;
        }
        catch (...)
        {
            // 捕获其他未知异常
            std::cerr << "Unknown exception caught in for_loop" << std::endl;
        }
    }

    // 通用 while 循环实现
    template <typename Func>
    void while_loop(size_t cycle_index, Func &&executive_function)
    {
        try
        {
            if (cycle_index == 0)
            {
                return; // 如果循环次数为 0，直接返回
            }

            while (cycle_index--)
            {
                std::invoke(std::forward<Func>(executive_function));
            }
        }
        catch (const std::exception &e)
        {
            // 捕获标准异常并打印错误信息
            std::cerr << "Exception caught in while_loop: " << e.what() << std::endl;
        }
        catch (...)
        {
            // 捕获其他未知异常
            std::cerr << "Unknown exception caught in while_loop" << std::endl;
        }
    }

public:
    // 标准化的 for 循环接口
    template <typename Func, typename UpdateFunc = std::nullptr_t>
    void super_for(size_t cycle_index, Func &&executive_function, UpdateFunc &&update_function = nullptr)
    {
#if __cplusplus >= 201703L
        // 如果是 C++17 或更高版本，静态断言函数对象是否可调用
        static_assert(std::is_invocable_v<Func, size_t *>,
                      "executive_function must be invocable with a single size_t* argument");
        if constexpr (!std::is_same_v<UpdateFunc, std::nullptr_t>)
        {
            static_assert(std::is_invocable_v<UpdateFunc, size_t>,
                          "update_function must be invocable with a single size_t argument");
        }
#endif
        for_loop(cycle_index, std::forward<Func>(executive_function), std::forward<UpdateFunc>(update_function));
    }

    // 标准化的 while 循环接口
    template <typename Func>
    void super_while(size_t cycle_index, Func &&executive_function)
    {
#if __cplusplus >= 201703L
        // 如果是 C++17 或更高版本，静态断言函数对象是否可调用
        static_assert(std::is_invocable_v<Func>,
                      "executive_function must be invocable with no arguments");
#endif
        while_loop(cycle_index, std::forward<Func>(executive_function));
    }
} circula;