cmake_minimum_required(VERSION 3.16.3)

if(ENABLE_SAMPLE_BUILD)
    if(ENABLE_SAMPLE_COMBINATORICS_BUILD)
        add_library(samplecombinatorics samplecombinatorics.cpp samplecombinatoricsversion.cpp)
        target_include_directories(samplecombinatorics
            PUBLIC "${PROJECT_BINARY_DIR}/inc/"
        )
        if(ENABLE_SAMPLE_COMBINATORICS_INSTALL)
            install(TARGETS samplecombinatorics
                DESTINATION lib)
            install(FILES samplecombinatorics.h samplecombinatoricsversion.h
                DESTINATION include)
        endif()
    endif()
endif()
