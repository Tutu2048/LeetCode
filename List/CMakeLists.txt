# 收集所有 .cpp 文件
file(GLOB SOURCES "*.cpp")

# 遍历每个 .cpp 文件，创建可执行文件
foreach(source_file ${SOURCES})
    # 获取文件名（不包含路径和扩展名）
    get_filename_component(exe_name ${source_file} NAME_WE)
    # 创建可执行文件
    add_executable(${exe_name} ${source_file})
endforeach()