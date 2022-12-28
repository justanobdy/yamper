rm -rf temp

mkdir libs

echo Downloading simpleini...
git clone https://github.com/brofield/simpleini.git temp &> /dev/null
echo Copying simpleini files...
cp temp/ConvertUTF.c libs/ConvertUTF.c
cp temp/ConvertUTF.h libs/ConvertUTF.h
cp temp/SimpleIni.h libs/SimpleIni.h

echo Cleaning up...
rm -rf temp

echo Downloading imgui...
git clone https://github.com/ocornut/imgui.git -b docking temp &> /dev/null
echo Copying imgui files...
cp temp/imgui_demo.cpp libs/imgui_demo.cpp
cp temp/imgui_draw.cpp libs/imgui_draw.cpp
cp temp/misc/cpp/imgui_stdlib.cpp libs/imgui_stdlib.cpp
cp temp/imgui_tables.cpp libs/imgui_tables.cpp
cp temp/imgui_widgets.cpp libs/imgui_widgets.cpp
cp temp/imgui.cpp libs/imgui.cpp
cp temp/imgui.h libs/imgui.h
cp temp/imgui_internal.h libs/imgui_internal.h
cp temp/misc/cpp/imgui_stdlib.h libs/imgui_stdlib.h
cp temp/imstb_rectpack.h libs/imstb_rectpack.h
cp temp/imstb_textedit.h libs/imstb_textedit.h
cp temp/imstb_truetype.h libs/imstb_truetype.h

echo Cleaning up...
rm -rf temp

echo Downloading portable-file-dialogs....
git clone https://github.com/samhocevar/portable-file-dialogs.git temp &> /dev/null
echo Copying portable-file-dialogs files...
cp temp/portable-file-dialogs.h libs/portable-file-dialogs.h

echo Cleaning up...
rm -rf temp

echo Downloading imgui-sfml...
git clone https://github.com/eliasdaler/imgui-sfml.git -b focus temp &> /dev/null
echo Copying imgui-sfml files...
cp temp/imgui-SFML.cpp libs/imgui-SFML.cpp
cp temp/imgui-SFML.h libs/imgui-SFML.h
cp temp/imgui-SFML_export.h libs/imgui-SFML_export.h
cp temp/imconfig-SFML.h libs/imconfig.h

echo Cleaning up...
rm -rf temp

echo Done!