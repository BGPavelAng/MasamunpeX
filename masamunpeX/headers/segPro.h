int proHeaders (const char *snamePh){
	
	char buffpHs[256];
	char resphs[PATH_MAX];
	const char *phdir;
	char *buff_ptyp;
	char *buff_pflg;

	snprintf(buffpHs, sizeof(buffpHs), "/proc/%s/exe", snamePh);

	ssize_t filepathPro = readlink(buffpHs, resphs, sizeof(resphs)-1);

	if(filepathPro != -1){
		phdir = dirname(resphs);
		printf("[+]Ubicación (symbolic_link):      %s\n", phdir);
	}else{

		printf("%s\n\n", "Proceso no encontrado");
		return 0;
	}

	//mapeo

	int filmps = open(buffpHs, O_RDONLY);

	struct stat probuf;

	if(fstat(filmps, &probuf)){
		return 0;
	}

	char *PHmap = mmap(NULL, probuf.st_size, PROT_READ, MAP_PRIVATE, filmps, 0);

	if(PHmap == MAP_FAILED){
		return 0;
	}

	const ElfW(Ehdr) *epHDR = (const ElfW(Ehdr)*)PHmap;
	const ElfW(Phdr) *pHDR = (const ElfW(Phdr)*)(PHmap + epHDR->e_phoff);

	for(uint hdphoff = 0; hdphoff < epHDR->e_phnum; hdphoff++){

	switch(pHDR[hdphoff].p_type){
		case PT_NULL: buff_ptyp = "[+]Tipo:                           [PT_NULL]";
		break;
		case PT_LOAD: buff_ptyp = "[+]Tipo:                           [PT_LOAD]";
		break;
		case PT_DYNAMIC: buff_ptyp = "[+]Tipo:                           [PT_DYNAMIC]";
		break;
		case PT_INTERP: buff_ptyp = "[+]Tipo:                           [PT_INTERP]";
		break;
		case PT_NOTE: buff_ptyp = "[+]Tipo:                           [PT_NOTE]";
		break;
		case PT_SHLIB: buff_ptyp = "[+]Tipo:                           [PT_SHLIB]";
		break;
		case PT_PHDR: buff_ptyp = "[+]Tipo:                           [PT_PHDR]";
		break;
		case PT_TLS: buff_ptyp = "[+]Tipo:                           [PT_TLS]";
		break;
		case PT_LOOS: buff_ptyp = "[+]Tipo:                           [PT_LOOS]";
		break;
		case PT_HIOS: buff_ptyp = "[+]Tipo:                           [PT_HIOS]";
		break;
		case PT_LOPROC: buff_ptyp = "[+]Tipo:                           [PT_LOPROC]";
		break;
		case PT_HIPROC: buff_ptyp = "[+]Tipo:                           [PT_HIPROC]";
		break;
		case PT_GNU_EH_FRAME: buff_ptyp = "[+]Tipo:                           [PT_HIPROC]";
		break;
		case PT_GNU_STACK: buff_ptyp = "[+]Tipo:                           [PT_HIPROC]";
		break;
		case PT_GNU_RELRO: buff_ptyp = "[+]Tipo:                           [PT_HIPROC]";
		break;
		case PT_GNU_PROPERTY: buff_ptyp = "[+]Tipo:                           [PT_HIPROC]";
		break;
		default: buff_ptyp = "[+]Tipo:                           No encontrado";
	}

	printf("\n%s\n", buff_ptyp);
	printf("[+]Offset:                         0x%016x\n", pHDR[hdphoff].p_offset);
	printf("[+]Virtual Address:                0x%016x\n", pHDR[hdphoff].p_vaddr);
	printf("[+]Physical Address:               0x%016x\n", pHDR[hdphoff].p_paddr);
	printf("[+]Bytes p_filesz:                 0x%016x\n", pHDR[hdphoff].p_filesz);
	printf("[+]Bytes p_memsz:                  0x%016x\n", pHDR[hdphoff].p_memsz);

	switch(pHDR[hdphoff].p_flags){
		case PF_X: buff_pflg = "Segmento executable";
		break;
		case PF_W: buff_pflg = "Segmento escritura";
		break;
		case PF_R: buff_pflg = "Segmento lectura";
		break;
	}

	printf("[+]Flag:                           %s\n", buff_pflg);

	if((pHDR[hdphoff].p_align) <= 0){
	printf("[+]Alineamiento:                   0x%016x (No necesita alinamiento)\n", pHDR[hdphoff].p_align);
}else{
	printf("[+]Alineamiento:                   0x%016x\n", pHDR[hdphoff].p_align);
}

}


printf("%s","\n");

}