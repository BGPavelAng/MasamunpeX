//https://www.baeldung.com/linux/proc-id-maps

void dmp_writ(FILE *MM, unsigned long whStar, long total){

	unsigned long whAddr = 0;
	int Longitud = 4096;
	unsigned char pag[4096];
	fseek(MM, whStar,SEEK_SET);
	char pau;

	for(whAddr = whStar; whAddr < whStar+total; whAddr+=Longitud){

		fread(&pag, 1, Longitud, MM);
		fwrite(&pag, 1, Longitud, stdout);

		if((whAddr % 800) == 0){
			printf("\n\n%s\n\n", "Presione Enter para continuar...");

			while(1){
				pau = fgetc(stdin);
				if(pau == 0x0A){
					break;
				}
			}
		}

	}

	
}

int mem_dmp(const char *nmdmp){
	
	char m_buff[256];
	char buff_mps[1024], buff_mm[1024], VMS[256];
	char reslmp[PATH_MAX];
	const char *D_pth;
	FILE *fmps, *fmms;

	snprintf(m_buff, sizeof(m_buff), "/proc/%s/exe", nmdmp);

	ssize_t dd_mlnk = readlink(m_buff, reslmp, sizeof(reslmp)-1);

	if(dd_mlnk != -1){

		D_pth = dirname(reslmp);
		printf("[+]Ubicación (symbolic_link):              %s\n", D_pth);
	}else{
		printf("%s\n", "Archivo no encontrado\n");
		return 0;
	}

	sprintf(buff_mps,"/proc/%s/maps", nmdmp);
	fmps = fopen(buff_mps, "r");
	sprintf(buff_mm, "/proc/%s/mem", nmdmp);
	fmms = fopen(buff_mm, "r");

	while(fgets(VMS, 256, fmps) != NULL){

		unsigned long startP;
		unsigned long endP;

		sscanf(VMS, "%08lx-%08lx\n", &startP, &endP);

		dmp_writ(fmms, startP, endP - startP);

	}

	fclose(fmps);
	fclose(fmms);

	printf("%s\n", "Finalizó (dump_memory.txt)");

}