/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** stock_file
*/

#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

void	*stock_file(const char *filename)
{
	int fd;
	struct	stat s;
	void *address;

	if (filename == NULL || (fd = open(filename, O_RDONLY)) == -1) {
		fprintf(stderr, "File is NULL or not readable\n");
		return (NULL);
	}
	if (fstat(fd, &s) == -1) {
		perror("stat");
		close(fd);
		return (NULL);
	}
	address = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	close(fd);
	return ((address != NULL ? address : NULL));
}
