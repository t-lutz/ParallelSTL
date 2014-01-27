#ifndef STD_PARALLEL_ALGOS
#error "please include <parallel> instead of this file"
#endif

#include <algorithm> // std::for_each
#include <thread>    // std::thread

namespace std {

/**
 * @brief Applies the given function object f to the result of dereferencing 
 *        every iterator in the range [first, last), in an unspecified order.
 *
 *        If InputIt is a mutable iterator, f may modify the elements of the range 
 *        through the dereferenced iterator. If f returns a result, the result 
 *        is ignored.
 * @param exec the Execution Policy.
 * @param first the beginning of the range.
 * @param last the end of the range.
 * @param f the unary function object to be applied.
 * @return std::move(f)
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
        detail::diffract(first, last, __for_each, std::move(f));

        // return functor
        return std::move(f);
    }
    return std::move(f);
}

}
