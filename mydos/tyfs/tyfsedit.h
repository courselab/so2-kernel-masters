/* In order to allow for the media to be bootable by BIOS, the file system
   signature starts with a jump instruction that leaps over the header data,
   and lands at the bootstrap program right next to it. In the present example,
   the signature is the instruction 'jump 0xe', follwed by the character
   sequence 'ty' (we thus jump 14 bytes). */

#define DIR_ENTRY_LEN 32  /* Max file name length in bytes.           */
#define FS_SIGNATURE "\xeb\xety" /* File system signature.                   */
#define FS_SIGLEN 4              /* Signature length.                        */

/* The file header. */


struct fs_header_t
{
  unsigned char signature[FS_SIGLEN];     /* The file system signature.              */
  unsigned short total_number_of_sectors; /* Number of 512-byte disk blocks.         */
  unsigned short number_of_boot_sectors;  /* Sectors reserved for boot code.         */
  unsigned short number_of_file_entries;  /* Maximum number of files in the disk.    */
  unsigned short max_file_size;           /* Maximum size of a file in blocks.       */
  unsigned int unused_space;              /* Remaining space less than max_file_size.*/
} __attribute__((packed)) fs_header;      /* Disable alignment to preserve offsets.  */