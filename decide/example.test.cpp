#include <decide/lics.hpp>
#include <cstdlib>

void test(){
    if (true)
        std::exit(EXIT_FAILURE);
}

int main(){
    test();
    
    return 0;
}
