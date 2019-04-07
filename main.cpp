#include <iostream>
#include "src/cView.h"

int main() {
    cView view(common::constants::kIsLoggerNeeded);
    view.start();
    return 0;
}