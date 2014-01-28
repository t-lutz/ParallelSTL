#ifndef STD_PARALLEL_ALGOS
#error "please include <parallel> instead of this file"
#endif

#include <algorithm> // std::replace
#include <thread>    // std::thread
#include <cassert>
#include <functional>

namespace std {

template<class InputIterator>
typename iterator_traits<InputIterator>::value_type
reduce(InputIterator first, InputIterator last){
    return std::accumulate(first, last, typename iterator_traits<InputIterator>::value_type{0});
}

template<class ExecutionPolicy, class InputIterator>
typename iterator_traits<InputIterator>::value_type
reduce(ExecutionPolicy &&exec, InputIterator first, InputIterator last){
    //static auto __acc = 
    //    (typename iterator_traits<InputIterator>::value_type(*)(InputIterator first, InputIterator last, )
    switch (exec) {
    case execution_policy::seq:
        return std::accumulate(first, last, typename iterator_traits<InputIterator>::value_type{0});
    case execution_policy::par:
        return detail::diffract_gather(first, last, 
                                       std::accumulate<InputIterator, typename iterator_traits<InputIterator>::value_type>, 
                                       std::plus<typename iterator_traits<InputIterator>::value_type>());
    }

}

template<class InputIterator, class T>
T reduce(InputIterator first, InputIterator last, T init){
    return std::accumulate(first, last, init);
}

template<class ExecutionPolicy, class InputIterator, class T>
T reduce(ExecutionPolicy &&exec,
         InputIterator first, InputIterator last, T init){
    switch (exec) {
    case execution_policy::seq:
        return std::accumulate(first, last, init);
        break;
    case execution_policy::par:
        assert(false && "Not implemented yet, needs diffract_gather");
        break;
    }


}

template<class InputIterator, class T, class BinaryOperation>
T reduce(InputIterator first, InputIterator last, 
         T init, BinaryOperation binary_op){
    return std::accumulate(first, last, init, binary_op);
}

template<class ExecutionPolicy, class InputIterator, class T, class BinaryOperation>
T reduce(ExecutionPolicy &&exec,
         InputIterator first, InputIterator last, T init,
         BinaryOperation binary_op){
    switch (exec) {
    case execution_policy::seq:
        return std::accumulate(first, last, init, binary_op);
        break;
    case execution_policy::par:
        assert(false && "Not implemented yet, needs diffract_gather");
        break;
    }
}

}
