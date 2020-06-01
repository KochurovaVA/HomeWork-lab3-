#include "histogram.h"
#include "svg_module.h"

#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_equal(){
   double min = 0;
    double max = 0;
    find_minmax({1,1,1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_empty(){
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void test_colors0(){
size_t bin_count = 0;
size_t i = 0;
vector<string> colors(bin_count);
assert(colors[0] == "colors[0]");
}

void test_colors1(){
size_t bin_count = 1;
size_t i = 1;
vector<string> colors(bin_count);
assert(colors[1] == "colors[1]");
}

void test_colors2(){
size_t bin_count = 2;
size_t i = 2;
vector<string> colors(bin_count);
assert(colors[1] == "colors[1]");
}


int
main() {
   test_positive();
   test_negative();
   test_equal();
   test_empty();
   test_colors0();
   test_colors1();
   test_colors2();
}
