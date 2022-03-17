cmake_minimum_required(VERSION 3.16)

# initialize the SDK based on PICO_SDK_PATH

set (PROJ_NAME templite)


set(PICO_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/pico-sdk" CACHE STRING "")
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(${PROJ_NAME})

# initialize the Pico SDK
pico_sdk_init()

set(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include"  CACHE STRING "")
set(FREERTOS_PORT "GCC_ARM_CM0" CACHE STRING "")
add_subdirectory(FreeRTOS-Kernel)

add_executable(${PROJ_NAME}
    src/main.c
)

target_link_libraries( ${PROJ_NAME} 
	pico_stdlib 
	hardware_gpio 
	hardware_irq
	hardware_resets



	freertos_kernel
)
	
pico_add_extra_outputs(${PROJ_NAME})
