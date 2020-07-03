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
