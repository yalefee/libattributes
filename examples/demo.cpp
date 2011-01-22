#include "attributes.hpp"

#include <iostream>

#include <boost/lexical_cast.hpp>

namespace string2type {

template<>
int convert<int>(const std::string &value) {
    return boost::lexical_cast<int>(value);
}

}

struct foo : attributes {
    foo() {
        REGISTER_ATTRIBUTE(int, x);
    }

    int x;
};

int main(int argc, char *argv) {
    foo f;
    f.set_attribute("x", "42");

    std::cout << f.x << std::endl;

    return 0;
}
