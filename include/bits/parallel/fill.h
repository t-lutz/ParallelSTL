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
        // segment the iteration space: if there is not enough elements we do not
        // divide the iteration space.
        const unsigned int segment_size = 
           distance(first, last) > (thread::hardware_concurrency()) ?
           distance(first, last) / (thread::hardware_concurrency()) : 1;

        // thread pool
        vector<thread> pool; 
        pool.reserve(segment_size);

        // divide the iteration space and delegate to threads.
        ForwardIt it = first;
        for(; it < last - segment_size; it += segment_size){
            pool.emplace_back(thread(__fill, it, it + segment_size, value));
        }
        pool.push_back(std::thread(__fill, it, last, value));

        // wait for the pool to finish
        for(auto &t : pool) t.join();

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
    static const std::function<OutputIt(OutputIt, Size, const T&)> __fill_n =
      (OutputIt(*)(OutputIt, Size, const T&))&fill_n<OutputIt, Size, T>;

    switch (exec) {
    case execution_policy::seq:
        __fill_n(first, count, value);
        break;
    case execution_policy::par:
        // segment the iteration space: if there is not enough elements we do not
        // divide the iteration space.
        const unsigned int segment_size = 
           count > (thread::hardware_concurrency()) ?
           count / (thread::hardware_concurrency()) : 1;

        // thread pool
        vector<thread> pool; 
        pool.reserve(segment_size);

        // divide the iteration space and delegate to threads.
        OutputIt it = first, end = it + count;
        for(; it < end - segment_size; it += segment_size){
            pool.emplace_back(thread(__fill_n, it, segment_size, value));
        }
        pool.push_back(std::thread(__fill_n, it, count - segment_size, value));

        // wait for the pool to finish
        for(auto &t : pool) t.join();

        // inplace algo, nothing to do here.
        break;
    }
}

}
