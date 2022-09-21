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


# execute_process() is invoked at configuration time. Can move to https://stackoverflow.com/questions/37862072/cmake-run-custom-command-before-build but not needed

execute_process(
        COMMAND python git_ver.py
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

execute_process(
        COMMAND python git_ver.py
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bootloader
)

add_compile_options(-Wall -Wextra)

#Uncomment for hardware floating point
#FreeRTOS Should Use FPU
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

add_compile_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)

# 按照实际MCU型号修改
add_compile_options(-DEMBEDDED -DAT32F403ACGT7 -DAT_START_F403A_V1 -DUSE_STDPERIPH_DRIVER)

file(GLOB APP_MAIN "User/main.cpp")

file(GLOB_RECURSE COMMON_SOURCES_R "User/Src/*.*")
file(GLOB COMMON_SOURCES_Normal
        "lib/freertos/source/*.*"
        "lib/core/*.*"
        )
file(GLOB COMMON_SOURCES_SINGLE
        "lib/cmsis/cm4/device_support/system_at32f403a_407.c"
        "lib/drivers/src/at32f403a_407_crm.c"
        "lib/drivers/src/at32f403a_407_misc.c"
        "lib/drivers/src/at32f403a_407_gpio.c"

        "lib/printf/printf.c"

        "lib/cmsis/cm4/device_support/system_at32f403a_407.c"
        "lib/cmsis/cm4/device_support/startup/gcc/startup_at32f403a_407.s"
        "lib/freertos/source/portable/memmang/heap_4.c" "lib/freertos/source/portable/GCC/ARM_CM4F/port.c"
        "lib/freertos/source/portable/common/mpu_wrappers.c"
        )

include_directories(
        lib/printf
        User/Src/utils/Config
        lib/drivers/inc
        lib/cmsis/cm4/core_support lib/cmsis/cm4/device_support lib/core
        lib/freertos/source/include
        lib/freertos/config
        User/Inc
)

# 用来检查谁用了malloc,new的重载似乎没成功
#add_link_options(-Wl,--wrap malloc)
#add_link_options(-Wl,--wrap _Znwm)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-DCORE_DEBUG_LEVEL=ARDUHAL_LOG_LEVEL_VERBOSE -DLOG_LOCAL_LEVEL=ESP_LOG_VERBOSE)
    include_directories(
            lib/SystemView_Src_V332/Sample/FreeRTOSV10.4
            lib/SystemView_Src_V332/Config
            lib/SystemView_Src_V332/SEGGER
    )
    file(GLOB_RECURSE SOURCES_R)
    file(GLOB SOURCES_Normal
            "lib/SeggerRTT/RTT/*.*" "lib/SystemView_Src_V332/SEGGER/*.*"
            )
    file(GLOB SOURCES_Single
            "lib/SystemView_Src_V332/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.c" "lib/SystemView_Src_V332/Sample/FreeRTOSV10.4/SEGGER_SYSVIEW_FreeRTOS.c" "lib/SystemView_Src_V332/Sample/FreeRTOSV10.4/Config/Cortex-M/SEGGER_SYSVIEW_Config_FreeRTOS.c"
            )
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-DCORE_DEBUG_LEVEL=ARDUHAL_LOG_LEVEL_INFO -DLOG_LOCAL_LEVEL=ESP_LOG_INFO)
    #add_compile_options(-O2)   // incase O3 caused some problem
    include_directories()
    file(GLOB_RECURSE SOURCES_R)
    file(GLOB SOURCES_Normal)
    file(GLOB SOURCES_Single)
else ()
    message(FATAL_ERROR "未知编译类型：${CMAKE_BUILD_TYPE};请显式指定编译类型")
endif ()

list(APPEND SOURCES ${APP_MAIN} ${COMMON_SOURCES_Normal} ${COMMON_SOURCES_R} ${COMMON_SOURCES_SINGLE} ${SOURCES_R} ${SOURCES_Normal} ${SOURCES_Single})

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/lib/cmsis/cm4/device_support/startup/gcc/linker/AT32F403AxG_FLASH.ld)
set(APP_BOOTLOADED_LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/AT32F403AxG_FLASH-app-bootloaded.ld)
set(BOOTLOADER_LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/AT32F403AxG_FLASH_bootloader.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_link_options(-specs=nosys.specs)


file(GLOB BootLoaderSourcesSingle
        "bootloader/main.cpp"
        "lib/cmsis/cm4/device_support/startup/gcc/startup_at32f403a_407.s"
        "lib/drivers/src/at32f403a_407_crm.c"
        "lib/drivers/src/at32f403a_407_misc.c"
        "lib/cmsis/cm4/device_support/system_at32f403a_407.c"
        "lib/core/*.*"
        #        "bootloader/log.cpp"
        )

list(APPEND BootLoaderSources ${BootLoaderSourcesSingle})
add_executable(bootloader ${BootLoaderSources} ${BOOTLOADER_LINKER_SCRIPT})

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})
add_executable(${PROJECT_NAME}_BootloaderVersion.elf ${SOURCES} ${APP_BOOTLOADED_LINKER_SCRIPT})


target_link_options(bootloader PRIVATE -T ${BOOTLOADER_LINKER_SCRIPT})
target_link_options(${PROJECT_NAME}.elf PRIVATE -T ${LINKER_SCRIPT})
target_link_options(${PROJECT_NAME}_BootloaderVersion.elf PRIVATE -T ${APP_BOOTLOADED_LINKER_SCRIPT})

target_include_directories(${PROJECT_NAME}.elf PUBLIC "lib/SeggerRTT/RTT" "lib/SeggerRTT/Config")
target_include_directories(${PROJECT_NAME}_BootloaderVersion.elf PUBLIC "lib/SeggerRTT/RTT" "lib/SeggerRTT/Config")


# For Bootloader's NVIC
set_target_properties(${PROJECT_NAME}_BootloaderVersion.elf PROPERTIES COMPILE_FLAGS "-DCORE_DEBUG_LEVEL=ARDUHAL_LOG_LEVEL_VERBOSE -DLOG_LOCAL_LEVEL=ESP_LOG_VERBOSE -DBOOTLOADERVERAPP -DFLASH_APP1_ADDR=0x08020000 -DAT32_FLASH_BASE=0x08000000")
set_target_properties(bootloader PROPERTIES COMPILE_FLAGS "-DBOOTLOADER_BUILD -DBOOTLOADER -DFLASH_APP1_ADDR=0x08020000 -DAT32_FLASH_BASE=0x08000000")
set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)
set(BOOTLOADER_BIN_FILE ${PROJECT_BINARY_DIR}/bootloader.bin)

add_custom_command(TARGET ${PROJECT_NAME}_BootloaderVersion.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}_BootloaderVersion.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}_BootloaderVersion.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")

add_custom_command(TARGET bootloader POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:bootloader> ${BOOTLOADER_BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")

