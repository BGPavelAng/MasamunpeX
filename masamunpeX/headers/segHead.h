
int showSeg(const char *nameS){

	char buffP[256];
	char result[PATH_MAX];
	const char *ph;
	char *buf_ty = 0;
	char *buf_flg = 0;
	char *buf_Os = 0;
	char *buf_tip = 0;
	char *buf_arch = 0;

	snprintf(buffP, sizeof(buffP), "/proc/%s/exe", nameS);

	ssize_t filPath = readlink(buffP, result, sizeof(result)-1);

	if(filPath != -1){
		ph = dirname(result);
		     printf("[+]Ubicación (symbolic_link):              %s\n", ph);
		}else{
		     printf("%s\n\n", "Proceso no encontrado");
		     return 0;
	  }

	  int filemap = open(buffP, O_RDONLY);
	

	//Empezar mapeo

	   /*struct stat {
               dev_t     st_dev;         ID of device containing file
               ino_t     st_ino;         Inode number 
               mode_t    st_mode;        File type and mode 
               nlink_t   st_nlink;       Number of hard links 
               uid_t     st_uid;         User ID of owner 
               gid_t     st_gid;         Group ID of owner 
               dev_t     st_rdev;        Device ID (if special file)
               off_t     st_size;        Total size, in bytes 
               blksize_t st_blksize;     Block size for filesystem I/O
               blkcnt_t  st_blocks;      Number of 512B blocks allocated 

        PROT_READ
              Pages may be read.

       MAP_PRIVATE
              Create a private copy-on-write mapping.  Updates to the
              mapping are not visible to other processes mapping the
              same file, and are not carried through to the underlying
              file.  It is unspecified whether changes made to the file
              after the mmap() call are visible in the mapped region.
              */

	struct stat buff_st;

	if(fstat(filemap, &buff_st) != 0){
		return 0;
	}

	char *map = mmap(NULL, buff_st.st_size, PROT_READ, MAP_PRIVATE, filemap, 0);

	if(map == MAP_FAILED){
		return 0;
	}

	const ElfW(Ehdr) *headr = (const ElfW(Ehdr)*)map;
	const ElfW(Shdr) *sheadr = (const ElfW(Shdr)*)(map + headr->e_shoff);

	/*e_shoff
              This member holds the section header table's file offset
              in bytes.  If the file has no section header table, this
              member holds zero.*/

	

	printf("[+]Magic number:                           0x%x -> %c%c%c [0x%x%x%x]\n", headr->e_ident[0], headr->e_ident[1], headr->e_ident[2], headr->e_ident[3], headr->e_ident[1], headr->e_ident[2], headr->e_ident[3]);

	if(headr->e_ident[4] == 1){
	printf("[+]Clase:                                  32bits\n");

	}
	if(headr->e_ident[4] == 2){
	printf("[+]Clase:                                  64bits\n");

	}

	if(headr->e_ident[5] == 1){
	printf("[+]EI_DATA:                                Little Endianness\n");

	}
	if(headr->e_ident[5] == 2){
	printf("[+]EI_DATA:                                Big Endianness\n");

	}

	printf("[+]EI_Version:                             0x%x\n", headr->e_ident[6]);

	switch(headr->e_ident[7]){
		case 0: buf_Os = "[+]Sistema operativo(ABI):                 System V";
		        break;
		case 1: buf_Os = "[+]Sistema operativo(ABI):      HP-UX";
		        break;
		case 2: buf_Os = "[+]Sistema operativo(ABI):      NetBSD";
		        break;
		case 3: buf_Os = "[+]Sistema operativo(ABI):      Linux";
		        break;
		case 4: buf_Os = "[+]Sistema operativo(ABI):      GNU Hurd";
		        break;
		case 6: buf_Os = "[+]Sistema operativo(ABI):      Solaris";
		        break;
		case 7: buf_Os = "[+]Sistema operativo(ABI):      AIX";
		        break;
		case 8: buf_Os = "[+]Sistema operativo(ABI):      IRIX";
		        break;
		case 9: buf_Os = "[+]Sistema operativo(ABI):      FreeBSD";
		        break;
		case 10: buf_Os = "[+]Sistema operativo(ABI):      Tru64";
		        break;
		case 11: buf_Os = "[+]Sistema operativo(ABI):      Novell Modeto";
		        break;
		case 12: buf_Os = "[+]Sistema operativo(ABI):      OpenBSD";
		        break;
		case 13: buf_Os = "[+]Sistema operativo(ABI):      OpenVMS";
		        break;
		case 14: buf_Os = "[+]Sistema operativo(ABI):      NonStop Kernel";
		        break;
		case 15: buf_Os = "[+]Sistema operativo(ABI):      Aros";
		        break;
		case 16: buf_Os = "[+]Sistema operativo(ABI):      Fenix OS";
		        break;
		case 17: buf_Os = "[+]Sistema operativo(ABI):      CloudABI";
		        break;
		case 18: buf_Os = "[+]Sistema operativo(ABI):      Stratus Technologies OpenVOS";
		        break;
		default : buf_Os = "[+]Sistema operativo:      No encontrado";
		        break;
	}

	switch(headr->e_type){
		case 1: buf_tip = "[+]Tipo:                                   [ET_NONE:Desconocido]";
		break;
		case 2: buf_tip = "[+]Tipo:                                   [ET_REL:Relocatable file]";
		break;
		case 3: buf_tip = "[+]Tipo:                                   [ET_EXEC:Executable file]";
		break;
		case 4: buf_tip = "[+]Tipo:                                   [ET_DYN:Shared object";
		break;
		case 5: buf_tip = "[+]Tipo:                                   [ET_CORE:Core file";
		break;
		case 6: buf_tip = "[+]Tipo:                                   [ET_LOOS:Reserved inclusive range. Operating system specific";
		break;
		case 7: buf_tip = "[+]Tipo:                                   [ET_HIOS:Reserved inclusive range. Operating system specific";
		break;
		case 8: buf_tip = "[+]Tipo:                                   [ET_LOPROC:Reserved inclusive range. Processor specific";
		break;
		case 9: buf_tip = "[+]Tipo:                                   [ET_HIPROC:Reserved inclusive range. Processor specific";
		break;
		default: buf_tip = "[+]Tipo no encontrado";
		break;
	}

	switch(headr->e_machine){
		case 0: buf_arch = "[+]Arquitectura:                           [No especifico]";
		break;
		case 1: buf_arch = "[+]Arquitectura:                           [AT&T WE 32100]";
		break;
		case 2: buf_arch = "[+]Arquitectura:                           [SPARC]";
		break;
		case 3: buf_arch = "[+]Arquitectura:                           [x86]";
		break;
		case 4: buf_arch = "[+]Arquitectura:                           [Motorola 68000 (M68k)]";
		break;
		case 5: buf_arch = "[+]Arquitectura:                           [Motorola 88000 (M88k)]";
		break;
		case 6: buf_arch = "[+]Arquitectura:                           [Intel MCU]";
		break;
		case 7: buf_arch = "[+]Arquitectura:                           [Intel 80860]";
		break;
		case 8: buf_arch = "[+]Arquitectura:                           [MIPS]";
		break;
		case 9: buf_arch = "[+]Arquitectura:                           [IBM System/370]";
		break;
		case 10: buf_arch = "[+]Arquitectura:                           [MIPS RS3000 Little-endian]";
		break;
		case 14: buf_arch = "[+]Arquitectura:                           [Hewlett-Packard PA-RISC]";
		break;
		case 19: buf_arch = "[+]Arquitectura:                           [Intel 80960]";
		break;
		case 20: buf_arch = "[+]Arquitectura:                           [PowerPC]";
		break;
		case 21: buf_arch = "[+]Arquitectura:                           [S390, including S390x]";
		break;
		case 22: buf_arch = "[+]Arquitectura:                           [IBM SPU/SPC]";
		break;
		case 36: buf_arch = "[+]Arquitectura:                           [NEC V800]";
		break;
		case 37: buf_arch = "[+]Arquitectura:                           [Fujitsu FR20]";
		break;
		case 38: buf_arch = "[+]Arquitectura:                           [TRW RH-32]";
		break;
		case 39: buf_arch = "[+]Arquitectura:                           [Motorola RCE]";
		break;
		case 40: buf_arch = "[+]Arquitectura:                           [ARM (up to ARMv7/Aarch32)]";
		break;
		case 41: buf_arch = "[+]Arquitectura:                           [Digital Alpha]";
		break;
		case 42: buf_arch = "[+]Arquitectura:                           [SuperH]";
		break;
		case 43: buf_arch = "[+]Arquitectura:                           [SPARC Version 9]";
		break;
		case 44: buf_arch = "[+]Arquitectura:                           [Siemens TriCore embedded processor]";
		break;
		case 45: buf_arch = "[+]Arquitectura:                           [Argonaut RISC Core]";
		break;
		case 46: buf_arch = "[+]Arquitectura:                           [Hitachi H8/300]";
		break;
		case 47: buf_arch = "[+]Arquitectura:                           [Hitachi H8/300H]";
		break;
		case 48: buf_arch = "[+]Arquitectura:                           [Hitachi H8S]";
		break;
		case 49: buf_arch = "[+]Arquitectura:                           [Hitachi H8/500]";
		break;
		case 50: buf_arch = "[+]Arquitectura:                           [IA-64]";
		break;
		case 51: buf_arch = "[+]Arquitectura:                           [Stanford MIPS-X]";
		break;
		case 52: buf_arch = "[+]Arquitectura:                           [Motorola ColdFire]";
		break;
		case 53: buf_arch = "[+]Arquitectura:                           [Motorola M68HC12]";
		break;
		case 54: buf_arch = "[+]Arquitectura:                           [Fujitsu MMA Multimedia Accelerator]";
		break;
		case 55: buf_arch = "[+]Arquitectura:                           [Siemens PCP]";
		break;
		case 56: buf_arch = "[+]Arquitectura:                           [Sony nCPU embedded RISC processor]";
		break;
		case 57: buf_arch = "[+]Arquitectura:                           [Denso NDR1 microprocessor]";
		break;
		case 58: buf_arch = "[+]Arquitectura:                           [Motorola Star*Core processor]";
		break;
		case 59: buf_arch = "[+]Arquitectura:                           [Toyota ME16 processor]";
		break;
		case 60: buf_arch = "[+]Arquitectura:                           [STMicroelectronics ST100 processor]";
		break;
		case 61: buf_arch = "[+]Arquitectura:                           [Advanced Logic Corp. TinyJ]";
		break;
		case 62: buf_arch = "[+]Arquitectura:                           [AMD x86-64]";
		break;
		case 140: buf_arch = "[+]Arquitectura:                          [TMS320C6000 Family]";
		break;
		case 175: buf_arch = "[+]Arquitectura:                          [MCST Elbrus e2k]";
		break;
		case 183: buf_arch = "[+]Arquitectura:                          [ARM 64-bits (ARMv8/Aarch64)]";
		break;
		case 243: buf_arch = "[+]Arquitectura:                          [RISC-V]";
		break;
		case 247: buf_arch = "[+]Arquitectura:                          Berkeley Packet Filter]";
		break;
		case 257: buf_arch = "[+]Arquitectura:                          [WDC 65C816]";
		break;
		default: buf_arch = "[+]Arquitectura no encontrada";
		break;
	}

	printf("%s\n", buf_Os);
	printf("%s\n", buf_tip);
	printf("%s [0x%x]\n", buf_arch, headr->e_machine);
	printf("[+]Version elf:                            0x%x\n", headr->e_version);
	printf("[+]Entry:                                  0x%x\n", headr->e_entry);
	printf("[+]Program header offset:                  0x%x\n", headr->e_phoff);
	printf("[+]Section header offset:                  0x%x\n", headr->e_shoff);
	printf("[+]Processor specific flags:               0x%x\n", headr->e_flags);
	printf("[+]elf Size:                               0x%x\n", headr->e_ehsize);
	printf("[+]Program header table entry size:        0x%x\n", headr->e_phentsize);
	printf("[+]Program header table entry count:       0x%x\n", headr->e_phnum);
	printf("[+]Section header table entry size:        0x%x\n", headr->e_shentsize);
	printf("[+]Section header table entry count:       0x%x\n", headr->e_shnum);
	printf("[+]Section header string table index:      0x%x\n", headr->e_shstrndx);

	printf("%s","\n");

	/*typedef struct Elf64Hdr{
	uint8_t e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;

}Elf64Hdr;*/

	const char *secciones = map + sheadr[headr->e_shstrndx].sh_offset;

	printf("%s  %s\t %s\t\t %s\t\t %s\t\t\t %s\t\t\t %s\n", "Num", "Nombre","Dirección", "Tipo","offset", "Tam", "Flags");

	for (uint t = 0; t < headr->e_shnum; t++)
	{
		switch(sheadr[t].sh_type){

			case 0: buf_ty = "SHT_NULL";
			break;
			case 1: buf_ty = "SHT_PROGBITS";
			break;
			case 2: buf_ty = "SHT_SYMTAB";
			break;
			case 3: buf_ty = "SHT_STRTAB";
			break;
			case 4: buf_ty = "SHT_RELA";
			break;
			case 5: buf_ty = "SHT_HASH";
			break;
			case 6: buf_ty = "SHT_DYNAMIC";
			break;
			case 7: buf_ty = "SHT_NOTE";
			break;
			case 8: buf_ty = "SHT_NOBITS";
			break;
			case 9: buf_ty = "SHT_REL";
			break;
			case 10: buf_ty = "SHT_SHLIB";
			break;
			case 11: buf_ty = "SHT_DYNSYM";
			break;
			case 12: buf_ty = "SHT_NUM";
			break;
			case 0x70000000: buf_ty = "SHT_LOPROC";
			break;
			case 0x7fffffff: buf_ty = "SHT_HIPROC";
			break;
			case 0x80000000: buf_ty = "SHT_LOUSER";
			break;
			case 0xffffffff: buf_ty = "SHT_HIUSER";
			break;
		}

		switch(sheadr[t].sh_flags){
			case 0x1: buf_flg = "SHF_WRITE";
			break;
			case 0x2: buf_flg = "SHF_ALLOC";
			break;
			case 0x4: buf_flg = "SHF_EXECINSTR";
			break;
			case 0x00100000: buf_flg = "SHF_RELA_LIVEPATCH";
			break;
			case 0x00200000: buf_flg = "SHF_RO_AFTER_INIT";
			break;
			case 0xf0000000: buf_flg = "SHF_MASKPROC";
			break;
		}

			printf("[%2d] %s\n     %2d-->\t[0x%016x]\t[%s]\t[0x%016x]\t[0x%016x]\t[%s]\n", t, secciones + sheadr[t].sh_name, t, sheadr[t].sh_addr, buf_ty,sheadr[t].sh_offset, sheadr[t].sh_size, buf_flg);

			/*typedef struct Elf64_shdr {
  uint32_t sh_name;       
  uint32_t sh_type;       
  uint64_t sh_flags;     
  uint64_t sh_addr;       
  uint64_t sh_offset;     
  uint64_t sh_size;      
  uint32_t sh_link;       
  uint32_t sh_info;       
  uint64_t sh_addralign; 
  uint64_t sh_entsize;   
} Elf64_shdr;*/

		
	}

	printf("%s","\n");
	
	return 0;

}



