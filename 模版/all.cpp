/**
 * @file AllNewDefinition.cpp
 * @brief 自包含的 AllNewDefinition 类，提供标准化的 IO 操作、矩阵运算和循环辅助工具。
 *
 * 该文件中的 AllNewDefinition 类可以直接复制到任何一个 cpp 文件中使用，无需额外引用。
 * 每个成员函数均有详细的注释说明其功能和使用方法。
 */

 #include <iostream>
 #include <vector>
 #include <string>
 #include <functional>
 #include <stdexcept>
 #include <cctype>
 #include <type_traits>
 
 /**
  * @brief AllNewDefinition 类封装了多种工具：
  *  - TwoMatrix：用于基本的矩阵运算（加、减、乘、快速幂）。
  *  - IO：标准化的输入输出库，基于 std::cin 和 std::cout 实现。
  *  - NewCirculation：提供标准化的 for 与 while 循环辅助接口。
  */
 class AllNewDefinition {
 public:
     // ============================================================
     // 矩阵类：TwoMatrix
     // ============================================================
     class TwoMatrix {
     private:
         std::vector<std::vector<int>> value; ///< 用于存储矩阵数据的二维 vector
 
     public:
         /**
          * @brief 构造函数，生成 n 行 m 列的矩阵，并将所有元素初始化为 0。
          * @param n 矩阵的行数
          * @param m 矩阵的列数
          */
         TwoMatrix(int n, int m) : value(n, std::vector<int>(m, 0)) {}
 
         /**
          * @brief 获取矩阵中指定位置的元素值。
          * @param i 行索引（从 0 开始）
          * @param j 列索引（从 0 开始）
          * @return 对应位置的整数值
          * @throws std::out_of_range 当索引超出矩阵范围时抛出异常
          */
         int get(int i, int j) const {
             if (i < 0 || i >= rows() || j < 0 || j >= cols())
                 throw std::out_of_range("Index out of range in get()");
             return value[i][j];
         }
 
         /**
          * @brief 设置矩阵中指定位置的元素值。
          * @param i 行索引（从 0 开始）
          * @param j 列索引（从 0 开始）
          * @param v 待设置的值
          * @throws std::out_of_range 当索引超出矩阵范围时抛出异常
          */
         void set(int i, int j, int v) {
             if (i < 0 || i >= rows() || j < 0 || j >= cols())
                 throw std::out_of_range("Index out of range in set()");
             value[i][j] = v;
         }
 
         /**
          * @brief 返回矩阵的行数。
          * @return 行数
          */
         int rows() const {
             return static_cast<int>(value.size());
         }
 
         /**
          * @brief 返回矩阵的列数。
          * @return 列数
          */
         int cols() const {
             return value.empty() ? 0 : static_cast<int>(value[0].size());
         }
 
         /**
          * @brief 实现矩阵加法操作符。
          * @param other 另一个矩阵对象
          * @return 两个矩阵相加后的结果
          * @throws std::invalid_argument 当两个矩阵的维度不匹配时抛出异常
          */
         TwoMatrix operator+(const TwoMatrix &other) const {
             if (rows() != other.rows() || cols() != other.cols())
                 throw std::invalid_argument("Dimension mismatch in operator+");
             int n = rows(), m = cols();
             TwoMatrix res(n, m);
             for (int i = 0; i < n; ++i)
                 for (int j = 0; j < m; ++j)
                     res.value[i][j] = value[i][j] + other.value[i][j];
             return res;
         }
 
         /**
          * @brief 实现矩阵减法操作符。
          * @param other 另一个矩阵对象
          * @return 两个矩阵相减后的结果
          * @throws std::invalid_argument 当两个矩阵的维度不匹配时抛出异常
          */
         TwoMatrix operator-(const TwoMatrix &other) const {
             if (rows() != other.rows() || cols() != other.cols())
                 throw std::invalid_argument("Dimension mismatch in operator-");
             int n = rows(), m = cols();
             TwoMatrix res(n, m);
             for (int i = 0; i < n; ++i)
                 for (int j = 0; j < m; ++j)
                     res.value[i][j] = value[i][j] - other.value[i][j];
             return res;
         }
 
         /**
          * @brief 实现矩阵乘法操作符。
          * @param other 另一个矩阵对象
          * @return 矩阵乘法后的结果
          * @throws std::invalid_argument 当当前矩阵的列数与另一个矩阵的行数不匹配时抛出异常
          */
         TwoMatrix operator*(const TwoMatrix &other) const {
             if (cols() != other.rows())
                 throw std::invalid_argument("Dimension mismatch in operator*");
             int n = rows(), m = other.cols(), p = cols();
             TwoMatrix res(n, m);
             for (int i = 0; i < n; ++i)
                 for (int j = 0; j < m; ++j)
                     for (int k = 0; k < p; ++k)
                         res.value[i][j] += value[i][k] * other.value[k][j];
             return res;
         }
 
         /**
          * @brief 快速计算矩阵的幂，仅适用于方阵。
          * @param base 基础矩阵
          * @param exp 指数（非负整数）
          * @return 结果矩阵，即 base 的 exp 次幂
          * @throws std::invalid_argument 当基础矩阵不是方阵时抛出异常
          */
         static TwoMatrix power(const TwoMatrix &base, int exp) {
             if (base.rows() != base.cols())
                 throw std::invalid_argument("Matrix exponentiation requires a square matrix");
             int n = base.rows();
             TwoMatrix res(n, n);
             // 初始化单位矩阵
             for (int i = 0; i < n; ++i) {
                 res.set(i, i, 1);
             }
             TwoMatrix current = base;
             while (exp > 0) {
                 if (exp & 1)
                     res = res * current;
                 current = current * current;
                 exp >>= 1;
             }
             return res;
         }
     };
 
     // ============================================================
     // IO 类：标准化输入输出库
     // ============================================================
     class IO {
     public:
         /**
          * @brief 构造函数，初始化 IO 流设置。
          *
          * 禁止同步 C++ IO 与 C IO，并解绑定 std::cin 和 std::cout，提高输入输出效率。
          */
         IO() {
             std::ios::sync_with_stdio(false);
             std::cin.tie(nullptr);
         }
 
         /**
          * @brief 从标准输入中读取一个值。
          * @tparam T 数据类型，要求支持 std::cin >> 操作
          * @param x 待读入的变量引用
          */
         template <typename T>
         void read(T &x) {
             std::cin >> x;
         }
 
         /**
          * @brief 递归读取多个值。
          *
          * 可一次性读取多个变量，依次调用 std::cin >> 进行输入。
          *
          * @tparam T 第一个数据的类型
          * @tparam Args 后续数据的类型列表
          * @param x 第一个待读取变量
          * @param args 后续待读取变量
          */
         template <typename T, typename... Args>
         void read(T &x, Args &...args) {
             std::cin >> x;
             read(args...);
         }
 
         /**
          * @brief 将一个值写入到标准输出中。
          * @tparam T 数据类型，要求支持 std::cout << 操作
          * @param x 待输出的变量
          */
         template <typename T>
         void write(const T &x) {
             std::cout << x;
         }
 
         /**
          * @brief 针对 C 风格字符串的写入重载。
          * @param s 待输出的 C 风格字符串
          */
         void write(const char *s) {
             std::cout << s;
         }
 
         /**
          * @brief 递归写入多个值到标准输出中。
          *
          * 可一次性输出多个变量，依次调用 std::cout << 输出。
          *
          * @tparam T 第一个数据的类型
          * @tparam Args 后续数据的类型列表
          * @param x 第一个待输出变量
          * @param args 后续待输出变量
          */
         template <typename T, typename... Args>
         void write(const T &x, const Args &...args) {
             std::cout << x;
             write(args...);
         }
 
         /**
          * @brief 输出换行符到标准输出中。
          */
         void newline() {
             std::cout.put('\n');
         }
     };
 
     // ============================================================
     // 循环辅助类：NewCirculation
     // ============================================================
     class NewCirculation {
     public:
         /**
          * @brief 标准化的 for 循环接口。
          *
          * 从 1 开始计数，每次循环调用 executive_function，并可选择调用 update_function 更新循环变量。
          *
          * @tparam Func 函数类型，要求可以用 size_t* 作为参数调用
          * @tparam UpdateFunc 更新函数类型，要求可以用 size_t 作为参数调用
          * @param cycle_index 循环执行次数
          * @param executive_function 循环中执行的函数，其参数为循环变量的指针
          * @param update_function 可选的更新函数，用于自定义循环变量的更新逻辑
          */
         template <typename Func, typename UpdateFunc = std::function<void(size_t)>>
         void super_for(size_t cycle_index, Func executive_function, UpdateFunc update_function = nullptr) {
 #if __cplusplus >= 201703L
             static_assert(std::is_invocable_v<Func, size_t*>,
                           "executive_function must be invocable with a pointer to size_t");
 #endif
             size_t i = 1;  // 循环变量从 1 开始
             for (size_t count = 0; count < cycle_index; ++count) {
                 std::invoke(executive_function, &i);
                 if (update_function)
                     std::invoke(update_function, i);
                 else
                     ++i;
             }
         }
 
         /**
          * @brief 标准化的 while 循环接口。
          *
          * 循环执行 executive_function 指定的次数。
          *
          * @tparam Func 函数类型，要求可以无参数调用
          * @param cycle_index 循环执行次数
          * @param executive_function 循环中每次执行的函数
          */
         template <typename Func>
         void super_while(size_t cycle_index, Func executive_function) {
 #if __cplusplus >= 201703L
             static_assert(std::is_invocable_v<Func>,
                           "executive_function must be invocable with no arguments");
 #endif
             while (cycle_index--) {
                 std::invoke(executive_function);
             }
         }
     };
 
     // ============================================================
     // 工厂函数，创建各个工具对象（返回值均为值语义）
     // ============================================================
 
     /**
      * @brief 工厂函数，创建 IO 对象。
      * @return IO 类对象，可用于标准化的输入输出操作
      */
     static IO createIO() {
         return IO();
     }
 
     /**
      * @brief 工厂函数，创建 NewCirculation 对象。
      * @return NewCirculation 类对象，用于辅助循环操作
      */
     static NewCirculation createCirculation() {
         return NewCirculation();
     }
 
     /**
      * @brief 工厂函数，创建 TwoMatrix 对象。
      * @param rows 矩阵的行数
      * @param cols 矩阵的列数
      * @return TwoMatrix 类对象，具有指定的行和列
      */
     static TwoMatrix createMatrix(int rows, int cols) {
         return TwoMatrix(rows, cols);
     }
 };
 
 /*
  * 使用示例：
  *
  * int main() {
  *     // 使用 IO 对象
  *     auto io = AllNewDefinition::createIO();
  *     int a, b;
  *     io.read(a, b);
  *     io.write("Sum: ", a + b);
  *     io.newline();
  *
  *     // 使用矩阵工具
  *     auto mat1 = AllNewDefinition::createMatrix(2, 2);
  *     auto mat2 = AllNewDefinition::createMatrix(2, 2);
  *     mat1.set(0, 0, 1); mat1.set(0, 1, 2);
  *     mat1.set(1, 0, 3); mat1.set(1, 1, 4);
  *     mat2.set(0, 0, 5); mat2.set(0, 1, 6);
  *     mat2.set(1, 0, 7); mat2.set(1, 1, 8);
  *     auto matSum = mat1 + mat2;
  *
  *     // 使用循环辅助工具
  *     auto circulation = AllNewDefinition::createCirculation();
  *     circulation.super_for(5, [](size_t* i) {
  *         std::cout << "循环变量: " << *i << " ";
  *     });
  *     std::cout << std::endl;
  *
  *     return 0;
  * }
  */
 