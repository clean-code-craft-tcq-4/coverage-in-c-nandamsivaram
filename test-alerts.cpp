#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

/*TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}*/

TEST_CASE("Test checkAndAlert functionality")
{ 
 BatteryCharacter batteryChar;
 batteryChar.coolingType = PASSIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,-5) == 1);
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,15) == 0);
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,40) == 1);
  
  batteryChar.coolingType = HI_ACTIVE_COOLING;
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar,-10) == 1);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar,15) == 0);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar,50) == 1);
  
  batteryChar.coolingType = MED_ACTIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,-15) == 1);
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,15) == 0);
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,41) == 1);
}

TEST_CASE("Test classifyTemperatureBreach functionality")
{ 
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) 	 	== 	TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -1) 		== 	TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) 	== 	TOO_LOW);
	
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) 	 	== 	TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) 		== 	TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 41) 	== 	TOO_HIGH);
	
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 30) 	 	== 	NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 25) 		== 	NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 20) 	== 	NORMAL);
}
