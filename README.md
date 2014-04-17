# n3960 Implementation

### Overview

This repository contains a parallel version of the STL algorithms as a proof of concept for a C++ extension proposal. It was filed as n3554 and then became [n3850](http://isocpp.org/blog/2014/01/n3850), then [n3960](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3960.pdf).

This project is in a very early stage. We plan to first implement an integration suite based on the current STL algorithms, then implement the sequential policy and finally a parallel policy based on std::thread.

We will also try to draft a documentation in the wiki, largely inspired by the [cppreference](http://en.cppreference.com) website. 

The goal is to make is as easy as possible for people to implement and test their own execution policies, once the standard parallel and sequential ones are implemented.

### Reference

* [Official TS](http://isocpp.org/blog/2014/01/n3850), most recent one [here](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3960.pdf).
* [Jared Hoberock's implementation](https://github.com/n3554/n3554) based on thrust.
* [Microsoft's implementation](https://parallelstl.codeplex.com) using Windows Foundation utilities.
* [GCC's parallel implementation](http://gcc.gnu.org/onlinedocs/libstdc++/manual/parallel_mode.html) of the STL algorithms.


