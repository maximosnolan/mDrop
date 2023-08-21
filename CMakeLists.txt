cmake_minimum_required(VERSION 3.10)
project(Bluetooth)

# Find BlueZ library
find_package(PkgConfig REQUIRED)
pkg_search_module(BLUEZ REQUIRED bluez)

# Add your source files
set(SOURCES
    src/Main/Main.cpp
    src/Bluetooth/BluetoothDeviceManager.cpp
    src/Logger/Logger.cpp
    src/Utils/Singleton.cpp
    src/Networking/NetworkManager.cpp
)
# Add debug flags for debug builds
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")  # Optional: Disable optimization for better debugging
endif()

# Create the executable
add_executable(Bluetooth ${SOURCES})

# Link against BlueZ library
target_link_libraries(Bluetooth PRIVATE ${BLUEZ_LIBRARIES})
target_include_directories(Bluetooth PRIVATE ${BLUEZ_INCLUDE_DIRS})
