cmake_minimum_required(VERSION 3.10)

project(Gauntlet)

include_directories(${CMAKE_SOURCE_DIR}/utility)


# Function to check if a given file contains a main function
# Arguments:
#   path - The path to the file to check
#   result - The variable to store the result (TRUE if the file contains a
#   main function, FALSE otherwise)
function(file_has_main path result)
  file(READ ${path} content)
  string(FIND "${content}" "int main" main_pos)
  if(main_pos EQUAL -1)
    set(${result} FALSE PARENT_SCOPE)
  else()
    set(${result} TRUE PARENT_SCOPE)
  endif()
endfunction()

# Generate a list of days from 1 to 30
foreach(day RANGE 1 30)
  if(day LESS 10)
    set(day_padded "0${day}")
  else()
    set(day_padded "${day}")
  endif()
  set(day_dir "day${day_padded}")
  set(main_file "${day_dir}/main.cpp")

  # Check if the main.cpp file has a main function
  file_has_main(${main_file} has_main)

  # Create an executable target for each day if main function exists
  if(has_main)
    add_executable(${day_dir} ${main_file})
  endif()
endforeach()
