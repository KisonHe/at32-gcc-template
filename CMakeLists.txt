set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.20)

# specify cross compilers and tools
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(at32_demo C CXX ASM)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug mode")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Release mode")
else ()
    message(FATAL_ERROR "请指定编译类型")
endif ()

add_compile_options(-Wall -Wextra)

#Uncomment for hardware floating point
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

#Uncomment for software floating point
#add_compile_options(-mfloat-abi=soft)

add_compile_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)


add_compile_options(-DEMBEDDED -DAT32F403ACGT7 -DAT_START_F403A_V1 -DUSE_STDPERIPH_DRIVER)

file(GLOB APP_MAIN "User/main.cpp")

file(GLOB COMMON_SOURCES_Normal
        "lib/core/*.*"
        )
file(GLOB COMMON_SOURCES_SINGLE
        "lib/cmsis/cm4/device_support/system_at32f403a_407.c"
        "lib/drivers/src/at32f403a_407_crm.c"
        "lib/drivers/src/at32f403a_407_misc.c"
        "lib/drivers/src/at32f403a_407_gpio.c"
        "lib/cmsis/cm4/device_support/startup/gcc/startup_at32f403a_407.s"
        )

include_directories(
        lib/cmsis/cm4/core_support lib/cmsis/cm4/device_support lib/core lib/drivers/inc
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")

elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    #add_compile_options(-O2)   // in case O3 caused some problem
else ()
    message(FATAL_ERROR "未知编译类型：${CMAKE_BUILD_TYPE};请显式指定编译类型")
endif ()

list(APPEND SOURCES ${APP_MAIN} ${COMMON_SOURCES_Normal} ${COMMON_SOURCES_R} ${COMMON_SOURCES_SINGLE})

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/lib/cmsis/cm4/device_support/startup/gcc/linker/AT32F403AxG_FLASH.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
#add_link_options(-T ${LINKER_SCRIPT})
add_link_options(-specs=nosys.specs)



add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

target_link_options(${PROJECT_NAME}.elf PRIVATE -T ${LINKER_SCRIPT})

target_include_directories(${PROJECT_NAME}.elf PUBLIC "lib/SeggerRTT/RTT" "lib/SeggerRTT/Config")

# For Bootloader's NVIC
set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)
set(BOOTLOADER_BIN_FILE ${PROJECT_BINARY_DIR}/bootloader.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")

