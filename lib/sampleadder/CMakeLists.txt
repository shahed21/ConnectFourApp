cmake_minimum_required(VERSION 3.16.3)

if(ENABLE_SAMPLE_BUILD)
    if(ENABLE_SAMPLE_ADDER_BUILD)
        add_library(sampleadder sampleadder.cpp sampleadderversion.cpp)
        target_include_directories(sampleadder
            PUBLIC "${PROJECT_BINARY_DIR}/inc/"
        )
        if(ENABLE_SAMPLE_ADDER_INSTALL)
            install(TARGETS sampleadder
                DESTINATION lib)
            install(FILES sampleadder.h sampleadderversion.h
                DESTINATION include)
        endif()
    endif()
endif()
