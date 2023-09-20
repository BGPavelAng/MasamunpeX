

int hexView (const char *nameHx){

	char bufh[256];
	char reslh[PATH_MAX];
	const char *px;

	snprintf(bufh, sizeof(bufh), "/proc/%s/exe", nameHx);

	ssize_t fHexPth = readlink(bufh, reslh, sizeof(reslh)-1);

	if(fHexPth != -1){
		px = dirname(reslh);
		printf("[+]Ubicación (symbolic_link):              %s\n", px);
	}else{
		printf("%s\n", "Archivo no encontrado\n");
		return 0;
	}

	FILE *filehex = fopen(bufh, "rb");
	unsigned long sizeHex;
	long d = 1;
	int loophexd = 1;


	fseek(filehex, 0, SEEK_END);
	long szhex = ftell(filehex);
	fseek(filehex, 0, SEEK_SET);

	unsigned char *buffHex = (char*)malloc(szhex);
	char pk;

	while(1){

		if(ftell(filehex) == szhex){
			break;
		}

		sizeHex = fgetc(filehex);
		printf("%02lx ", sizeHex);
		d++; 

		buffHex[d]= sizeHex;

		if((d % 16) == 0){
			printf("\t");

			for(loophexd; loophexd < d+1; loophexd++){
				if(buffHex[loophexd] < 33 || buffHex[loophexd] > 128 || buffHex[loophexd] == 0){
					printf("%s", ".");
				}else{
					printf("%c", buffHex[loophexd]);
				}
			}

			printf("%s","\n");
		}

		if((d % 800) == 0){
			printf("\n\n%s\n\n", "Presione Enter para continuar...");

			while(1){
				pk = fgetc(stdin);
				if(pk == 0x0A){
					break;
				}
			}
		}

	}

	printf("%s","\n");

	fclose(filehex);

}