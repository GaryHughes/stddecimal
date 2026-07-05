![Build](https://github.com/GaryHughes/stddecimal/workflows/Build/badge.svg)


# std::decimal

This is an implementation of the proposed C++ [ISO/IEC JTC1 SC22 WG21 N2849](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2009/n2849.pdf) std::decimal including the [ISO/IEC JTC1 SC22 WG21 N3871](http://open-std.org/JTC1/SC22/WG21/docs/papers/2014/n3871.html) revisions. It is built on the [Intel Floating Point Library](https://software.intel.com/content/www/us/en/develop/articles/pre-release-license-agreement-for-intel-decimal-floating-point-math-library.html) that does all the hard work.

# Intent

I've used [this implementation](https://sourceforge.net/p/stddecimal/code/HEAD/tree/trunk/) successfully in the past however I wanted build a modern version that relied on templates instead of macros to generate the numerous operators required.

# Building

* std::decimal currently requires a C++ 23 compiler. It is built and tested on macOS with Apple Clang from the latest Xcode and on Ubuntu with Clang 21.
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

* The large majority of failures are not calculation bugs - they're a consequence of how the test harness runs the cases, not the underlying arithmetic. Each `.decTest` file declares a `precision:` and an exponent range (`maxExponent:`/`minexponent:`) that its expected results assume, but the harness doesn't apply these - every test just runs at the native precision and exponent range of whichever type (`decimal32`/`64`/`128`) is under test. Where a file's declared context is narrower or wider than the type's real limits, results legitimately diverge from what the file expects even though the type itself is behaving correctly for its own precision (e.g. a file assuming 9 significant digits will expect rounding that a native 7-digit `decimal32` needs to apply sooner, or won't expect the overflow/underflow that a `decimal32`'s much smaller exponent range hits on values the file treats as perfectly ordinary). Enforcing each file's declared context is a much larger undertaking than a bug fix, and hasn't been done.
* A smaller share of failures come from exceptions genuinely being raised, just not carrying every condition flag the test expects alongside the primary one (most often a missing companion `Inexact`), or from the underlying [Intel library](https://software.intel.com/content/www/us/en/develop/articles/pre-release-license-agreement-for-intel-decimal-floating-point-math-library.html) occasionally mislabelling which flag it raises (e.g. signalling `Overflow` on a `power` result that's actually underflowing to zero).
* Test cases exercising operations or special values that aren't applicable in a given file's mode (e.g. the subset arithmetic tests don't support `NaN`/`Infinity` as operands) or that aren't implemented yet are explicitly skipped, so this column won't necessarily reach zero for every file - though as of writing it's at zero across the entire subset arithmetic suite.

## Subset Arithmetic
<details>
<summary>decimal 32</summary>

|Type|Operation|Passed|Failed|Skipped|
|:---|:--------|:----:|:----:|:-----:|
decimal32|abs|59|0|0|
decimal32|add|348|44|0|
decimal32|base|488|286|0|
decimal32|compare|413|0|0|
decimal32|comparetotal|428|27|0|
decimal32|divide|180|10|0|
decimal32|divideint|162|11|0|
decimal32|exp|319|0|0|
decimal32|fma|9|0|0|
decimal32|inexact|112|8|0|
decimal32|ln|282|31|0|
decimal32|log10|290|23|0|
decimal32|max|67|0|0|
decimal32|min|67|0|0|
decimal32|minus|45|0|0|
decimal32|multiply|192|0|0|
decimal32|plus|64|0|0|
decimal32|power|242|17|0|
decimal32|quantize|394|34|0|
decimal32|randombound32|2142|258|0|
decimal32|randoms|3503|497|0|
decimal32|reduce|106|0|0|
decimal32|remainder|240|9|0|
decimal32|remaindernear|254|9|0|
decimal32|rescale|181|22|0|
decimal32|rounding|511|217|0|
decimal32|samequantum|64|0|0|
decimal32|squareroot|2798|19|0|
decimal32|subtract|430|89|0|
decimal32|testall|0|0|0|
decimal32|tointegral|70|0|0|
decimal32|trim|93|0|0|
decimal32| |14553|1611|0|

</details>
<details>
<summary>decimal 64</summary>

|Type|Operation|Passed|Failed|Skipped|
|:---|:--------|:----:|:----:|:-----:|
decimal64|abs|56|3|0|
decimal64|add|253|139|0|
decimal64|base|514|260|0|
decimal64|compare|413|0|0|
decimal64|comparetotal|426|29|0|
decimal64|divide|171|19|0|
decimal64|divideint|161|12|0|
decimal64|exp|319|0|0|
decimal64|fma|9|0|0|
decimal64|inexact|74|46|0|
decimal64|ln|301|12|0|
decimal64|log10|296|17|0|
decimal64|max|61|6|0|
decimal64|min|61|6|0|
decimal64|minus|42|3|0|
decimal64|multiply|171|21|0|
decimal64|plus|61|3|0|
decimal64|power|236|23|0|
decimal64|quantize|420|8|0|
decimal64|randombound32|2177|223|0|
decimal64|randoms|3235|765|0|
decimal64|reduce|106|0|0|
decimal64|remainder|238|11|0|
decimal64|remaindernear|252|11|0|
decimal64|rescale|199|4|0|
decimal64|rounding|224|504|0|
decimal64|samequantum|64|0|0|
decimal64|squareroot|2817|0|0|
decimal64|subtract|303|216|0|
decimal64|testall|0|0|0|
decimal64|tointegral|70|0|0|
decimal64|trim|93|0|0|
decimal64| |13823|2341|0|

</details>
<details>
<summary>decimal 128</summary>

|Type|Operation|Passed|Failed|Skipped|
|:---|:--------|:----:|:----:|:-----:|
decimal128|abs|56|3|0|
decimal128|add|236|156|0|
decimal128|base|536|238|0|
decimal128|compare|413|0|0|
decimal128|comparetotal|439|16|0|
decimal128|divide|171|19|0|
decimal128|divideint|161|12|0|
decimal128|exp|318|1|0|
decimal128|fma|9|0|0|
decimal128|inexact|57|63|0|
decimal128|ln|303|10|0|
decimal128|log10|305|8|0|
decimal128|max|61|6|0|
decimal128|min|61|6|0|
decimal128|minus|42|3|0|
decimal128|multiply|169|23|0|
decimal128|plus|61|3|0|
decimal128|power|236|23|0|
decimal128|quantize|422|6|0|
decimal128|randombound32|2326|74|0|
decimal128|randoms|3042|958|0|
decimal128|reduce|106|0|0|
decimal128|remainder|238|11|0|
decimal128|remaindernear|252|11|0|
decimal128|rescale|199|4|0|
decimal128|rounding|210|518|0|
decimal128|samequantum|64|0|0|
decimal128|squareroot|2817|0|0|
decimal128|subtract|269|250|0|
decimal128|testall|0|0|0|
decimal128|tointegral|70|0|0|
decimal128|trim|93|0|0|
decimal128| |13742|2422|0|

</details>

## Extended Arithmetic

<details>
<summary>decimal 32</summary>

|Type|Operation|Passed|Failed|Skipped|
|:---|:--------|:----:|:----:|:-----:|
decimal32|abs|89|0|0|
decimal32|add|1862|234|4|
decimal32|and|217|62|0|
decimal32|base|556|598|16|
decimal32|clamp|0|0|132|
decimal32|class|52|32|0|
decimal32|compare|612|27|0|
decimal32|comparesig|598|27|0|
decimal32|comparetotal|533|137|0|
decimal32|comparetotmag|524|140|0|
decimal32|copy|43|0|0|
decimal32|copyabs|43|0|0|
decimal32|copynegate|43|0|0|
decimal32|copysign|111|0|0|
decimal32|ddAbs|75|0|0|
decimal32|ddAdd|994|95|2|
decimal32|ddAnd|215|72|0|
decimal32|ddBase|455|492|0|
decimal32|ddCanonical|125|21|84|
decimal32|ddClass|26|16|0|
decimal32|ddCompare|645|4|0|
decimal32|ddCompareSig|555|4|0|
decimal32|ddCompareTotal|513|100|0|
decimal32|ddCompareTotalMag|513|100|0|
decimal32|ddCopy|43|0|0|
decimal32|ddCopyAbs|43|0|0|
decimal32|ddCopyNegate|43|0|0|
decimal32|ddCopySign|107|0|0|
decimal32|ddDivide|702|15|0|
decimal32|ddDivideInt|326|47|0|
decimal32|ddEncode|0|0|376|
decimal32|ddFMA|1261|115|2|
decimal32|ddInvert|83|68|0|
decimal32|ddLogB|92|16|0|
decimal32|ddMax|254|2|0|
decimal32|ddMaxMag|240|2|0|
decimal32|ddMin|245|2|0|
decimal32|ddMinMag|231|2|0|
decimal32|ddMinus|43|0|0|
decimal32|ddMultiply|444|2|0|
decimal32|ddNextMinus|12|72|0|
decimal32|ddNextPlus|12|72|0|
decimal32|ddNextToward|187|117|0|
decimal32|ddOr|195|42|0|
decimal32|ddPlus|43|0|0|
decimal32|ddQuantize|635|48|0|
decimal32|ddReduce|130|4|0|
decimal32|ddRemainder|437|68|0|
decimal32|ddRemainderNear|461|68|0|
decimal32|ddRotate|69|143|0|
decimal32|ddSameQuantum|325|8|0|
decimal32|ddScaleB|180|4|0|
decimal32|ddShift|70|142|0|
decimal32|ddSubtract|434|82|0|
decimal32|ddToIntegral|176|2|0|
decimal32|ddXor|222|56|0|
decimal32|decDouble|0|0|0|
decimal32|decQuad|0|0|0|
decimal32|decSingle|0|0|0|
decimal32|divide|616|15|0|
decimal32|divideint|324|65|0|
decimal32|dqAbs|75|0|0|
decimal32|dqAdd|920|90|2|
decimal32|dqAnd|215|142|0|
decimal32|dqBase|440|488|0|
decimal32|dqCanonical|112|18|114|
decimal32|dqClass|26|16|0|
decimal32|dqCompare|655|4|0|
decimal32|dqCompareSig|555|4|0|
decimal32|dqCompareTotal|513|100|0|
decimal32|dqCompareTotalMag|513|100|0|
decimal32|dqCopy|43|0|0|
decimal32|dqCopyAbs|43|0|0|
decimal32|dqCopyNegate|43|0|0|
decimal32|dqCopySign|107|0|0|
decimal32|dqDivide|665|23|0|
decimal32|dqDivideInt|326|48|0|
decimal32|dqEncode|1|0|367|
decimal32|dqFMA|1335|114|2|
decimal32|dqInvert|83|110|0|
decimal32|dqLogB|93|16|0|
decimal32|dqMax|254|2|0|
decimal32|dqMaxMag|240|2|0|
decimal32|dqMin|245|2|0|
decimal32|dqMinMag|231|2|0|
decimal32|dqMinus|43|0|0|
decimal32|dqMultiply|471|2|0|
decimal32|dqNextMinus|12|72|0|
decimal32|dqNextPlus|12|72|0|
decimal32|dqNextToward|187|117|0|
decimal32|dqOr|195|146|0|
decimal32|dqPlus|43|0|0|
decimal32|dqQuantize|635|51|0|
decimal32|dqReduce|130|4|0|
decimal32|dqRemainder|436|64|0|
decimal32|dqRemainderNear|461|69|0|
decimal32|dqRotate|69|179|0|
decimal32|dqSameQuantum|325|8|0|
decimal32|dqScaleB|198|4|0|
decimal32|dqShift|70|178|0|
decimal32|dqSubtract|438|82|0|
decimal32|dqToIntegral|176|2|0|
decimal32|dqXor|222|126|0|
decimal32|dsBase|652|257|0|
decimal32|dsEncode|0|0|268|
decimal32|exp|430|10|0|
decimal32|fma|2373|237|2|
decimal32|inexact|130|22|0|
decimal32|invert|83|45|0|
decimal32|ln|374|40|0|
decimal32|log10|328|61|0|
decimal32|logb|98|30|0|
decimal32|max|319|8|0|
decimal32|maxmag|304|8|0|
decimal32|min|309|8|0|
decimal32|minmag|295|8|0|
decimal32|minus|113|0|0|
decimal32|multiply|508|13|0|
decimal32|nextminus|12|92|0|
decimal32|nextplus|12|94|0|
decimal32|nexttoward|191|150|0|
decimal32|or|222|54|0|
decimal32|plus|122|0|0|
decimal32|power|1026|181|0|
decimal32|powersqrt|2826|30|0|
decimal32|quantize|672|103|0|
decimal32|randombound32|2138|262|0|
decimal32|randoms|3503|497|0|
decimal32|reduce|163|5|0|
decimal32|remainder|486|31|0|
decimal32|remaindernear|406|40|0|
decimal32|rescale|504|87|26|
decimal32|rotate|70|125|0|
decimal32|rounding|781|249|0|
decimal32|samequantum|325|8|0|
decimal32|scaleb|145|10|0|
decimal32|shift|71|129|0|
decimal32|squareroot|3225|361|0|
decimal32|subtract|559|122|0|
decimal32|testall|0|0|0|
decimal32|tointegral|153|15|0|
decimal32|tointegralx|180|0|0|
decimal32|trim|110|0|0|
decimal32|xor|223|54|0|
decimal32| |54381|9343|1397|

</details>
<details>
<summary>decimal 64</summary>

|Type|Operation|Passed|Failed|Skipped|
|:---|:--------|:----:|:----:|:-----:|
decimal64|abs|86|3|0|
decimal64|add|1795|301|4|
decimal64|and|275|4|0|
decimal64|base|602|552|16|
decimal64|clamp|0|0|132|
decimal64|class|70|14|0|
decimal64|compare|627|12|0|
decimal64|comparesig|613|12|0|
decimal64|comparetotal|548|122|0|
decimal64|comparetotmag|539|125|0|
decimal64|copy|43|0|0|
decimal64|copyabs|43|0|0|
decimal64|copynegate|43|0|0|
decimal64|copysign|111|0|0|
decimal64|ddAbs|75|0|0|
decimal64|ddAdd|1089|0|2|
decimal64|ddAnd|287|0|0|
decimal64|ddBase|690|257|0|
decimal64|ddCanonical|125|21|84|
decimal64|ddClass|42|0|0|
decimal64|ddCompare|649|0|0|
decimal64|ddCompareSig|559|0|0|
decimal64|ddCompareTotal|515|98|0|
decimal64|ddCompareTotalMag|515|98|0|
decimal64|ddCopy|43|0|0|
decimal64|ddCopyAbs|43|0|0|
decimal64|ddCopyNegate|43|0|0|
decimal64|ddCopySign|107|0|0|
decimal64|ddDivide|717|0|0|
decimal64|ddDivideInt|322|51|0|
decimal64|ddEncode|0|0|376|
decimal64|ddFMA|1376|0|2|
decimal64|ddInvert|151|0|0|
decimal64|ddLogB|108|0|0|
decimal64|ddMax|254|2|0|
decimal64|ddMaxMag|240|2|0|
decimal64|ddMin|245|2|0|
decimal64|ddMinMag|231|2|0|
decimal64|ddMinus|43|0|0|
decimal64|ddMultiply|446|0|0|
decimal64|ddNextMinus|84|0|0|
decimal64|ddNextPlus|84|0|0|
decimal64|ddNextToward|304|0|0|
decimal64|ddOr|237|0|0|
decimal64|ddPlus|43|0|0|
decimal64|ddQuantize|683|0|0|
decimal64|ddReduce|124|10|0|
decimal64|ddRemainder|498|7|0|
decimal64|ddRemainderNear|522|7|0|
decimal64|ddRotate|111|101|0|
decimal64|ddSameQuantum|333|0|0|
decimal64|ddScaleB|180|4|0|
decimal64|ddShift|111|101|0|
decimal64|ddSubtract|516|0|0|
decimal64|ddToIntegral|176|2|0|
decimal64|ddXor|278|0|0|
decimal64|decDouble|0|0|0|
decimal64|decQuad|0|0|0|
decimal64|decSingle|0|0|0|
decimal64|divide|603|28|0|
decimal64|divideint|324|65|0|
decimal64|dqAbs|75|0|0|
decimal64|dqAdd|940|70|2|
decimal64|dqAnd|280|77|0|
decimal64|dqBase|481|447|0|
decimal64|dqCanonical|112|18|114|
decimal64|dqClass|28|14|0|
decimal64|dqCompare|657|2|0|
decimal64|dqCompareSig|557|2|0|
decimal64|dqCompareTotal|515|98|0|
decimal64|dqCompareTotalMag|515|98|0|
decimal64|dqCopy|43|0|0|
decimal64|dqCopyAbs|43|0|0|
decimal64|dqCopyNegate|43|0|0|
decimal64|dqCopySign|107|0|0|
decimal64|dqDivide|669|19|0|
decimal64|dqDivideInt|322|52|0|
decimal64|dqEncode|1|0|367|
decimal64|dqFMA|1357|92|2|
decimal64|dqInvert|83|110|0|
decimal64|dqLogB|94|15|0|
decimal64|dqMax|254|2|0|
decimal64|dqMaxMag|240|2|0|
decimal64|dqMin|245|2|0|
decimal64|dqMinMag|231|2|0|
decimal64|dqMinus|43|0|0|
decimal64|dqMultiply|472|1|0|
decimal64|dqNextMinus|12|72|0|
decimal64|dqNextPlus|12|72|0|
decimal64|dqNextToward|187|117|0|
decimal64|dqOr|230|111|0|
decimal64|dqPlus|43|0|0|
decimal64|dqQuantize|676|10|0|
decimal64|dqReduce|130|4|0|
decimal64|dqRemainder|459|41|0|
decimal64|dqRemainderNear|487|43|0|
decimal64|dqRotate|69|179|0|
decimal64|dqSameQuantum|325|8|0|
decimal64|dqScaleB|198|4|0|
decimal64|dqShift|70|178|0|
decimal64|dqSubtract|512|8|0|
decimal64|dqToIntegral|176|2|0|
decimal64|dqXor|271|77|0|
decimal64|dsBase|501|408|0|
decimal64|dsEncode|0|0|268|
decimal64|exp|433|7|0|
decimal64|fma|2294|316|2|
decimal64|inexact|92|60|0|
decimal64|invert|83|45|0|
decimal64|ln|393|21|0|
decimal64|log10|348|41|0|
decimal64|logb|101|27|0|
decimal64|max|313|14|0|
decimal64|maxmag|292|20|0|
decimal64|min|303|14|0|
decimal64|minmag|295|8|0|
decimal64|minus|110|3|0|
decimal64|multiply|491|30|0|
decimal64|nextminus|12|92|0|
decimal64|nextplus|12|94|0|
decimal64|nexttoward|189|152|0|
decimal64|or|264|12|0|
decimal64|plus|119|3|0|
decimal64|power|1076|131|0|
decimal64|powersqrt|2847|9|0|
decimal64|quantize|706|69|0|
decimal64|randombound32|2141|259|0|
decimal64|randoms|3237|763|0|
decimal64|reduce|163|5|0|
decimal64|remainder|504|13|0|
decimal64|remaindernear|427|19|0|
decimal64|rescale|526|67|24|
decimal64|rotate|70|125|0|
decimal64|rounding|413|617|0|
decimal64|samequantum|325|8|0|
decimal64|scaleb|149|6|0|
decimal64|shift|86|114|0|
decimal64|squareroot|3275|311|0|
decimal64|subtract|525|156|0|
decimal64|testall|0|0|0|
decimal64|tointegral|153|15|0|
decimal64|tointegralx|180|0|0|
decimal64|trim|110|0|0|
decimal64|xor|266|11|0|
decimal64| |55609|8117|1395|

</details>
<details>
<summary>decimal 128</summary>

|Type|Operation|Passed|Failed|Skipped|
|:---|:--------|:----:|:----:|:-----:|
decimal128|abs|74|15|0|
decimal128|add|1296|800|4|
decimal128|and|275|4|0|
decimal128|base|610|544|16|
decimal128|clamp|0|0|132|
decimal128|class|72|12|0|
decimal128|compare|627|12|0|
decimal128|comparesig|613|12|0|
decimal128|comparetotal|561|109|0|
decimal128|comparetotmag|552|112|0|
decimal128|copy|43|0|0|
decimal128|copyabs|43|0|0|
decimal128|copynegate|43|0|0|
decimal128|copysign|111|0|0|
decimal128|ddAbs|75|0|0|
decimal128|ddAdd|605|484|2|
decimal128|ddAnd|287|0|0|
decimal128|ddBase|511|436|0|
decimal128|ddCanonical|125|21|84|
decimal128|ddClass|36|6|0|
decimal128|ddCompare|649|0|0|
decimal128|ddCompareSig|559|0|0|
decimal128|ddCompareTotal|515|98|0|
decimal128|ddCompareTotalMag|515|98|0|
decimal128|ddCopy|43|0|0|
decimal128|ddCopyAbs|43|0|0|
decimal128|ddCopyNegate|43|0|0|
decimal128|ddCopySign|107|0|0|
decimal128|ddDivide|673|44|0|
decimal128|ddDivideInt|322|51|0|
decimal128|ddEncode|0|0|376|
decimal128|ddFMA|931|445|2|
decimal128|ddInvert|83|68|0|
decimal128|ddLogB|108|0|0|
decimal128|ddMax|254|2|0|
decimal128|ddMaxMag|240|2|0|
decimal128|ddMin|245|2|0|
decimal128|ddMinMag|231|2|0|
decimal128|ddMinus|43|0|0|
decimal128|ddMultiply|370|76|0|
decimal128|ddNextMinus|10|74|0|
decimal128|ddNextPlus|10|74|0|
decimal128|ddNextToward|142|162|0|
decimal128|ddOr|237|0|0|
decimal128|ddPlus|43|0|0|
decimal128|ddQuantize|671|12|0|
decimal128|ddReduce|124|10|0|
decimal128|ddRemainder|498|7|0|
decimal128|ddRemainderNear|522|7|0|
decimal128|ddRotate|70|142|0|
decimal128|ddSameQuantum|333|0|0|
decimal128|ddScaleB|165|19|0|
decimal128|ddShift|92|120|0|
decimal128|ddSubtract|385|131|0|
decimal128|ddToIntegral|176|2|0|
decimal128|ddXor|278|0|0|
decimal128|decDouble|0|0|0|
decimal128|decQuad|0|0|0|
decimal128|decSingle|0|0|0|
decimal128|divide|603|28|0|
decimal128|divideint|324|65|0|
decimal128|dqAbs|75|0|0|
decimal128|dqAdd|1010|0|2|
decimal128|dqAnd|357|0|0|
decimal128|dqBase|669|259|0|
decimal128|dqCanonical|112|18|114|
decimal128|dqClass|42|0|0|
decimal128|dqCompare|659|0|0|
decimal128|dqCompareSig|559|0|0|
decimal128|dqCompareTotal|515|98|0|
decimal128|dqCompareTotalMag|515|98|0|
decimal128|dqCopy|43|0|0|
decimal128|dqCopyAbs|43|0|0|
decimal128|dqCopyNegate|43|0|0|
decimal128|dqCopySign|107|0|0|
decimal128|dqDivide|688|0|0|
decimal128|dqDivideInt|323|51|0|
decimal128|dqEncode|1|0|367|
decimal128|dqFMA|1447|2|2|
decimal128|dqInvert|193|0|0|
decimal128|dqLogB|109|0|0|
decimal128|dqMax|254|2|0|
decimal128|dqMaxMag|240|2|0|
decimal128|dqMin|245|2|0|
decimal128|dqMinMag|231|2|0|
decimal128|dqMinus|43|0|0|
decimal128|dqMultiply|473|0|0|
decimal128|dqNextMinus|84|0|0|
decimal128|dqNextPlus|84|0|0|
decimal128|dqNextToward|304|0|0|
decimal128|dqOr|341|0|0|
decimal128|dqPlus|43|0|0|
decimal128|dqQuantize|686|0|0|
decimal128|dqReduce|124|10|0|
decimal128|dqRemainder|493|7|0|
decimal128|dqRemainderNear|523|7|0|
decimal128|dqRotate|147|101|0|
decimal128|dqSameQuantum|333|0|0|
decimal128|dqScaleB|198|4|0|
decimal128|dqShift|147|101|0|
decimal128|dqSubtract|520|0|0|
decimal128|dqToIntegral|176|2|0|
decimal128|dqXor|348|0|0|
decimal128|dsBase|496|413|0|
decimal128|dsEncode|0|0|268|
decimal128|exp|408|32|0|
decimal128|fma|1752|858|2|
decimal128|inexact|75|77|0|
decimal128|invert|83|45|0|
decimal128|ln|399|15|0|
decimal128|log10|355|34|0|
decimal128|logb|114|14|0|
decimal128|max|307|20|0|
decimal128|maxmag|280|32|0|
decimal128|min|297|20|0|
decimal128|minmag|295|8|0|
decimal128|minus|98|15|0|
decimal128|multiply|451|70|0|
decimal128|nextminus|10|94|0|
decimal128|nextplus|10|96|0|
decimal128|nexttoward|151|190|0|
decimal128|or|264|12|0|
decimal128|plus|103|19|0|
decimal128|power|1032|175|0|
decimal128|powersqrt|2847|9|0|
decimal128|quantize|708|67|0|
decimal128|randombound32|2170|230|0|
decimal128|randoms|3044|956|0|
decimal128|reduce|151|17|0|
decimal128|remainder|504|13|0|
decimal128|remaindernear|429|17|0|
decimal128|rescale|528|65|24|
decimal128|rotate|70|125|0|
decimal128|rounding|395|635|0|
decimal128|samequantum|333|0|0|
decimal128|scaleb|137|18|0|
decimal128|shift|86|114|0|
decimal128|squareroot|3245|341|0|
decimal128|subtract|473|208|0|
decimal128|testall|0|0|0|
decimal128|tointegral|153|15|0|
decimal128|tointegralx|180|0|0|
decimal128|trim|110|0|0|
decimal128|xor|266|11|0|
decimal128| |53572|10154|1395|

</details>
