#ifndef STD_PARALLEL_ALGOS
#error "please include <parallel> instead of this file"
#endif

#include <algorithm> // std::for_each
#include <thread>    // std::thread

namespace std {

/**
 * @brief Parallel implementation of std::for_each.
 * @param exec The preferred execution policy
 * @param first Beginning of the range.
 * @param last End of the range.
 * @param f The functor to apply.
 * @return The applied function.
 */
template<class InputIterator, class UnaryFunction>
UnaryFunction for_each(execution_policy &&exec,
                       InputIterator first, InputIterator last,
                       UnaryFunction f){
    // function to wrap
    static const std::function<UnaryFunction(InputIterator, InputIterator, UnaryFunction)> __for_each =
        (UnaryFunction(*)(InputIterator, InputIterator, UnaryFunction))&for_each<InputIterator, UnaryFunction>;

    switch (exec) {
    case execution_policy::seq:
        return std::move(__for_each(first, last, f));
    case execution_policy::par:
        // segment the iteration space: if there is not enough elements we do not
        // divide the iteration space.
        const unsigned int segment_size = 
           distance(first, last) > (thread::hardware_concurrency()) ?
           distance(first, last) / (thread::hardware_concurrency()) : 
           segment_size; // is not even one per proc, we don't divide

        // thread pool
        vector<thread> pool; 
        pool.reserve((distance(first, last) / segment_size) + 1);

        // divide the iteration space and delegate to threads.
        InputIterator it = first;
        for(; it < last - segment_size; it += segment_size){
            pool.emplace_back(thread(__for_each, it, it + segment_size, std::move(f)));
        }
        pool.push_back(std::thread(__for_each, it, last, std::move(f)));

        // wait for the pool to finish
        for(auto &t : pool) t.join();

        // inplace algo, nothing to do here.

        // return functor
        return std::move(f);
    }
    return std::move(f);
}

}
