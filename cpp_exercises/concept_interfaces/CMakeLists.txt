cmake_minimum_required(VERSION 3.14...3.18)
project(ConceptInterface
	VERSION
        0.1
	DESCRIPTION
	"How to make an cpp interface 3 ways"
	LANGUAGES
	 CXX
	 )
set(CMAKE_CXX_STANDARD 20)
set(BOOST_ROOT "/usr/lib/boost")

find_package(Boost 1.76.0 REQUIRED COMPONENTS
            date_time)

if(Boost_FOUND)
    message("found BOOST: " ${BOOST_ROOT})
    include_directories(${Boost_INCLUDE_DIR})
    add_executable(example_interface example_interface_01.cpp)
    target_link_libraries(example_interface ${Boost_LIBRARIES})
else()
    message("Boost not found")
endif()	
