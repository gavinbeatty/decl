
if(CMAKE_COMPILER_IS_GNUC)
    add_subdirectory(gnu)
elseif(MSVC)
    add_subdirectory(msvc)
endif(CMAKE_COMPILER_IS_GNUC)

add_subdirectory(generic)


