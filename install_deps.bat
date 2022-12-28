@echo off

rmdir /s /q temp
rmdir /s /q libs

mkdir libs\

echo Downloading simpleini...
git clone -q https://github.com/brofield/simpleini.git temp
echo Moving simpleini files...
move temp\ConvertUTF.c libs\
move temp\ConvertUTF.h libs\
move temp\SimpleIni.h libs\

echo Cleaning up...
rmdir /s /q temp

echo Downloading imgui...
git clone -q https://github.com/ocornut/imgui.git -b docking temp
echo Moving imgui files...
move temp\imgui_demo.cpp libs\
move temp\imgui_draw.cpp libs\
move temp\misc\cpp\imgui_stdlib.cpp libs\
move temp\imgui_tables.cpp libs\
move temp\imgui_widgets.cpp libs\
move temp\imgui.cpp libs\
move temp\imgui.h libs\
move temp\imgui_internal.h libs\
move temp\misc\cpp\imgui_stdlib.h libs\
move temp\imstb_rectpack.h libs\
move temp\imstb_textedit.h libs\
move temp\imstb_truetype.h libs\

echo Cleaning up...
rmdir /s /q temp

echo Downloading portable-file-dialogs....
git clone -q https://github.com/samhocevar/portable-file-dialogs.git temp
echo Moving portable-file-dialogs files...
move temp\portable-file-dialogs.h libs\

echo Cleaning up...
rmdir /s /q temp

echo Downloading imgui-sfml...
git clone -q https://github.com/eliasdaler/imgui-sfml.git -b focus temp
echo Moving imgui-sfml files...
move temp\imgui-SFML.cpp libs\
move temp\imgui-SFML.h libs\
move temp\imgui-SFML_export.h libs\
move temp\imconfig-SFML.h libs\
rename libs\imconfig-SFML.h imconfig.h

echo Cleaning up...
rmdir /s /q temp
