#include <iostream>
#include "src/cView.h"

int main() {
    // TODO: include GTEST lib
    // TODO: cover validator with tests
    // TODO: cover controller with tests
    cView view(common::constants::kIsLoggerNeeded);
    view.start();
    return 0;
}