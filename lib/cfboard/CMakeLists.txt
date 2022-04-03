cmake_minimum_required(VERSION 3.16.3)

if(ENABLE_CFBOARD_BUILD)
    add_library(cfboard boardconstants.cpp cfboardversion.cpp)
    target_include_directories(cfboard
        PUBLIC "${PROJECT_BINARY_DIR}/inc/"
    )
    if(ENABLE_CFBOARD_INSTALL)
        install(TARGETS cfboard
            DESTINATION lib)
        install(FILES cfboard.h boardconstants.h cfboardversion.h
            DESTINATION include)
    endif()
endif()
