# Repositório do Linear-Feedback Shift Register de SB | lfsr-SB

Gabriel Nunes Rodrigues Fonseca - 16/0006597

Foram implementadas dois LFSR, um em C++ e outro em Assembly.

Os arquivos asm_io.asm e asm_io.inc NÃO são de autoria
minha e são utilizados somente para abstrair, via macros, toda
a parte da saída em tela. 

Para compilar o arquivo 02-c++11lsfr.cpp , use:

    $ g++ -std=c++11 -o lfsrc++11 02-c++11lfsr.cpp

Para compilar o arquivo 02-assemblylsfr.asm
    
    $ nasm -f elf 02-assemblylfsr.asm
    $ gcc -m32 02-assemblylfsr.o -o lfsrassembly asm_io.o


Utilizando o comando time nos dois arquivos, i.e:

    $ time ./lfsrc++11
        real	0m0,010s
        user	0m0,004s
        sys	0m0,006s

    $ time ./lfsrassembly
        real	0m0,005s
        user	0m0,001s
        sys	0m0,004s

