#ifndef STD_PARALLEL_ALGOS
#error "please include <parallel> instead of this file"
#endif

#include <algorithm> // std::fill
#include <thread>    // std::thread

namespace std {

/**
 * @brief Parallel implementation of std::fill.
 * @param exec The preferred execution policy
 * @param first Beginning of the range.
 * @param last End of the range.
 * @param value Value to set.
 */
template<class ForwardIt, class T>
void fill(execution_policy &&exec,
          ForwardIt first, ForwardIt last,
          const T& value){
    // function to wrap
    static const std::function<void(ForwardIt, ForwardIt, const T&)> __fill = 
      (void(*)(ForwardIt, ForwardIt, const T&))&fill<ForwardIt, T>;

    switch (exec) {
    case execution_policy::seq:
        __fill(first, last, value);
        break;
    case execution_policy::par:
        detail::diffract(first, last, __fill, value);

        // inplace algo, nothing to do here.
        break;
    }
}


/**
 * @brief Parallel implementation of std::fill_n.
 * @param exec The preferred execution policy
 * @param first Beginning of the range.
 * @param count the number of elements to set.
 * @param value Value to set.
 */
template< class OutputIt, class Size, class T >
OutputIt fill_n(execution_policy &&exec,
                OutputIt first, Size count, 
                const T& value){
    // function to wrap
    //static const std::function<OutputIt(OutputIt, Size, const T&)> __fill_n =
    //  (OutputIt(*)(OutputIt, Size, const T&))&fill_n<OutputIt, Size, T>;

    static const std::function<void(OutputIt, OutputIt, const T&)> __fill =
      (void(*)(OutputIt, OutputIt, const T&))&fill<OutputIt, T>;

    switch (exec) {
    case execution_policy::seq:
        __fill(first, first + count, value);
        return std::max(first, first + count);
    case execution_policy::par:
        detail::diffract(first, first + count, __fill, value);

        // inplace algo, nothing to do here.
        return std::max(first, first + count);
    }
}

}
