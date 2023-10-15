cmake_minimum_required(VERSION 3.10)
project(MQTT_CPP)

set(CMAKE_CXX_STANDARD 11)

find_package(PahoMqttCpp REQUIRED)

add_executable(mqtt_example mqtt.cpp)

target_link_libraries(mqtt_example PRIVATE PahoMqttCpp::paho-mqttpp3)
