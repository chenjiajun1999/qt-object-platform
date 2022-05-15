cmake_minimum_required(VERSION 3.17)
project(${PROJECT_NAME})

# init qt
set(CMAKE_AUTOMOC ON) # for meta object compiler
set(CMAKE_AUTORCC ON) # resource files
set(CMAKE_AUTOUIC ON) # UI files
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D FREEGLUT_STATIC")

set(CMAKE_PREFIX_PATH "C:/Software/QT/Qt/5.14.2/mingw73_32/")
link_directories("C:/Software/QT/Qt/5.14.2/mingw73_32/lib")

# find package
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

file(GLOB_RECURSE DIR_SRCS    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE DIR_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME}
        ${DIR_SRCS}
        ${DIR_HEADERS})
target_link_libraries(${PROJECT_NAME}
        ${GLUT_LIBS}
        Qt5::Widgets
        Qt5::Core
        freeglut_static
        opengl32
        glu32
        winmm
        )
qt5_use_modules(${PROJECT_NAME}
        Core Widgets Gui)
