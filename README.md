![Build](https://github.com/GaryHughes/stddecimal/workflows/Build/badge.svg)


# std::decimal

This is an implementation of the proposed C++ [ISO/IEC JTC1 SC22 WG21 N2849](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2009/n2849.pdf) std::decimal including the [ISO/IEC JTC1 SC22 WG21 N3871](http://open-std.org/JTC1/SC22/WG21/docs/papers/2014/n3871.html) revisions. It is built on the [Intel Floating Point Library](https://software.intel.com/content/www/us/en/develop/articles/pre-release-license-agreement-for-intel-decimal-floating-point-math-library.html) that does all the hard work.

# Intent

I've used [this](https://sourceforge.net/p/stddecimal/code/HEAD/tree/trunk/) implementation successfully in the past however I wanted build a modern version that relied on templates instead of macros to generate the numerous operators required.

# Status

* The initial interfaces have been implemented as a proof of concept.
* Some of the 128 bit implementation is incomplete.
* Testing is currently limited to the supplied unit tests that are primarily there to instantiate the templates and prove basic functionality.
* Testing will be expanded to include an automated test suite built using [these](http://speleotrove.com/decimal/dectest.html) test cases.
* There is currently no explicit error handling and any exceptions signalled by the Intel library are ignored.