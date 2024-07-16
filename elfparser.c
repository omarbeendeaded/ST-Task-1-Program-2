#include <stdio.h>
#include <elf.h>

int main(int argc, char** argv) {
	
	FILE *elfFile  = fopen(argv[1], "r");
	Elf64_Ehdr header;

	fread(&header, sizeof(header), 1, elfFile);

	printf("ELF Header:\n");

	printf(" Magic:\t %x %x %x %x\n", header.e_ident[EI_MAG0], header.e_ident[EI_MAG1], header.e_ident[EI_MAG2], header.e_ident[EI_MAG3]);
	
	printf(" Class:\t\t\t\t\t");
	switch(header.e_ident[EI_CLASS]) {
		case ELFCLASSNONE: printf("INVALID\n"); break;
		case ELFCLASS32:   printf("ELF32\n"); break;
		case ELFCLASS64:   printf("ELF64\n"); break;
	}
	
	printf(" Data:\t\t\t\t\t");
	switch(header.e_ident[EI_DATA]) {
		case ELFDATANONE: printf("Unknown data format.\n"); break;
		case ELFDATA2LSB: printf("Two\'s complement, little-endian.\n"); break;
		case ELFDATA2MSB: printf("Two\'s complement, big-endian.\n"); break;
	}

	printf(" Version:\t\t\t\t");
	switch(header.e_ident[EI_VERSION]) {
		case EV_NONE:    printf("INVALID\n"); break;
		case EV_CURRENT: printf("1 (current)\n"); break;
	}

	printf(" OS/ABI:\t\t\t\t");
	switch(header.e_ident[EI_OSABI]) {
		case ELFOSABI_SYSV:       printf("UNIX System V ABI\n"); break;
		case ELFOSABI_HPUX:       printf("HP-UX ABI\n"); break;
		case ELFOSABI_NETBSD:     printf("NetBSD ABI\n"); break;
		case ELFOSABI_LINUX:      printf("Linux ABI\n"); break;
		case ELFOSABI_SOLARIS:    printf("Solaris ABI\n"); break;
		case ELFOSABI_IRIX:       printf("IRIX ABI\n"); break;
		case ELFOSABI_FREEBSD:    printf("FreeBSD ABI\n"); break;
		case ELFOSABI_TRU64:      printf("TRU64 Unix ABI\n"); break;
		case ELFOSABI_ARM:        printf("ARM architecture ABI\n"); break;
		case ELFOSABI_STANDALONE: printf("Stand-alone (embedded) ABI\n"); break;
	}

	printf(" ABI Version:\t\t\t\t%d\n", header.e_ident[EI_ABIVERSION]);

	printf(" Type:\t\t\t\t\t");
	switch(header.e_type) {
		case ET_NONE: printf("Unknown type\n"); break;
		case ET_REL:  printf("Relocatable file\n"); break;
		case ET_EXEC: printf("Excutable file\n"); break;
		case ET_DYN:  printf("Shared file\n"); break;
		case ET_CORE: printf("Core file\n"); break;
	}

	printf(" Machine:\t\t\t\t");
	switch (header.e_machine) {
		case EM_NONE:        printf("Unknown machine\n"); break;
		case EM_M32:         printf("AT&T WE 32100\n"); break;
		case EM_SPARC:       printf("Sun Microsystems SPARC\n"); break;
		case EM_386:         printf("Intel 80386\n"); break;
		case EM_68K:         printf("Motorola 68000\n"); break;
		case EM_88K:         printf("Motorola 88000\n"); break;
		case EM_860:         printf("Intel 80860\n"); break;
		case EM_MIPS:        printf("MIPS RS3000 big-endian"); break;
		case EM_PARISC:      printf("HP/PA\n"); break;
		case EM_SPARC32PLUS: printf("SPARC with enhanced instruction set\n"); break;
		case EM_PPC:         printf("PowerPC\n"); break;
		case EM_PPC64:       printf("PowerPC 64-bit\n"); break;
		case EM_S390:        printf("IBM S/390\n"); break;
		case EM_ARM: 	     printf("ARM\n"); break;
		case EM_SH:          printf("Renesas SuperH\n"); break;
		case EM_SPARCV9:     printf("SPARC v9 64-bit\n"); break;
		case EM_IA_64:       printf("Intel Itanium\n"); break;
		case EM_X86_64:      printf("AMD x86-64\n"); break;
		case EM_VAX:         printf("DEC Vax\n"); break;
	}

	printf(" Version:\t\t\t\t0x%x\n", header.e_version);

	printf(" Entry point address:\t\t\t0x%lx\n", header.e_entry);
	printf(" Start of program headers:\t\t%ld (bytes into file)\n", header.e_phoff);
	printf(" Start of section headers:\t\t%ld (bytes into file)\n", header.e_shoff);
	printf(" Flags:\t\t\t\t\t0x%d\n", header.e_flags);
	printf(" Size of this header:\t\t\t%d (bytes)\n", header.e_ehsize);
	printf(" Size of program headers:\t\t%d (bytes)\n", header.e_phentsize);
	printf(" Number of program headers:\t\t%d\n", header.e_phnum);
	printf(" Size of section headers:\t\t%d (bytes)\n", header.e_shentsize);
	printf(" Number of section headers:\t\t%d\n", header.e_shnum);
	printf(" Section header string table index:\t%d\n", header.e_shstrndx);


	fclose(elfFile);	
	
	return 0;
}
