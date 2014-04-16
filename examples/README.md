# Example applications using parallel standard algorithms

## Compilation

To compile the code, add the include directory from the root to the include path, make sure you have C++11 enabled and link with the thread library if necessary:

```
#!c++
$> g++ -O3 -std=c++11 -I../include -o bs blackscholes.cpp -lpthread
$> ./bs
Using seq: 1609520 us
Using par: 130504 us
```

