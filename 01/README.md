# 01 - Hello World
- Estrutura de um projeto C++
- Organização em módulos (.h e .cpp)
- Projeto descrito via CMake

# Comando CMake para buildar
$ mkdir build && cd build
$ cmake -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..

-GNinja : define o gerador a ser utilizado, neste caso o Ninja;
-DCMAKE_EXPORT_COMPILE_COMMANDS=1 : habilita a geração do arquivo compile_commands.json que contém informações sobre cada arquivo fonte. É utilizado como entrada pelo clangd para fazer o intellisense;
.. : diretorio onde esta o arquivo CMakeLists.txt

## Comando para compilar
$ ninja

## Comando para executar o programa
$ HelloEletra.exe

## Comando para compilar e executar
$ ninja && HelloEletra.exe

## Criar um link para o arquivo compile_commands.json
na raiz do projeto, em um terminal com privilegios de administrador:
$ mklink compile_commands.json build\compile_commands.json

ou executar o arquivo mklink_compile_commands.bat como administrador

# Busca no Cpp Reference
Após selecionar o tempo a ser buscado: Ctrl+Shift+P -> "Search: Cpp Reference"

## Ferramentas
- CMAKE = https://cmake.org/download/
- clang 11.0.0 = https://prereleases.llvm.org/11.0.0/
- vscode = https://code.visualstudio.com/Download
- visual studio c/c++ = https://visualstudio.microsoft.com/vs/features/cplusplus/
- clonar = https://github.com/catchorg/Catch2
- clonar = https://github.com/marvins/cli-cpp 
