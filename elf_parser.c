#include<stdlib.h>
#include<elf.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


void getPflag(int flag){


	switch(flag){
		
			case PF_X: printf("Executable segment "); break;
			case PF_W: printf("Writeable segment "); break;
			case PF_R: printf("Readable segment "); break;


	}



}


void print_type(int type){

		switch(type){
			
				case 0x00: printf("Unknown"); break;
				case 0x01: printf("Relocatable file"); break;
				case 0x02: printf("Executable file"); break;
				case 0x03: printf("Shared object"); break;
				case 0x04: printf("Core file"); break;
				default: printf("Other"); break;



		}

}

void print_seg_type(int segtype){

		switch(segtype){
			
				case PT_NULL: printf("Program header table entry unused ,"); break;
				case PT_LOAD: printf("Loadable segment ,"); break;
				case PT_DYNAMIC: printf("Dynamic linking information ,"); break;
				case PT_INTERP: printf("Loadable segment ,"); break;
				case PT_NOTE: printf("Auxiliary information ,"); break;
				case PT_SHLIB: printf("Reserved ,"); break;
				case PT_PHDR: printf("Segment containing program header table itself ,"); break;
				case PT_TLS: printf("Thread-Local Storage template ,"); break;
				case PT_LOOS: printf("Recursive ,"); break;
				case PT_HIOS: printf("Recursive ,"); break;
				case PT_LOPROC: printf("Processor specific 1 ,"); break;
				case PT_HIPROC: printf("Processor specific 2 ,"); break;




		}




}

void print_section_type(int section_type){

		switch(section_type){

				case SHT_NULL: printf("Section header unused "); break;
				case SHT_PROGBITS: printf("Program data "); break;
				case SHT_SYMTAB: printf("Symbol table "); break;
				case SHT_STRTAB: printf("String table"); break;
				case SHT_RELA: printf("Relocation entries with addends "); break;
				case SHT_HASH: printf("Symbol hash table "); break;
				case SHT_DYNAMIC: printf("Dynamic linking information "); break;
				case SHT_NOTE: printf("Notes "); break;
				case SHT_NOBITS: printf("Program space with no data (bss) "); break;
				case SHT_REL: printf("Relocation entries, no addends "); break;
				case SHT_SHLIB: printf("Reserved "); break;
				case SHT_DYNSYM: printf("Dynamic linker symbol table "); break;
				case SHT_INIT_ARRAY: printf("Array of constructors "); break;
				case SHT_FINI_ARRAY: printf("Array of destructors "); break;
				case SHT_PREINIT_ARRAY: printf("Array of pre-constructors "); break;
				case SHT_GROUP: printf("Section group "); break;
				case SHT_SYMTAB_SHNDX: printf("Extended section indices "); break;
				case SHT_NUM: printf("Number of defined types "); break;
				case SHT_LOOS: printf("Start OS-specific "); break;



		}

}

void print_section_flag(int section_flag){


		switch(section_flag){
			case SHF_WRITE: printf("Writable "); break;
			case SHF_ALLOC: printf("Occupies memory during execution "); break;
			case SHF_EXECINSTR: printf("Executable "); break;
			case SHF_MERGE: printf("Might be merged "); break;
			case SHF_STRINGS: printf("Contains null terminated strings "); break;
			case SHF_INFO_LINK: printf("Link info "); break;
			case SHF_LINK_ORDER: printf("Preserve order after combining "); break;
			case SHF_OS_NONCONFORMING: printf("Non standard OS specific handling required "); break;
			case SHF_GROUP: printf("Section is member of a group "); break;
			case SHF_TLS: printf("Section hold thread-local data "); break;
			case SHF_MASKOS: printf("OS-Specific "); break;
			case SHF_MASKPROC: printf("Processor specific "); break;
			case SHF_ORDERED: printf("Special ordering requirment (solaris) "); break;
			case SHF_EXCLUDE: printf("Writable "); break;
		}




}





void print_machineset(int code){

		switch(code){

			case 0x00: printf("No specific instruction set"); break;
			case 0x01: printf("AT&T WE 32100"); break;
			case 0x02: printf("SPARC"); break;
			case 0x03: printf("x86"); break;
			case 0x04: printf("Motorola 68000 (M68k)"); break;
			case 0x05: printf("Motorola 88000 M88k"); break;
			case 0x06: printf("Intel MCU"); break;
			case 0x07: printf("Intel 80860"); break;
			case 0x08: printf("MIPS"); break;
			case 0x09: printf("IBM System/370"); break;
			case 0x0A: printf("MIPS RS3000 Little-endian"); break;
			case 0x0F: printf("Hewlett-Packard PA-RISC"); break;
			case 0x13: printf("Intel 80960"); break;
			case 0x14: printf("Power PC"); break;
			case 0x15: printf("Power PC 64 bit"); break;
			case 0x16: printf("S390"); break;
			case 0x17: printf("IBM SPU/SPC"); break;
			case 0x24: printf("NEC V800"); break;
			case 0x25: printf("Fujitsu FR20"); break;
			case 0x26: printf("TRW RH-32"); break;
			case 0x27: printf("Motorola RCE"); break;
			case 0x28: printf("Arm"); break;
			case 0x29: printf("Digital Alpha"); break;
			case 0x2A: printf("SuperH"); break;
		    case 0x3E: printf("AMD x86-64"); break;

		}





}




void print_osabi(char code){
	
		switch(code){

			case 0x00: printf("V-System"); break;
			case 0x01: printf("HP UX"); break;
			case 0x02: printf("NET BSD"); break;
			case 0x03: printf("Linux"); break;
			case 0x04: printf("GNU Hurd"); break;
			case 0x06: printf("Solaris"); break;
			case 0x07: printf("AIX (Monterey)"); break;
			case 0x08: printf("IRIX"); break;
			case 0x09: printf("Free BSD"); break;
			case 0x0A: printf("Tru 64"); break;
			case 0x0B: printf("Model Modesto"); break;
			case 0x0C: printf("Open BSD"); break;
			case 0x0D: printf("Open VMS"); break;
			case 0x0E: printf("Nonstop kernel"); break;
			case 0x0F: printf("AROS"); break;
			case 0x10: printf("Fenix OS"); break;
			case 0x11: printf("Nuxi CloudABI"); break;
			case 0x12: printf("Status technologies OpenVOS"); break;

		}


}





int main(){
	Elf64_Ehdr header;
	Elf64_Shdr section_header;
	Elf64_Phdr program_header;
	Elf64_Shdr str_index;

	char filename[] = "sample";


	int fd = open(filename, O_RDONLY);
	char buffer[5];
	char section_name[256];
	short int i = 0;

	if(read(fd, &header, sizeof(Elf64_Ehdr))!=sizeof(Elf64_Ehdr)){
		printf("Errore");
	}else{
		
			printf("Specifiche del binario '%s': \n", filename);
			printf("\t--> Sistema: ");
			print_osabi(header.e_ident[EI_OSABI]);
			printf("\n\t--> Tipo:");
			print_type(header.e_type);
			printf("\n\t--> Istruction Set: ");
			print_machineset(header.e_machine);
			printf("\n\t--> Versione ELF: %x.0\n\n", header.e_version);
            
			if(lseek(fd, header.e_phoff, SEEK_SET) > 0){
				
					printf("Segmenti: \n");

					for(i = 0; i < header.e_phnum; i++){

						if(read(fd, &program_header, sizeof(Elf64_Phdr)) != sizeof(Elf64_Phdr)){
							exit(1);
						}
						printf("--<%d>: ", i);
						print_seg_type(program_header.p_type);
						getPflag(program_header.p_flags);
						printf("- Size (Disk) %ld Bytes", program_header.p_filesz / 8);
						printf("- Size (Ram) %ld Bytes \n", program_header.p_memsz / 8);

					}



		    }

			lseek(fd, header.e_shoff + header.e_shstrndx * sizeof(Elf64_Shdr), SEEK_SET);
			read(fd, &str_index, sizeof(Elf64_Shdr));
			if(lseek(fd, header.e_shoff, SEEK_SET) > 0){
				
					printf("\nSezioni: ");
					for(i = 0; i < header.e_shnum; i ++){
							
						if(lseek(fd, header.e_shoff + i * sizeof(Elf64_Shdr), SEEK_SET) < 0){
								exit(1);
						}else{
								read(fd, &section_header, sizeof(Elf64_Shdr));
								lseek(fd, str_index.sh_offset + section_header.sh_name, SEEK_SET);
								read(fd, section_name, sizeof(char) * 100);
								printf("<%d> section '%s' - ", i, section_name);
								print_section_type(section_header.sh_type);
								print_section_flag(section_header.sh_flags);
								printf("- Size %ld \n", section_header.sh_size / 8);



						}

					}

			}






					

	}

}
