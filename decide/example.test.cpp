#include <decide/lics.hpp>
#include <cstdlib>

void testLic0(){
    lic0();
    if (true)
        std::exit(EXIT_FAILURE);
}

int main(){
    testLic0();
    // [...]
    return 0;
}
