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
)

set(ch01
    main1
    main2
)

set(ch02
    saltImage
    colorReduce
    contrast
    addImages
)

set(ch04
    histograms
)

set(ch05
    morphology
)

include_directories(${OpenCV_INCLUDE_DIRS})

set(LIBS ${OpenCV_LIBS})

foreach(CHAPTER ${CHAPTERS})
    foreach(DEMO ${${CHAPTER}})
        add_executable(${DEMO} ${CHAPTER}/${DEMO}.cpp)
        target_link_libraries(${DEMO} ${LIBS}) 
        set_target_properties(${DEMO} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CHAPTER})
    endforeach(DEMO)
endforeach(CHAPTER)
