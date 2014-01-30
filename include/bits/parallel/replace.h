#ifndef STD_PARALLEL_ALGOS
#error "please include <parallel> instead of this file"
#endif

#include <algorithm> // std::replace
#include <thread>    // std::thread

namespace std {

template<class ExecutionPolicy, class ForwardIt, class T>
void replace(ExecutionPolicy &&exec, 
             ForwardIt first, ForwardIt last, 
             const T& old_value, const T& new_value){
    // function to wrap
    static const auto __replace = 
      (void(*)(ForwardIt, ForwardIt, const T&, const T&))&replace<ForwardIt, T>;

    switch (exec) {
    case execution_policy::seq:
        __replace(first, last, old_value, new_value);
        break;
    case execution_policy::par:
        detail::diffract(first, last, __replace, old_value, new_value);
        break;
    }
}

template<class ExecutionPolicy, class ForwardIt, class Predicate, class T>
void replace_if(ExecutionPolicy &&exec, 
                ForwardIt first, ForwardIt last,
                Predicate pred, const T& new_value){
    // function to wrap
    static const auto __replace_if = 
      (void(*)(ForwardIt, ForwardIt, Predicate, const T&))&replace_if<ForwardIt, Predicate, T>;

    switch (exec) {
    case execution_policy::seq:
        __replace_if(first, last, pred, new_value);
        break;
    case execution_policy::par:
        detail::diffract(first, last, __replace_if, pred, new_value);
        break;
    }
 
}

}
