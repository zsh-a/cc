cmake_minimum_required(VERSION 3.0.0)
project(cc VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cc Lexer.cc Parser.cc Var.cc Error.cc Token.cc main.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
