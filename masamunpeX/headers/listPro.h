

void mostrar_direc(const struct dirent *show){

    char buffPth[512];
    FILE *Lpro;
    int pid = 0;;

    snprintf(buffPth, sizeof(buffPth), "/proc/%s/stat", show->d_name);
    Lpro = fopen(buffPth, "r");

    fscanf(Lpro, "%d %s", &pid, buffPth); //Id y nombre

    printf("%5d %-20s\n", pid, buffPth);

    fclose(Lpro);

    
}

int direc_fil(const struct dirent *enu){

    return !fnmatch("[0-9]*", enu->d_name, 0); //encontrar coincidencias en los nombres [0-9]* -> comparar todo

}



int showProc(){

    struct dirent **listProc;  //buscar directorios dentro de /proc

    int num;

    num = scandir("/proc", &listProc, direc_fil, 0); //escaneo de los directorios

    if(num < 0){
        printf("%s\n", "No se encontro el directorio o no tiene permisos de lectura");
    }

    for (int i = 0; i < num; i++)
    {
        mostrar_direc(listProc[i]);
        free(listProc[i]);
    }

    free(listProc);

    return 0;
}