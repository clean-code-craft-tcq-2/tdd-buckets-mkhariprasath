#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"


TEST_CASE("") {

  int chargingSession[] = {4,5}
  REQUIRE(getRangeReading(chargingSession) == "4-5, 2");

}
