#include "s21_cat.h"

int exit_status = EXIT_SUCCESS;

int main(int argc, char **argv) {
  t_cat florida;

  if (argc < 1 && !*argv)
    s21_exit("cat: error first argument can't be null !\n", 1);

  ft_init_flags(&florida);
  read_args(&florida, argc, argv);
  print_files(&florida);
  free_cat(&florida);
  return 0;
}
