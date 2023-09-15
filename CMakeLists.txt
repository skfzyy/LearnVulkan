cmake_minimum_required(VERSION 3.25)
project(LearnVulkan)

set(CMAKE_CXX_STANDARD 17)

set(VulkanAPIPath "" CACHE FILEPATH "set the VulkanSDK path")
set(GLEWAPIPath "" CACHE FILEPATH "set the GLFW path")
message(STATUS ${VulkanAPIPath})


set(Vulkan_IncludePath ${VulkanAPIPath}/Include)
set(Vulkan_LibPath ${VulkanAPIPath}/Lib)
set(Vulkan_BinaryPath ${VulkanAPIPath}/Bin)

set(GLFW_IncludePath ${GLEWAPIPath}/Include)
set(GLFW_LibPath ${GLEWAPIPath}/Lib)
set(GLFW_BinaryPath ${GLEWAPIPath}/Bin)

FILE(GLOB Root CONFIGURE_DEPENDS ./*.hpp ./*.cpp ./*.h)

# 这里为了方便，直接检索所有vulkan的目标文件
file(GLOB VulkanLIBFiles CONFIGURE_DEPENDS ${Vulkan_LibPath}/*.lib)
file(GLOB GLFWLIBFiles CONFIGURE_DEPENDS ${GLFW_LibPath}/*.lib)
message(STATUS ${VulkanLIBFiles})


add_executable(LearnVulkan)

target_sources(LearnVulkan PRIVATE ${Root})

target_include_directories(LearnVulkan PRIVATE ${Vulkan_IncludePath} ${GLFW_IncludePath})
target_link_directories(LearnVulkan PRIVATE ${Vulkan_LibPath} ${GLFW_LibPath})
target_link_libraries(LearnVulkan PRIVATE ${VulkanLIBFiles} ${GLFWLIBFiles})

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    target_compile_definitions(LearnVulkan PRIVATE "VulkanDebug")
endif ()

# install vulkan dll
file(INSTALL ${Vulkan_BinaryPath} DESTINATION ${CMAKE_CURRENT_BINARY_DIR} FILES_MATCHING PATTERN *.dll)


