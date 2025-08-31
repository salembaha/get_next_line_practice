#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
static char	*read_to_stash(int fd, char *stash);
static char	*extract_line(char *stash);
static char	*stash_after_line(char *stash);

#endif
