#include <stdio.h>


// This function can delete any unwanted tasks or data entry mistakes.
void DELETETASK()
{
  FILE* zfp;
  FILE* vfp;
  char character;
  int line = 0;
  int temporary = 1;
  zfp = fopen("TASKFILE.txt", "r");
  if (zfp == NULL) {
        printf("\nTHE FILE IS UNABLE TO OPEN. PLEASE CHECK.\n");
        return ;
  }
  while (!feof(zfp)) {
        character = getc(zfp);
  }
  rewind(zfp);
  printf("\n**********************************");
  printf("\nEnter number of which task that you want to delete(example: 1 or 2): ");
  scanf("%d", &line);
  vfp = fopen("temp.txt", "w");
  while (!feof(zfp)) {
      character = getc(zfp);
      if (character == '\n')
            temporary++;
      if (temporary != line)
            putc(character, vfp);
  }
  rewind(vfp);
  fclose(zfp);
  fclose(vfp);
  remove("TASKFILE.txt");
  rename("temp.txt", "TASKFILE.txt");
  printf("\nChanged or Updated file. Enjoy !!");
  Sleep(1000);
  zfp = fopen("TASKFILE.txt", "r");
  if (zfp == NULL) {
      printf("\nTHE FILE IS UNABLE TO OPEN.PLEASE CHECK\n");
      return;
  }
  while (!feof(zfp)) {
      character = getc(zfp);
  }
  rewind(zfp);
  fclose(zfp);
  printf("\n");
  return;
}
