#ifndef STD_PARALLEL_ALGOS
#error "please include <parallel> instead of this file"
#endif

#include <algorithm> // std::generate
#include <thread>    // std::thread

namespace std {

/**
 * @brief Parallel implementation of std::generate.
 * @param exec The preferred execution policy
 * @param first Beginning of the range.
 * @param last End of the range.
 * @param gen The value generator.
 */
template<class ExecutionPolicy, class ForwardIt, class Generator>
void generate(ExecutionPolicy &&exec, 
              ForwardIt first, ForwardIt last, 
              Generator gen){
    // function to wrap
    static const std::function<void(ForwardIt, ForwardIt, Generator)> __generate = 
      (void(*)(ForwardIt, ForwardIt, Generator))&generate<ForwardIt, Generator>;

    switch (exec) {
    case execution_policy::seq:
        __generate(first, last, gen);
        break;
    case execution_policy::par:
        detail::diffract(first, last, __generate, gen);

        // inplace algo, nothing to do here.
        break;
    }
}


template<class ExecutionPolicy, class OutputIterator, class Size, class Generator>
OutputIterator generate_n(ExecutionPolicy &&exec, 
                          OutputIterator first, Size n, 
                          Generator gen){
    // function to wrap
    static const std::function<void(OutputIterator, OutputIterator, Generator)> __generate = 
      (void(*)(OutputIterator, OutputIterator, Generator))&generate<OutputIterator, Generator>;

    switch (exec) {
    case execution_policy::seq:
        __generate(first, first + n, gen);
        break;
    case execution_policy::par:
        detail::diffract(first, first + n, __generate, gen);

        // inplace algo, nothing to do here.
        break;
    }
}

}
