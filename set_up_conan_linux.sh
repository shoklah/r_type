conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default
conan remote update conan-center https://api.bintray.com/conan/conan/conan-center
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
conan remote add epitech https://api.bintray.com/conan/epitech/public-conan