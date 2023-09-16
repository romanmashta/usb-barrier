#include <unity.h>
#include <library.h>

#ifdef ARCH_NATIVE
#include <ArduinoFake.h>
#else
#include <Arduino.h>
#endif

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    UNITY_END();
}