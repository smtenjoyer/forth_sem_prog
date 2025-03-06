cmake_minimum_required(VERSION 3.5.0)
project(FactoryMethod VERSION 0.1.0 LANGUAGES C CXX)

add_executable(FactoryMethod main.cpp fighter.h weapon.h AbstractWeapon.h Versus.h WeaponFactory.h) 

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
