# CMakeList.txt : CMake project for video_transformer, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "video_transformer.cpp" "video_transformer.h")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)

# linking vendor content
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/vendor/ffmpeg/include")

target_link_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/vendor/ffmpeg/lib")

target_link_libraries(${PROJECT_NAME} PRIVATE avcodec 
											  avformat 
											  avutil 
											  swscale)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/ffmpeg/bin"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
