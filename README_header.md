![Build](https://github.com/GaryHughes/stddecimal/workflows/Build/badge.svg)


# std::decimal

This is an implementation of the proposed C++ [ISO/IEC JTC1 SC22 WG21 N2849](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2009/n2849.pdf) std::decimal including the [ISO/IEC JTC1 SC22 WG21 N3871](http://open-std.org/JTC1/SC22/WG21/docs/papers/2014/n3871.html) revisions. It is built on the [Intel Floating Point Library](https://software.intel.com/content/www/us/en/develop/articles/pre-release-license-agreement-for-intel-decimal-floating-point-math-library.html) that does all the hard work.

# Intent

I've used [this implementation](https://sourceforge.net/p/stddecimal/code/HEAD/tree/trunk/) successfully in the past however I wanted build a modern version that relied on templates instead of macros to generate the numerous operators required.

# Building

* std::decimal currently requires a C++ 17 compiler. It is built and tested on macOS with Apple Clang from the latest Xcode and on Ubuntu with Clang 10.
* The general_decimal_arithmetic/test_runner requires [boost](https://boost.org). If you don't want to install this just comment it out in the top level CMakeLists.txt
* Check the supplied [Dockerfile](https://github.com/GaryHughes/stddecimal/blob/main/Dockerfile) for detailed build requirements. This is the environment used to build in Github Actions [here](https://github.com/GaryHughes/stddecimal/actions?query=workflow%3ABuild).
# Floating Point Environment

The specification adds the following functions which have been implemented.

```c++
namespace std::decimal {

    int fe_dec_getround();
    int fe_dec_setround(int round);  

}
```

The specification does not add decimal specific exception state functions as [described here](https://en.cppreference.com/w/cpp/numeric/fenv). Because the state functions are opaque and we can't really use them I've introduced a decimal specific set by adding DEC\_ and \_dec\_ to the names as follows.

```c++
namespace std::decimal {

    constexpr fexcept_t FE_DEC_DIVBYZERO;
    constexpr fexcept_t FE_DEC_INEXACT;
    constexpr fexcept_t FE_DEC_INVALID;
    constexpr fexcept_t FE_DEC_OVERFLOW;
    constexpr fexcept_t FE_DEC_UNDERFLOW;
    constexpr fexcept_t FE_DEC_ALL_EXCEPT;

    struct fenv_t;

    int fe_dec_clearexcept(int except);
    int fe_dec_raiseexcept(int except);
    int fe_dec_setexceptflag(const fexcept_t *pflag, int except);
    int fe_dec_getexceptflag(fexcept_t *pflag, int except);
    int fe_dec_testexcept(int except);
    int fe_dec_getenv(fenv_t *penv);
    int fe_dec_setenv(const fenv_t *penv);
    int fe_dec_holdexcept(fenv_t *penv);
    int fe_dec_updateenv(const fenv_t *penv);

}
```

# Extensions

Support has been added for selectively throwing C++ exceptions.

```c++
// Throw std::decimal::exception if any of the exceptions in the except mask are raised.
// NB: Some operations will result in multiple floating point exceptions being raised and
// this will result in a single std::decimal::exception being thrown. The flags property of
/// this exception will include all raised exceptions.
void set_exceptions(int except) noexcept;
// Remove an exceptions in the except mask from the throw list.
void clear_exceptions(int except) noexcept;
// What exceptions have been configured to throw with set_exceptions?
int get_exceptions() noexcept;
// Check the decimal floating point environment exception flags and throw a std:decimal::exception if
// any exceptions have been raised.
// This function is called internally if any exceptions have been enabled with set_exceptions but it
// can also be called manually by the user.
void check_exceptions();
```



```c++
namespace std::decimal {

class exception : public std::exception
{
public:

    exception(fexcept_t flags);
    constexpr fexcept_t flags() const { return m_flags; }
    const char* what() const noexcept override { return m_what.c_str(); }

private:

    fexcept_t m_flags;
    std::string m_what;

};

}

```

# Testing

The library is validated using the [General Decimal Arithmetic Test Cases](http://speleotrove.com/decimal/dectest.html).

* I'm currently in the process of building the test harness and implementing what is needed to run as many tests as possible so there are a lot of failures.
* Failing tests are currently more likely to be problems mapping exceptions between the specification and the Intel library than real problems with the calculations.
* Test cases that are not applicable or not yet supported will be explicitly skipped so this column will likely never get to zero.

