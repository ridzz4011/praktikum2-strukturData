cmake_minimum_required(VERSION 3.27.7)
project(TugasPraktikum2 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(TugasPraktikum2 main.cpp

               src/functionMisc/clearscreen/clearscreen.cpp
               src/functionMisc/loading/loading.cpp
               src/functionMisc/pauseconsole/pauseconsole.cpp
               src/functionMisc/intro/intro.cpp
               
               src/functionTugas/array2DreverseTranspose/arraytranspose.cpp
               src/functionTugas/pointerTanggal/pointerTanggal.cpp)

target_include_directories(TugasPraktikum2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
