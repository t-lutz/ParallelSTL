#ifndef STD_PARALLEL_POLICY_SEQUENTIAL
#define STD_PARALLEL_POLICY_SEQUENTIAL

#include <algorithm>

namespace std {

namespace parallel {

namespace policy {

static struct seq {
  // Algorithm

  // non-modifying sequence operations:
  template<class InputIterator, class Predicate>
    bool all_of(InputIterator first, InputIterator last, Predicate pred){
    return std::all_of(first, last, pred);
  }


  template<class InputIterator, class Predicate>
    bool any_of(InputIterator first, InputIterator last, Predicate pred){
    return std::any_of(first, last, pred);
  }


  template<class InputIterator, class Predicate>
    bool none_of(InputIterator first, InputIterator last, Predicate pred){
    return std::none_of(first, last, pred);
  }

  template<class InputIterator, class Function>
    Function for_each(InputIterator first, InputIterator last,
                      Function f){
    return std::for_each(first, last, f);
  }

  template<class InputIterator, class Size, class Function>
    Function for_each_n(InputIterator first, Size n,
                        Function f){
    return std::for_each(first, first + n, f);
  }



  template<class InputIterator, class T>
    InputIterator find(InputIterator first, InputIterator last,
                       const T& value){
    return std::find(first, last, value);
  }


  template<class InputIterator, class Predicate>
    InputIterator find_if(InputIterator first, InputIterator last,
                          Predicate pred){
    return std::find_if(first, last, pred);
  }


  template<class InputIterator, class Predicate>
    InputIterator find_if_not(InputIterator first, InputIterator last,
                              Predicate pred){
    return std::find_if_not(first, last, pred);
  }



  template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1
      find_end(ForwardIterator1 first1, ForwardIterator1 last1,
               ForwardIterator2 first2, ForwardIterator2 last2){
    return std::find_end(first1, last1, first2, last2);
  }


  template<class ForwardIterator1, class ForwardIterator2,
           class BinaryPredicate>
    ForwardIterator1
      find_end(ForwardIterator1 first1, ForwardIterator1 last1,
               ForwardIterator2 first2, ForwardIterator2 last2,
               BinaryPredicate pred){
    return std::find_end(first1, last1, first2, last2, pred);
  }



  template<class InputIterator, class ForwardIterator>
    InputIterator
      find_first_of(InputIterator first1, InputIterator last1,
                    ForwardIterator first2, ForwardIterator last2){
    return std::find_first_of(first1, last1, first2, last2);
  }


  template<class InputIterator, class ForwardIterator,
           class BinaryPredicate>
    InputIterator
      find_first_of(InputIterator first1, InputIterator last1,
                    ForwardIterator first2, ForwardIterator last2,
                    BinaryPredicate pred){
    return std::find_first_of(first1, last1, first2, last2, pred);
  }



  template<class ForwardIterator>
    ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last){
    return std::adjacent_find(first, last);
  }


  template<class ForwardIterator, class BinaryPredicate>
    ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last,
                                  BinaryPredicate pred){
    return std::adjacent_find(first, last, pred);
  }



  template<class InputIterator, class EqualityComparable>
    typename iterator_traits<InputIterator>::difference_type
      count(InputIterator first, InputIterator last, const EqualityComparable &value){
    return std::count(first, last, value);
  }


  template<class InputIterator, class Predicate>
    typename iterator_traits<InputIterator>::difference_type
      count_if(InputIterator first, InputIterator last, Predicate pred){
    return std::count_if(first, last, pred);
  }



  template<class InputIterator1, class InputIterator2>
    pair<InputIterator1,InputIterator2>
      mismatch(InputIterator1 first1, InputIterator1 last1, 
               InputIterator2 first2){
    return std::mismatch(first1, last1, first2);
  }


  template<class InputIterator1, class InputIterator2, class BinaryPredicate>
    pair<InputIterator1,InputIterator2>
      mismatch(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, BinaryPredicate pred){
    return std::mismatch(first1, last1, first2, pred);
  }



  template<class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2){
    return std::equal(first1, last1, first2);
  }


  template<class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, BinaryPredicate pred){
    return std::equal(first1, last1, first2, pred);
  }



  template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                            ForwardIterator2 first2, ForwardIterator2 last2){
    return std::search(first1, last1, first2, last2);
  }


  template<class ForwardIterator1, class ForwardIterator2,
           class BinaryPredicate>
    ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                            ForwardIterator2 first2, ForwardIterator2 last2,
                            BinaryPredicate pred){
    return std::search(first1, last1, first2, last2, pred);
  }


  template<class ForwardIterator, class Size, class T>
    ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count,
                             const T& value){
    return std::search_n(first, last, count, value);
  }


  template<class ForwardIterator, class Size, class T, class BinaryPredicate>
    ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count,
                             const T& value, BinaryPredicate pred){
    return std::search_n(first, last, count, value, pred);
  }



  // modifying sequence operations:
  // copy:
  template<class InputIterator, class OutputIterator>
    OutputIterator copy(InputIterator first, InputIterator last,
                        OutputIterator result){
    return std::copy(first, last, result);
  }



  template<class InputIterator, class Size, class OutputIterator>
    OutputIterator copy_n(InputIterator first, Size n,
                          OutputIterator result){
    return std::copy_n(first, n, result);
  }



  template<class InputIterator, class OutputIterator, class Predicate>
    OutputIterator
      copy_if(InputIterator first, InputIterator last,
              OutputIterator result, Predicate pred){
    return std::copy_if(first, last, result, pred);
  }



  // move:
  template<class InputIterator, class OutputIterator>
    OutputIterator
      move(InputIterator first, InputIterator last,
           OutputIterator result){
    return std::move(first, last, result);
  }



  // swap:
  template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator2
      swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1,
                  ForwardIterator1 first2){
    return std::swap_ranges(first1, last1, first2);
  }



  template<class InputIterator, class OutputIterator,
           class UnaryOperation>
    OutputIterator transform(InputIterator first, InputIterator last,
                             OutputIterator result, UnaryOperation op){
    return std::transform(first, last, result, op);
  }


  template<class InputIterator1, class InputIterator2, class OutputIterator,
           class BinaryOperation>
    OutputIterator
      transform(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, OutputIterator result,
                BinaryOperation binary_op){
    return std::transform(first1, last1, first2, result, binary_op);
  }



  template<class ForwardIterator, class T>
    void replace(ForwardIterator first, ForwardIterator last,
                 const T& old_value, const T& new_value){
    return std::replace(first, last, old_value, new_value);
  }


  template<class ForwardIterator, class Predicate, class T>
    void replace_if(ForwardIterator first, ForwardIterator last,
                    Predicate pred, const T& new_value){
    return std::replace_if(first, last, pred, new_value);
  }


  template<class InputIterator, class OutputIterator, class T>
    OutputIterator
      replace_copy(InputIterator first, InputIterator last,
                   OutputIterator result,
                   const T& old_value, const T& new_value){
    return std::replace_copy(first, last, result, old_value, new_value);
  }


  template<class InputIterator, class OutputIterator, class Predicate, class T>
    OutputIterator
      replace_copy_if(InputIterator first, InputIterator last,
                      OutputIterator result, Predicate pred,
                      const T& new_value){
    return std::replace_copy_if(first, last, result, pred, new_value);
  }



  template<class ForwardIterator, class T>
    void fill(ForwardIterator first, ForwardIterator last, const T& value){
    std::fill(first, last, value);
  }


  template<class OutputIterator, class Size, class T>
    void fill_n(OutputIterator first, Size n, const T& value){
    std::fill_n(first, n, value);
  }



  template<class ForwardIterator, class Generator>
    void generate(ForwardIterator first, ForwardIterator last, Generator gen){
    std::generate(first, last, gen);
  }


  template<class OutputIterator, class Size, class Generator>
    OutputIterator generate_n(OutputIterator first, Size n, Generator gen){
    return std::generate_n(first, n, gen);
  }



  template<class ForwardIterator, class T>
    ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& value){
    return std::remove(first, last, value);
  }


  template<class ForwardIterator, class Predicate>
    ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, Predicate pred){
    return std::remove_if(first, last, pred);
  }


  template<class InputIterator, class OutputIterator, class T>
    OutputIterator
      remove_copy(InputIterator first, InputIterator last,
                  OutputIterator result, const T& value){
    return std::remove_copy(first, last, result, value);
  }


  template<class InputIterator, class OutputIterator, class Predicate>
    OutputIterator
      remove_copy_if(InputIterator first, InputIterator last,
                     OutputIterator result, Predicate pred){
    return std::remove_copy_if(first, last, result, pred);
  }



  template<class ForwardIterator>
    ForwardIterator unique(ForwardIterator first, ForwardIterator last){
    return std::unique(first, last);
  }


  template<class ForwardIterator, typename BinaryPredicate>
    ForwardIterator unique(ForwardIterator first, ForwardIterator last,
                           BinaryPredicate pred){
    return std::unique(first, last, pred);
  } 



  template<class InputIterator, class OutputIterator>
    OutputIterator
      unique_copy(InputIterator first, InputIterator last,
                  OutputIterator result){
    return std::unique_copy(first, last, result);
  }


  template<class InputIterator, class OutputIterator, class BinaryPredicate>
    OutputIterator
      unique_copy(InputIterator first, InputIterator last,
                  OutputIterator result, BinaryPredicate pred){
    return std::unique_copy(first, last, result, pred);
  }



  template<class BidirectionalIterator>
    void reverse(BidirectionalIterator first, BidirectionalIterator last){
    std::reverse(first, last);
  }



  template<class BidirectionalIterator, class OutputIterator>
    OutputIterator
      reverse_copy(BidirectionalIterator first,
                   BidirectionalIterator last, OutputIterator result){
    return std::reverse_copy(first, last, result);
  }



  template<class ForwardIterator>
    void rotate(ForwardIterator first, ForwardIterator middle,
                           ForwardIterator last){
    std::rotate(first, middle, last);
    return first + (last - middle);
  }


  template<class ForwardIterator, class OutputIterator>
    OutputIterator
      rotate_copy(ForwardIterator first, ForwardIterator middle,
                  ForwardIterator last, OutputIterator result){
    return std::rotate_copy(first, middle, last, result);
  }



  // partitions:
  template<class InputIterator, class Predicate>
    bool is_partitioned(InputIterator first, InputIterator last, Predicate pred){
    return std::is_partitioned(first, last, pred);
  }


  template<class ForwardIterator, class Predicate>
    ForwardIterator
      partition(ForwardIterator first,
                ForwardIterator last, Predicate pred){
    return std::partition(first, last, pred);
  }


  template<class BidirectionalIterator, class Predicate>
    BidirectionalIterator
      stable_partition(BidirectionalIterator first,
                       BidirectionalIterator last, Predicate pred){
    return std::stable_partition(first, last, pred);
  }


  template<class InputIterator, class OutputIterator1,
           class OutputIterator2, class Predicate>
  pair<OutputIterator1, OutputIterator2>
  partition_copy(InputIterator first, InputIterator last,
                 OutputIterator1 out_true, OutputIterator2 out_false,
                 Predicate pred){
    return partition_copy(first, last, out_true, out_false, pred);
  }


  template<class ForwardIterator, class Predicate>
    ForwardIterator partition_point(ForwardIterator first,
                                    ForwardIterator last,
                                    Predicate pred){
    return std::partition_point(first, last, pred);
  }



  // sorting and related operations:
  // sorting:
  template<class RandomAccessIterator>
    void sort(RandomAccessIterator first, RandomAccessIterator last){
    std::sort(first, last);
  }


  template<class RandomAccessIterator, class Compare>
    void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp){
    std::sort(first, last, comp);
  }



  template<class RandomAccessIterator>
    void stable_sort(RandomAccessIterator first, RandomAccessIterator last){
    std::stable_sort(first, last);
  }


  template<class RandomAccessIterator, class Compare>
    void stable_sort(RandomAccessIterator first, RandomAccessIterator last,
                     Compare comp){
    std::stable_sort(first, last, comp);
  }



  template<class RandomAccessIterator>
    void partial_sort(RandomAccessIterator first,
                      RandomAccessIterator middle,
                      RandomAccessIterator last){
    std::partial_sort(first, middle, last);
  }


  template<class RandomAccessIterator, class Compare>
    void partial_sort(RandomAccessIterator first,
                      RandomAccessIterator middle,
                      RandomAccessIterator last,
                      Compare comp){
    std::partial_sort(first, middle, last, comp);
  }


  template<class InputIterator, class RandomAccessIterator>
    RandomAccessIterator
      partial_sort_copy(InputIterator first, InputIterator last,
                        RandomAccessIterator result_first,
                        RandomAccessIterator result_last){
    return std::partial_sort_copy(first, last, result_first, result_last);
  }


  template<class InputIterator, class RandomAccessIterator,
           class Compare>
    RandomAccessIterator
      partial_sort_copy(InputIterator first, InputIterator last,
                        RandomAccessIterator result_first,
                        RandomAccessIterator result_last,
                        Compare comp){
    return std::partial_sort_copy(first, last, result_first, result_last);
  }



  template<class ForwardIterator>
    bool is_sorted(ForwardIterator first, ForwardIterator last){
    return std::is_sorted(first, last);
  } 


  template<class ForwardIterator, class Compare>
    bool is_sorted(ForwardIterator first, ForwardIterator last,
                   Compare comp){
    return std::is_sorted(first, last, comp);
  }


  template<class ForwardIterator>
    ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last){
    return std::is_sorted_until(first, last);
  }


  template<class ForwardIterator, class Compare>
    ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last,
                                    Compare comp){
    return std::is_sorted_until(first, last, comp);
  }



  template<class RandomAccessIterator>
    void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                     RandomAccessIterator last){
    std::nth_element(first, nth, last);
  }


  template<class RandomAccessIterator, class Compare>
    void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                     RandomAccessIterator last, Compare comp){
    std::nth_element(first, nth, last, comp);
  }



  // merge:
  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      merge(InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2,
            OutputIterator result){
    return std::merge(first1, last1, first2, last2, result);
  }


  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      merge(InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2,
            OutputIterator result, Compare comp){
    return std::merge(first1, last1, first2, last2, result, comp);
  }



  template<class BidirectionalIterator>
    void inplace_merge(BidirectionalIterator first,
                       BidirectionalIterator middle,
                       BidirectionalIterator last){
    std::inplace_merge(first, middle, last);
  }


  template<class BidirectionalIterator,
           class Compare>
    void inplace_merge(BidirectionalIterator first,
                       BidirectionalIterator middle,
                       BidirectionalIterator last, Compare comp){
    std::inplace_merge(first, middle, last, comp);
  }



  // set operations:
  template<class InputIterator1, class InputIterator2>
    bool includes(InputIterator1 first1, InputIterator1 last1,
                  InputIterator2 first2, InputIterator2 last2){
    return std::includes(first1, last1, first2, last2);
  }


  template<class InputIterator1, class InputIterator2, class Compare>
    bool includes(InputIterator1 first1, InputIterator1 last1,
                  InputIterator2 first2, InputIterator2 last2,
                  Compare comp){
    return std::includes(first1, last1, first2, last2, comp);
  }



  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      set_union(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2,
                OutputIterator result){
    return std::set_union(first1, last1, first2, last2, result);
  }


  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      set_union(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2,
                OutputIterator result, Compare comp){
    return std::set_union(first1, last1, first2, last2, result, comp);
  }



  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      set_intersection(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       OutputIterator result){
    return std::set_intersection(first1, last1, first2, last2, result);
  }


  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      set_intersection(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       OutputIterator result, Compare comp){
    return std::set_intersection(first1, last1, first2, last2, result, comp);
  }



  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      set_difference(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     OutputIterator result){
    return std::set_difference(first1, last1, first2, last2, result);
  }


  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      set_difference(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     OutputIterator result, Compare comp){
    return std::set_difference(first1, last1, first2, last2, result, comp);
  }



  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                               InputIterator2 first2, InputIterator2 last2,
                               OutputIterator result){
    return std::set_symmetric_difference(first1, last1, first2, last2, result);
  }  


  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                               InputIterator2 first2, InputIterator2 last2,
                               OutputIterator result, Compare comp){
    return std::set_symmetric_difference(first1, last1, first2, last2, result, comp);
  }



  // minimum and maximum:
  template<class ForwardIterator>
    ForwardIterator min_element(ForwardIterator first, ForwardIterator last){
    return std::min_element(first, last);
  }


  template<class ForwardIterator, class Compare>
    ForwardIterator min_element(ForwardIterator first, ForwardIterator last,
                                Compare comp){
    return std::min_element(first, last, comp);
  }


  template<class ForwardIterator>
    ForwardIterator max_element(ForwardIterator first, ForwardIterator last){
    return std::max_element(first, last);
  }


  template<class ForwardIterator, class Compare>
    ForwardIterator max_element(ForwardIterator first, ForwardIterator last,
                                Compare comp){
    return std::max_element(first, last, comp);
  }


  template<class ForwardIterator>
    pair<ForwardIterator, ForwardIterator>
      minmax_element(ForwardIterator first, ForwardIterator last){
    return std::minmax_element(first, last);
  }


  template<class ForwardIterator, class Compare>
    pair<ForwardIterator, ForwardIterator>
      minmax_element(ForwardIterator first, ForwardIterator last, Compare comp){
    return std::minmax_element(first, last, comp);
  }




  template<class InputIterator1, class InputIterator2>
    bool
      lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2){
    return std::lexicographical_compare(first1, last1, first2, last2);
  }



  template<class InputIterator1, class InputIterator2, class Compare>
    bool
      lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2,
                              Compare comp){
    return std::lexicographical_compare(first1, last1, first2, last2, comp);
  }

  // Utilities
   template<class InputIterator>
    typename iterator_traits<InputIterator>::value_type
      reduce(InputIterator first, InputIterator last){
    typedef typename iterator_traits<InputIterator>::value_type T;
    return std::accumulate(first, last, T{0});
  }

  template<class InputIterator, class T>
    T reduce(InputIterator first, InputIterator last, T init){
    return std::accumulate(first, last, init);
  }

  template<class InputIterator, class T, class BinaryOperation>
    T reduce(InputIterator first, InputIterator last, T init,
             BinaryOperation binary_op){
    return std::accumulate(first, last, init, binary_op);
  }

  template<class InputIterator, class OutputIterator>
    OutputIterator
      exclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result);
  

  template<class InputIterator, class OutputIterator,
           class T>
    OutputIterator
      exclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result,
                     T init);
  

  template<class InputIterator, class OutputIterator,
           class T, class BinaryOperation>
    OutputIterator
      exclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result,
                     T init, BinaryOperation binary_op);


  template<class InputIterator, class OutputIterator>
    OutputIterator
      inclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result);

  
  template<class InputIterator, class OutputIterator,
           class BinaryOperation>
    OutputIterator
      inclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result,
                     BinaryOperation binary_op);
  

  template<class InputIterator, class OutputIterator,
           class T, class BinaryOperation>
    OutputIterator
      inclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result,
                     T init, BinaryOperation binary_op);
} seq ; //
} // ::policy
} // ::parallel
} // ::std 

#endif

