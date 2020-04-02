
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <io.h>

#define MAX_LENGTH 100
#define MAX_MASK 20

void FindFilesAndPrint(char* mask, char* dir)
{
	struct _finddata_t foundFile;
	intptr_t hFile;
	char buff[MAX_LENGTH] = " ";
	hFile = _findfirst(mask, &foundFile, 0);
	snprintf(buff, sizeof buff, "%s/%s\n", dir, foundFile.name);
	printf(buff);
	while (_findnext(hFile, &foundFile) == 0)
	{
		snprintf(buff, sizeof buff, "%s/%s\n", dir, foundFile.name);
		printf(buff);
	}
}

int main()
{
	struct _finddata_t file_info;
	char directory[MAX_LENGTH] = " ";
	char mask[MAX_MASK] = " ";
	printf("Enter the directory:");
	scanf_s("%s", directory, MAX_LENGTH);
	printf("Enter the mask:");
	scanf_s("%s", mask, MAX_MASK);
	_chdir(directory);
	if (_findfirst(mask, &file_info, 0) == -1)
	{
		printf("Help! We can't find files with this mask.");
		return 1;
	}
	else
	{
		FindFilesAndPrint(mask, directory);
	}
	return 0;
}