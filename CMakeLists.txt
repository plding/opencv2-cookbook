cmake_minimum_required (VERSION 2.8)
project (OpenCV2-cookbook)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -Wno-unsequenced")

# find the required packages
find_package(OpenCV REQUIRED)

set(CHAPTERS
    ch01
    ch02
    ch04
    ch05
    ch06
    ch07
    ch08
)

include_directories(${OpenCV_INCLUDE_DIRS})

set(LIBS ${OpenCV_LIBS})

foreach(CHAPTER ${CHAPTERS})
    file(GLOB SOURCES ${CHAPTER}/*.cpp)
    foreach(SOURCE ${SOURCES})
        get_filename_component(TARGET ${SOURCE} NAME_WE)
        add_executable(${TARGET} ${SOURCE})
        target_link_libraries(${TARGET} ${LIBS}) 
        set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CHAPTER})
    endforeach(SOURCE)
endforeach(CHAPTER)
