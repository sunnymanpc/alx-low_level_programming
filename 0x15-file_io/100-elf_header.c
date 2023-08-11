#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void print_class(unsigned char *elf_id);
void print_data(unsigned char *elf_id);
void check_elf(unsigned char *elf_id);
void print_entry(unsigned long int elf_entry, unsigned char *elf_id);
void print_magic(unsigned char *elf_id);
void print_version(unsigned char *elf_id);
void print_abi(unsigned char *elf_id);
void print_osabi(unsigned char *elf_id);
void print_type(unsigned int elf_type, unsigned char *elf_id);
void close_elf(int elf);

/**
 * check_elf - This will check if it is an ELF file.
 * @elf_id: This is pointer to an array containing the ELF magic numbers.
 *
 * Description: If this file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *elf_id)
{
	int i;

	for (i = 0; i < 4; index++)
	{
		if (elf_id[i] != 127 &&
		    elf_id[i] != 'E' &&
		    elf_id[i] != 'L' &&
		    elf_id[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: This is not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - This will print a magic number of an ELF header.
 * @elf_id: This is a pointer to an array containing the ELF magic numbers.
 *
 * Description: all magic numbers are separated by spaces.
 */
void print_magic(unsigned char *elf_id)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", elf_id[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - This will print the class of an ELF header.
 * @elf_id: This is a pointer to an array containing the ELF class.
 */
void print_class(unsigned char *elf_id)
{
	printf("  Class:                             ");

	switch (elf_id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_id[EI_CLASS]);
	}
}

/**
 * print_data - This will print the data of an ELF header.
 * @elf_id: This is a pointer to an array containing the ELF class.
 */
void print_data(unsigned char *elf_id)
{
	printf("  Data:                              ");

	switch (elf_id[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2 is complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2 is complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_id[EI_CLASS]);
	}
}

/**
 * print_version - This will print the version of an ELF header.
 * @elf_id: This is a pointer to an array containing the ELF version.
 */
void print_version(unsigned char *elf_id)
{
	printf("  Version:                           %d",
	       elf_id[EI_VERSION]);

	switch (elf_id[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - This will print the OS/ABI of an ELF header.
 * @elf_id: This is a pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *elf_id)
{
	printf("  OS/ABI:                            ");

	switch (elf_id[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_id[EI_OSABI]);
	}
}

/**
 * print_abi - This will print the ABI version of an ELF header.
 * @elf_id: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *elf_id)
{
	printf("  ABI Version:                       %d\n",
	       elf_id[EI_ABIVERSION]);
}

/**
 * print_type - This will print the type of an ELF header.
 * @elf_type: This is the ELF type.
 * @elf_id: This is a pointer to an array containing the ELF class.
 */
void print_type(unsigned int elf_type, unsigned char *elf_id)
{
	if (elf_id[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type:                              ");

	switch (elf_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - This will print the entry point of an ELF header.
 * @elf_entry: This is the address of the ELF entry point.
 * @elf_id: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int elf_entry, unsigned char *elf_id)
{
	printf("  Entry point address:               ");

	if (elf_id[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (elf_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}

/**
 * close_elf - This will close the ELF file.
 * @elf: This is the file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Cannot close a %d\n", elf);
		exit(98);
	}
}

/**
 * main - This will display the information contained in the ELF header.
 * @argc: These are the number of arguments supplied to the program.
 * @argv: These are the array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->elf_id);
	printf("ELF Header:\n");
	print_magic(header->elf_id);
	print_class(header->elf_id);
	print_data(header->elf_id);
	print_version(header->elf_id);
	print_osabi(header->elf_id);
	print_abi(header->elf_id);
	print_type(header->elf_type, header->elf_id);
	print_entry(header->elf_entry, header->elf_id);

	free(header);
	close_elf(o);
	return (0);
}
