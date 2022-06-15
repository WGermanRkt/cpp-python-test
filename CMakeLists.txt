cmake_minimum_required (VERSION 3.6)

project(dlogprocessor VERSION 0.1.0)

set(HEADER_FILES
)

set(SOURCE_FILES
)

include_directories(dlogprocessor
    ${PROJECT_SOURCE_DIR}/include
)

add_compile_options("-I/usr/include/python3.8")
add_compile_options("-Wno-unused-result")
add_compile_options("-Wsign-compare")
add_compile_options("-fdebug-prefix-map=/build/python3.8-4wuY7n/python3.8-3.8.10=.")
add_compile_options("-specs=/usr/share/dpkg/no-pie-compile.specs")
add_compile_options("-fstack-protector")
add_compile_options("-Wformat")
add_compile_options("-Werror=format-security")
add_compile_options("-DNDEBUG")
add_compile_options("-g")
add_compile_options("-fwrapv")
add_compile_options("-O3")
add_compile_options("-Wall")
add_compile_options("-fPIE")

link_libraries("-L/usr/lib/python3.8/config-3.8-x86_64-linux-gnu")
link_libraries("-L/usr/lib")
link_libraries("-lcrypt")
link_libraries("-lpthread")
link_libraries("-ldl")
link_libraries("-lutil")
link_libraries("-lm")
link_libraries("-lpython3.8")


#add_test_subdirectory(unit_test)


add_executable (
   dlogprocessor
   main.cpp
   ${SOURCE_FILES}
   ${HEADER_FILES}
)



target_link_libraries (dlogprocessor z)

