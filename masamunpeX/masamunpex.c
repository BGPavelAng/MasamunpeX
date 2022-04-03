//usr/src/kernels/$(uname -r)/include/uapi/linux/elf.h
//www.man7.org/linux/man-pages/man5/elf.5.html

#include <elf.h>
#include <link.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fnmatch.h>
#include <stdint.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <dirent.h>
#include <libgen.h>
#include <fcntl.h>

#include "headers/listPro.h"
#include "headers/segHead.h"
#include "headers/hexview.h"
#include "headers/segPro.h"


void ayuda(){

    printf("\n%s\n\n", "Uso: ");
    printf("\t%s\n", "-h Ayuda");
    printf("\t%s\n", "-p Listado de procesos");
    printf("\t%s\n", "-sH [Id] - Mostrar datos de segmentos");
    printf("\t%s\n", "-X [Id] - Dump de Hexadecimales");
    printf("\t%s\n\n", "-PH [Id] - Mostrar datos del programa");


}

int main(int argc, char const *argv[]){

printf("\033[0;31m"); //Set the text to the color red

printf("\n\n\t\t%s\n", "  __   __ ______ _______ ______ __   __ __   __ __    _ _______ ______   __        __"); 
printf("\t\t%s\n", "||  |||  |      |       |      |  |_|  |  | |  |  |  | |       |      | \\  \\     /  /");
printf("\t\t%s\n", "||       |  _   |  _____|  _   |       |  | |  |  |__| |    _  |   ___|  \\  \\   /  /");
printf("\t\t%s\n", "||       | |_|  | |_____| |_|  |       |  |_|  |       |   |_| |  |___    \\  \\_/  /");
printf("\t\t%s\n", "||       |      |_____  |      |       |       |  _    |    ___|   ___|   /   _   \\");
printf("\t\t%s\n", "|| ||_|| |  _   |_____| |  _   | ||_|| |       | | |   |   |   |   |__   /   / \\   \\");
printf("\t\t%s\n", "||_|   |_|_| |__|_______|_| |__|_|   |_|_______|_| |___|___|   |______| /__ /   \\ __\\");
printf("\t\t%s\n", " ___    _ _   __________ _   __ _     _ _______ _   ___ ___     ______   __       __");

 printf("\n\t\t\t\t\t\t\t%s\n"," .--.");
 printf("\t\t\t\t\t\t%s\n", "        |o_o |");
 printf("\t\t\t\t\t\t%s\n", "        |:_/ |");
 printf("\t\t\t\t\t\t%s\n", "       //    \\\\");
 printf("\t\t\t\t\t\t%s\n", "      (|     | )");
 printf("\t\t\t\t\t\t%s\n", "     /'|_   _/'\\");
 printf("\t\t\t\t\t\t%s","     \\___)=(___/");

printf("\033[0m\n");

printf("\t\t\t\t\t%s\n","---------------------------------------");
	printf("\t\t\t\t\t%s\n","---------------------------------------");
	printf("\t\t\t\t\t%s\n","***************MasamunPEX***************");
	printf("\t\t\t\t\t%s\n","---------------------------------------");
	printf("\t\t\t\t\t%s\n","*********github.com/BGPavelAng*********");
	printf("\t\t\t\t\t%s\n","---------------------------------------");
	printf("\t\t\t\t\t%s\n\n\n","---------------------------------------");



if(argc < 2){
    printf("\n%s\n","No hubo segundo parametro (usar -h para ayuda)");
    ayuda();
    return 0;
}

if(strncmp(argv[1], "-h", 2) == 0){
    ayuda();
    return 0;
}

if(strncmp(argv[1], "-p", 2) == 0){
    showProc();
    return 0;
}

if(strncmp(argv[1], "-sH", 3) == 0){
    if(argv[2] > 0){
    	showSeg(argv[2]);
    }else{
    	ayuda();
    }
}

if(strncmp(argv[1], "-X", 2) == 0){
    if(argv[2] > 0){
    	hexView(argv[2]);
    }else{
    	ayuda();
    }
}

if(strncmp(argv[1], "-PH", 3) == 0){
	if(argv[2] > 0){
    proHeaders(argv[2]);
}else{
	ayuda();
}
}

    return 0;
}