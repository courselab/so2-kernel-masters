#include "filesystem.h"
#include "tyfs/tyfsedit.h"
#include "bios2.h"

extern char _DIR_BUFF_ADDR[];

void f_list_kernel(){
	struct fs_header_t *dir_buff;
	dir_buff = (struct fs_header_t*) 0x7c00;

	load_dir();

	kwrite("Listing...\n");

	char *filename;

	// for EVERY POSSIBLE file entry...
	for(int i = 0; i < dir_buff->number_of_file_entries; i++){
		filename = _DIR_BUFF_ADDR + i * DIR_ENTRY_LEN;

		// if the file entry is not empty...
		if(*filename){
			kwrite(filename);
			kwrite("\n");
		}
	
	}

}