#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

// Helper function to capture std::cout output
std::string captureMainOutput() {
    std::streambuf* oldCout = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    // Call main
    main();

    std::cout.rdbuf(oldCout);
    return oss.str();
}

TEST(MainTest, PrintsHelloWorld) {
    std::string output = captureMainOutput();
    EXPECT_NE(output.find("hello world!"), std::string::npos);
