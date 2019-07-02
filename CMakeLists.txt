cmake_minimum_required (VERSION 2.8)
project (OpenCV2-cookbook)

# find the required packages
find_package(OpenCV REQUIRED)

set(CHAPTERS
    ch01
    ch02
)

set(ch01
    main1
    main2
)

set(ch02
    saltImage
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
