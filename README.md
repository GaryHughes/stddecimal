![Build](https://github.com/GaryHughes/stddecimal/workflows/Build/badge.svg)


# std::decimal

This is an implementation of the proposed C++ [ISO/IEC JTC1 SC22 WG21 N2849](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2009/n2849.pdf) std::decimal including the [ISO/IEC JTC1 SC22 WG21 N3871](http://open-std.org/JTC1/SC22/WG21/docs/papers/2014/n3871.html) revisions. It is built on the [Intel Floating Point Library](https://software.intel.com/content/www/us/en/develop/articles/pre-release-license-agreement-for-intel-decimal-floating-point-math-library.html) that does all the hard work.

# Intent

I've used [this implementation](https://sourceforge.net/p/stddecimal/code/HEAD/tree/trunk/) successfully in the past however I wanted build a modern version that relied on templates instead of macros to generate the numerous operators required.

# Testing

The library is validated using the [General Decimal Arithmetic Test Cases](http://speleotrove.com/decimal/dectest.html).

* I'm currently in the process of building the test harness and implementing what is needed to run as many tests as possible so there are a lot of failures.
* Failing tests are currently more likely to be problems mapping exceptions between the specification and the Intel library than real problems with the calculations.
* Test cases that are not applicable or not yet supported will be explicitly skipped so this column will likely never get to zero.

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

```## Subset Arithmetic

|Type|Operation|Passed|Failed|Skipped|
|:---|:--------|:----:|:----:|:-----:|
decimal32|abs0|16|1|42|
decimal32|add0|49|9|334|
decimal32|base0|0|0|772|
decimal32|compare0|0|0|413|
decimal32|comparetotal0|0|0|455|
decimal32|divide0|8|1|181|
decimal32|divideint0|0|0|173|
decimal32|exp0|0|0|319|
decimal32|fma0|0|0|9|
decimal32|inexact0|21|3|96|
decimal32|ln0|0|0|313|
decimal32|log100|55|21|237|
decimal32|max0|0|0|67|
decimal32|min0|0|0|67|
decimal32|minus0|6|1|38|
decimal32|multiply0|6|0|186|
decimal32|plus0|6|1|57|
decimal32|power0|18|1|240|
decimal32|quantize0|2|23|403|
decimal32|randombound320|0|0|2400|
decimal32|randoms0|0|0|4000|
decimal32|reduce0|0|0|106|
decimal32|remainder0|0|0|249|
decimal32|remaindernear0|0|0|263|
decimal32|rescale0|0|0|203|
decimal32|rounding0|511|217|0|
decimal32|samequantum0|0|0|64|
decimal32|squareroot0|2681|7|129|
decimal32|subtract0|27|22|470|
decimal32|testall0|0|0|0|
decimal32|tointegral0|0|0|70|
decimal32|trim0|0|0|93|
decimal32| |3406|307|12449|
decimal64|abs0|56|3|0|
decimal64|add0|229|163|0|
decimal64|base0|0|0|772|
decimal64|compare0|0|0|413|
decimal64|comparetotal0|0|0|455|
decimal64|divide0|158|32|0|
decimal64|divideint0|0|0|173|
decimal64|exp0|0|0|319|
decimal64|fma0|2|7|0|
decimal64|inexact0|67|46|7|
decimal64|ln0|0|0|313|
decimal64|log100|132|53|128|
decimal64|max0|0|0|67|
decimal64|min0|0|0|67|
decimal64|minus0|42|3|0|
decimal64|multiply0|90|55|47|
decimal64|plus0|61|3|0|
decimal64|power0|171|81|7|
decimal64|quantize0|233|195|0|
decimal64|randombound320|0|0|2400|
decimal64|randoms0|715|1785|1500|
decimal64|reduce0|0|0|106|
decimal64|remainder0|0|0|249|
decimal64|remaindernear0|0|0|263|
decimal64|rescale0|0|0|203|
decimal64|rounding0|224|504|0|
decimal64|samequantum0|0|0|64|
decimal64|squareroot0|2807|2|8|
decimal64|subtract0|303|216|0|
decimal64|testall0|0|0|0|
decimal64|tointegral0|0|0|70|
decimal64|trim0|0|0|93|
decimal64| |5290|3148|7724|
decimal128|abs0|56|3|0|
decimal128|add0|224|168|0|
decimal128|base0|0|0|772|
decimal128|compare0|0|0|413|
decimal128|comparetotal0|0|0|455|
decimal128|divide0|159|31|0|
decimal128|divideint0|0|0|173|
decimal128|exp0|0|0|319|
decimal128|fma0|2|7|0|
decimal128|inexact0|50|63|7|
decimal128|ln0|0|0|313|
decimal128|log100|209|44|60|
decimal128|max0|0|0|67|
decimal128|min0|0|0|67|
decimal128|minus0|42|3|0|
decimal128|multiply0|134|58|0|
decimal128|plus0|61|3|0|
decimal128|power0|172|81|6|
decimal128|quantize0|241|187|0|
decimal128|randombound320|1332|168|900|
decimal128|randoms0|541|1959|1500|
decimal128|reduce0|0|0|106|
decimal128|remainder0|0|0|249|
decimal128|remaindernear0|0|0|263|
decimal128|rescale0|0|0|203|
decimal128|rounding0|210|518|0|
decimal128|samequantum0|0|0|64|
decimal128|squareroot0|2815|2|0|
decimal128|subtract0|269|250|0|
decimal128|testall0|0|0|0|
decimal128|tointegral0|0|0|70|
decimal128|trim0|0|0|93|
decimal128| |6517|3545|6100|
## Extended Arithmetic

|Type|Operation|Passed|Failed|Skipped|
|:---|:--------|:----:|:----:|:-----:|
decimal32|abs|29|10|50|
decimal32|add|149|79|1872|
decimal32|and|0|0|279|
decimal32|base|0|0|1168|
decimal32|clamp|0|0|132|
decimal32|class|0|0|84|
decimal32|compare|0|0|639|
decimal32|comparesig|0|0|625|
decimal32|comparetotal|0|0|670|
decimal32|comparetotmag|0|0|664|
decimal32|copy|0|0|43|
decimal32|copyabs|0|0|43|
decimal32|copynegate|0|0|43|
decimal32|copysign|0|0|111|
decimal32|ddAbs|0|0|75|
decimal32|ddAdd|0|0|1091|
decimal32|ddAnd|0|0|287|
decimal32|ddBase|0|0|945|
decimal32|ddCanonical|0|0|230|
decimal32|ddClass|0|0|42|
decimal32|ddCompare|0|0|649|
decimal32|ddCompareSig|0|0|559|
decimal32|ddCompareTotal|0|0|613|
decimal32|ddCompareTotalMag|0|0|613|
decimal32|ddCopy|0|0|43|
decimal32|ddCopyAbs|0|0|43|
decimal32|ddCopyNegate|0|0|43|
decimal32|ddCopySign|0|0|107|
decimal32|ddDivide|0|0|717|
decimal32|ddDivideInt|0|0|373|
decimal32|ddEncode|0|0|376|
decimal32|ddFMA|0|0|1378|
decimal32|ddInvert|0|0|151|
decimal32|ddLogB|0|0|108|
decimal32|ddMax|0|0|256|
decimal32|ddMaxMag|0|0|242|
decimal32|ddMin|0|0|247|
decimal32|ddMinMag|0|0|233|
decimal32|ddMinus|0|0|43|
decimal32|ddMultiply|0|0|446|
decimal32|ddNextMinus|0|0|84|
decimal32|ddNextPlus|0|0|84|
decimal32|ddNextToward|0|0|304|
decimal32|ddOr|0|0|237|
decimal32|ddPlus|0|0|43|
decimal32|ddQuantize|0|0|683|
decimal32|ddReduce|0|0|134|
decimal32|ddRemainder|0|0|505|
decimal32|ddRemainderNear|0|0|529|
decimal32|ddRotate|0|0|212|
decimal32|ddSameQuantum|0|0|333|
decimal32|ddScaleB|0|0|184|
decimal32|ddShift|0|0|212|
decimal32|ddSubtract|0|0|516|
decimal32|ddToIntegral|0|0|178|
decimal32|ddXor|0|0|278|
decimal32|decDouble|0|0|0|
decimal32|decQuad|0|0|0|
decimal32|decSingle|0|0|0|
decimal32|divide|108|6|517|
decimal32|divideint|0|0|389|
decimal32|dqAbs|0|0|75|
decimal32|dqAdd|0|0|1012|
decimal32|dqAnd|0|0|357|
decimal32|dqBase|0|0|926|
decimal32|dqCanonical|0|0|244|
decimal32|dqClass|0|0|42|
decimal32|dqCompare|0|0|659|
decimal32|dqCompareSig|0|0|559|
decimal32|dqCompareTotal|0|0|613|
decimal32|dqCompareTotalMag|0|0|613|
decimal32|dqCopy|0|0|43|
decimal32|dqCopyAbs|0|0|43|
decimal32|dqCopyNegate|0|0|43|
decimal32|dqCopySign|0|0|107|
decimal32|dqDivide|0|0|688|
decimal32|dqDivideInt|0|0|374|
decimal32|dqEncode|0|0|368|
decimal32|dqFMA|0|0|1451|
decimal32|dqInvert|0|0|193|
decimal32|dqLogB|0|0|109|
decimal32|dqMax|0|0|256|
decimal32|dqMaxMag|0|0|242|
decimal32|dqMin|0|0|247|
decimal32|dqMinMag|0|0|233|
decimal32|dqMinus|0|0|43|
decimal32|dqMultiply|0|0|473|
decimal32|dqNextMinus|0|0|84|
decimal32|dqNextPlus|0|0|84|
decimal32|dqNextToward|0|0|304|
decimal32|dqOr|0|0|341|
decimal32|dqPlus|0|0|43|
decimal32|dqQuantize|0|0|686|
decimal32|dqReduce|0|0|134|
decimal32|dqRemainder|0|0|500|
decimal32|dqRemainderNear|0|0|530|
decimal32|dqRotate|0|0|248|
decimal32|dqSameQuantum|0|0|333|
decimal32|dqScaleB|0|0|202|
decimal32|dqShift|0|0|248|
decimal32|dqSubtract|0|0|520|
decimal32|dqToIntegral|0|0|178|
decimal32|dqXor|0|0|348|
decimal32|dsBase|0|0|907|
decimal32|dsEncode|0|0|268|
decimal32|exp|0|0|440|
decimal32|fma|174|117|2321|
decimal32|inexact|39|17|96|
decimal32|invert|0|0|128|
decimal32|ln|0|0|414|
decimal32|log10|55|33|301|
decimal32|logb|0|0|128|
decimal32|max|0|0|327|
decimal32|maxmag|0|0|312|
decimal32|min|0|0|317|
decimal32|minmag|0|0|303|
decimal32|minus|20|10|83|
decimal32|multiply|53|38|430|
decimal32|nextminus|0|0|104|
decimal32|nextplus|0|0|106|
decimal32|nexttoward|0|0|341|
decimal32|or|0|0|276|
decimal32|plus|20|10|92|
decimal32|power|233|100|874|
decimal32|powersqrt|2687|7|162|
decimal32|quantize|64|217|494|
decimal32|randombound32|0|0|2400|
decimal32|randoms|0|0|4000|
decimal32|reduce|0|0|168|
decimal32|remainder|0|0|517|
decimal32|remaindernear|0|0|446|
decimal32|rescale|0|0|617|
decimal32|rotate|0|0|195|
decimal32|rounding|744|264|22|
decimal32|samequantum|0|0|333|
decimal32|scaleb|0|0|155|
decimal32|shift|0|0|200|
decimal32|squareroot|3059|340|187|
decimal32|subtract|65|35|581|
decimal32|testall|0|0|0|
decimal32|tointegral|0|0|168|
decimal32|tointegralx|0|0|180|
decimal32|trim|0|0|110|
decimal32|xor|0|0|277|
decimal32| |7499|1283|56331|
decimal64|abs|76|13|0|
decimal64|add|1710|357|33|
decimal64|and|0|0|279|
decimal64|base|0|0|1168|
decimal64|clamp|0|0|132|
decimal64|class|0|0|84|
decimal64|compare|0|0|639|
decimal64|comparesig|0|0|625|
decimal64|comparetotal|0|0|670|
decimal64|comparetotmag|0|0|664|
decimal64|copy|0|0|43|
decimal64|copyabs|0|0|43|
decimal64|copynegate|0|0|43|
decimal64|copysign|0|0|111|
decimal64|ddAbs|0|0|75|
decimal64|ddAdd|0|0|1091|
decimal64|ddAnd|0|0|287|
decimal64|ddBase|0|0|945|
decimal64|ddCanonical|0|0|230|
decimal64|ddClass|0|0|42|
decimal64|ddCompare|0|0|649|
decimal64|ddCompareSig|0|0|559|
decimal64|ddCompareTotal|0|0|613|
decimal64|ddCompareTotalMag|0|0|613|
decimal64|ddCopy|0|0|43|
decimal64|ddCopyAbs|0|0|43|
decimal64|ddCopyNegate|0|0|43|
decimal64|ddCopySign|0|0|107|
decimal64|ddDivide|0|0|717|
decimal64|ddDivideInt|0|0|373|
decimal64|ddEncode|0|0|376|
decimal64|ddFMA|0|0|1378|
decimal64|ddInvert|0|0|151|
decimal64|ddLogB|0|0|108|
decimal64|ddMax|0|0|256|
decimal64|ddMaxMag|0|0|242|
decimal64|ddMin|0|0|247|
decimal64|ddMinMag|0|0|233|
decimal64|ddMinus|0|0|43|
decimal64|ddMultiply|0|0|446|
decimal64|ddNextMinus|0|0|84|
decimal64|ddNextPlus|0|0|84|
decimal64|ddNextToward|0|0|304|
decimal64|ddOr|0|0|237|
decimal64|ddPlus|0|0|43|
decimal64|ddQuantize|0|0|683|
decimal64|ddReduce|0|0|134|
decimal64|ddRemainder|0|0|505|
decimal64|ddRemainderNear|0|0|529|
decimal64|ddRotate|0|0|212|
decimal64|ddSameQuantum|0|0|333|
decimal64|ddScaleB|0|0|184|
decimal64|ddShift|0|0|212|
decimal64|ddSubtract|0|0|516|
decimal64|ddToIntegral|0|0|178|
decimal64|ddXor|0|0|278|
decimal64|decDouble|0|0|0|
decimal64|decQuad|0|0|0|
decimal64|decSingle|0|0|0|
decimal64|divide|564|49|18|
decimal64|divideint|0|0|389|
decimal64|dqAbs|0|0|75|
decimal64|dqAdd|0|0|1012|
decimal64|dqAnd|0|0|357|
decimal64|dqBase|0|0|926|
decimal64|dqCanonical|0|0|244|
decimal64|dqClass|0|0|42|
decimal64|dqCompare|0|0|659|
decimal64|dqCompareSig|0|0|559|
decimal64|dqCompareTotal|0|0|613|
decimal64|dqCompareTotalMag|0|0|613|
decimal64|dqCopy|0|0|43|
decimal64|dqCopyAbs|0|0|43|
decimal64|dqCopyNegate|0|0|43|
decimal64|dqCopySign|0|0|107|
decimal64|dqDivide|0|0|688|
decimal64|dqDivideInt|0|0|374|
decimal64|dqEncode|0|0|368|
decimal64|dqFMA|0|0|1451|
decimal64|dqInvert|0|0|193|
decimal64|dqLogB|0|0|109|
decimal64|dqMax|0|0|256|
decimal64|dqMaxMag|0|0|242|
decimal64|dqMin|0|0|247|
decimal64|dqMinMag|0|0|233|
decimal64|dqMinus|0|0|43|
decimal64|dqMultiply|0|0|473|
decimal64|dqNextMinus|0|0|84|
decimal64|dqNextPlus|0|0|84|
decimal64|dqNextToward|0|0|304|
decimal64|dqOr|0|0|341|
decimal64|dqPlus|0|0|43|
decimal64|dqQuantize|0|0|686|
decimal64|dqReduce|0|0|134|
decimal64|dqRemainder|0|0|500|
decimal64|dqRemainderNear|0|0|530|
decimal64|dqRotate|0|0|248|
decimal64|dqSameQuantum|0|0|333|
decimal64|dqScaleB|0|0|202|
decimal64|dqShift|0|0|248|
decimal64|dqSubtract|0|0|520|
decimal64|dqToIntegral|0|0|178|
decimal64|dqXor|0|0|348|
decimal64|dsBase|0|0|907|
decimal64|dsEncode|0|0|268|
decimal64|exp|0|0|440|
decimal64|fma|2070|433|109|
decimal64|inexact|85|60|7|
decimal64|invert|0|0|128|
decimal64|ln|0|0|414|
decimal64|log10|155|106|128|
decimal64|logb|0|0|128|
decimal64|max|0|0|327|
decimal64|maxmag|0|0|312|
decimal64|min|0|0|317|
decimal64|minmag|0|0|303|
decimal64|minus|100|13|0|
decimal64|multiply|322|107|92|
decimal64|nextminus|0|0|104|
decimal64|nextplus|0|0|106|
decimal64|nexttoward|0|0|341|
decimal64|or|0|0|276|
decimal64|plus|109|13|0|
decimal64|power|859|218|130|
decimal64|powersqrt|2840|9|7|
decimal64|quantize|296|476|3|
decimal64|randombound32|0|0|2400|
decimal64|randoms|748|1752|1500|
decimal64|reduce|0|0|168|
decimal64|remainder|0|0|517|
decimal64|remaindernear|0|0|446|
decimal64|rescale|0|0|617|
decimal64|rotate|0|0|195|
decimal64|rounding|398|632|0|
decimal64|samequantum|0|0|333|
decimal64|scaleb|0|0|155|
decimal64|shift|0|0|200|
decimal64|squareroot|3247|309|30|
decimal64|subtract|502|173|6|
decimal64|testall|0|0|0|
decimal64|tointegral|0|0|168|
decimal64|tointegralx|0|0|180|
decimal64|trim|0|0|110|
decimal64|xor|0|0|277|
decimal64| |14081|4720|46312|
decimal128|abs|74|15|0|
decimal128|add|1273|820|7|
decimal128|and|0|0|279|
decimal128|base|0|0|1168|
decimal128|clamp|0|0|132|
decimal128|class|0|0|84|
decimal128|compare|0|0|639|
decimal128|comparesig|0|0|625|
decimal128|comparetotal|0|0|670|
decimal128|comparetotmag|0|0|664|
decimal128|copy|0|0|43|
decimal128|copyabs|0|0|43|
decimal128|copynegate|0|0|43|
decimal128|copysign|0|0|111|
decimal128|ddAbs|0|0|75|
decimal128|ddAdd|0|0|1091|
decimal128|ddAnd|0|0|287|
decimal128|ddBase|0|0|945|
decimal128|ddCanonical|0|0|230|
decimal128|ddClass|0|0|42|
decimal128|ddCompare|0|0|649|
decimal128|ddCompareSig|0|0|559|
decimal128|ddCompareTotal|0|0|613|
decimal128|ddCompareTotalMag|0|0|613|
decimal128|ddCopy|0|0|43|
decimal128|ddCopyAbs|0|0|43|
decimal128|ddCopyNegate|0|0|43|
decimal128|ddCopySign|0|0|107|
decimal128|ddDivide|0|0|717|
decimal128|ddDivideInt|0|0|373|
decimal128|ddEncode|0|0|376|
decimal128|ddFMA|0|0|1378|
decimal128|ddInvert|0|0|151|
decimal128|ddLogB|0|0|108|
decimal128|ddMax|0|0|256|
decimal128|ddMaxMag|0|0|242|
decimal128|ddMin|0|0|247|
decimal128|ddMinMag|0|0|233|
decimal128|ddMinus|0|0|43|
decimal128|ddMultiply|0|0|446|
decimal128|ddNextMinus|0|0|84|
decimal128|ddNextPlus|0|0|84|
decimal128|ddNextToward|0|0|304|
decimal128|ddOr|0|0|237|
decimal128|ddPlus|0|0|43|
decimal128|ddQuantize|0|0|683|
decimal128|ddReduce|0|0|134|
decimal128|ddRemainder|0|0|505|
decimal128|ddRemainderNear|0|0|529|
decimal128|ddRotate|0|0|212|
decimal128|ddSameQuantum|0|0|333|
decimal128|ddScaleB|0|0|184|
decimal128|ddShift|0|0|212|
decimal128|ddSubtract|0|0|516|
decimal128|ddToIntegral|0|0|178|
decimal128|ddXor|0|0|278|
decimal128|decDouble|0|0|0|
decimal128|decQuad|0|0|0|
decimal128|decSingle|0|0|0|
decimal128|divide|585|46|0|
decimal128|divideint|0|0|389|
decimal128|dqAbs|0|0|75|
decimal128|dqAdd|0|0|1012|
decimal128|dqAnd|0|0|357|
decimal128|dqBase|0|0|926|
decimal128|dqCanonical|0|0|244|
decimal128|dqClass|0|0|42|
decimal128|dqCompare|0|0|659|
decimal128|dqCompareSig|0|0|559|
decimal128|dqCompareTotal|0|0|613|
decimal128|dqCompareTotalMag|0|0|613|
decimal128|dqCopy|0|0|43|
decimal128|dqCopyAbs|0|0|43|
decimal128|dqCopyNegate|0|0|43|
decimal128|dqCopySign|0|0|107|
decimal128|dqDivide|0|0|688|
decimal128|dqDivideInt|0|0|374|
decimal128|dqEncode|0|0|368|
decimal128|dqFMA|0|0|1451|
decimal128|dqInvert|0|0|193|
decimal128|dqLogB|0|0|109|
decimal128|dqMax|0|0|256|
decimal128|dqMaxMag|0|0|242|
decimal128|dqMin|0|0|247|
decimal128|dqMinMag|0|0|233|
decimal128|dqMinus|0|0|43|
decimal128|dqMultiply|0|0|473|
decimal128|dqNextMinus|0|0|84|
decimal128|dqNextPlus|0|0|84|
decimal128|dqNextToward|0|0|304|
decimal128|dqOr|0|0|341|
decimal128|dqPlus|0|0|43|
decimal128|dqQuantize|0|0|686|
decimal128|dqReduce|0|0|134|
decimal128|dqRemainder|0|0|500|
decimal128|dqRemainderNear|0|0|530|
decimal128|dqRotate|0|0|248|
decimal128|dqSameQuantum|0|0|333|
decimal128|dqScaleB|0|0|202|
decimal128|dqShift|0|0|248|
decimal128|dqSubtract|0|0|520|
decimal128|dqToIntegral|0|0|178|
decimal128|dqXor|0|0|348|
decimal128|dsBase|0|0|907|
decimal128|dsEncode|0|0|268|
decimal128|exp|0|0|440|
decimal128|fma|1689|911|12|
decimal128|inexact|68|77|7|
decimal128|invert|0|0|128|
decimal128|ln|0|0|414|
decimal128|log10|232|97|60|
decimal128|logb|0|0|128|
decimal128|max|0|0|327|
decimal128|maxmag|0|0|312|
decimal128|min|0|0|317|
decimal128|minmag|0|0|303|
decimal128|minus|98|15|0|
decimal128|multiply|379|120|22|
decimal128|nextminus|0|0|104|
decimal128|nextplus|0|0|106|
decimal128|nexttoward|0|0|341|
decimal128|or|0|0|276|
decimal128|plus|103|19|0|
decimal128|power|977|212|18|
decimal128|powersqrt|2847|9|0|
decimal128|quantize|340|435|0|
decimal128|randombound32|1419|81|900|
decimal128|randoms|574|1926|1500|
decimal128|reduce|0|0|168|
decimal128|remainder|0|0|517|
decimal128|remaindernear|0|0|446|
decimal128|rescale|0|0|617|
decimal128|rotate|0|0|195|
decimal128|rounding|382|648|0|
decimal128|samequantum|0|0|333|
decimal128|scaleb|0|0|155|
decimal128|shift|0|0|200|
decimal128|squareroot|3224|339|23|
decimal128|subtract|471|210|0|
decimal128|testall|0|0|0|
decimal128|tointegral|0|0|168|
decimal128|tointegralx|0|0|180|
decimal128|trim|0|0|110|
decimal128|xor|0|0|277|
decimal128| |14735|5980|44398|
