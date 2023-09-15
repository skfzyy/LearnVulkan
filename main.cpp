#include <iostream>
#include "HelloTriandleApplication.h"

int main() {
    HelloTriandleApplication app;
    app.init();
    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
