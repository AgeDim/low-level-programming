cd ..
mkdir build
cd build
cmake .. -D CMAKE_C_COMPILER="C:\msys64\mingw64\bin\clang.exe" -D CMAKE_CXX_COMPILER="C:\msys64\mingw64\bin\clang++.exe"
cmake --build . --target ALL_BUILD --config Release