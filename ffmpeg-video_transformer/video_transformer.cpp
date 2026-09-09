// video_transformer.cpp : Defines the entry point for the application.
//

#include "video_transformer.h"

#include <cstdlib>
#include <print>

int main(int argc, char* argv[]) 
{
    // Filename catch
    if (argc < 2) 
    {
        std::println("Error: No video file provided.\n");
        return EXIT_FAILURE; 
    }

	// Get filename from command line arguments
    const char* video_file = argv[1];
    std::println("Video File: {}", video_file);

    

	return EXIT_SUCCESS;
}